#include <bits/stdc++.h>

using namespace std;

void solution() {
  // Now this turns into a dynamic programming problem.
  int c, n, buf, result = 0;
  cin >> n;
  cin >> c;

  vector<int> a;
  priority_queue<int, vector<int>, greater<int>> minimum_queue;

  for (int i = 0; i < n; i++) {
    cin >> buf;
    minimum_queue.push(buf + i + 1);
  }

  while (c > 0 && !minimum_queue.empty()) {
    int cost = minimum_queue.top();
    minimum_queue.pop();

    c -= cost;
    if (c >= 0) {
      result++;
    }
  }
  cout << result << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solution();
}
