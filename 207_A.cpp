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

void print(auto &&r) {
  std::ranges::for_each(r, [](auto &&i) { std::cout << i << ' '; });
  cout << "\n";
}

const int maxN = 300000;
int n;
int t[maxN * 4];
bool marked[maxN * 4];

// build
void build(int a[], int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) >> 1;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

// update
void update(int l, int r, int win, int v = 1, int tl = 1, int tr = n) {
  if (l > tr || r < tl || tr < tl) {
    return;
  }
  if (t[v] != 0) {
    return;
  }
  if (tl >= l && tr <= r) {
    t[v] = win;
    return;
  }
  int tm = (tl + tr) >> 1;
  update(l, r, win, 2 * v, tl, tm);
  update(l, r, win, 2 * v + 1, tm + 1, tr);
}

// queries
int sum(int l, int r, int v = 1, int tl = 1, int tr = n) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  int tm = (tl + tr) >> 1;
  int x, y;
  x = sum(l, min(r, tm), v * 2, tl, tm);
  y = sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
  if (x == 0 and y == 0)
    return t[v];
  return max(x, y);
}

void solution() {
  // Solve it.
  // Global n
  int m;
  cin >> n >> m;

  // Simply store for each mn[u], the knight that won in each range.
  // Tricky is that we should update [l, x-1] and [x+1, r] and not x.

  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    update(l, x - 1, x);
    update(x + 1, r, x);
  }

  for (int i = 1; i < n; i++) {
    cout << sum(i, i) << " ";
  }
  cout << sum(n, n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
