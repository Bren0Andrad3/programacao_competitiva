#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000;

vector<int> adj[MAX];
int capacity[MAX][MAX], visited[MAX];

bool dfs(int u, int t, int flow) {
    if (u == t) return true;
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v] && capacity[u][v] > 0) {
            if (dfs(v, t, flow)) {
                capacity[u][v] -= flow;
                capacity[v][u] += flow;
                return true;
            }
        }
    }
    return false;
}

int fordFulkerson(int s, int t, int n) {
    int maxFlow = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        if (!dfs(s, t, 1e9)) break;
        maxFlow += 1;
    }
    return maxFlow;
}
