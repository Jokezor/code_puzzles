#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    int d = s[i] - 'a';
    if (d >= 26 || d < 0) {
      cout << i + 1 << endl;
      break;
    }
  }
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
