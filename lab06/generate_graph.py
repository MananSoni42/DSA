import matplotlib.pyplot as plt
import csv
import sys
import os

fname = sys.argv[1]

x = []
y = []
with open(fname,"r") as f:
    reader = csv.reader(f)
    next(reader)
    for row in reader:
        x.append(float(row[0]))
        y.append(float(row[1]))

plt.plot(x,y)
plt.xlabel('length - n')
plt.ylabel('time - t')
plt.savefig(f'{os.path.splitext(fname)[0]}.png')
plt.show()
