n = int(input())

graph = {i: set() for i in range(1, n+1)}
for i in range(1, n + 1):
    key = int(input())
    graph[i].add(key)
    graph[key].add(i)

visited = [False] * (n + 1)

def dfs(start):
    visited[start] = True
    for v in graph[start]:
        if not visited[v]:
            dfs(v)

count = 0
for i in range(1, n + 1):
    if not visited[i]:
        count += 1
        dfs(i)

print(count)