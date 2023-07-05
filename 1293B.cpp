#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  double n;
  cin >> n;

  double sum = 0;

  while (n) {
    sum += 1 / n;
    n--;
  }

  printf("%.5lf\n", sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
