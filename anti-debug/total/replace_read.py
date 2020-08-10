
#找到数组的名字
def getArrayName(text,start,end):
    #print(text[start:end])
    arrayName = text[start:end]
    print(arrayName)
    return arrayName

#找到数组的长度大小，第一次出现的地方就是
def findArraySize(text, arrayName):
    start = 0

    start = text.find(arrayName+"[", start) + len(arrayName+"[")
    end = text.find("]", start)
    length = text[start:end]
    print(length)
    return length
def findReadArry(text,arrayName,length):#找到初始read函数的值
    
    str0 = 0
    str0 = text.find("read(0,"+arrayName+",",str0)+len("read(0,"+arrayName+",")
    str1 = text.find(")",str0)
    length1 = text[str0:str1]
    print(length1)
    return length1
def loop1(text):
        # 从头开始搜索
    start = 0
    # 依次往后找
    start = text.find("read(0,", start) +len("read(0,")
    print(start)
    end = text.find(",", start)
    arrayName = getArrayName(text, start, end)  # 找数组名字
    length = findArraySize(text, arrayName)  # 找数组长度
    length1 = findReadArry(text,arrayName,length)
    text = changeread(text,length,length1,arrayName)  # 将拼接好的发回来
    return text
   
def changeread(text,length,length1,arrayName):

    text = text.replace("read(0,"+arrayName+","+length1,"read(0,"+arrayName+","+length)
    print(text)
    f2 = open("a.c", "w")
    f2.write(text)

def main():
    a = input("请输入：")
    filename = a
    try:
        fp = open(filename, "r")
        print("%s 文件打开成功" % filename)
        text = fp.read()
        text = loop1(text)
    except IOError:
        print("文件打开失败,%s 文件不存在" % filename)

main()
