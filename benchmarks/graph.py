import matplotlib
# matplotlib.use("pgf")
# matplotlib.rcParams.update({
#     "pgf.texsystem": "pdflatex",
#     'font.family': 'serif',
#     'text.usetex': True,
#     'pgf.rcfonts': False,
# })
import matplotlib.pyplot as plt
import numpy as np


root = 'results/8ary_query/'

M = [1000, 2500, 5000, 7500, 10000, 12500, 15000, 22500, 30000, 37500, 45000, 52500]
N = [150000, 300000, 600000, 1200000, 2400000, 4800000, 7200000, 10800000, 14400000, 19200000, 21600000]

K = ['150K', '300K', '600K', '1.2M', '2.4M', '4.8M', '9.6M']

naive = []
preorder = []
table = []
jump = []

for n in N:
    arr = []
    with open(str(root)+ 'naive_8ary_' + str(n) + '_query.txt') as f:
        for line in f:
            arr.append(float(line))
    naive.append(np.mean(arr))

for n in N:
    arr = []
    with open(str(root)+ 'preorder_8ary_' + str(n) + '_query.txt') as f:
        for line in f:
            arr.append(float(line))
    preorder.append(np.mean(arr))

for n in N:
    arr = []
    with open(str(root)+ 'table_8ary_' + str(n) + '_query.txt') as f:
        for line in f:
            arr.append(float(line))
    table.append(np.mean(arr))

for n in N:
    arr = []
    with open(str(root)+ 'jump_8ary_' + str(n) + '_query.txt') as f:
        for line in f:
            arr.append(float(line))
    jump.append(np.mean(arr))

x = N

fig, ax = plt.subplots()
#ax.tick_params(axis ='x', rotation = 45) 
#ax.tick_params(axis ='y', rotation =-45) 
ax.plot(x, naive, '--bo', label='Trivial')
ax.plot(x, preorder, '--rx', label='Preordem')
ax.plot(x, table, '--g*', label='Tabela')
ax.plot(x, jump, '--cv', label='Ponteiros')
ax.set(xlabel='quantidade de nós', ylabel='tempo de execução (segundos)')
plt.ticklabel_format(axis='y')
plt.ticklabel_format(axis='x', style='sci')

ax.legend()

#plt.savefig("../modelo-latex/figuras/query_8ary.pdf")
plt.show()
