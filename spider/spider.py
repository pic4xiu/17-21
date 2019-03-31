import requests
import re
url = "https://www.kanshushenzhan.com/4326/"
fb = open("唯有星河.txt",'w',encoding = 'gbk')
this = requests.get(url)
this.encoding = 'gbk'
html = this.text
easy = re.findall(r'<div class="chapterCon">(.*?)</div>',html,re.S)[0]
chapter_info_list = re.findall(r'href="(.*?)">(.*?)</a>',easy)
for chapter_info in chapter_info_list:
	chapter_url,chapter_title = chapter_info
	chapter_url = "https://www.kanshushenzhan.com%s" % chapter_url
	this = requests.get(chapter_url)
	this.encoding = 'gbk'
	chapter_con = re.findall(r'<div class="articleCon">(.*?)</div>',this.text,re.S)[0]
	fb.write(chapter_title)
	chapter_con = chapter_con.replace('<br />','')
	chapter_con = chapter_con.replace(' ','')
	chapter_con = chapter_con.replace('<p>','')
	chapter_con = chapter_con.replace('\n','')
	chapter_con = chapter_con.replace('&nbsp;','')
	chapter_con = chapter_con.replace('<script>chuanqisf()</script>','')
	fb.write(chapter_con)
	fb.write('\n')
	print(chapter_url)
#this py has some obvious disadvantages.If you find a problem, please make your own contribution to this project.
