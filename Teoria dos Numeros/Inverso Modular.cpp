int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcdExtended(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int modInverse(int a, int n) {
    int x, y;
    int g = gcdExtended(a, n, x, y);
    if (g != 1) {
        // Inverso modular não existe
        return -1;
    } else {
        // Pode ser negativo, ajusta para estar no intervalo [0, n-1]
        return (x % n + n) % n;
    }
}
