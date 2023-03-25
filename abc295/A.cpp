#include <bits/stdc++.h>

using namespace std;

void solution() {

  int N;
  string W;
  bool found = false;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> W;
    if (W == "and" || W == "not" || W == "that" || W == "the" || W == "you") {
      found = true;
      break;
    }
  }

  if (found) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  // Test this :>
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
