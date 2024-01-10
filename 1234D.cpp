#include <algorithm>
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

const int maxN = 10;
int n, m;
ll t[maxN * 4][26];

// build
void build(string &s, ll v = 1, ll tl = 1, ll tr = n) {
  if (tl == tr) {
    // cout << tl << ":" << tr << "\n";
    t[v][s[tl] - 'a']++;
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
ll sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (L > R)
    return 0;
  if (l == L && r == R) {
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      if (t[v][i]) {
        ans++;
      }
    }
    return ans;
  }
  ll mid = (l + r) >> 1;

  // Return a vector
  sum(l, mid, v * 2, L, min(mid, R));

  // Return a vector
  sum(mid + 1, r, v * 2 + 1, max(mid + 1, L), R);

  // Combine the vectors?
}

void solution() {
  // ScopedTimer timer{"solution"};
  // Solve it.
  string s;
  cin >> s;

  n = s.length();
  cin >> m;

  build(s);

  for (int j = 0; j < m; j++) {
    cout << m << " j=" << j << "\n";
    ll q = 0, l = 1, r = n;
    char c;

    cin >> q;

    if (q == 1) {
      cin >> l >> c;
      update(s, 1, n, l, 'b', 1);
    } else {
      cin >> l >> r;
      cout << sum(1, n, 1, l, r) << "\n";
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
