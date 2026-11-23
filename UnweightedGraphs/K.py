from sys import setrecursionlimit
setrecursionlimit(5000000)

def dfs(start):
    global timer
    timer += 1
    tin[start] = timer
    for v in graph[start]:
        if tin[v] == 0:
            dfs(v)
    timer += 1
    tout[start] = timer

n = int(input())
parents = list(map(int, input().split()))

graph = {i: set() for i in range(1, n + 1)}
root = 0
for i in range(1, n + 1):
    p = parents[i - 1]
    if p == 0:
        root = i
    else:
        graph[p].add(i)

tin = [0] * (n + 1)
tout = [0] * (n + 1)
timer = 0

dfs(root)

m = int(input())
for i in range(m):
    a, b = map(int, input().split())
    if tin[a] < tin[b] and tout[b] < tout[a]:
        print(1)
    else:
        print(0)