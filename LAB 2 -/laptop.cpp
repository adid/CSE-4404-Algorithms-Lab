#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> laptops;

    for (int i = 0; i < n; i++) {
        int price, quality;
        cin >> price >> quality;
        laptops.push_back({price, quality});
    }

    sort(laptops.begin(), laptops.end());

    for (int i = 1; i < n; i++) {
        if (laptops[i - 1].second > laptops[i].second) {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }

    cout << "Poor Alex" << endl;

    return 0;
}
