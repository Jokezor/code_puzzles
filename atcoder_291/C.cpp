#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  map<pair<int, int>, int> visited;
  bool found = false;

  pair<int, int> pos = {0, 0};
  visited[pos] = 1;

  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      pos.first++;
    } else if (S[i] == 'L') {
      pos.first--;
    } else if (S[i] == 'U') {
      pos.second++;
    } else if (S[i] == 'D') {
      pos.second--;
    }
    visited[pos]++;
  }

  for (auto const &[key, val] : visited) {
    if (val > 1) {
      found = true;
    }
  }

  if (found) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
