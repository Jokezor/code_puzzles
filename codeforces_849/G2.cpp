#include <bits/stdc++.h>

using namespace std;

class Compare {
public:
  bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first > b.first;
  }
};

void solution() {
  // Now this turns into a dynamic programming problem.
  // OR it might be enough to consider the optimal of 2D.
  // Either we take the smallest from the front, or the smallest from the back.
  // But once you use a teleporter, you can't use it again.
  // So, the cost of the teleporters in the end are more complex.
  // For example, the cost of the rightmost teleporter is the cost of the
  // leftmost teleporter + 1 + the cost of the teleporter. Then the cost of the
  // second most right teleporter is either the cost of the rightmost teleport +
  // the cost of the teleporter +2 or the cost of any other teleporter + 2 + the
  // cost of the teleporter
  //
  // So it feels like DP. Need to think about how chosing one teleporter affects
  // other teleporters cost.
  //
  // Let's try for a solution:
  // So the first teleporter to choose is the one from the left with i + cost of
  // teleporter as cost. Then we need to check, should we go to the start or the
  // end + 1? If we pick the local optimal solution here, either from end + 1 or
  // the start, then
  // This is still a greedy solution. And does not work for
  // 2 14
  // 7 5
  //
  // Since I would always pick the 5, with cost 7 rather than the 7 with cost 8.
  // Is this only a problem for size 2?
  // 3 19
  // 7 4 5
  //
  // I think so.
  // So, should rather take for the first choice, consider if the index is the
  // same in right but lower cost and we have c >= right, then take another from
  // the priority_queue. By popping and take a new.
  long long c, n, buf, result = 0;
  long long max_cost = 1000000001;
  cin >> n;
  cin >> c;

  vector<long long> a;
  // Maintain a tuple with <index, cost> so that if index has already been used,
  // pop it.
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 Compare>
      left_queue;
  // priority_queue<long long, vector<long long>, greater<long long>>
  // left_queue;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 Compare>
      right_queue;
  // priority_queue<long long, vector<long long>, greater<long long>>
  // right_queue;
  set<long long> used_teleports;

  // No longer true, this is only considering jumping from the left.
  // Maintain a second min queue where the current total cost is added before
  // checking if we pick from the left or right.
  for (long long i = 0; i < n; i++) {
    cin >> buf;
    left_queue.push(make_pair(buf + i + 1, i));
    right_queue.push(make_pair(buf + (n - i), i));
  }

  bool start = true;
  while (c > 0 && !left_queue.empty() && !right_queue.empty()) {
    auto [left_cost, left_index] = left_queue.top();
    auto [right_cost, right_index] = right_queue.top();

    // If we are at the start, we always need to take the leftmost first.
    if (start) {
      pair<long long, long long> old_left_pair =
          make_pair(left_cost, left_index);

      if (left_index == right_index && right_cost < left_cost) {
        // Here I don't want to take the left since then I would increase the
        // cost. But if I just pop, I will remove the element. Solution:
        // 1. Store current left_cost and left_index in temp variables.
        // 2. Get the next top element from the queue.
        // 3. In the end of the function, add back the temp variables as a pair
        // in the queue.
        left_queue.pop();

        // Take the pair explicitly and assign to the variables outside this
        // scope.
        pair<long long, long long> new_left_pair = left_queue.top();
        left_cost = new_left_pair.first;
        left_index = new_left_pair.second;

        // Add back the pair.
        left_queue.push(old_left_pair);
      }
      c -= left_cost;
      used_teleports.insert(left_index);
      left_queue.pop();
      start = false;
    }
    // Now we have a choice, do we stay at the start or go to the end?
    // Also need to remove this element from the right queue.
    else {
      if (used_teleports.find(left_index) != used_teleports.end()) {
        left_queue.pop();
        left_cost = max_cost;
      }
      if (used_teleports.find(right_index) != used_teleports.end()) {
        right_queue.pop();
        right_cost = max_cost;
      }
      if (left_cost <= right_cost) {
        c -= left_cost;
        left_queue.pop();
        used_teleports.insert(left_index);
        // Also need to remove this element from the right queue.
        if (left_index == right_index) {
          right_queue.pop();
        }
      } else {
        c -= right_cost;
        right_queue.pop();
        used_teleports.insert(right_index);
        // Also need to remove this element from the left queue.
        if (left_index == right_index) {
          left_queue.pop();
        }
      }
      // This is equivalent but split to make the popping.
      // c = max(c - left_cost, c - right_cost);
    }

    if (c >= 0) {
      result++;
    }
  }
  cout << result << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solution();
}
