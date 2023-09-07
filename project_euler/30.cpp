#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

int fifth_power_sum(int n) {
  int sum = 0;

  while (n) {
    sum += pow(n % 10, 5);
    n /= 10;
  }
  return sum;
}

int main() {

  clock_t start = clock();

  // Digit fifth powers.
  // 1634 = 1^4 + 6^4 + 3^4 + 4^4
  //
  // We have an even number.
  // Thus we need to have an even number of odd numbers.
  //
  // The upper bound for 4th power is 10000.
  //
  // Which means we can simply count up to 10^5.
  //

  int sum_fifth_powers = 0;
  int max_n = 1000000;

  for (int n = 2; n < max_n; n++) {
    if (n == fifth_power_sum(n)) {
      sum_fifth_powers += n;
      cout << n << ": " << sum_fifth_powers << "\n";
    }
  }

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
