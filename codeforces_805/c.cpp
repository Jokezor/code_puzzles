#include <bits/stdc++.h>

using namespace std;
 
 
void solve(void) {
    int n, k;
    map<int, int> min_indices;
    map<int, int> max_indices;

    cin >> n >> k;

    vector<int> stations(n);
    for (int j=0; j < n; j++) {
        cin >> stations[j];
    }

    for (int j = 0; j < n; j++) {
        if (min_indices.find(stations[j]) == min_indices.end()) {
            min_indices[stations[j]] = j;
        }
        max_indices[stations[j]] = j;
    }

    while (k--) {
        int start, end;

        cin >> start >> end;

        if (max_indices.find(end) == max_indices.end() || min_indices.find(start) == min_indices.end()) {
            cout << "NO" << endl;
            continue;
        }

        if (max_indices[end] <= min_indices[start]) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }

    }

}
 
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    };
 
    return 0;
 
};
 
