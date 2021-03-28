from random import randint
from itertools import permutations
N = 4
T = N*(N+1)//2
with open('testcase.txt', mode='w') as f:
  f.write(str(T)+'\n')
  for i in range(1, T+1):
    f.write(str(N)+' '+str(i)+'\n')
