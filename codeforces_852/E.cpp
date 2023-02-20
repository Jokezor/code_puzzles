#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  // maximum satisfied readers during each year.
  // The minimum a_i should always take a book first
  // Thinking of doing some DSU with connected components
  // the connected set with only 1 book as requirement. The number of books to
  // subtract is (group_cost - 1) * group_size. Where -1 is for the starting
  // value of taking 1 book to each person.
  //
  // Then I just need to build DSU in c++ and it should be done!
  int n, q;

  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> groups(n, 0);

  for (int i = 0; i < n; i++) {
    groups[a[i]]++;
  }
  // Actually, could just make a hashmap from cost to an int containing how many
  // are in that group.
  //
  cin >> q;

  for (int i = 0; i < q; i++) {
    int ans = 0;
    // Just check the set here.
    int k;
    cin >> k;

    // Take away 1 book for each reader.
    // Not from k! but the total books needed to satisfy all.
    k -= n;

    for (int j = 1; j <= n; j++) {
      // Need to check how many readers of the group can be fulfilled.
      int num_satisified = min(groups[j], k / max((j - 1), 1));
      k -= (j - 1) * num_satisified;
      ans += num_satisified;
      cout << j << groups[j] << endl;
      cout << k << endl;

      if (k <= 0) {
        break;
      }
    }
    // cout << ans << endl;
  }
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
