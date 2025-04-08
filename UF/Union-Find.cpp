#include <iostream>
#include <vector>      // <- ESSENCIAL para usar vector
#include <algorithm>   // Para sort
#include <queue>       // Para priority_queue
#include <functional>  // Para greater<>
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
            parent[u] = find(parent[u]); // path compression
        return parent[u];
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
