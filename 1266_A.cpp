#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  string y;
  cin >> y;

  int num_zeroes = 0;
  int digit_sum = 0;
  int num_evens = 0;
  for (int i = 0; i < y.length(); i++) {
    digit_sum += (y[i] - '0');
    if (y[i] == '0') {
      num_zeroes++;
    }
    if ((y[i] - '0') % 2 == 0) {
      num_evens++;
    }
  }

  if (num_evens >= 2 && digit_sum % 3 == 0 && num_zeroes > 0) {
    cout << "red"
         << "\n";
  } else {
    cout << "cyan"
         << "\n";
  }
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
