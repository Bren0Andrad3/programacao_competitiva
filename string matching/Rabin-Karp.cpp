#include <vector>
#include <string>
using namespace std;

vector<int> rabinKarp(const string& txt, const string& pat, int prime = 101) {
    vector<int> result;
    int m = pat.size(), n = txt.size();
    int d = 256; // tamanho do alfabeto
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    int p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % prime;
        t = (d * t + txt[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            if (txt.substr(i, m) == pat)
                result.push_back(i);
        }

        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % prime;
            if (t < 0) t += prime;
        }
    }

    return result;
}
