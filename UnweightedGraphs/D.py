n, s = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

def dfs(start):
    visited[start] = True
    for v in range(n):
        if matrix[start][v] == 1 and not visited[v]:
            dfs(v)

visited = [False] * n
dfs(s - 1)
print(sum(visited))
