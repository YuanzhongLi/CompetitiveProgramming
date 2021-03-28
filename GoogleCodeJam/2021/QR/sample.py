from random import randint
from itertools import permutations
A = [1, 2, 3, 4]
T = 1
for i in range(len(A)):
  T *= (i+1)
with open('testcase.txt', mode='w') as f:
  f.write(str(T)+'\n')
  for a in permutations(A):
    f.write(str(len(A))+'\n')
    f.write(' '.join([str(i) for i in a]) + '\n')
