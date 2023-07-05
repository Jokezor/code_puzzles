#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> shoot_shots(vector<int> nums) {
  nums[1] -= nums[0] / 7;
  nums[2] -= nums[0] / 7;
  nums[0] %= 7;
  return nums;
}

void solution() {
  int a, b, c;

  cin >> a >> b >> c;

  vector<int> nums = {a, b, c};

  sort(nums.begin(), nums.end(), greater<int>());

  nums = shoot_shots(nums);

  sort(nums.begin(), nums.end(), greater<int>());

  nums = shoot_shots(nums);

  sort(nums.begin(), nums.end(), greater<int>());

  nums = shoot_shots(nums);

  int i = 1;
  while (nums[0] && nums[1] && nums[2]) {
    if (i % 7 == 0) {
      nums[0]--;
      nums[1]--;
      nums[2]--;
    } else {
      nums[0]--;
    }
    i++;
    sort(nums.begin(), nums.end(), greater<int>());
  }
  if (!nums[0] && !nums[1] && !nums[2]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
