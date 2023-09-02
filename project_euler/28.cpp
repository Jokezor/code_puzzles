#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

int main() {

  clock_t start = clock();

  // To get to 13, we need to pass 3 + 3 + 4 = 10 positions before returning.
  // To get to 17 we need to pass 2 + 2 + 2*4 = 12 positions
  // To get to 21 we need to pass 1 + 1 + 3 * 4 = 14 positions
  // To get to 25 we need to pass 0 + 0 + 4*4 = 16 positions
  //
  // To get to 31 we need to pass 3*3 + 3 + 1*6 = 18 positions
  // To get to 37 we need to pass 2*3 + 2 + 2*6 = 20 positions
  // To get to 43 we need to pass 1*3 + 1 + 3*6 = 22 positions
  // To get to 49 we need to pass 0*3 + 0 + 4*6 = 24 positions
  //
  // To get to 57 we need to pass 3*5 + 3 + 8 = 25 positions
  // To get to 65 we need to pass 2*5 + 7 + 8 = 26 positions
  // To get to 73 we need to pass
  //
  //
  // {1, 3, 5, 7, 9, 13,17,21,25, 31, 37, 43, 49, 57, 65, 73, 81}
  // Step size: 2, 4, 6, 8
  //
  // 5x5 is numbers up to 25
  // 1001x1001 is 10^6 + 2001
  //
  // Step size seems to be n-1
  // So then we can take D[i] = D[i-1] + 2*ceil(i/4)
  //
  vector<int> D;

  D.push_back(1);
  int n = 1001;

  int N = 1 + 4 * floor((float)n / 2.0);

  for (int i = 1; i < N; i++) {
    int multiplier = 2 * ceil((float)i / 4.0);
    D.push_back(D[i - 1] + multiplier);
  }

  int res = 0;
  for (int d : D) {
    cout << d << "\n";
    res += d;
  }

  cout << res << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
