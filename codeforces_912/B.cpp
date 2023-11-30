#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n, k;

  scanf("%d", &n);

  ll M[n][n];
  ll a[n];

  for (int i = 0; i < n; i++) {
    ll a_new = ((ll)1 << 31) - 1;
    for (int j = 0; j < n; j++) {
      scanf("%lld", &M[i][j]);
      if (i != j) {
        a_new = a_new & M[i][j];
      }
    }
    a[i] = a_new;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (M[i][j] != (a[i] | a[j])) {
          printf("NO\n");
          return;
        }
      }
    }
  }

  printf("YES\n");
  for (int i = 0; i < n - 1; i++) {
    printf("%lld ", min(((ll)1 << 30) - 1, a[i]));
  }
  printf("%lld\n", min(((ll)1 << 30) - 1, a[n - 1]));

  // First I'm thinking we can simply go through
  // All of the entires and get an equation to solve it.
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  scanf("%d", &t);

  while (t--)
    solution();

  return 0;
}
