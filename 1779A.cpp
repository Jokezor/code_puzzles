// Hall Of Fame
//
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solution() {
  int n;

  cin >> n;

  string s;

  cin >> s;

  if (s[0] == s[1] && s[n - 1] == s[n - 2])
    return -1;

  return 0;

  // Every L needs to have an R to the right or an L to the left.
  // Every R needs to have an L to the right or an R to the left.
  //
  // So the algorithm is as follows:
  // For every ind, c in s:
  //
  //  if s.all_L_can_be_seen() and s.all_R_can_be_seen():
  //    return ind
  //
  //  s_copy = s.swap(ind, ind+1)  // no side effect
  //  if s_copy.all_L_can_be_seen() and s_copy.all_R_can_be_seen():
  //    return ind
  //
  // Thus it has a time complexity of O(n * n)= O(n^2)
  // With the limit of 10^5 => 10^10 ops!
  //
  // I believe the BCR (Best conceivable runtime) for this problem is O(N).
}

int main() {
  int t;

  cin >> t;

  while (t > 0) {
    cout << solution() << endl;
    t--;
  }
}
