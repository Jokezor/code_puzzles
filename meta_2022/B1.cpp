#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int R, C;
  bool seen_trees = false;
  string canvas;

  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      char c;
      cin >> c;
      canvas += c;
      if (c == '^') {
        seen_trees = true;
      }
    }
    canvas += "\n";
  }

  string ans = "Possible";

  if (seen_trees && (R == 1 || C == 1)) {
    ans = "Impossible";
  }

  string output = ("Case #" + to_string(c + 1) + ": " + ans + "\n");

  if (seen_trees && ans == "Possible") {
    for (int i = 0; i < canvas.length(); i++) {
      if (canvas[i] == '.') {
        canvas[i] = '^';
      }
    }
  }

  if (ans == "Possible")
    output += canvas;

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
