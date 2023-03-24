#include <bits/stdc++.h>

using namespace std;

#define modN 1000000007
#define ll long long

long long H, W, A, B, K, ret, res, fact[300000], inv[300000], factinv[300000];

long long ncr(int n, int r) {
  return (n - r >= 0 && r >= 0)
             ? fact[n] * factinv[r] % modN * factinv[n - r] % modN
             : 0;
}

void calcFactorial() {
  fact[0] = 1;
  for (int i = 1; i < 300000; i++) {
    fact[i] = fact[i - 1] * i % modN;
  }
}

void calcInverseFactorial() {
  inv[1] = 1;
  for (int i = 2; i < 300000; i++) {
    inv[i] = inv[modN % i] * (modN - modN / i) % modN;
  }
  factinv[0] = 1;
  for (int i = 1; i < 300000; i++) {
    factinv[i] = factinv[i - 1] * inv[i] % modN;
  }
}

void solution() {
  // Calculate the factorials
  calcFactorial();

  // Calculate the inverse factorial
  calcInverseFactorial();

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
