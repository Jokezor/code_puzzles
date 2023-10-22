#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int P;
  int sum = 0;

  cin >> P;

  string ans = "-1";

  vector<int> arr;

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
