# because the lines are infinite long, if the (x1,y1) and (x2,y2) are seperated
# by a line, we have to cross it, i.e., the result must be increased by 1.
# so the answer is the amount of lines which lie between the source and dest.

from sys import stdin

def check(x1, y1, x2, y2, a, b, c):
  return (a * x1 + b * y1 + c) * (a * x2 + b * y2 + c) < 0

if __name__ == '__main__':
  x1, y1 = map(int, stdin.readline().split())
  x2, y2 = map(int, stdin.readline().split())
  n = int(stdin.readline())
  ans = 0
  for i in xrange(n):
    a, b, c = map(int, stdin.readline().split())
    if check(x1, y1, x2, y2, a, b, c):
      ans += 1
  print(ans)


