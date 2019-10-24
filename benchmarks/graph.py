import matplotlib
import matplotlib.pyplot as plt
import numpy as np

root = 'results/linear_preprocessing/'

N = [150000, 300000, 600000, 1200000, 2400000, 4800000, 7200000, 10800000, 14400000, 19200000, 21600000]

N2 = [150000, 300000, 600000, 1200000, 2400000, 4800000, 9600000, 19200000]

M = [1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000, 2048000, 4096000, 8192000]

K = ['150K', '300K', '600K', '1.2M', '2.4M', '4.8M', '9.6M']

naive = []
preorder = []
table = []
jump = []


for n in N:
    arr = []
    with open(str(root) + 'naive_linear_' + str(n) + '_preprocess.txt') as f:
        for line in f:
            arr.append(float(line))
    naive.append(np.mean(arr))

for n in N:
    arr = []
    with open(str(root) + 'preorder_linear_' + str(n) + '_preprocess.txt') as f:
        for line in f:
            arr.append(float(line))
    preorder.append(np.mean(arr))

# for n in N:
#     arr = []
#     with open(str(root) + 'table_linear_' + str(n) + '_preprocess.txt') as f:
#         for line in f:
#             arr.append(float(line))
#     table.append(np.mean(arr))

for n in N:
    arr = []
    with open(str(root) + 'jump_linear_' + str(n) + '_preprocess.txt') as f:
        for line in f:
            arr.append(float(line))
    jump.append(np.mean(arr))

x = N

fig, ax = plt.subplots()
#ax.tick_params(axis ='x', rotation = 45) 
#ax.tick_params(axis ='y', rotation =-45) 
ax.plot(x, naive, '--bo', label='Naïve')
ax.plot(x, preorder, '--rx', label='PreOrder')
#ax.plot(x, table, '--g*', label='Table')
ax.plot(x, jump, '--cv', label='Jump Pointers')
#ax.plot(x, jump, '--g*')
#ax.plot(x, medias4, '--cv')
#ax.plot(x, nlogn, '--ys')
#ax.plot(x, N, '--cv')
ax.set(xlabel='number of nodes', ylabel='time (seconds)',
        title='Preprocessing Time (Linear Tree)')
plt.ticklabel_format(axis='y', style='sci', scilimits=(0,2))
plt.ticklabel_format(axis='x', style='sci')

ax.legend()

#fig.savefig("graph.png")
plt.show()
