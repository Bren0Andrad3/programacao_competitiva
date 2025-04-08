#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(const string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0;

    for (int i = 1; i < m; ) {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len > 0)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }

    return lps;
}

vector<int> kmpSearch(const string& txt, const string& pat) {
    vector<int> result;
    vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;
    int n = txt.size(), m = pat.size();

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i]) {
            j = (j ? lps[j - 1] : 0);
        }
    }

    return result;
}
