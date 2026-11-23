n, m = map(int, input().split())

graph = {i: set() for i in range(1, n + 1)}
for i in range(m):
    x, y = map(int, input().split())
    graph[x].add(y)

perm = list(map(int, input().split()))

visited = [False] * (n + 1)
ans = "YES"

for i in perm:
    visited[i] = True
    for v in graph[i]:
        if visited[v]:
            ans = "NO"
            break
    if ans == "NO":
        break

print(ans)