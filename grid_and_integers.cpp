#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solution() {
  int R, C, N;

  cin >> R >> C >> N;

  vector<vector<int>> a(R);
  fill(a.begin(), a.end(), vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    int r, c;
    cin >> r >> c;
    cin >> a[r - 1][c - 1];
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << a[i][j] << "\n";
    }
  }
}

int main() {

  int t = 1;

  while (t--) {
    solution();
  }

  return 0;
}
