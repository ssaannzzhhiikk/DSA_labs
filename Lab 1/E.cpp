#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> boris, nursik;
    for (int i = 0; i < 5; ++i) {
        int x; if (!(cin >> x)) return 0;
        boris.push_back(x);
    }
    for (int i = 0; i < 5; ++i) {
        int x; cin >> x;
        nursik.push_back(x);
    }

    const int MAX_MOVES = 1000000;
    int moves = 0;

    while (!boris.empty() && !nursik.empty() && moves < MAX_MOVES) {
        ++moves;
        int a = boris.front(); boris.pop_front();
        int b = nursik.front(); nursik.pop_front();

        bool boris_wins;
        if (a == 0 && b == 9) boris_wins = true;
        else if (a == 9 && b == 0) boris_wins = false;
        else boris_wins = (a > b);

        if (boris_wins) {
            boris.push_back(a);
            boris.push_back(b);
        } else {
            nursik.push_back(a);
            nursik.push_back(b);
        }
    }

    if (nursik.empty()) {
        cout << "Boris " << moves << '\n';
    } else if (boris.empty()) {
        cout << "Nursik " << moves << '\n';
    } else {
        cout << "Draw\n";
    }

}
