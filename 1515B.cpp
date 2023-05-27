#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isSquaredNumber(int x) {
  int root = sqrt(x);
  return root * root == x;
}

void solution() {
  int n;
  cin >> n;

  bool canUseSmallSquares = n % 2 == 0 && isSquaredNumber(n / 2);
  bool canUseBigSquares = n % 4 == 0 && isSquaredNumber(n / 4);

  if (canUseSmallSquares || canUseBigSquares) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
