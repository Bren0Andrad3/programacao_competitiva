#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1000;

vector<int> adj[MAX];
int capacity[MAX][MAX], parent[MAX];

int bfs(int s, int t) {
    memset(parent, -1, sizeof(parent));
    queue<pair<int, int>> q;
    q.push({s, 1e9});
    parent[s] = s;

    while (!q.empty()) {
        int u = q.front().first, flow = q.front().second;
        q.pop();

        for (int v : adj[u]) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if (v == t) return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int edmondsKarp(int s, int t, int n) {
    int maxFlow = 0, flow;
    while ((flow = bfs(s, t))) {
        maxFlow += flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= flow;
            capacity[cur][prev] += flow;
            cur = prev;
        }
    }
    return maxFlow;
}
