#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(string pat, string txt) {
    int m = pat.size(), n = txt.size();
    vector<int> lps = computeLPS(pat);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string txt, pat;
    cout << "Enter text string: ";
    getline(cin, txt);
    cout << "Enter pattern: ";
    getline(cin, pat);

    KMPSearch(pat, txt);
    return 0;
}
