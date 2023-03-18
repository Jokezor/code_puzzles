#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll n;
  int x = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s.find('+') != s.npos) {
      x++;
    }
    if (s.find('-') != s.npos) {
      x--;
    }
  }

  cout << x << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
