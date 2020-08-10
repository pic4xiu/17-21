import re

def Findhf(text):
    Headerfile=[]
    x=text.split("\n")
    #print(x)
    for i in x:
        if('#include' in i):
            Headerfile.append(i)
    #print(Headerfile)
    return Headerfile

def Findo(text):
    others=[]

    x=text.split("\n")
    #print(x)
    for i in x:
        if('#include' not in i):
                if('main' not in i):
                    others.append(i)
                else:
                    break
    #print(others)
    return others

def Findm(text):
    real=[]
    rep=[]
    count=1
    x=text.split("\n")
    for i in x:
        if(count==1):
            if('main' in i):
                #print(i)
                count=count-1
        else:
                if('}' != i):
                    real.append(i)
                else:
                    print('found finish')
    for a in real:
        if('write' in a):
            te=a.split(',')
            del te[0]
            te.pop()
            place=','.join(te)
            place='    mywrite('+place+');'
            rep.append(place)
        else:
            rep.append(a)
    #print(rep)
    return rep

def antidebug(text):
    head=Findhf(text)
    oth=Findo(text)
    main_real=Findm(text)
    fp = open('head.c', "r", encoding='UTF-8')
    head0 = fp.read()
    fp = open('ot.c', "r", encoding='UTF-8')
    oth0 = fp.read()
    head1='\n'.join(head)+head0+'\n'.join(oth)
    print(head1)
    fp = open('mai.c', "r", encoding='UTF-8')
    main0 = fp.read()
    main1=main0+'\n'.join(main_real)
    print(main1)
    text=head1+main1+oth0
    return text

def start():
    filename = input("请输入文件名字：")
    try:
        fp = open(filename, "r", encoding='UTF-8')
        print("%s 文件打开成功" % filename)
        text = fp.read()
        text = antidebug(text)
        outputFileName = "antidebug_"+filename
        f2 = open(outputFileName, "w+")
        f2.write(text)
    except IOError:
        print("文件打开失败,%s 文件不存在" % filename)
        start()

if __name__ == '__main__':
    message=''
    while message != "exit":
        start()
        message = input("输入exit结束程序 或 输入任意键继续\n")




