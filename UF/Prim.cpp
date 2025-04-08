#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pii; // peso, vértice

int prim(int n, vector<vector<pii>>& adj, int start = 0) {
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, start);
    int totalWeight = 0;

    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int weight = top.first;
        int u = top.second;
                if (visited[u]) continue;
        visited[u] = true;
        totalWeight += weight;

        for (const pii& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v])
                pq.emplace(w, v);
        }
        
    }

    return totalWeight;
}
