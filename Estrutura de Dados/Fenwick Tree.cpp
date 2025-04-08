#include <vector>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    // Adiciona 'val' ao índice 'i'
    void update(int i, int val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }

    // Soma de 0 até i
    int query(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    // Soma no intervalo [l, r]
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
