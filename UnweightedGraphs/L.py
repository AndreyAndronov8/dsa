n, m = map(int, input().split())

graph = {i: set() for i in range(1, n + 1)}
for i in range(m):
    x, y = map(int, input().split())
    graph[x].add(y)
    graph[y].add(x)

visited = [False] * (n + 1)

def dfs(start):
    visited[start] = True
    for v in graph[start]:
        if not visited[v]:
            print(start, v)
            dfs(v)

dfs(1)
