import sys
sys.setrecursionlimit(200000)

def dfs(v):
    global cycle
    color[v] = 'gray'
    for w in graph[v]:
        if color[w] == 'white':
            dfs(w)
        if color[w] == 'gray':
            cycle = True
    color[v] = 'black'

n = int(input())
w = []
for i in range(n):
    w.append(input().split())
graph = {i: set() for i in range(1, n + 1)}

for i in range(n):
    for j in range(n):
        if w[i][j] == '1':
            graph[i + 1].add(j + 1)

color = ['white'] * (n + 1)
cycle = False

for v in range(1, n + 1):
    if color[v] == 'white':
        dfs(v)
        if cycle:
            print(1)
            break
else:
    print(0)