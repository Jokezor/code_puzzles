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

const int maxN = 10;
int n;
int mn[maxN * 4];
int lz[maxN * 4];

// Just initializes both lz and mn to 0s.
void init(int u = 1, int lo = 1, int hi = n) {
  mn[u] = lz[u] = 0;

  if (lo != hi) {
    int mid = (lo + hi) >> 1;
    init(2 * u, lo, mid);
    init(2 * u + 1, mid + 1, hi);
  }
}

// updating its left and right child with lz[u]
// Then sets lz[u] = 0.
void propo(int u) {
  if (lz[u] == 0) {
    return;
  }

  lz[2 * u] += lz[u];
  lz[2 * u + 1] += lz[u];
  mn[2 * u] += lz[u];
  mn[2 * u + 1] += lz[u];
  lz[u] = 0;
}

void incre(int s, int e, int x, int u = 1, int lo = 1, int hi = n) {
  if (lo >= s && hi <= e) {
    mn[u] += x;
    lz[u] += x;
    return;
  }
  propo(u);
  int mid = (lo + hi) >> 1;
  if (s <= mid) {
    incre(s, e, x, 2 * u, lo, mid);
  }
  if (e > mid) {
    incre(s, e, x, 2 * u + 1, mid + 1, hi);
  }
  mn[u] = min(mn[2 * u], mn[2 * u + 1]);
}

// if s = 1, e = 7
//
int qmn(int s, int e, int u = 1, int lo = 1, int hi = n) {
  cout << u << " : " << lo << hi << "\n";
  if (s > e) {
    return MAX_VAL;
  }
  if (lo >= s && hi <= e) {
    cout << "naaah \n";
    return mn[u];
  }
  propo(u);
  int mid = (lo + hi) >> 1;
  int res = MAX_VAL;
  if (s <= mid) {
    cout << "tbh \n";
    res = min(res, qmn(s, e, 2 * u, lo, mid));
  }
  if (e > mid) {
    cout << "totz\n";
    res = min(res, qmn(s, e, 2 * u + 1, mid + 1, hi));
  }
  print(lz);
  return res;
}

void solution() {
  // Solve it.
  // Global n
  cin >> n;

  vector<ll> a(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;

  // Using DP to solve it.
  // But through a segment tree?

  // Initialize mn and lz to 0s. in the segment tree
  init();

  // Go through all elements of a
  for (int i = 0; i < n; i++) {
    // Lets look for 8:
    // qmn(1, 7), qmn(8, 8)
    qmn(1, a[i] - 1);
    return;
    int ndp = min(qmn(1, a[i] - 1) + 1, qmn(a[i], n));
    cout << ndp << "\n";
    return;
    if (i > 0) {
      if (a[i - 1] < a[i]) {
        incre(1, n, 1);
      }
      int dp = qmn(a[i - 1], a[i - 1]);
      if (ndp < dp) {
        incre(a[i - 1], a[i - 1], ndp - dp);
      }
    }
  }

  cout << qmn(1, n) << "\n";
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
