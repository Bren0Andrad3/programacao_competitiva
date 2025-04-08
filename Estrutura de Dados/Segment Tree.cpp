#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

struct Node {
    int sum, minVal, maxVal;
};

class SegmentTree {
    vector<Node> tree;
    vector<int> data;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        data = arr;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {data[l], data[l], data[l]};
        } else {
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            merge(node);
        }
    }

    void update(int index, int value, int node, int l, int r) {
        if (l == r) {
            tree[node] = {value, value, value};
        } else {
            int mid = (l + r) / 2;
            if (index <= mid)
                update(index, value, 2 * node, l, mid);
            else
                update(index, value, 2 * node + 1, mid + 1, r);
            merge(node);
        }
    }

    void update(int index, int value) {
        update(index, value, 1, 0, n - 1);
    }

    Node query(int ql, int qr, int node, int l, int r) {
        if (qr < l || r < ql)
            return {0, INT_MAX, INT_MIN};

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;
        Node left = query(ql, qr, 2 * node, l, mid);
        Node right = query(ql, qr, 2 * node + 1, mid + 1, r);
        return {
            left.sum + right.sum,
            min(left.minVal, right.minVal),
            max(left.maxVal, right.maxVal)
        };
    }

    Node query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }

private:
    void merge(int node) {
        // soma
        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
        // mínimo
        tree[node].minVal = min(tree[2 * node].minVal, tree[2 * node + 1].minVal);
        // máximo
        tree[node].maxVal = max(tree[2 * node].maxVal, tree[2 * node + 1].maxVal);
    }
};
