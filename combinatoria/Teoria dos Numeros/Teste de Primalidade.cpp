// Força Bruta
bool isPrimeBrute(int n) {
    if (n < 2) return false;
    if (n == 2) return true;

    for (int i = 2; i < n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Otimizado

#include <cmath>

bool isPrimeOptimized(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

