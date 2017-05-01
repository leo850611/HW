# coding=utf-8
import numpy as np
from matplotlib import pyplot as plt

#連線
def link(a,b):
    linex = [a[0],b[0]]
    liney = [a[1],b[1]]
    plt.plot(linex, liney, marker='^')

#求斜率
def getslope(a,b):
    if(a[0] - b[0] )==0:
        return 9999999
    else:
        m = (a[1] - b[1])/(a[0] - b[0])
        return m

#產生的點個數
pointnum = 30

allpoint = []
for i in range(pointnum):
    x = np.random.randint(1000)
    y = np.random.randint(1000)
    t = [x,y]
    allpoint.append(t)
    plt.plot(x, y, "o") 
allpoint.sort()
print(allpoint)

#上半凸包
num = 0
for t in range (len(allpoint)):
    m = 9999999
    for i in range (len(allpoint)):
        if(i > num) and getslope(allpoint[num], allpoint[i]) <= m:
            m = getslope(allpoint[num], allpoint[i])
            no = i
    link(allpoint[num], allpoint[no])
    num = no

#下半凸包
num = 0  
for t in range (len(allpoint)):
    m = -99999
    for i in range (len(allpoint)):
        if(i > num) and getslope(allpoint[num], allpoint[i]) >= m:
            m = getslope(allpoint[num], allpoint[i])
            no = i
    link(allpoint[num], allpoint[no])
    num = no

plt.show()