import re

#检测字符串时候含有数字
def hasNumbers(string):
    return bool(re.search(r'\d',string))


def twoNumber(text,start):
    deperate = text.find(";", start) #第一个分号
    deperateTwo = text.find(";",deperate+1)
    first = text[text.find("=", start)+len("="):deperate]
    strOne = ""#有等号，放等号
    if text.find(">", deperate, deperateTwo) != -1:
        str = ">"
    elif text.find("<", deperate, deperateTwo) != -1:
        str = "<"
    else:
        return -1, -1           #不符合

    position = text.find(str,deperate,deperateTwo)

    if "=" in text[deperate:deperateTwo]:
        str += "="

    second = text[text.find(str, start)+len(str):deperateTwo]
    return first, second, str


#判断字符串是否都是数字
def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass

    try:
        import unicodedata
        unicodedata.numeric(s)
        return True
    except (TypeError, ValueError):
        pass

    return False

#找到数组的名字
def getArrayName(text,start,end):
    #print(text[start:end])
    arrayName = text[text.find(",", start)+1:end]
    return arrayName

#找到数组的名字
def getArrayNameA(text,start,end):
    arrayNameA = text[start+len("strcpy("):text.find(",", start)]
    return arrayNameA

def getArrayNameB(text, start, end):
    #print(text[start:end])
    arrayNameB = text[text.find(",", start)+1:end]
    return arrayNameB

#找到数组的长度大小，第一次出现的地方就是
def findArraySize(text, arrayName):
    start = 0

    if '\"' in arrayName:
        return len(arrayName)
    else:
        start = text.find(arrayName+"[", start) + len(arrayName+"[")
        end = text.find("]", start)
        length = text[start:end]
    return length


#找到数组的长度大小，第一次出现的地方就是
def findArraySizeTWO(text, arrayName):
    start = 0

    start = text.find(arrayName+"[", start) + len(arrayName+"[")
    end = text.find("]", start)
    length = text[start:end]
    return length,start

def editScanf(text, arrayName,length,start,end):
    string = text[start:end]

    #截取text的左和右边，再把长度拼上去
    left=text[0:start+string.find("%")+1]
    middle=str(length)
    right = text[start+string.find("%")+1: len(text)]

    text = left + middle + right

    return text

def editGets(text, arrayName,length,start,end):
    string = text[start:end]

    #截取text的左和右边，再把长度拼上去
    left = text[0:start]
    middle = "fgets("+arrayName+","+length+",stdin"
    right = text[end:len(text)]
    text = left + middle + right

    return text


def editStrcpy(text, arrayNameA,arrayNameB,length,start,end):
    string = text[start:end]

    #截取text的左和右边，再把长度拼上去
    left=text[0:start]
    middle="strncpy("+arrayNameA+","+arrayNameB+","+length+""
    right = text[end: len(text)]

    text = left + middle + right

    return text


def editStrcat(text, arrayNameA,arrayNameB,length,start,end):
    string = text[start:end]

    #截取text的左和右边，再把长度拼上去
    left=text[0:start]
    middle="strncat("+arrayNameA+","+arrayNameB+","+length+""
    right = text[end: len(text)]

    text = left + middle + right

    return text


def editSprintf(text,arrayName,length,start,end):
    string = text[start:end]

    #截取text的左和右边，再把长度拼上去
    left = text[0:start]
    middle = "snprintf("+arrayName+","+length

    right = text[end:len(text)]
    text = left + middle + right

    print("left:{}".format(left))
    print("middle:".format(middle))
    print("right:{}".format(right))
    return text


def editVsprintf(text,arrayName,length,start,end):
    string = text[start:end]

    #截取text的左和右边，再把长度拼上去
    left = text[0:start]
    middle = "vsnprintf("+arrayName+","+length

    right = text[end:len(text)]
    text = left + middle + right

    print("left:{}".format(left))
    print("middle:".format(middle))
    print("right:{}".format(right))
    return text


def editOutBound(text, arrstart, end, length):
    if is_number(length):
        length = str(int(length)-1)
    length = str(length)
    left = text[0:arrstart]
    middle = str(length)
    right = text[end:len(text)]
    text = left + middle + right
    return text


def editOneByte(text, arrayName, length, arraystart, start, end,first, second, string ):
    deperate = text.find(";", start)  # 第一个分号
    #最常见的，就是从零开始一直到数组大小
    if '=' in string:
        if '<' in string and int(second) - int(first):
            point = text.find("=",deperate)
            left = text[0:point]
            right = text[point+1:len(text)]

            text = left+right
        elif '>' in string and first == length:
            point = text.find(first,start)
            left = text[0:point]
            middle = int(first)-1
            right =text[point+len(first):len(text)]
            text = left+str(middle)+right
    return text

#循环找到每一个
def loopFormat(text):
    # 从头开始搜索
    start = 0
    # 依次往后找

    while text.find("scanf(\"", start) != -1:  # 还能找到一个，就进入循环

        start = text.find("scanf(\"", start) + len("scanf(\"")  # 函数里面参数的起始地址
        end = text.find(")", start)  # 结束部分

        yinStart = text.find("scanf(\"", start) + len("scanf(\"")  # 找到的引号开始
        if not hasNumbers(text[yinStart:text.find("\"",yinStart)]):#判断是否有数字

            arrayName = getArrayName(text, start, end)  # 找数组名字
            length = findArraySize(text, arrayName)  # 找数组长度
            text = editScanf(text, arrayName, length, start, end)  # 将拼接好的发回来
        start += end - start  # 到下一个数组
    return text


#循环找到每一个
def loopGets(text):
    # 从头开始搜索
    start = 0
    # 依次往后找

    while text.find("gets(", start) != -1:  # 还能找到一个，就进入循环

        start = text.find("gets(", start)  # 函数里面参数的起始地址
        print("start:{}".format(text[start:len(text)]))
        end = text.find(")", start)  # 结束部分

        arrayName = text[start + len("gets("):end]  # 找数组名字
        print("arrayName:{}".format(arrayName))
        length = findArraySize(text, arrayName)  # 找数组长度

        text = editGets(text, arrayName, length, start, end)  # 将拼接好的发回来
        start += end - start  # 到下一个数组

    return text


#循环找到每一个
def loopStrcpy(text):
    # 从头开始搜索
    start = 0
    # 依次往后找

    while text.find("strcpy(", start) != -1:  # 还能找到一个，就进入循环

        start = text.find("strcpy(", start)  # 函数里面参数的起始地址
        end = text.find(")", start)  # 结束部分


        arrayNameA = getArrayNameA(text, start, end)  # 找目的数组名字
        arrayNameB = getArrayNameB(text, start, end)  # 找原数组名字
        print("arrayNameA:{}".format(arrayNameA))
        print("arrayNameB:{}".format(arrayNameB))
        lengthA = findArraySize(text, arrayNameA)  # 找数组长度
        lengthB = findArraySize(text, arrayNameB)  # 找数组长度

        text = editStrcpy(text, arrayNameA,arrayNameB, str(min(int(lengthA), int(lengthB))), start, end)  # 将拼接好的发回来
        start += end - start  # 到下一个数组
    return text


#循环找到每一个
def loopStrcat(text):
    # 从头开始搜索
    start = 0
    # 依次往后找
    functionName = "strcat"
    while text.find(functionName+"(", start) != -1:  # 还能找到一个，就进入循环

        start = text.find(functionName+"(", start)  # 函数里面参数的起始地址
        end = text.find(")", start)  # 结束部分


        arrayNameA = getArrayNameA(text, start, end)  # 找目的数组名字
        arrayNameB = getArrayNameB(text, start, end)  # 找原数组名字
        print("arrayNameA:{}".format(arrayNameA))
        print("arrayNameB:{}".format(arrayNameB))
        lengthA = findArraySize(text, arrayNameA)  # 找数组长度
        lengthB = findArraySize(text, arrayNameB)  # 找数组长度

        text = editStrcat(text, arrayNameA,arrayNameB, str(min(eval(lengthA), eval(lengthB))), start, end)  # 将拼接好的发回来
        start += end - start  # 到下一个数组
    return text


#循环找到每一个
def loopSprintf(text):
    # 从头开始搜索
    start = 0
    # 依次往后找

    while text.find("sprintf(", start) != -1:  # 还能找到一个，就进入循环

        start = text.find("sprintf(", start)  # 函数里面参数的起始地址
        end = text.find(")", start)  # 结束部分

        arrayName = text[start + len("sprintf("):text.find(",", start)]  # 找数组名字
        length = findArraySize(text, arrayName)  # 找数组长度
        start1 = text.find(",", start)#第一个逗号
        right = text.find(",", start1)
        text = editSprintf(text, arrayName, length, start, right)  # 将拼接好的发回来
        start += end - start  # 到下一个数组

    return text


#循环找到每一个
def loopVsprintf(text):
    # 从头开始搜索
    start = 0
    # 依次往后找
    while text.find("vsprintf(",start) != -1:  # 还能找到一个，就进入循环

        start = text.find("vsprintf(", start)  # 函数里面参数的起始地址
        end = text.find(")", start)  # 结束部分

        arrayName = text[start + len("vsprintf("):text.find(",", start)]  # 找数组名字
        length = findArraySize(text, arrayName)  # 找数组长度

        start1 = text.find(",", start)#第一个逗号
        right = text.find(",", start1)
        text = editGets(text, arrayName, length, start, right)  # 将拼接好的发回来
        start += end - start  # 到下一个数组

    return text

def replaceName(text,start,end):
    left = text[0:start]
    middle = "puts"
    right = text[start+len("printf")]
    return text

#循环找到每一个
def loopPrintf(text):
    # 从头开始搜索
    start = 0

    # 依次往后找
    while text.find("printf(", start) != -1:  # 还能找到一个，就进入循环

        start = text.find("printf(", start)  # 函数里面参数的起始地址
        end = text.find(")", start)  # 结束部分
        text = replaceName(text, start, end)
        start += end - start  # 到下一个数组

    return text


#循环找到每一个
def loopOutBound(text):
    # 从头开始搜索
    start = 0
    # 依次往后找

    while text.find("[", start) != -1:  # 还能找到一个，就进入循环
        start = text.find("[", start)  # 函数里面参数的起始地址
        end = text.find("]", start)  # 结束部分
        arrayPOINT = start -1
        aStr = text[arrayPOINT:arrayPOINT+1]
        num=0
        while (aStr>'a' and aStr<'z') or (aStr>'A' and aStr<'Z' ) or aStr=='_':
             num += 1
             arrayPOINT-=1
             aStr = text[arrayPOINT:arrayPOINT + 1]
        arrayPOINT+=1
        arrayName = text[arrayPOINT:arrayPOINT+num]

        number = text[start+1:end]

        if is_number(number):
            length, arrstart = findArraySizeTWO(text, arrayName)  # 找数组长度
            if start + 1 == arrstart:  # 初始化就不管了
                start += end - start
                continue
            else:
                if int(number) >= int(length):
                    text = editOutBound(text, start+1, end, length)  # 将拼接好的发回来

        start += end - start  # 到下一个数组

    return text

#循环找到每一个
def loopOneByte(text):
    # 从头开始搜索
    start = 0
    # 依次往后找

    while text.find("for(", start) != -1:  # 还能找到一个，就进入循环

        start = text.find("for(", start)  # 函数里面参数的起始地址
       # print("start:{}".format(text[start:len(text)]))
        end = text.find(")", start)  # 结束部分
        first, second, str = twoNumber(text, start)#数组里面的循环
        kuo = text.find("{", start)
        right = text.find("]", start)-2;

        #找到数组的起始地址
        arraystart = 0
        for i in range(kuo+1,right):
            if((text[i:i+1]>'a' and text[i:i+1]<'z') or (text[i:i+1]>'A' and text[i:i+1]<'Z' ) or text[i:i+1]=='_'):
                arraystart = i
                break


        arrayName = text[arraystart:text.find("]", start)-2]  # 找数组名字
        length = findArraySize(text, arrayName)  # 找数组长度

        text = editOneByte(text, arrayName, length, arraystart, start, end,first, second, str)  # 将拼接好的发回来
        start += end - start  # 到下一个数组

    return text


def diaoyong(text):
    text = loopFormat(text)
    text = loopGets(text)
    text = loopStrcpy(text)
    text = loopStrcat(text)
    text = loopSprintf(text)
    text = loopVsprintf(text)
    text = loopPrintf(text)
    text = loopOutBound(text)
    text = loopOneByte(text)
    return text

def start():
    filename = input("请您输入文件名字（带后缀名）：")
    try:

        fp = open(filename, "r", encoding='UTF-8')


        print("%s 文件打开成功" % filename)
        text = fp.read()

        text = diaoyong(text)

        outputFileName = "new_"+filename
        f2 = open(outputFileName, "w+")
        f2.write(text)
    except IOError:
        print("文件打开失败,%s 文件不存在" % filename)
        start()
    except UnicodeDecodeError:
        fp = open(filename, "r")
        print("%s 文件打开成功" % filename)
        text = fp.read()

        text = diaoyong(text)

        outputFileName = "new_" + filename
        f2 = open(outputFileName, "w+")
        f2.write(text)

if __name__ == '__main__':
    message=''
    while message != "exit":
        start()
        message = input("输入exit结束程序 或 输入任意键继续\n\n")


