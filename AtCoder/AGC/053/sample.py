from random import randint
N = 5
A = ['<', '>']
with open('testcase.txt', mode='w') as f:
  f.write(str(N)+'\n')
  S = ""
  for i in range(N):
    S += A[randint(0,1)]
  f.write(S+'\n')
