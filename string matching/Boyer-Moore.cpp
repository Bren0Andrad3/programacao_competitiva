#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> boyerMoore(const string& txt, const string& pat) {
    int m = pat.length();
    int n = txt.length();
    vector<int> result;

    if (m > n) return result;

    vector<int> badChar(256, -1);
    for (int i = 0; i < m; i++)
        badChar[(int)pat[i]] = i;

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {
            result.push_back(s);
            s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
        } else {
            s += max(1, j - badChar[txt[s + j]]);
        }
    }

    return result;
}
