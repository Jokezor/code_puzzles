#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int N;

  cin >> N;

  vector<ll> A(2 * N - 1);

  for (int i = 0; i < 2 * N - 1; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  // This works if the new apple is not the biggest in the sequence
  // How to check for that?
  // Upper bound is 2 * A[2*N -2]
  // Lower bound is A[2*N - 2]
  ll ans = 0;

  ll sum = A[0] + A[2 * N - 2];
  int j = 2;

  for (int i = 1; i < N; i++) {
    // cout << A[i] << ": " << A[A.size() - j] << "\n";
    if (A[i] + A[A.size() - j] != sum) {
      if (ans == 0) {
        ans = sum - A[i];
        j--;
      } else {
        ans = -1;
      }
    }
    if (ans == -1) {
      break;
    }
    j++;
  }

  // Check for inserting a bigger number
  if (ans == -1) {
    sum = A[2 * N - 2] + A[1];
    ans = sum - A[0];

    for (int i = 1; i < N; i++) {
      if (A[i] + A[A.size() - i] != sum) {
        ans = -1;
        break;
      }
    }
  } else if (ans == 0) {
    ans = sum - A[N - 1];
  }

  // 2 4 10 999999994 1000000000

  // Essentially group up pairs of apples in the list
  // What grouping could be done?
  //
  // Brute force would be:
  // Take first apple, sum it with one apple, check
  // the next etc until all apples have been taken except one.
  //
  // Then sum the first apple with another apple etc.
  // The time complexity is N^2
  //
  // Directly if the next index cant find such an apple,
  // break the inner loop.
  //
  //
  // We could instead use binary search.
  // Sort all apples, pair the smallest with the biggest.

  string output = ("Case #" + to_string(c + 1) + ": " + to_string(ans) + "\n");
  // cout << output;
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
