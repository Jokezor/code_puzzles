#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int P;

  cin >> P;

  vector<int> arr;
  int sum = 0;

  for (int i = 2; i * i <= P && P > 1; ++i) {
    while (P % i == 0) {
      P /= i;
      arr.push_back(i);
      sum += i;
    }
  }

  if (P > 1) {
    arr.push_back(P);
    sum += P;
  }

  if (sum < 41) {
    cout << "Case #" << c + 1 << ": -1\n";
    return "Case #" + to_string(c + 1) + ": -1\n";
  }

  for (int i = arr.size() - 1; i >= 0 && sum > 41; --i) {
    int diff = sum - 41;
    if (arr[i] - 1 >= diff) {
      arr[i] -= diff;
      sum -= diff;
      arr.push_back(1);
      break;
    } else {
      sum -= arr[i] - 1;
      arr[i] = 1;
    }
  }

  cout << "Case #" << c + 1 << ": " << arr.size();
  for (int x : arr) {
    cout << " " << x;
  }
  cout << "\n";

  return "";
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
