#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solution() {
  int N, M;

  cin >> N >> M;

  vector<vector<int>> G(N);
  vector<int> deg(N);

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    deg[y]++;
  }

  vector<int> ans(N);
  queue<int> q;
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    if (q.size() != 1) {
      cout << "No" << endl;
      return 0;
    }
    int v = q.front();
    q.pop();
    ans[v] = ++cnt;
    for (auto vv : G[v]) {
      if (!--deg[vv]) {
        q.push(vv);
      }
    }
  }

  cout << "Yes" << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[N - 1] << endl;

  return 0;
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
