#include <bits/stdc++.h>

#define ll long long

using namespace std;

int solution() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // What does it mean to differ in evenness?
  // Seems that there should be at least one number that divides each number.
  // among the set of numbers in a.
  //
  // Will n^2 work with just just go through each number and check how many
  // times each number is divided by that number.
  //
  int num_even = 0;
  int num_odd = 0;
  int first_even = 0;
  int first_odd = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      num_even++;
      first_even = i + 1;
    }
    if (a[i] % 2 != 0) {
      num_odd++;
      first_odd = i + 1;
    }
  }
  if (num_even == 1) {
    cout << first_even << endl;
  } else if (num_odd == 1) {
    cout << first_odd << endl;
  }

  return 0;
}

int main() {

  int t = 1;
  while (t--)
    solution();
}
