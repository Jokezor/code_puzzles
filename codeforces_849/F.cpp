#include <bits/stdc++.h>

using namespace std;

void solution() {
  int n, q, buf;
  cin >> n;
  cin >> q;

  vector<int> a;
  for (int i = 0; i < n; i++) {
    cin >> buf;
    a.push_back(buf);
  }

  auto sum_digits = [&](int m) {
    int sum = 0;
    while (m >= 10) {
      sum += m % 10;
      m = m / 10;
    }
    sum += m % 10;
    return sum;
  };

  // Should just find a way to get the digits from each number.
  // Then it is just to go through the numbers to perform the queries.
  for (int i = 0; i < q; i++) {
    int type, left, right;
    // if first is 1, then get 2 more.
    // if first is 2, then get 1 more.
    cin >> type;

    if (type == 1) {
      cin >> left;
      cin >> right;

      // This is O(N), making the full algorithm O(N^2). Need to improve later.
      for (int j = left - 1; j < right; j++) {
        a[j] = sum_digits(a[j]);
      }
    } else {
      cin >> left;
      cout << a[left - 1] << endl;
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solution();
}
