#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> applyPermutation(vector<int> sequence, vector<int> permutation) {
  vector<int> newSequence(sequence.size());
  for (int i = 0; i < sequence.size(); i++) {
    newSequence[i] = sequence[permutation[i] - 1];
  }
  return newSequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, ll b) {
  while (b > 0) {
    if (b & 1) {
      sequence = applyPermutation(sequence, permutation);
    }
    permutation = applyPermutation(permutation, permutation);
    b >>= 1;
  }
  return sequence;
}

void solution() {
  ll n, k;

  cin >> n >> k;

  vector<int> sequence;
  vector<int> permutation;

  for (int i = 0; i < n; i++) {
    sequence.push_back(i + 1);
  }

  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2) {
      permutation.push_back(i + 1);
    }
  }

  for (int i = 0; i < n; i++) {
    if (((i + 1) % 2) == 0) {
      permutation.push_back(i + 1);
    }
  }

  assert(sequence.size() == permutation.size());

  vector<int> riffle = permute(sequence, permutation, k);

  for (int i = 0; i < n - 1; i++) {
    cout << riffle[i] << " ";
  }
  cout << riffle[n - 1] << "\n";

  // [f(1), f(2), f(3), f(4)]
  // [f(1), f(3), f(2), f(4)]
  // [f(1), f(2), f(3), f(4)]
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
