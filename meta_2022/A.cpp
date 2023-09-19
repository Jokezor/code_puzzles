#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int N, K;

  cin >> N >> K;

  vector<int> S(100);
  string ans = "YES";

  for (int i = 0; i < N; i++) {
    int s;
    cin >> s;

    S[s - 1]++;

    if (S[s - 1] > 2) {
      ans = "NO";
    }
  }

  if (N > 2 * K) {
    ans = "NO";
  }

  cout << "Case #" << c + 1 << ": " << ans << "\n";

  // Essentially, if N > 2 * K then it a  NO
  // Or if the count of any is S_i > 2.

  return ("Case #" + to_string(c + 1) + ": " + ans + "\n");
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
