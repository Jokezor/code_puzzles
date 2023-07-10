#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int a, b, c;

  cin >> a >> b >> c;

  int sum = a + b + c;
  int x = sum / 9;

  if (sum % 9 == 0 && a >= x && b >= x && c >= x) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
