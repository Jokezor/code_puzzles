#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <tuple>
#include <vector>

using namespace std;

void solution() {
  int n;

  cin >> n;

  vector<int> a;
  vector<int> dp;
  int buf;
  int tot = 0;

  for (int i = 0; i < n; i++) {
    cin >> buf;
    tot += buf;
    a.push_back(buf);
  }
  dp.push_back(tot);

  for (int i = 1; i < n; i++) {
    dp[i] = max(dp[i - 1], dp[i - 1] - 2 * (a[i] + a[i - 1]));
  }

  cout << dp[n - 1] << endl;
}

int main() {

  int t;

  cin >> t;

  while (t) {
    solution();
    t--;
  }
}
