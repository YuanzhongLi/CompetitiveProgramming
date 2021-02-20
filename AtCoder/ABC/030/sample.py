from random import randint
randq = randint(10000, 100000)
randd = randint(1, randq-1)
with open('testcase.txt', mode='w') as f:
  f.write(str(randq)+' '+str(randd))

print('sub: ', randq-randd)
