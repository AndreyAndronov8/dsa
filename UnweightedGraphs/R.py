import sys
sys.setrecursionlimit(20000)

m, n = map(int, input().split())
paper = [list(input()) for _ in range(m)]
count = 0

def dfs(row, col):
    if not (row < 0 or row >= m or col < 0 or col >= n or paper[row][col] != '#'):
        paper[row][col] = '.'
        dfs(row + 1, col)
        dfs(row - 1, col)
        dfs(row, col + 1)
        dfs(row, col - 1)

for i in range(m):
    for j in range(n):
        if paper[i][j] == '#':
            count += 1
            dfs(i, j)

print(count)
