#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

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

template <class A> ostream &operator<<(ostream &out, const vector<A> &v) {
  out << "[";
  forn(i, sz(v)) {
    if (i)
      out << ", ";
    out << v[i];
  }
  return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 300 * 1000 + 13;
const int M = 1000 * 1000 + 13;

int n, m;
int a[N];
li sum[4 * N];
int mx[4 * N];
int f[M];
int d[M];

bool read() {
  if (scanf("%d%d", &n, &m) != 2)
    return false;
  forn(i, n) scanf("%d", &a[i]);
  return true;
}

void init() {
  for (int i = 2; i < M; i++) {
    if (d[i])
      continue;
    d[i] = i;
    for (li j = i * 1ll * i; j < M; j += i)
      if (!d[j])
        d[j] = i;
  }

  f[1] = 1;
  for (int i = 2; i < M; i++) {
    int lst = -1, cnt = 0;
    int x = i;
    f[i] = 1;
    while (x > 1) {
      if (lst != d[x]) {
        f[i] *= cnt + 1;
        lst = d[x];
        cnt = 1;
      } else {
        cnt++;
      }
      x /= d[x];
    }

    f[i] *= cnt + 1;
  }
}

void build(int v, int l, int r) {
  if (l == r) {
    sum[v] = mx[v] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(v * 2 + 1, l, mid);
  build(v * 2 + 2, mid + 1, r);
  sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
  mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}

void upd(int v, int l, int r, int L, int R) {
  if (l == r) {
    sum[v] = mx[v] = f[sum[v]];
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid && mx[v * 2 + 1] > 2)
    upd(v * 2 + 1, l, mid, L, min(mid, R));
  if (R > mid && mx[v * 2 + 2] > 2)
    upd(v * 2 + 2, mid + 1, r, max(mid + 1, L), R);
  sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
  mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}

li get(int v, int l, int r, int L, int R) {
  if (L > R)
    return 0;
  if (l == L && r == R)
    return sum[v];
  int mid = (l + r) >> 1;
  return get(v * 2 + 1, l, mid, L, min(mid, R)) +
         get(v * 2 + 2, mid + 1, r, max(mid + 1, L), R);
}

void solve() {
  init();
  build(0, 0, n - 1);

  forn(_, m) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      upd(0, 0, n - 1, l - 1, r - 1);
    } else
      printf("%lld\n", get(0, 0, n - 1, l - 1, r - 1));
  }
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //	freopen("output.txt", "w", stdout);

  int tt = clock();

#endif

  cerr.precision(15);
  cout.precision(15);
  cerr << fixed;
  cout << fixed;

  while (read()) {
    solve();

#ifdef _DEBUG
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
#endif
  }
}
