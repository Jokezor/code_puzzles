#include <bits/stdc++.h>

using namespace std;

#define modN 1000000007
#define ll long long

long long H, W, A, B, K, ret, res, fact[300000], inv[300000], factinv[300000];

long long ncr(int n, int r) {
  return (n - r >= 0 && r >= 0)
             ? 1LL * fact[n] * factinv[r] % modN * factinv[n - r] % modN
             : 0;
}

void solution() {
  fact[0] = 1;
  for (int i = 1; i < 300000; i++)
    fact[i] = 1LL * fact[i - 1] * i % modN;
  inv[1] = 1;
  for (int i = 2; i < 300000; i++)
    inv[i] = 1LL * inv[modN % i] * (modN - modN / i) % modN;
  factinv[0] = 1;
  for (int i = 1; i < 300000; i++)
    factinv[i] = 1LL * factinv[i - 1] * inv[i] % modN;
  cin >> H >> W >> A >> B;
  long long sum = 0;
  for (int i = 0; i < H - A; i++) {
    sum += ncr(B + i - 1, B - 1) * ncr((W - B - 1) + (H - i - 1), W - B - 1);
    sum %= modN;
  }

  cout << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}

/*
#include <bits/stdc++.h>

#define ll long long

using namespace std;

#define modN 1000000007;

long long H, W, A, B, K, ret, res, fact[300000], inv[300000], factinv[300000];
long long ncr(int n, int r) { return (n - r >= 0 && r >= 0) ? 1LL * fact[n] *
factinv[r] % modN * factinv[n - r] % modN : 0; }

void solution() {
  // What should we do?
  ll H, W, A, B;

  cin >> H >> W >> A >> B;

  auto factorial = [&](int m) {
    ll res = 1;
    for (int i = 1; i <= m; i++) {
      res = (res % modN) * (i % modN) % modN;
    }
    return res % modN;
  };

  ll all_combinations = (((factorial(H + W - 2) % modN)) /
                         ((factorial(H - 1) * factorial(W - 1)) % modN));
  ll combinations_removed =
      (((factorial(A + B - 2) % modN)) /
       (((factorial(A - 1) % modN) * (factorial(B - 1) % modN)) % modN));

  cout << all_combinations << " " << combinations_removed << "\n";
  cout << all_combinations - combinations_removed << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
*/
