import sys
sys.setrecursionlimit(200000)

n, m = map(int, input().split())
graph = {i: set() for i in range(1, n + 1)}

for i in range(m):
    x, y = map(int, input().split())
    graph[x].add(y)
    graph[y].add(x)

visited = set()
components = []

def dfs(v):
    visited.add(v)
    current_comp.append(v)
    for neighbor in graph[v]:
        if neighbor not in visited:
            dfs(neighbor)

for v in graph:
    if v not in visited:
        current_comp = []
        dfs(v)
        components.append(current_comp)

print(len(components))
for comp in components:
    print(len(comp))
    print(*comp)
