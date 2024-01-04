#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define all(x) x.begin(), x.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))

using namespace std;

ll MAX_VAL = (ll)(1e9 + 7);

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int lcm(int x, int y) { return (x / gcd(x, y)) * y; }

constexpr size_t arraySize = 99;

constexpr int calculateValue(size_t i, size_t j) {
  if (i == j) {
    return i;
  } else {
    return 0;
  }
}

constexpr std::array<std::array<int, arraySize>, arraySize> initializeArray() {
  std::array<std::array<int, arraySize>, arraySize> arr{};
  for (size_t i = 0; i < arraySize; ++i) {
    for (size_t j = 0; j < arraySize; ++j) {
      arr[i][j] = calculateValue(i, j);
    }
  }
  return arr;
}

constexpr auto myArray = initializeArray();

unordered_map<ll, vector<string>> powers;

void solution() {
  // Solve it
  // Need up to 99 length numbers.
  ll n = 1;
  cin >> n;

  for (string num : powers[n]) {
    cout << num << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;

  cin >> t;

  powers[1] = {"1"};
  powers[3] = {"169", "961", "196"};

  for (int i = 5; i <= 99; i += 2) {
    for (auto p : powers[i - 2]) {
      powers[i].push_back(p + "00");
    }

    string num_1(i, '0');
    num_1[0] = '1';
    num_1[i / 2] = '6';
    num_1[i - 1] = '9';

    string num_2(i, '0');
    num_2[0] = '9';
    num_2[i / 2] = '6';
    num_2[i - 1] = '1';

    powers[i].push_back(num_1);
    powers[i].push_back(num_2);
  }

  while (t--)
    solution();

  return 0;
}
