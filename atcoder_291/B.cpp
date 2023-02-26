#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int N;

  cin >> N;
  vector<int> X(5 * N);

  for (int i = 0; i < 5 * N; i++) {
    cin >> X[i];
  }

  sort(X.begin(), X.end());

  int tot = 0;

  for (int i = N; i < 4 * N; i++) {
    tot += X[i];
  }

  cout << std::setprecision(10) << (float(tot) / float(3 * N)) << endl;
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
