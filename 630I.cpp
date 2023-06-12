#include <bits/stdc++.h>

#define ll long long

using namespace std;

long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

void solution() {
  // There is 4 different cars to choose from.
  // 2*n -2 slots.
  int n;
  cin >> n;

  assert(n > 2);

  // Placing in front
  // (2*n - 2) - (n+1) = n-3
  ll front = 4 * 3 * binpow(4, n - 3);

  // Placing in back
  // (2*n - 2) - (n+1) = n-3
  ll back = 4 * 3 * binpow(4, n - 3);

  // Placing in the middle
  // 3 choices for first front element
  // 3 choices for first back element
  // Rest slots:
  //  (2*n - 2) - (n+2) = n-4
  // Free choice of these, so 4^(n-4)
  // (n - 3) is for the number of ways we can fit the middle elements
  // This is actually not understood at this time. Why (n-3)?
  ll middle = (n - 3) * 4 * 3 * 3 * binpow(4, n - 4);

  cout << front + back + middle << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
