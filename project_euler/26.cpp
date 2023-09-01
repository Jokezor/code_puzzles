#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

vector<int> get_repeating_fractions(int n) {
  // https://math.stackexchange.com/questions/2845984/how-to-calculate-a-repeating-decimal-for-any-fraction
  // Works by taking the floor of division to see how many multiples fit.
  // Then we simply take the remainder and since the next position is /10
  // We multiply our remainder by 10 and take out the next fraction.
  set<int> seen_remainders;
  map<int, int> remainder_to_index;
  vector<int> fractions;

  int d = 1;
  int index = 0;

  while (seen_remainders.find(d) == seen_remainders.end()) {
    int fraction = floor((d * 10) / n);
    fractions.push_back(fraction);
    seen_remainders.insert(d);
    remainder_to_index[d] = index;

    d = (d * 10) % n;
    index++;
  }

  return vector<int>(fractions.begin() + remainder_to_index[d],
                     fractions.end());
}

int main() {

  clock_t start = clock();

  int max_cycle = 0;
  int max_d;

  for (int d = 2; d < 1000; d++) {
    vector<int> repeating_fractions = get_repeating_fractions(d);
    for (int f : repeating_fractions) {
      cout << f;
    }
    cout << "\n";

    int cycle_length = (int)repeating_fractions.size();
    if (cycle_length > max_cycle) {
      max_cycle = cycle_length;
      max_d = d;
    }
  }

  cout << max_d << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
