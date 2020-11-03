import math
import numpy

def printlist( str_one, str_two, record ):
    len_str1 = len(str_one)
    len_str2 = len(str_two)
    print(' ',end=' ')
    for i in range(len_str2):
        print(str_two[i],end=' ')
    print('')
    for i in range(1,len_str1+1):
        if i!=0:
            print(str_one[i-1],end=' ')
        else:
            print(' ',end=' ')
        for j in range(1,len_str2+1):
            print(record[i][j], end=' ')
        print('')

def lcs(str_one, str_two, case_sensitive=True):
    len_str1 = len(str_one)
    len_str2 = len(str_two)
  # 定义一个列表来保存最长公共子序列的长度，并初始化
    record = [[0 for i in range(len_str2 + 1)] for j in range(len_str1 + 1)]
    for i in range(len_str1):
        for j in range(len_str2):
            if str_one[i] == str_two[j]:
                record[i + 1][j + 1] = record[i][j] + 1
                #print(str_one[i])
            elif record[i + 1][j] > record[i][j + 1]:
                record[i + 1][j + 1] = record[i + 1][j]
            else:
                record[i + 1][j + 1] = record[i][j + 1]
    printlist( str_one, str_two, record )
    key = []
    i = len_str1
    j = len_str2
    while record[i][j]!=0:
        if record[i][j]==record[i][j-1] and record[i][j]==record[i-1][j]:
            key.append(False)
            i=i-1
        elif record[i][j]==record[i][j-1]+1 and record[i][j]==record[i-1][j]+1 :
            key.append(str_one[i-1])
            i=i-1
            j=j-1
        elif record[i][j]==record[i][j-1]+1 and record[i][j]==record[i-1][j] :
            key.append(False)
            i=i-1
        elif record[i][j]==record[i][j-1] and record[i][j]==record[i-1][j]+1 :
            key.append(False)
            j=j-1
        else:
            print("error!")
            exit()
    if i!=0 or j!=0:
        key.append(False)
    
    #print(key)
    flag = 0
    for num in range(len(key)-1,-1,-1):
        #print(key[num])
        #print (num)
        if key[num]!=False:
            print(key[num],end=' ')
            flag = 0
        else:
            if flag==0:
                print("\\w+",end=' ')
                flag = 1
    print('')

    return record[-1][-1]
 
s1 = input()
s2 = input()
x = lcs(s1, s2)
print ("最大子序列长度：", x)