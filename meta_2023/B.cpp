#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int R, C, A, B;

  cin >> R >> C >> A >> B;

  // Bob wins if we get to row R
  // Alice wins if we get to column C.
  //
  // So simply, if we have (R - x) <= A, then Alice can win in the following
  // turns.
  //
  // If (C - y) <= B, then Bob can.
  //
  // So, do we reach (R - x) <= A first or (C - y) <= B?
  //
  // But does it matter?
  // Is it not who reaches their edge first who loose anyway?
  //
  // Bob changes
  //
  // So, if R <= C, then Bob wins
  //
  // But what if they are really far away?
  // Still the other person should loose.

  string ans = "YES";

  if (R <= C) {
    ans = "NO";
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
