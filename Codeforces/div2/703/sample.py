from random import randint
from itertools import permutations
v = [i for i in range(8)]
vp = list(permutations(v))
with open('testcase.txt', mode='w') as f:
  randv = vp[randint(0, len(vp)-1)]
  f.write(str(randv))
