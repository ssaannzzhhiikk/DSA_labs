#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        string line;
        getline(cin, line);

        vector<string> words;
        stringstream ss(line);
        string word;

        while (ss >> word)
            words.push_back(word);

        stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        for (string &w : words)
            cout << w << " ";
        cout << "\n";
    }

    return 0;
}
