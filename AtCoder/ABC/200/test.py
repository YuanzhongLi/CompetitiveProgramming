import random

A = []
for i in range(1,200):
  A.append(i)

B = random.sample(A, 8)

print(B)
s = set([])

for i in range(1<<8):
  tmp = 0
  for j in range(8):
    if ((i>>j)&1) == 1:
      tmp += B[j]
  s.add(tmp%200)

s = list(s)
s.sort()
print(s)
print(len(s))
