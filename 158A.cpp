#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll n, k;
  cin >> n >> k;

  int kth_score = 0;

  // Look through until k
  int i = 1;
  for (; i <= n; i++) {
    int score;
    cin >> score;
    if (i == k) {
      kth_score = score;
    }
    if (score == 0) {
      break;
    }
    if (score < kth_score) {
      break;
    }
  }

  cout << i - 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
