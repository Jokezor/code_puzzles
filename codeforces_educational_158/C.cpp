#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n;
  scanf("%d", &n);

  int mx = 0, mn = (int)1e9 + 7;
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    mn = min(mn, x);
    mx = max(mx, x);
  }
  int k = 0;
  while (mx - mn >= (1 << k)) {
    k++;
  }
  printf("%d\n", k);
  if (k > n)
    return;
  if (k == 0)
    return;
  x = mn & ((1 << k) - 1);
  x = (1 << k) - x;
  printf("%d", x);
  for (int i = 1; i < k; i++) {
    printf(" 0");
  }
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);

  while (t--)
    solution();

  return 0;
}
