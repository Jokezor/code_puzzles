#include <bits/stdc++.h>

#define ll long long

using namespace std;

int solution() {
  int n, l;

  cin >> n >> l;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int big_diff = 0;

  for (int i = 1; i < n; i++) {
    big_diff = max(big_diff, a[i] - a[i - 1]);
  }

  int max_ends = max(a[0], l - a[n - 1]);
  printf("%.9f\n", max(double(max_ends), double(big_diff) / double(2)));

  return 0;
}

int main() {

  int t = 1;
  while (t--)
    solution();
}
