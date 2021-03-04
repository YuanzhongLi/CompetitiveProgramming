
for a in range(100):
  for b in range(100):
    for c in range(100):
      if a^b^c == a + b + c and (a & b != 0 or a & c != 0 or b & c !=0):
        print("a: {0}, b: {1}, c: {2}".format(a, b, c))
        print((bin(a)[2:])[::-1])
        print((bin(b)[2:])[::-1])
        print((bin(c)[2:])[::-1])
        print('-------')
