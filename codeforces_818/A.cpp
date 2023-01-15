#include <iostream>

using namespace std;

long gcd(long a, long b, long res) {
  if (a == b) {
    return res * a;
  } else if ((a % 2 == 0) && (b % 2 == 0)) {
    return gcd(a / 2, b / 2, res * 2);
  } else if (a % 2 == 0) {
    return gcd(a / 2, b, res);
  } else if (b % 2 == 0) {
    return gcd(a, b / 2, res);
  } else if (a > b) {
    return gcd(a - b, b, res);
  } else {
    return gcd(a, b - a, res);
  }
}

void solution(void) {
  long result = 0;
  long n, m;

  scanf("%ld", &n);
  scanf("%ld", &m);

  long greatest_common_divisor = gcd(n, m, 1);

  printf("%ld\n", n * m / (greatest_common_divisor * greatest_common_divisor));
}

int main(void) {
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
