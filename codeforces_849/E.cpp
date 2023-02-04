#include <bits/stdc++.h>

using namespace std;

void solution() {
  long long n;

  cin >> n;

  vector<long long> a;
  long long buf;
  long long num_negative_numbers = 0;
  long long smallest = 1000000001;
  long long result = 0;

  // If even number of negative numbers, the sum is just the sum of the absolute
  // values If odd number of negative numbers, the sum is the sum of all values
  // - the smallest value in a.
  for (long long i = 0; i < n; i++) {
    cin >> buf;
    a.push_back(buf);
    if (buf <= 0) {
      num_negative_numbers++;
      result += -1 * buf;

      if (-1 * buf < smallest) {
        smallest = -1 * buf;
      }
    } else {
      result += buf;
      if (buf < smallest) {
        smallest = buf;
      }
    }
  }

  if (num_negative_numbers % 2 == 0) {
    cout << result << endl;
  } else {
    // -2* smallest since I include it in the absolute sum. -1 time is just
    // summing without it.
    cout << result - 2 * smallest << endl;
  }
}

int main() {

  int t;

  cin >> t;

  while (t) {
    solution();
    t--;
  }
}
