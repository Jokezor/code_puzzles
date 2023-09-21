#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int N;
  string C;

  cin >> N;
  cin >> C;

  set<string> codes;

  // How to check if a conflict could be made when adding a new code?
  // One way could be to traverse it using a graph?
  // For example:
  // Given -, we check ..., no way to get -
  // Then check .-, then we need to have one . prior, which we do not
  // Then we check ..-, we would need 2 dots which we do not.
  // We are essentially looking for nodes which lead up to the existing
  // If so, we check until we find no path
  char init_char = '.';

  if (C[0] == '.') {
    init_char = '-';
  }

  string seed_string(10, init_char);

  int i = 9;
  while (codes.size() < N - 1) {
    if (C.find(seed_string) == string::npos) {
      codes.insert(seed_string);
    }

    if (init_char == '.') {
      if (seed_string[i] == '-') {
        seed_string[i] = '.';
        i -= 1;
      } else {
        seed_string[i] = '-';
        i = 9;
      }
    } else {
      if (seed_string[i] == '.') {
        seed_string[i] = '-';
        i -= 1;
      } else {
        seed_string[i] = '.';
        i = 9;
      }
    }
  }

  string ans = "";
  for (string code : codes) {
    ans += code + "\n";
  }

  string output = ("Case #" + to_string(c + 1) + ":\n" + ans);
  cout << output;
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
