#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int ans = 0;
  string s;

  cin >> s;

  // track positions of 'B'
  int n = s.length();

  vector<int> pos;
  vector<int> prefix_sum(n + 1, 0);

  pos.push_back(0);

  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      pos.push_back(i + 1);
    } else if (s[i] == 'A') {
      prefix_sum[i + 1] = 1;
    }
  }

  // calculate prefix_sum
  for (int i = 1; i < n + 1; i++) {
    prefix_sum[i] += prefix_sum[i - 1];
  }

  int m = pos.size();

  vector<int> dp(m, -1);

  // Here we can use dp later for the true/false map.

  auto count_A = [&](auto self, int i, bool right_used) -> int {
    if (i >= m) {
      return 0;
    }
    if (dp[i] != -1 && right_used) {
      return dp[i];
    }

    int s_ind = pos[i];
    int left = prefix_sum[s_ind] - prefix_sum[pos[i - 1]];

    // cout << s_ind << " " << left << "\n";
    int right = 0;

    if (i < m - 1) {
      right = prefix_sum[pos[i + 1]] - prefix_sum[s_ind];
    } else {
      right = prefix_sum[n] - prefix_sum[s_ind];
    }
    // cout << left << ": " << right << "\n";
    if (right_used) {
      dp[i] = max(dp[i], right + self(self, i + 1, true));
    } else {
      dp[i] = max(dp[i], max(left + self(self, i + 1, false),
                             right + self(self, i + 1, true)));
    }
    return dp[i];
  };

  if (m > 1) {
    // cout << prefix_sum[pos[1]] << "\n";
    count_A(count_A, 1, false);
    ans = dp[1];
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
