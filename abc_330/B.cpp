#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int N, L, R;

  cin >> N >> L >> R;

  vector<int> A(N);
  vector<int> X(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    // Check if A[i] <= L
    if (A[i] >= L && A[i] <= R) {
      X[i] = A[i];
    } else {
      // binary search for the optimum X?
    }
  }

  int left = L;
  int right = R;

  while (left < right) {
  }

  for (int i = 0; i < N - 1; i++) {
    cout << X[i] << " ";
  }
  cout << X[N - 1] << "\n";
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
