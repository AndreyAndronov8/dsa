n, m = map(int, input().split())
matr = [[0] * n for _ in range(n)]

for i in range(m):
    x, y = map(int, input().split())
    matr[x - 1][y - 1] = 1
    matr[y - 1][x - 1] = 1

complete = True
for i in matr:
    if i.count(0) > 1:
        complete = False
        break

if complete:
    print("YES")
else:
    print("NO")
