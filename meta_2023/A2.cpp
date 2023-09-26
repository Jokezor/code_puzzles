#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  ll A, B, C;

  cin >> A >> B >> C;

  // Check if we have K patties and K+1 buns.
  // Now we should do greedy.
  //
  // We need to find when its worth buying double compared to single.
  //
  // 2-decker needs 1 single and a double
  // 3-decker needs 3 singles or 1 double and a single.
  //
  // N singles means N decker with (N-1) buns wasted
  // N doubles means N+1 decker with no buns left over Only if N odd?
  //
  // Because 4 decker is |x|x|x|x| = 4 patties, 5 buns
  // 2 doubles are one bun short.
  //
  // 5 decker is: |x|x|x|x|x| = 5 patties, 6 buns. means 3 doubles will have one
  // patty left over
  //
  // 6 decker is 6 patties, 7 buns, 3 doubles are one short.
  //
  // 1 decker: 1 patties, 2 buns
  // 2 decker: 2 patties, 3 buns
  // 3 decker: 3 patties, 4 buns
  //
  // Which means buy as many doubles as you can and if possible, add one single.
  //
  // But at what price point?
  //
  // Lets compare price per patties.
  //
  // Using this, we should buy doubles if B < 2*A

  // K = doubles*2 -1
  // We should simply calculate K = min(patties, buns-1)
  ll buns = 0;
  ll patties = 0;
  ll K = 0;

  ll doubles = 0;
  ll singles = 0;

  // if (B < 2 * A) {
  //   doubles = C / B;
  //   C %= B;
  //   singles = C / A;
  //   C = 0;
  // } else {
  //   singles = C / A;
  //   C %= A;
  //   doubles = C / B;
  //   C = 0;
  // }

  // patties += doubles * 2;
  // patties += singles;
  //
  // buns += 2 * doubles;
  // buns += 2 * singles;

  vector<ll> test_singles = {0LL, 1LL, 2LL, C / A};

  for (ll singles : test_singles) {
    ll new_C = C - singles * A;
    if (singles * A >= C) {
      singles = C / A;
      new_C = 0;
    }
    doubles = new_C / B;

    patties = singles + 2 * doubles;
    buns = 2 * (singles + doubles);

    K = max(K, max(0LL, min(patties, max(0LL, buns - 1))));
  }

  string ans = to_string(K);

  string output = ("Case #" + to_string(c + 1) + ": " + ans + "\n");
  // cout << output;
  return output;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ofstream MyFile("output.txt");

  int t;
  cin >> t;

  for (int c = 0; c < t; c++) {
    MyFile << solution(c);
  }
  MyFile.close();
}
