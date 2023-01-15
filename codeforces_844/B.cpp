#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void solution(void) {
  int result = 0;
  int n;
  priority_queue<int> pq;

  scanf("%d", &n);
  int a[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pq.push(-1 * a[i]);
  }

  // Heapify the array a.
  // Then just loop through the elements and add.
  //
  int i = 0;

  while (i <= n) {
    int top = (-1) * pq.top();
    if (pq.empty()) {
      top = -50000;
    } else {
      pq.pop();
    }
    if (i < top) {
      // Check here if there are more that will be sad
      // Essentially, pop if there are any matching.
      // Then we need to increase i by more than 1
      // And if it is not the same, then push it back.
      i++;
      while (pq.empty() == false && ((-1) * pq.top()) == top) {
        pq.pop();
      }
      result++;
    } else {
      i++;
    }
  }

  printf("%d\n", result);
}

int main(void) {
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
