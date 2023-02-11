#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void solution() {
  long long n, m, d, l, buf;

  cin >> n >> m >> d >> l;

  // Holds all the CD players and ranges
  map<long long, pair<int, int>> M;

  // Holds the holes
  vector<long long> N(n);

  // Add the first hole
  N.push_back(0);

  for (int i = 1; i < n + 1; i++) {
    cin >> N[i];
  }

  for (int i = 0; i < m; i++) {
    // Add the range that can be accessed by the CD player.
    cin >> buf;
    M[buf] = make_pair(buf - l, buf + l);
  }

  // Check how many holes are being covered by the CD players.
  auto disturbed_holes = [&]() {
    // Go through all CD players
    // Either use distance to check how many elements in M[ind].first
    // And subtract with M[ind].second
    long long tot = 0;

    for (auto const &[key, val] : M) {
      std::vector<long long>::iterator low =
          lower_bound(N.begin(), N.end(), val.first);
      std::vector<long long>::iterator high =
          lower_bound(N.begin(), N.end(), val.second);
      tot += distance(low, high);
    }
    cout << tot << "\n";
  };

  // First output how many are covered.
  disturbed_holes();

  for (int i = 0; i < d; i++) {
    // perform queries
    // Take the first element of the
    disturbed_holes();
  }
  // I'm thinking some kind of prefix sum
  // But having trouble how to compute it efficiently
}

int main() {
  solution();

  return 0;
}
