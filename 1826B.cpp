#include <bits/stdc++.h>

#define ll long long

using namespace std;

int commonGcd(int *a, int n) {
  // Use two pointers
  int start = 0;
  int end = n - 1;
  int common_gcd = 0;

  while (start <= end) {
    common_gcd = gcd(common_gcd, abs(a[end] - a[start]));
    start++;
    end--;
  }

  return common_gcd;
}

void solution() {
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << commonGcd(a, n) << endl;
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
