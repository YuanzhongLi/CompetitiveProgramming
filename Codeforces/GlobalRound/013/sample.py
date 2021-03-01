from random import randint
ma = 1000000000
N = 5000
V = [ma for _ in range(N)]
for i in range(N):
  if (i&1) == 0:
    V[i] = 4000
with open('testcase.txt', mode='w') as f:
  f.write(str(1)+'\n')
  f.write(str(N)+'\n')
  f.write(' '.join(str(num) for num in V) + '\n')
