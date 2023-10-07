#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

bool findCombination(int P, int target, vector<int> &ans, int sum) {
  if (sum == target && P == 1)
    return true;
  if (sum >= target || P == 1)
    return false;

  for (int i = 2; i <= P; ++i) {
    if (P % i == 0) {
      ans.push_back(i);
      if (findCombination(P / i, target, ans, sum + i))
        return true;
      ans.pop_back();
    }
  }

  return false;
}

string solution(int c) {
  int P;
  int sum = 0;

  cin >> P;

  string ans = "-1";

  vector<int> arr;
  if (findCombination(P, 41, arr, 0)) {
    ans = to_string(arr.size());
  }

  if (sum == 41) {
    for (int i = 0; i < arr.size(); i++) {
      ans += " " + to_string(arr[i]);
    }
  }
  string output = ("Case #" + to_string(c + 1) + ": " + ans + "\n");
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
