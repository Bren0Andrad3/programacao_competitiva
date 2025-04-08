#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]); 
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[u] > rank[v]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int mstWeight = 0;

    for (const auto& edge : edges) {
        if (!uf.sameSet(edge.u, edge.v)) {
            uf.unite(edge.u, edge.v);
            mstWeight += edge.weight;
        }
    }

    return mstWeight;
}
