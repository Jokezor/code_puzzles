#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_map>

using namespace std;

void solution() {
  int result = 0;
  int n;
  string s;
  std::unordered_map<char, int> characters;

  set<char> a;
  set<char> b;

  cin >> n;
  cin >> s;

  for (char c : s) {
    characters[c]++;
    b.insert(c);
  }

  for (int i = 0; i < n; i++) {
    a.insert(s[i]);
    characters[s[i]]--;

    if (characters[s[i]] <= 0 && b.count(s[i])) {
      b.erase(s[i]);
    }

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
