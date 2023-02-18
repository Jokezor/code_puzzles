#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  // maximum satisfied readers during each year.
  // The minimum a_i should always take a book first
  // Thinking of doing some DSU with connected components
  // Connect pairs with a_i.
  // Start with 1. All members of the set with 1 takes
  // the books first.
  // Then the members with 2 etc.
  // But if we in the end notice books left,
  // Then we need to backtrack and take more books.
  // Maybe that can be done with some binary search?
  //
  // Not necessarily! What if we start with assigning each user a book?
  // Then we can happily continue with the approach I had in mind greedily.
  //
  // So start with making connected components of books
  //
  // The number of satisfied customers starts with the number of customers in
  // the connected set with only 1 book as requirement. The number of books to
  // subtract is (group_cost - 1) * group_size. Where -1 is for the starting
  // value of taking 1 book to each person.
  //
  // Then I just need to build DSU in c++ and it should be done!
  int n, q, ans;

  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  multiset<int> groups;

  for (int i = 0; i < n; i++) {
    groups.insert(a[i]);
  }
  // Actually, could just make a hashmap from cost to an int containing how many
  // are in that group.
  //
  cin >> q;

  for (int i = 0; i < q; q++) {
    int ans = 0;
    // Just check the set here.
    int k;
    cin >> k;

    // Take away 1 book for each reader.
    k -= n;

    for (int j = 1; j <= n; j++) {
      // Need to check how many readers of the group can be fulfilled.
      // Can actually just use a simple vector instead.
      k -= (j - 1) * groups.count(j);

      if (k <= 0) {
        break;
      } else {
        ans += groups.count(j);
      }
    }
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
