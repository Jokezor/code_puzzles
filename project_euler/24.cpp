#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

#define ll long long

ll factorial(int n) {
  ll res = 1;
  while (n) {
    res *= n;
    n--;
  }
  return res;
}

int get_kth_element(set<int> elements, int k) {

  // Get kth largest
  auto rit = elements.begin();

  for (int i = 1; i < k; i++) {
    ++rit;
  }

  return *rit;
}

int main() {

  clock_t start = clock();

  //
  // 0,1,2,3,4,5,6,7,8,9
  // 10 digits. 10! = 3 628 800 combinations
  // Naive way would be to take each digit and align them.
  // Essentially, checks how many permutations for each position and checks what
  // integer must be leading.
  // O(n*log(n)) where n is the number of digits.
  cout << "Enter the permutation_index: "
       << "\n";
  ll permutation_index;

  cin >> permutation_index;

  vector<int> permutation;
  set<int> choices;

  for (int i = 0; i < 10; i++) {
    choices.insert(i);
  }

  int m = 9;

  while (m > 0) {
    if (permutation_index == 0) {
      for (auto it = choices.rbegin(); it != choices.rend(); ++it) {
        permutation.push_back(*it);
      }
      break;
    }

    double k = (double)permutation_index / (double)factorial(m);
    permutation_index %= factorial(m);

    int next_index = ceil(k);

    int next_integer = get_kth_element(choices, next_index);

    permutation.push_back(next_integer);

    choices.erase(next_integer);
    m--;
  }

  for (auto p : permutation) {
    cout << p;
  }
  cout << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
