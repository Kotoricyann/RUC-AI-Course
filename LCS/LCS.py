import math
import numpy

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
    for i in range(0,len_str1+1):
        for j in range(0,len_str2+1):
            print(record[i][j], end=' ')
        print('')
    key = []
    i = len_str1
    j = len_str2
    while record[i][j]!=0:
        if record[i][j]==record[i][j-1] and record[i][j]==record[i-1][j]:
            key.append(0)
            i=i-1
        elif record[i][j]==record[i][j-1]+1 and record[i][j]==record[i-1][j]+1 :
            key.append(record[i][j])
            i=i-1
            j=j-1
        elif record[i][j]==record[i][j-1]+1 and record[i][j]==record[i-1][j] :
            key.append(0)
            i=i-1
        elif record[i][j]==record[i][j-1] and record[i][j]==record[i-1][j]+1 :
            key.append(0)
            j=j-1
        else:
            print("error!")
            exit()
    
    print(key)
        

    return record[-1][-1]
 
s1 = input()
s2 = input()
x = lcs(s1, s2)
print(x)