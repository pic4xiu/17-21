import requests
import re
import urllib.request
count=1
jpg_count=1
url='https://www.cust.edu.cn/'
response = requests.get(url)
response.encoding = 'utf-8'
html = response.text
easy = re.findall(r'<ul class="list01">(.*?)</ul>',html,re.S)
people = re.findall(r'href="(.*?)"',str(easy),re.S)
for i in people:
    i='https://www.cust.edu.cn/'+i
    file = "E:/new/新闻" + str(count) + '.html'
    r = requests.get(i)
    r.encoding = 'utf-8'
    with open(file, "wb") as code:
        code.write(r.content)
    count=count+1
    jpg = re.findall(r'window.open(.*?).jpg',r.text,re.S)
    for j in jpg:
        print(j[4:])
        rsp=urllib.request.urlopen("https://www.cust.edu.cn/"+j[4:]+".jpg")
        img=rsp.read()
        file = "E:/new/图片" + str(jpg_count) + '.jpg'
        with open(file,'wb') as f:
            f.write(img)
        jpg_count=jpg_count+1
