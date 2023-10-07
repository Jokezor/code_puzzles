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

bool is_valid_grouping(const vector<ll> &elves, int num_toys,
                       double max_distance) {
  int groups = 1;
  ll last_elf = elves[0];

  for (int i = 1; i < elves.size(); ++i) {
    if ((double)(elves[i] - last_elf) > max_distance) {
      last_elf = elves[i];
      ++groups;
    }
  }

  return groups <= num_toys;
}

string solution(int c) {
  int N;
  cin >> N;

  vector<ll> elves(N);

  for (int i = 0; i < N; i++) {
    cin >> elves[i];
  }

  sort(elves.begin(), elves.end());

  double low = 0;
  double high = elves.back() - elves.front();
  double ans = high;

  while (low <= high) {
    double mid = (low + high) / 2.0;

    if (is_valid_grouping(
            elves, 2,
            mid)) { // Assuming 2 toys, you might want to generalize this
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
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
