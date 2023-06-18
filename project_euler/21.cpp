#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main() {

  clock_t start = clock();

  // simple is O(N*N/2)
  // Simply take n, divide by all numbers less than N.
  // Save all numbers that are integers and take the sum.
  // Once another number n is found with the same sum as an existing,
  // add the sum of both numbers to the result.
  // Feels like we can do it better later.
  //
  // Code up this and then improve the solution.

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
