#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, x = 0;
  string s;

  cin >> n;
  cin >> s;

  // All critics should taste the same number of white wines
  // All critics should taste at least n wines
  // No critics should taste the exactly same wines
  //
  // Find x such that the valid intervals are met and
  // each critic taste exactly x white wines

  // How can we prove that an interval exist?
  // Well it does not say that all wines needs to be tasted.
  // Also x does not need to be minimized or maximized.
  // I would think to start greedily, assign one pointer to the left
  // and one to the right.
  // First we need at least n wines.
  // Then the next critic takes n+1 wines until the next wine is W.
  // If it is, then we need to increment left until left < right contains
  // the same number of W.
  // If we have smaller than n now, then increment right until n and left <
  // right contains the same number of W. If right > 2n -1, then this max_W was
  // set to a wrong value.
  //
  // This solution would iterate through i < count_W
  // Then for each critique n, it would go 2*n -1
  // since we use a two pointer solution.
  //
  // O((2*n -1)*(2*n -1)) = O(n^2)
  //
  // Still O(n^2) since all wines might be white.
  // Implement this and see how it goes.
  int W_count = 0;
  vector<ll> prefix_sum(2 * n);
  prefix_sum[0] = 0;

  // Get the number of whites
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (s[i - 1] == 'W') {
      W_count++;
      prefix_sum[i - 1]++;
    }
    prefix_sum[i] += prefix_sum[i - 1];
  }

  // Go through all assortments, trying with 0 whites first.
  for (int w = 0; w < W_count; w++) {
    int left = 1;
    int right = n;
    int num_critics = 0;
    while (left <= right && right < 2 * n) {
      // First check so we have n in length
      if (right - left < n) {
        right++;
      }

      // The critic takes the wines between left and right until i W seen.
      // Feels like this can be stored and searched in a range query
      // If we store the indices of how many whites seen as prefix_sum
      // Then the number here is white_wines[right] - white_wines[left]
      ll whites_found = prefix_sum[right] - prefix_sum[left];

      if (whites_found == w) {
        num_critics++;
        right++;
        cout << "[" << left << ", " << right << "]" << endl;
      } else if (whites_found < w) {
        right++;
      } else if (whites_found > w) {
        left++;
      }

      cout << w << " " << num_critics << endl;
    }
    // Found a matching arrangement
    if (num_critics == n) {
      x = w;
      break;
    }
  }

  cout << x << endl;
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
