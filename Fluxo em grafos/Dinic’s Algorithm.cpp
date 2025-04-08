#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Edge {
    int to, rev;
    int cap;
};

const int MAX = 1000;
vector<Edge> adj[MAX];
int level[MAX], ptr[MAX];

void addEdge(int u, int v, int cap) {
    adj[u].push_back({v, (int)adj[v].size(), cap});
    adj[v].push_back({u, (int)adj[u].size() - 1, 0});
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (Edge& e : adj[u]) {
            if (level[e.to] == -1 && e.cap > 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    for (; ptr[u] < adj[u].size(); ++ptr[u]) {
        Edge& e = adj[u][ptr[u]];
        if (level[e.to] == level[u] + 1 && e.cap > 0) {
            int pushed = dfs(e.to, t, min(flow, e.cap));
            if (pushed) {
                e.cap -= pushed;
                adj[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int dinic(int s, int t) {
    int maxFlow = 0;
    while (bfs(s, t)) {
        memset(ptr, 0, sizeof(ptr));
        while (int flow = dfs(s, t, 1e9)) {
            maxFlow += flow;
        }
    }
    return maxFlow;
}
