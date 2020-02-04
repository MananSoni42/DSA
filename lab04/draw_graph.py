import matplotlib.pyplot as plt
import csv

with open('cyclic_1_time') as f:
    reader = csv.reader(f)
    x1 = []
    y1 = []
    for row in reader:
        x1.append(float(row[0]))
        y1.append(float(row[1]))

with open('cyclic_2_time') as f:
    reader = csv.reader(f)
    x2 = []
    y2 = []
    for row in reader:
        x2.append(float(row[0]))
        y2.append(float(row[1]))

    plt.plot(x1,y1,label='algorithm 1')
    plt.plot(x2,y2,label='algorithm 2')
    plt.xlabel('n - size of LL')
    plt.ylabel('t - time take in ms')
    plt.legend()
    plt.savefig('./alg.png')
    plt.show()
