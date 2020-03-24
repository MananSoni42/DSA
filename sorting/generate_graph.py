import numpy as np
import matplotlib.pyplot as plt
import csv
import sys
from pprint import pprint

try:
    fname = sys.argv[1]
except IndexError:
    print("Usage: python3 generate_graph.py <file.csv>")
    exit(1)


data = dict()
with open(fname,'r') as f:
    reader = csv.reader(f)
    for row in reader:
        try:
            data[row[0]].append([int(row[1]),float(row[2])])
        except KeyError:
            data[row[0]] = [[int(row[1]),float(row[2])]]

for k,v in data.items():
    data[k] = np.array(v)
    plt.plot(data[k][:,0], data[k][:,1], label=k)

plt.title(sys.argv[1])
plt.ylabel("T - time in ms")
plt.xlabel("N - size of array")
plt.legend(loc="upper left")
plt.show()
