int binomialRecursive(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialRecursive(n - 1, k - 1) + binomialRecursive(n - 1, k);
}
