#include <bits/stdc++.h>

using namespace std;

void solution() {
  int result = 0;
  int n;
  string s;
  std::unordered_map<char, int> characters;

  // Generally the flow is to have two sets, one starts empty, the other with
  // all values. Then just count what the optimal split should be for the size
  // of both sets to maxiumum.
  set<char> a;
  set<char> b;

  cin >> n;
  cin >> s;

  // Count the number of each character in the string
  for (char c : s) {
    characters[c]++;
    b.insert(c);
  }

  // Start with set b having all characters.
  // Each step, we remove one and add to a.
  for (int i = 0; i < n; i++) {
    a.insert(s[i]);
    characters[s[i]]--;

    // If the count of that specific char reaches zero, then remove it.
    if (characters[s[i]] == 0) {
      b.erase(s[i]);
    }

    // Take the maximum of existing or if the new sets split is greater, than
    // this is a better split.
    result = std::max(result, (int)(a).size() + (int)(b).size());
  }

  cout << result << endl;
}

int main() {

  int t;

  cin >> t;

  while (t) {
    solution();
    t--;
  }
}
