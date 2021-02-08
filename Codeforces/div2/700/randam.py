from random import randint
n = 10
A = []
for i in range(n):
  A.append(randint(1, 3))

with open('testcast.txt', mode='w') as f:
  f.write(str(n)+'\n')
  f.write(' '.join([str(i) for i in A]))
