#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  ll local_max, local_min;
  cin >> local_max >> local_min;

  ll tmp_max = local_max;
  ll tmp_min = local_min;

  cout << 2 * (local_max - local_min) << endl;

  while (tmp_max >= local_min + 1) {
    cout << tmp_max << " ";
    tmp_max -= 1;
  }

  while (tmp_min <= local_max - 2) {
    cout << tmp_min << " ";
    tmp_min += 1;
  }

  cout << tmp_min << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
