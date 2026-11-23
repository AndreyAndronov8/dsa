n = int(input())
matr = [list(map(int, input().split())) for i in range(n)]

undirected = True

for i in range(n):
    for j in range(i + 1, n):
        if matr[i][j] != matr[j][i]:
            undirected = False
            break
    if matr[i][i] == 1:
        undirected = False
    if not undirected:
        break

if undirected:
    print("YES")
else:
    print("NO")
