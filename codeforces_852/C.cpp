#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solution() {
  // The integers are unique since they are permutations.
  // What if we maintain a min and max heap, first just check if the min is at
  // either end Then check if max is at either end.
  // If any of them are true, then use 2 pointers to move that index in.
  // For example, if start is biggest or smallest, then increment start by 1 and
  // pop 1 from the heap used.
  // Add an early exit with returning "start end"
  // Otherwise return -1.
  // Do it while start < end

  // Create min and max heap.
  // Store also values in array a.
  // Actually, min and max are known since its permutations of index 1, ..., n.
  // Just start with 1 and n as max and change instead of maintaining separate
  // heap.
  ll n;

  cin >> n;

  vector<ll> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll start = 0;
  ll end = n - 1;
  ll smallest = 1;
  ll largest = n;

  while (start < end) {

    if (a[start] == smallest) {
      start++;
      smallest++;
    } else if (a[start] == largest) {
      start++;
      largest--;
    } else if (a[end] == smallest) {
      end--;
      smallest++;
    } else if (a[end] == largest) {
      end--;
      largest--;
    } else {
      // Found a good subsegment
      cout << start + 1 << " " << end + 1 << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
