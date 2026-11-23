n = int(input())
matr = [list(map(int, input().split())) for i in range(n)]

istok = []
stok = []

for i in range(n):
    if sum(matr[j][i] for j in range(n)) == 0:
        istok.append(i + 1)
    if sum(matr[i]) == 0:
        stok.append(i + 1)

print(len(istok))
for i in istok:
    print(i)

print(len(stok))
for i in stok:
    print(i)
