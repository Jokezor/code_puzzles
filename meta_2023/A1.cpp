#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int S, D, K;

  cin >> S >> D >> K;

  string ans = "NO";

  // Check if we have K patties and K+1 buns.
  int buns = 0;
  int patties = 0;

  buns += 2 * S;
  buns += 2 * D;

  patties += S;
  patties += 2 * D;

  if (patties >= K && buns >= (K + 1)) {
    ans = "YES";
  }

  string output = ("Case #" + to_string(c + 1) + ": " + ans + "\n");
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
