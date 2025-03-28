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

template <class Os, class K> Os &operator<<(Os &os, const std::multiset<K> &v) {
  os << '[' << v.size() << "] {";
  bool o{};
  for (const auto &e : v)
    os << (o ? ", " : (o = 1, " ")) << e;
  return os << " }\n";
}

// build
// void build(int a[], ll v = 1, ll tl = 1, ll tr = n) {
//   if (tl == tr) {
//     // Go through all other elements and add
//     // 1 to their score if they divide us.
//     // Also count how many we divide to add our score.
//     // Either best with a map?
//     cout << a[tl] << "\n";
//     for (int i = tl + 1; i <= n; ++i) {
//       if (a[i] % a[tl] == 0) {
//         cout << "hm\n";
//         t[v]++;
//       }
//       if (a[tl] % a[i] == 0) {
//         cout << "what\n";
//         score[i]++;
//       }
//     }
//     t[v] += score[tl];
//     cout << t[v] << "\n";
//     return;
//   }
//   ll tm = (tl + tr) >> 1;
//
//   build(a, v * 2, tl, tm);
//   build(a, v * 2 + 1, tm + 1, tr);
//
//   // Unclear what to store at each non-leaf vertex
//   // t[v] = max(t[2 * v], t[2 * v + 1]);
// }

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
// unsigned int sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
//   if (L > R)
//     return 0;
//   if (l == L && r == R) {
//     return t[v];
//   }
//   ll mid = (l + r) >> 1;
//
//   unsigned int x, y;
//
//   x = sum(l, mid, v * 2, L, min(mid, R));
//
//   y = sum(mid + 1, r, v * 2 + 1, max(mid + 1, L), R);
//
//   if (N & 1) {
//     return x | y;
//   } else {
//     return x ^ y;
//   }
// }

// const int maxN = 100'013;
const int maxN = 10;
int n;
ll t[maxN * 4];
ll score[maxN];

void solution() {
  // ScopedTimer timer{"solution"};
  //
  // Solve it

  cin >> n;

  ll ans = 0;
  vector<ll> edges(n);

  for (int i = 0; i < n - 1; i++) {
    int l, r;
    cin >> l >> r;
    edges[l - 1]++;
    edges[r - 1]++;
  }

  int count_candidates = 0;
  for (auto num_edges : edges) {
    if (num_edges == 1) {
      count_candidates++;
    }
  }
  ans = (count_candidates / 2 + count_candidates % 2);

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
