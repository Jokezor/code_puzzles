#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll MAX = (ll)(1e9 + 7);

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int lcm(int x, int y) { return (x / gcd(x, y)) * y; }

void solution() {
  string s;
  cin >> s;

  // Maintain a set of indices in the string
  set<int> s_indices;

  stack<int> uppercase;
  stack<int> lowercase;

  vector<int> ans(s.length(), -1);

  // Then we pop the stacks and reverse.

  // Count positions of B and b.
  //
  // Removes the rightmost big or small
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'B') {
      if (!uppercase.empty()) {
        uppercase.pop();
      }
    } else if (s[i] == 'b') {
      if (!lowercase.empty()) {
        lowercase.pop();
      }
    } else if (isupper(s[i])) {
      uppercase.push(i);
    } else {
      lowercase.push(i);
    }
  }

  while (!uppercase.empty()) {
    ans[uppercase.top()] = uppercase.top();
    uppercase.pop();
  }
  while (!lowercase.empty()) {
    ans[lowercase.top()] = lowercase.top();
    lowercase.pop();
  }

  string string_ans = "";

  for (int i = 0; i < s.length(); i++) {
    if (ans[i] >= 0) {
      string_ans += s[ans[i]];
    }
  }
  cout << string_ans << "\n";
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
