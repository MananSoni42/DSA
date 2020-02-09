import numpy as np
import csv
import matplotlib.pyplot as plt

x = []
t = []
s = []
with open('insert_out.txt') as f:
    reader = csv.reader(f)
    next(reader)
    for row in reader:
        x.append(float(row[0]))
        t.append(float(row[1]))
        s.append(float(row[2]))

plt.scatter(x,t,c='b', label='actual time taken')
x_ = np.arange(min(x),max(x),1000)
y_ = np.power(x_,1.4)
print(x_,y_)
plt.plot(x_,y_*0.001,c='g',label='O(n^2)')
plt.xlabel('n - size of array')
plt.ylabel('time')
plt.savefig('fig.png')
plt.show()
