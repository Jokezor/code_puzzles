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

  codes.insert(C);
  char init_char = '.';

  string seed_string(200, init_char);

  int i = 199;
  while (codes.size() < N) {
    codes.insert(seed_string);

    if (seed_string[i] == '-') {
      seed_string[i] = '.';
      i -= 1;
    } else {
      seed_string[i] = '-';
      i = 199;
    }
  }

  string ans = "";
  for (string code : codes) {
    ans += code + "\n";
  }

  string output = ("Case #" + to_string(c + 1) + ": " + ans + "\n");
  cout << output << "\n";
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
