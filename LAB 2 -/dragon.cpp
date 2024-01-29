#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragons;

    for (int i = 0; i < n; i++) {
        int strength, bonus;
        cin >> strength >> bonus;
        dragons.push_back({strength, bonus});
    }

    sort(dragons.begin(), dragons.end());

    for (int i = 0; i < n; i++) {
        if (dragons[i].first >= s) {
            cout << "NO" << endl;
            return 0;
        }

        s += dragons[i].second;
    }

    cout << "YES" << endl;

    return 0;
}
