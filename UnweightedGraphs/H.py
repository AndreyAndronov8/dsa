from collections import deque

INF = 10**9

n = int(input())
graph = {i: set() for i in range(1, n + 1)}

for i in range(1, n + 1):
    row = [0] + list(map(int, input().split()))
    for j in range(i + 1, n + 1):
        if row[j] == 1:
            graph[i].add(j)
            graph[j].add(i)

s, end = map(int, input().split())

n = len(graph)

dist = [INF] * (n + 1)
dist[s] = 0
visited = [False] * (n + 1)
parent = [-1] * (n + 1)

q = deque([s])
visited[s] = True

while q:
    node = q.popleft()
    for neighbor in graph[node]:
        if not visited[neighbor]:
            q.append(neighbor)
            visited[neighbor] = True
            dist[neighbor] = min(dist[neighbor], dist[node] + 1)
            parent[neighbor] = node

if dist[end] == INF:
    print(-1)
elif dist[end] == 0:
    print(0)
else:
    print(dist[end])

    path = []
    curr = end
    while curr != -1:
        path.append(curr)
        curr = parent[curr]
    path.reverse()
    print(*path)
