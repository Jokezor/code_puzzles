#include <bits/stdc++.h>

using namespace std;

void solution() {
  int n, q;
  cin >> n;
  cin >> q;

  vector<int> a(n);
  set<int> indices;

  // Add all elements to a.
  // Only add the index of the elements greater than 9 to indices, others won't
  // be affected by summing their digits and will just be wasted work.
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 9) {
      indices.insert(i);
    }
  }

  auto sum_digits = [&](int m) {
    int sum = 0;
    while (m) {
      sum += m % 10;
      m /= 10;
    }
    return sum;
  };

  // Should just find a way to get the digits from each number.
  // Then it is just to go through the numbers to perform the queries.
  for (int i = 0; i < q; i++) {
    int type, left, right;
    // if first is 1, then get 2 more.
    // if first is 2, then get 1 more.
    cin >> type;

    if (type == 1) {
      cin >> left;
      cin >> right;

      left--;
      right--;

      // This is O(N), making the full algorithm O(N^2). Need to improve later.
      // People recommend sqrt decomposition. This is new to me.
      // But I need some way of storing the queries first.
      // Let's look on solutions and really understand it.
      while (!indices.empty()) {
        // Find the lower bound, meaning the pointer to its value?
        // Still unclear on this.
        auto index_iterator = indices.lower_bound(left);

        // Either we have no index to update or we have passed the right side of
        // what we should consider. Terminate this query.
        if (index_iterator == indices.end() || *index_iterator > right) {
          break;
        }
        // This is O(9), negligble
        a[*index_iterator] = sum_digits(a[*index_iterator]);

        // Increment by 1 before removing the pointer from the set
        left = *index_iterator + 1;

        // Check if we need to keep the index or not in the set.
        if (a[*index_iterator] <= 9) {
          indices.erase(index_iterator);
        }
      }
    } else {
      cin >> left;
      cout << a[left - 1] << endl;
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solution();
}
