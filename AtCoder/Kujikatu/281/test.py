N = 2
K = 8
su = {"num": 0 }
mp = {}
for i in range(1, K+1): mp[i] = 0
from math import gcd
def dfs(A, N, K):
  if len(A) == N:
    g = A[0]
    for i in range(N):
      g = gcd(g, A[i])
    su["num"] += g
    mp[g] += 1
    return
  for i in range(1, K+1):
    A.append(i)
    dfs(A, N, K)
    A.pop()
  return

dfs([], N, K)
print(su["num"])
print(mp)
