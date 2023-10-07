#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string remove_trailing_zeros(const std::string &str) {
  string result = str;

  auto dotPos = result.find('.');
  if (dotPos != string::npos) {
    // Remove trailing zeros
    result.erase(result.find_last_not_of('0') + 1, string::npos);

    // Remove trailing dot, if any
    if (result.back() == '.') {
      result.pop_back();
    }
  }

  return result;
}

string solution(int c) {
  int N;

  cin >> N;

  vector<ll> elves(N);

  for (int i = 0; i < N; i++) {
    cin >> elves[i];
  }

  sort(elves.begin(), elves.end());

  double ans;

  // Handle the special case of taking the optimal triplet
  if (N == 5) {
    ans = max(
        (elves[N - 1] + elves[N - 2]) / 2.0L - (elves[2] + elves[0]) / 2.0L,
        (elves[N - 1] + elves[N - 3]) / 2.0L - (elves[0] + elves[1]) / 2.0L);
  } else {
    double first_toy = (elves[0] + elves[1]) / 2.0L;
    double second_toy = (elves[N - 1] + elves[N - 2]) / 2.0L;
    ans = second_toy - first_toy;
  }

  std::ostringstream ss;
  int precision = 6;
  ss << std::fixed << std::setprecision(precision) << ans;

  std::string formatted = remove_trailing_zeros(ss.str());

  string output = ("Case #" + to_string(c + 1) + ": " + formatted + "\n");
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
