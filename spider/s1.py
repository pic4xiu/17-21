import requests
import re
url='https://github.com/pic4xiu?tab=followers'
response = requests.get(url)
response.encoding = 'utf-8'
html = response.text
#fb = open("test.txt",'w',encoding = 'utf-8')
easy = re.findall(r'class="UnderlineNav-item selected"(.*?)class="UnderlineNav-item "',html,re.S)
people = re.findall(r'<span class="Counter">(.*?)</span>',str(easy),re.S)[0]
people = people.replace(' ','')
a = str(people)
a = a.replace("\\n",'')
print(a)
