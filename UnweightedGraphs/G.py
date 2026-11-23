def dfs(v):
    visited.add(v)
    for neighbor in graph[v]:
        if neighbor not in visited:
            dfs(neighbor)

n, m = map(int, input().split())

if m != n - 1:
    print("NO")
else:
    graph = {i: set() for i in range(1, n + 1)}
    for i in range(m):
        x, y = map(int, input().split())
        graph[x].add(y)
        graph[y].add(x)

    visited = set()
    dfs(1)

    if len(visited) == n:
        print("YES")
    else:
        print("NO")
