#include <algorithm>
#include <bit>
#include <bits/stdc++.h>
#include <string>

#define ll long long
#define all(x) x.begin(), x.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define THROW(exceptionClass, message)                                         \
  throw exceptionClass(__FILE__, __LINE__, (message))

using namespace std;

ll MAX_VAL = (ll)(1e9 + 9);

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

template <class Os, class K> Os &operator<<(Os &os, const std::multiset<K> &v) {
  os << '[' << v.size() << "] {";
  bool o{};
  for (const auto &e : v)
    os << (o ? ", " : (o = 1, " ")) << e;
  return os << " }\n";
}

// const int maxN = 100'013;
const int maxN = 10;
int n;
ll fib[maxN + 10];

void fibonacci(ll n) {
  fib[0] = 1;
  fib[1] = 1;

  for (int i = 2; i <= n; ++i) {
    fib[i] = (fib[i - 2] + fib[i - 1]) % MAX_VAL;
  }
}
// a[i]
vector<ll> t(maxN * 4);
// Should lz hold the l value for which fib to apply?
vector<stack<ll>> lz(maxN * 4);

// build
void build(int a[], int v = 1, int tl = 1, int tr = n) {
  if (tl > tr) {
    return;
  }
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }
  ll tm = (tl + tr) >> 1;

  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);

  t[v] = (t[2 * v] + t[2 * v + 1]) % MAX_VAL;
}

void push(int v) {
  while (!lz[v].empty()) {
    ll fib_num = lz[v].top();
    t[2 * v] += fib[v - fib_num + 1];
    t[2 * v + 1] += fib[v + 1 - fib_num + 1];
    lz[2 * v].push(fib_num);
    lz[2 * v + 1].push(fib_num);
    lz[v].pop();
  }
}

// update
// new_val is the original l
// Does not work, how would I apply to queries at the same time?
// I cannot simply add the indexes.
void update(ll l, ll r, ll new_val, ll L = 1, ll R = n, ll v = 1) {
  if (l > r) {
    return;
  }
  if (l == R && r == R) {
    cout << v - new_val + 1 - n << "\n";
    t[v] += fib[v - new_val + 1];
    lz[v].push(new_val);
    return;
  }
  push(v);
  ll mid = (L + R) >> 1;
  update(l, min(r, mid), new_val, L, mid, 2 * v);
  update(max(l, mid + 1), r, new_val, mid + 1, R, 2 * v + 1);
  t[v] = t[2 * v] + t[2 * v + 1];
}

// queries

ll sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (R < l || r < L) {
    return 0;
  }
  if (l <= L && R <= r) {
    return t[v];
  }
  push(v);
  ll mid = (L + R) >> 1;

  return sum(l, r, 2 * v, L, mid) + sum(l, r, 2 * v + 1, mid + 1, R);
}

void solution() {
  // ScopedTimer timer{"solution"};
  // Solve it.
  int m;

  cin >> n >> m;

  int a[n + 1];

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  build(a);

  print(t);

  // void update(ll l, ll r, ll new_val, ll L = 1, ll R = n, ll v = 1) {
  update(1, 4, 1);

  print(t);
  // Essentially, take queries to add fibonacci numbers in segment to all
  // elements. Or ouput the sum mod 10^9 + 9 of the elements.
  //
  // So in this case, we only need to know that we would apply F_{i -l +1} to a
  // range. But we only need the value when query type 2 comes.
  //
  // The fibonacci numbers should be precomputed up to 300k.
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  // Compute all fibonacci up to N.
  fibonacci(maxN + 1);

  while (t--)
    solution();

  return 0;
}
