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
  // So start with making connected components of books
  //
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
