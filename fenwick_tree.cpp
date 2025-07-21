// https://github.com/cschiou/competitive-programming/blob/main/fenwick_tree.cpp
// T can be int, long long, etc.
template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    // adjust to 1-index
    FenwickTree(int n) : tree(n + 1) {}

    // input parameter is 0-index for convenience
    void update(int i, T val) {
        ++i;
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    // input parameter is 0-index for convenience
    T prefixSum(int i) const {
        ++i;
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

    // 0-index, 0 <= l <= r <= n - 1
    // [l,r], both ends are included
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return prefixSum(r) - prefixSum(l - 1);
    }
};
