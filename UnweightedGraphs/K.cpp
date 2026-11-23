#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> tin, tout;
int timer = 0;

void dfs(int start) {
    tin[start] = ++timer;
    for (int v : graph[start]) {
        if (tin[v] == 0) {
            dfs(v);
        }
    }
    tout[start] = ++timer;
}

int main() {
    int n;
    cin >> n;

    graph.resize(n + 1);
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if (p == 0) {
            root = i;
        } else {
            graph[p].push_back(i);
        }
    }

    dfs(root);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (tin[a] < tin[b] && tout[b] < tout[a]) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}
