#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Compare {
public:
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second < b.second;
  }
};

void solution() {
  multiset<pair<int, int>, Compare> segments;
  int q;
  int disjoint = 0;
  int l, r;
  char operation;

  cin >> q;

  while (q--) {
    cin >> operation >> l >> r;

    pair<int, int> query = {l, r};

    if (operation == '+') {
      segments.insert(query);
    } else if (operation == '-') {
      segments.erase(query);
    }

    // Find first segment starting after the query segment
    auto it_upper = segments.upper_bound({query.second, INT_MAX});

    // Find last segment ending before the query segment
    auto it_lower = segments.lower_bound({query.first, INT_MIN});

    int count = 0;
    // Check for overlaps and increment count
    for (auto it = it_lower; it != it_upper; ++it) {
      if (it->second >= query.first && it->first <= query.second) {
        if (it->second != query.second && it->first != query.second) {
          count++;
        }
      }
    }
    if (count == 0) {
      if (operation == '+' && segments.size() > 1) {
        disjoint++;
      } else if (operation == '-') {
        disjoint--;
      }
    }
    if (disjoint) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
