from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))

B = deque()
rev = False

for x in A:
    if not rev:
        B.append(x)
    else:
        B.appendleft(x)
    rev = not rev

if rev:
    B.reverse()

print(*B)
