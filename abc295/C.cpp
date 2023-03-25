#include <bits/stdc++.h>

using namespace std;

void solution() {

  int N;
  cin >> N;

  multiset<long long> A;
  set<long long> pos;

  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    A.insert(k);
    pos.insert(k);
  }

  int ans = 0;
  for (set<long long>::iterator itr = pos.begin(); itr != pos.end(); itr++) {
    ans += A.count(*itr) / 2;
  }

  cout << ans << endl;

  // Test this :>
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
