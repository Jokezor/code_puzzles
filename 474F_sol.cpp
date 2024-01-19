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

template <class Os, class K> Os &operator<<(Os &os, const std::multiset<K> &v) {
  os << '[' << v.size() << "] {";
  bool o{};
  for (const auto &e : v)
    os << (o ? ", " : (o = 1, " ")) << e;
  return os << " }\n";
}

// const int maxN = 100'013;
const int maxN = 100000;
int n;
// {smallest, gcd, count}
vector<ll> t(maxN * 4);

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

  t[v] = gcd(t[2 * v], t[2 * v + 1]);
}

// update
// void update(ll l, ll r, ll pos, ll i, ll new_val, ll v = 1) {
//   if (l == r) {
//     t[v] = new_val;
//     return;
//   }
//   ll mid = (l + r) >> 1;
//   if (pos <= mid)
//     update(l, mid, pos, i + 1, new_val, 2 * v);
//   else
//     update(mid + 1, r, pos, i + 1, new_val, 2 * v + 1);
//
//   if (i % 2 == 0) {
//     if (N & 1) {
//       t[v] = t[2 * v] | t[2 * v + 1];
//     } else {
//       t[v] = t[2 * v] ^ t[2 * v + 1];
//     }
//   } else {
//     if (N & 1) {
//       t[v] = t[2 * v] ^ t[2 * v + 1];
//     } else {
//       t[v] = t[2 * v] | t[2 * v + 1];
//     }
//   }
// }
//
// // queries

// {smallest, gcd, {strength: count}}
// vector<pair<pair<ll, ll>, unordered_map<ll, ll>>> t(maxN * 4);
ll sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (R < l || r < L) {
    return 0;
  }
  if (l <= L && R <= r) {
    return t[v];
  }
  ll mid = (L + R) >> 1;
  // cout << l << " " << r << " " << mid << " " << v << "\n";
  // cout << L << " " << R << "\n";

  // if (v == 0) {
  //   return {0, 0, 0};
  // }

  // {smallest, gcd, count}
  auto x = sum(l, r, v * 2, L, mid);
  auto y = sum(l, r, v * 2 + 1, mid + 1, R);

  return gcd(x, y);
}

void solution() {
  // ScopedTimer timer{"solution"};
  // Solve it.
  //
  // Fails for:
  //
  // 1 1
  // 1 1
  // 1 1

  ll ans = 0;

  cin >> n;

  int a[n + 1];
  vector<pair<ll, ll>> b(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = make_pair(a[i], i);
  }

  sort(b.begin(), b.end());
  build(a);

  int m = 1, l = 4, r = 5;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> l >> r;
    auto gcd_q = sum(l, r);

    // Finds the first entry of gcd_q.
    pair<ll, ll> p = make_pair(gcd_q, l);

    ll from = (lower_bound(b.begin(), b.end(), p) - b.begin());

    // Finds the last entry of gcd_q
    p = make_pair(gcd_q, r + 1);
    ll to = (lower_bound(b.begin(), b.end(), p) - b.begin());

    ll winners = to - from;
    // count is the distance between first and last occurance.
    // Whole range length - count
    cout << ((r - l + 1) - winners) << "\n";
  }

  // {smallest, gcd, count}

  // vector<pair<pair<ll, ll>, unordered_map<ll, ll>>> t(maxN * 4);
  // pair<pair<ll, ll>, unordered_map<ll, ll>>
  // for (auto e : t) {
  //   cout << "gcd=" << e << "\n";
  // }

  // ans = (r - l + 1) - q.second[q.first].second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
