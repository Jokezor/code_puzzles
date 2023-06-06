#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {

  //
  // Idea:
  // Generate multiples of 60 and then sort both the number and multiple to
  // compare them.
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string y;
    cin >> y;

    string y_reversed[y.length()];

    for (int j = 0; j < y.length(); j++) {
      y_reversed[j] = &y[j];
    }

    sort(y.begin(), y.end());
    y[0] = 'R';
    cout << y << endl;
    cout << *y_reversed << endl;

    // sort(y.begin(), y.end());
  }
}

int32_t main() {
  int t;
  t = 1;
  while (t--)
    solution();
}
