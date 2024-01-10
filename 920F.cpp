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

const int maxN = 300030;
const int M = 1000013;
int n, m;
ll t[maxN * 4];
ll mx[maxN * 4];
ll a[maxN];
bool marked[maxN * 4];
ll D[M];

void precalc() {
  for (ll i = 1; i <= M; i++) {
    D[i] = num_divisors(i);
  }
}

// build
void build(ll a[], ll v = 1, ll tl = 1, ll tr = n) {
  if (tl == tr) {
    t[v] = mx[v] = a[tl];
    return;
  }
  ll tm = (tl + tr) >> 1;
  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);
  t[v] = t[v * 2] + t[v * 2 + 1];
  mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}

// update
void update(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (l == r) {
    t[v] = mx[v] = D[t[v]];
    return;
  }
  ll mid = (l + r) >> 1;
  if (L <= mid && mx[v * 2] > 2)
    update(l, mid, 2 * v, L, min(mid, R));
  if (R > mid && mx[v * 2 + 1] > 2)
    update(mid + 1, r, 2 * v + 1, max(mid + 1, L), R);
  t[v] = t[2 * v] + t[2 * v + 1];
  mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}

// queries
ll sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (L > R)
    return 0;
  if (l == L && r == R)
    return t[v];
  ll mid = (l + r) >> 1;
  return sum(l, mid, v * 2, L, min(mid, R)) +
         sum(mid + 1, r, v * 2 + 1, max(mid + 1, L), R);
}

void solution() {
  // ScopedTimer timer{"solution"};
  // Solve it.
  // Global n
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(a);
  // print(t);

  for (int i = 0; i < m; i++) {
    ll q, l, r;
    cin >> q >> l >> r;
    if (q == 1) {
      update(1, n, 1, l, r);
      // print(t);
    } else {
      cout << sum(1, n, 1, l, r) << "\n";
    }
  }
}

int main() {
  precalc();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
