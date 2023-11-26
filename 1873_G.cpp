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
  vector<int> prefix_sum(n + 1);

  pos.push_back(0);

  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      pos.push_back(i);
    } else if (s[i] == 'A') {
      prefix_sum[i + 1] = 1;
    }
  }

  // calculate prefix_sum
  for (int i = 1; i < n + 1; i++) {
    prefix_sum[i] += prefix_sum[i - 1];
  }

  int m = pos.size();
  bool right_used = false;

  for (int i = 1; i < m - 1; i++) {
    // So actually, we need to check the best.
    // Either take the right or left.
    int diff_left = prefix_sum[pos[i]] - prefix_sum[pos[i - 1]];
    int diff_right = prefix_sum[pos[i + 1]] - prefix_sum[pos[i]];

    // Actually, the second to last B can not use right if it does not have
    // Any extra to the right
    if (i == m - 2) {
      bool last_b_has_A = prefix_sum[n] - prefix_sum[pos[i + 1]];

      // Can take optimal
      if (last_b_has_A) {
        if (right_used) {
          ans += diff_right;
          right_used = true;
        } else {
          if (diff_right > diff_left) {
            ans += diff_right;
            right_used = true;
          } else {
            ans += diff_left;
            right_used = false;
          }
        }
      } else if (!right_used) {
        ans += diff_left;
        right_used = false;
      } else {
        right_used = false;
      }
    } else if ((diff_right > diff_left || right_used)) {
      ans += diff_right;
      right_used = true;
    } else {
      ans += diff_left;
      right_used = false;
    }
  }

  // Count the number of 'A's after and before.
  if (m > 1) {
    int diff_left = prefix_sum[pos[m - 1]] - prefix_sum[pos[m - 2]];
    int diff_right = prefix_sum[n] - prefix_sum[pos[m - 1]];
    // cout << diff_left << " " << diff_right << " " << right_used << "\n";
    // Cant use left, use right.
    if (right_used) {
      ans += diff_right;
    } else {
      // Free to use optimal.
      ans += max(diff_left, diff_right);
    }
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
