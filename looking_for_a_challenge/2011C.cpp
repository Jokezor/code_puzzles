#include <bits/stdc++.h>

using namespace std;

int will_it_stop(long long n) {

  // n xor (n-1)
  // 1101 xor 1100 = 0001
  // 0001 & 1101 = 0001
  // 0001 != 1101
  //
  // Power of two means there's only one leading 1 with rest zeroes.
  // 1000 xor 0111 = 1111
  // 1111 & 1000 = 1000
  // 1000 == 1000
  //
  // 10 xor 01: 11
  //
  // Of course! If its a power of two, then n-1 is only 1s but not
  // in the highest power.
  // xor takes all as 1s if its a power of two.
  // The & operation is done to take only the leading bit and
  // will only be equal if its a power of two.
  //
  if (((n xor (n - 1)) & n) == n) {
    cout << "TAK"
         << "\n";
  } else {
    cout << "NIE"
         << "\n";
  }
  return 0;
}

int main() {
  long long n;
  cin >> n;

  will_it_stop(n);

  return 0;
}
