#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

map<int, vector<int>> digitMap;

vector<int> getDigits(int n) {
  if (digitMap.count(n)) {
    return digitMap[n];
  }
  vector<int> digits;

  while (n > 0) {
    digits.push_back(n % 10);
    n /= 10;
  }

  digitMap[n] = digits;

  return digitMap[n];
}

int main() {

  clock_t start = clock();

  ll ans = 0;

  for (int i = 1; i < 2000; i++) {
    bool duplicate = false;
    set<int> used_digits;

    vector<int> i_digits = getDigits(i);
    for (int d : i_digits) {
      if (used_digits.find(d) != used_digits.end()) {
        duplicate = true;
      }
      used_digits.insert(d);
    }
    if (duplicate) {
      continue;
    }
    for (int j = i + 1; j < 2000; j++) {
      // cout << i << "x" << j << "\n";
      int used[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

      for (int d : used_digits) {
        used[d - 1] = 1;
      }

      duplicate = false;
      vector<int> j_digits = getDigits(j);
      for (int d : j_digits) {
        if (used[d - 1]) {
          duplicate = true;
        }
        used[d - 1] = 1;
      }
      int prod = i * j;

      vector<int> prod_digits = getDigits(prod);
      for (int d : prod_digits) {
        if (used[d - 1]) {
          duplicate = true;
        }
        used[d - 1] = 1;
      }
      if (!duplicate) {
        bool using_all = true;
        for (int d : used) {
          if (d == 0) {
            using_all = false;
          }
        }

        if (using_all) {
          ans += prod;
        }
      }
    }
  }

  cout << ans << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
