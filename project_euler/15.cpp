#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// Factorials
vector<vector<ull>> calc_factorials(int n) {

  vector<vector<ull>> factorials(n + 1, vector<ull>(n + 1));
  factorials[0][0] = 1;

  for (ull i = 1; i <= n; i++) {
    factorials[i][0] = factorials[i][i] = 1;
    for (int k = 1; k < i; k++) {
      factorials[i][k] = factorials[i - 1][k - 1] + factorials[i - 1][k];
    }
  }

  return factorials;
}

int main() {

  time_t timer;
  time_t start = time(&timer);

  // I feel like this is the binomial coefficients.
  // 40!/(20!*20!)
  int n = 40;
  vector<vector<ull>> factorials = calc_factorials(n);
  // 4!/2!*2!
  cout << factorials[40][20] << endl;

  time_t end = time(&timer);

  printf("took %.f seconds\n", difftime(end, start));

  return 0;
}
