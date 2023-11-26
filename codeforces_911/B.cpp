#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int a, b, c;

  cin >> a >> b >> c;

  int a_odd = a % 2;
  int b_odd = b % 2;
  int c_odd = c % 2;

  cout << (int)(b_odd == c_odd) << " ";
  cout << (int)(a_odd == c_odd) << " ";
  cout << (int)(a_odd == b_odd) << "\n";
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
