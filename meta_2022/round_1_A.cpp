#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

int get_starting_point(vector<int> A, int N, int start) {
  int p = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == start) {
      p = i;
    }
  }
  return p;
}

string solution(int c) {
  // Essentially, what they are asking if by we can make array A equal array B
  // Using K turns. Each turn can move 1, ... N-1 cards from top to bottom.
  //
  // Possible to make them the same if the overall order is the same.
  // That is, 5 follows 3 which follows 4 etc.
  //
  // It is always possible if we find the starting point of the chain for A and
  // B. find B[0] in A. 2 is in position 2. Thus p = 2. That means we need to
  // move x*N + 2 cards after K turns.
  //
  // First check if they have same chain.
  //
  // if !common_chain(A, B):
  //  ans = "NO"
  //  break;
  //
  // p = find(A, B[0])
  //
  // if K < N:
  //  ans = "YES"
  // else if (K-p) % N == 0:
  //  ans = "YES"
  // else:
  //  ans = "NO"

  // K = x*N + p => possible if (K - p) % N == 0
  int N, K;

  cin >> N >> K;

  vector<int> A(N);
  vector<int> B(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  string ans = "YES";
  int p = get_starting_point(A, N, B[0]);
  // How to check if they have a common chain?
  // One way is to simply start in B[0], walk in A until we find B[0], then we
  // set p. Then, we increment i, and check that A[(p + i) % N] == B[i] If any
  // don't match, then return False.

  for (int i = 0; i < N; i++) {
    if (A[(p + i) % N] != B[i]) {
      ans = "NO";
    }
  }

  if (ans == "YES") {
    if ((p > 0 && (K % (N - 1)) % 2 != 0) || (K % 2 == 1 && p == 0)) {
      ans = "NO";
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
