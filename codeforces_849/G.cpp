#include <bits/stdc++.h>

using namespace std;

void solution() {

  // Feels greedy and should minimize the repeated steps.
  // Should be the most optimal.
  // There is only one dimension. Taking the closest means the same steps are
  // repeated. Does it even matter? Yes, because they cost different! So we
  // should go and count how much it costs for each step + the cost of the
  // teleporter. Take them into a priority queue. The cost is index+1 +
  // a[index]. Pop and subtract from c while the cost can be covered.
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
