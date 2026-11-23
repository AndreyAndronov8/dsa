n, m = map(int, input().split())

graph = {i: set() for i in range(1, n + 1)}
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].add(y)
    graph[y].add(x)

color = [0] * (n + 1)
possible = True

def dfs(u, c):
    global possible
    color[u] = c
    next_color = 3 - c
    
    for v in graph[u]:
        if color[v] == 0:
            dfs(v, next_color)
        elif color[v] == c:
            possible = False

for i in range(1, n + 1):
    if color[i] == 0:
        dfs(i, 1)

if possible:
    print("YES")
else:
    print("NO")
