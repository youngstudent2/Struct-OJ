# -*- coding:utf-8 -*-
import requests
import re
from bs4 import BeautifulSoup


'''
title = jumbotron.select('title')[0].get_text()
description = jumbotron.select('.content')[0].get_text()
input_text = jumbotron.select('.content')[1].get_text()
output_text = jumbotron.select('.content')[2].get_text()
input_example = jumbotron.select('.content')[3].get_text()
output_example = jumbotron.select('.content')[4].get_text()
note = jumbotron.select('.content')[5].get_text()
'''
def remove_blankline(s):
    return ' '.join(re.split('\n| |\r',s))

def generate_question(questions,contest):
    filename = "{}.md".format(contest[1])
    with open(filename,'w',encoding='utf-8') as f:
        f.write('# {}\n'.format(contest[1]))
        f.write('`{}`\n'.format(contest[2]))
        for q in questions:
            f.write('## {}\n'.format(q[0])) # title
            f.write('### 问题描述:\n{}\n'.format(remove_blankline(q[1])))
            f.write('### 输入:\n{}\n'.format(remove_blankline(q[2])))
            f.write('### 输出:\n{}\n'.format(remove_blankline(q[3])))
            f.write('### 输入样例:\n```\n{}\n```\n'.format(q[4]))
            f.write('### 输出样例:\n```\n{}\n```\n'.format(q[5]))
            f.write('### 提示:\n{}\n'.format(remove_blankline(q[6])))
            f.write('\n---\n')
    
cookie = {
    "PHPSESSID":"agcmt92c9sbrdejfda72305ri6"
}
url = r'http://114.212.80.13:10000/contest.php'
r = requests.get(url,cookies=cookie)
soup = BeautifulSoup(r.content,'lxml')
jumbotron = soup.select('.jumbotron')[0]
trs = jumbotron.select('tr')
contests = []
for tr in trs:
    tds = tr.select('td')
    titles = [td.get_text().strip() for td in tds]
    #print(titles)
    contests.append(titles)

print(contests)

for contest in contests[1:]:
    i = contest[0]
    questions = []
    for j in range(2):
        url = r'http://114.212.80.13:10000/problem.php?cid={}&pid={}'.format(i,j)
        r = requests.get(url,cookies = cookie)
        soup = BeautifulSoup(r.content,'lxml')
        jumbotron = soup.select('.jumbotron')[0]
        try: 
            title = jumbotron.select('title')[0].get_text().strip()
            print(title)
        except IndexError as e:
            break
        data = [title] + [jumbotron.select('.content')[k].get_text().strip() for k in range(6)]     
        questions.append(data)
    generate_question(questions,contest)
    print("{} finish!".format(contest[1]))
    
