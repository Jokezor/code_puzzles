#include <algorithm>
#include <bit>
#include <bits/stdc++.h>
#include <string>

#define ll long long
#define all(x) x.begin(), x.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))

using namespace std;

ll MAX_VAL = (ll)(1e9 + 7);

bool USE_TIMER = true;

#if USE_TIMER
#define MEASURE_FUNCTION()                                                     \
  ScopedTimer timer { __func__ }
#else
#define MEASURE_FUNCTION()
#endif

class ScopedTimer {
public:
  using ClockType = std::chrono::steady_clock;
  ScopedTimer(const char *func)
      : function_name_{func}, start_{ClockType::now()} {}
  ScopedTimer(const ScopedTimer &) = delete;
  ScopedTimer(ScopedTimer &&) = delete;
  auto operator=(const ScopedTimer &) -> ScopedTimer & = delete;
  auto operator=(ScopedTimer &&) -> ScopedTimer & = delete;
  ~ScopedTimer() {
    using namespace std::chrono;
    auto stop = ClockType::now();
    auto duration = (stop - start_);
    auto ms = duration_cast<milliseconds>(duration).count();
    std::cout << ms << " ms " << function_name_ << '\n';
  }

private:
  const char *function_name_{};
  const ClockType::time_point start_{};
};

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int lcm(int x, int y) { return (x / gcd(x, y)) * y; }

ll num_divisors(ll num) {
  ll total = 1;
  for (int i = 2; (ll)i * i <= num; i++) {
    if (num % i == 0) {
      int e = 0;
      do {
        e++;
        num /= i;
      } while (num % i == 0);
      total *= e + 1;
    }
  }
  if (num > 1) {
    total *= 2;
  }
  return total;
}

void print(auto &&r) {
  std::ranges::for_each(r, [](auto &&i) { std::cout << i << ' '; });
  cout << "\n";
}

const int maxN = 100013;
int n, m;
ll t[maxN * 4][26];

// build
void build(string &s, ll v = 1, ll tl = 1, ll tr = n) {
  if (tl == tr) {
    // Remember, s is 0 index, t and all range queries is 1 indexed.
    t[v][s[tl - 1] - 'a']++;
    return;
  }
  ll tm = (tl + tr) >> 1;
  build(s, v * 2, tl, tm);
  build(s, v * 2 + 1, tm + 1, tr);
  for (int i = 0; i < 26; ++i) {
    t[v][i] = (t[2 * v][i] + t[2 * v + 1][i]);
  }
}

// update
void update(string &s, ll l, ll r, ll pos, char c, ll v = 1) {
  if (l == r) {
    // Remove current
    t[v][s[pos - 1] - 'a']--;

    s[pos - 1] = c;

    // Add new
    t[v][s[pos - 1] - 'a']++;
    return;
  }
  ll mid = (l + r) >> 1;
  if (pos <= mid)
    update(s, l, mid, pos, c, 2 * v);
  else
    update(s, mid + 1, r, pos, c, 2 * v + 1);
  for (int i = 0; i < 26; ++i) {
    t[v][i] = (t[2 * v][i] + t[2 * v + 1][i]);
  }
}
//
// // queries
unsigned int sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (L > R)
    return 0;
  if (l == L && r == R) {
    unsigned int ans = 1 << 27;

    for (int i = 0; i < 26; i++) {
      ans |= (t[v][i] > 0) << i;
    }

    return ans;
  }
  ll mid = (l + r) >> 1;

  unsigned int x, y;

  // Get bits set for left
  x = sum(l, mid, v * 2, L, min(mid, R));

  // get bits set for right
  y = sum(mid + 1, r, v * 2 + 1, max(mid + 1, L), R);

  // Combine bits
  return x | y;
}

void solution() {
  ScopedTimer timer{"solution"};
  // Solve it.
  string s;
  cin >> s;

  n = s.length();
  cin >> m;

  // Holds the indexes of where each char occurs
  vector<set<int>> positions(26);

  for (int i = 0; i < n; i++) {
    positions[s[i] - 'a'].insert(i);
  }

  for (int j = 0; j < m; j++) {
    ll q = 0, l = 1, r = n;
    char c;

    cin >> q;

    if (q == 1) {
      cin >> l >> c;

      int pos = l;

      // Need to update chars.
      positions[s[pos - 1] - 'a'].erase(pos - 1);
      s[pos - 1] = c;
      positions[s[pos - 1] - 'a'].insert(pos - 1);
    } else {
      cin >> l >> r;
      int ans = 0;
      // Need to binary search to find first index smaller.
      for (int i = 0; i < 26; i++) {
        // Find how many ith char
        std::set<int>::iterator it = positions[i].lower_bound(l - 1);
        if (it != positions[i].end() && *it <= r - 1) {
          ans++;
        }
      }
      cout << ans << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
