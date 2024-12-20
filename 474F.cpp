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
// {smallest, gcd, {strength: count}}
vector<tuple<ll, ll, ll>> t(maxN * 4);

void init(int L = 1, int R = maxN * 4) {
  for (; L < R; L++) {
    get<0>(t[L]) = MAX_VAL;
    get<1>(t[L]) = MAX_VAL;
  }
}

// build
void build(int a[], int v = 1, int tl = 1, int tr = n) {
  if (tl > tr) {
    return;
  }
  if (tl == tr) {
    // smallest and gcd is itself.
    get<0>(t[v]) = a[tl];
    get<1>(t[v]) = a[tl];
    get<2>(t[v]) = 1;
    return;
  }
  ll tm = (tl + tr) >> 1;

  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);

  auto x = t[2 * v];
  auto y = t[2 * v + 1];

  // gcd of the gcds.
  if (get<0>(x) < get<0>(y)) {
    get<0>(t[v]) = get<0>(x);
    get<2>(t[v]) = get<2>(x);
  } else if (get<0>(y) < get<0>(x)) {
    get<0>(t[v]) = get<0>(y);
    get<2>(t[v]) = get<2>(y);
  } else {
    get<0>(t[v]) = get<0>(x);
    get<2>(t[v]) = get<2>(x) + get<2>(y);
  }
  get<1>(t[v]) = gcd(get<1>(x), get<1>(y));
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

// {smallest, gcd, count}
// vector<pair<pair<ll, ll>, unordered_map<ll, ll>>> t(maxN * 4);
tuple<ll, ll, ll> sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (R < l || r < L) {
    return make_tuple(MAX_VAL, 0, 0);
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
  auto [smallest_x, gcd_x, count_x] = sum(l, r, v * 2, L, mid);
  auto [smallest_y, gcd_y, count_y] = sum(l, r, v * 2 + 1, mid + 1, R);

  if ((smallest_x < smallest_y && smallest_x > 0) || smallest_y == 0) {
    return make_tuple(smallest_x, gcd(gcd_x, gcd_y), count_x);
  } else if ((smallest_y < smallest_x && smallest_y > 0) || smallest_x == 0) {
    return make_tuple(smallest_y, gcd(gcd_x, gcd_y), count_y);
  } else {
    return make_tuple(smallest_y, gcd(gcd_x, gcd_y), count_y + count_x);
  }

  // Unsure how to combine here.
  //
  // int best_strength = x.first;
  // int most_score = 0;
  // if (x.first) {
  //   most_score = x.second[best_strength].first;
  // }

  // for (pair<int, pair<int, int>> e : x.second) {
  //   if (e.first == 0) {
  //     continue;
  //   }
  //   // Add score, count etc from x
  //   q.second[e.first] = e.second;
  //
  //   for (pair<int, pair<int, int>> f : y.second) {
  //     if (f.first == 0) {
  //       continue;
  //     }
  //     if (f.first % e.first == 0) {
  //       // Increment score
  //       q.second[e.first].first++;
  //       if (q.second[e.first].first > most_score) {
  //         best_strength = e.first;
  //         most_score = q.second[e.first].first;
  //       }
  //     }
  //     if (e.first % f.first == 0) {
  //       q.second[f.first].first++;
  //       if (q.second[f.first].first > most_score) {
  //         best_strength = f.first;
  //         most_score = q.second[f.first].first;
  //       }
  //     }
  //   }
  // }
  //
  // // Add count from y
  // for (auto f : y.second) {
  //   q.second[f.first].second += f.second.second;
  // }
  // q.first = best_strength;
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

  cin >> n;

  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  init();
  build(a);

  int m = 1, l = 4, r = 5;

  cin >> m;

  for (int i = 0; i < m; ++i) {
    ll winners = 0;
    cin >> l >> r;
    auto [smallest, gcd_q, count_q] = sum(l, r);

    // cout << smallest << " " << gcd_q << " " << count_q << "\n";

    if (gcd_q == smallest) {
      winners = count_q;
    }
    cout << (r - l + 1) - winners << "\n";
  }

  // {smallest, gcd, count}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
