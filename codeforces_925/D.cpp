#include <algorithm>
#include <bit>
#include <bits/stdc++.h>
#include <string>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;

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

vector<ll> trial_division1(ll n) {
  vector<ll> factorization;

  for (ll d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  if (n > 1) {
    factorization.push_back(n);
  }
  return factorization;
}

unordered_set<ll> divisors(ll n) {
  unordered_set<ll> divisors;

  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      divisors.insert(i);
      divisors.insert(n / i);
    }
  }

  return divisors;
}

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

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct hash_pair {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    auto hash_func = custom_hash{};
    auto hash1 = hash_func(p.first);
    auto hash2 = hash_func(p.second);

    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

const int maxN = 200013;
ll n;

vector<ll> p;

void sieve_of_eratosthenes(ll n) {
  vector<ll> isPrime(n + 1, true);

  isPrime[0] = isPrime[1] = false;

  for (ll i = 2; i <= n; i++) {
    if (isPrime[i] && i * i <= n) {
      for (ll j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  for (ll i = 0; i < n + 1; i++) {
    if (isPrime[i]) {
      p.push_back(i);
    }
  }
}

void print(auto &&r) {
  std::ranges::for_each(r, [](auto &&i) { std::cout << i << ' '; });
  cout << "\n";
}

struct hash_triplet {
  template <class T1, class T2, class T3>
  size_t operator()(const tuple<T1, T2, T3> &p) const {
    auto hash1 = hash<T1>{}(get<0>(p));
    auto hash2 = hash<T2>{}(get<1>(p));
    auto hash3 = hash<T3>{}(get<2>(p));

    size_t seed = 0;
    seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash3 + 0x9e3779b9 + (seed << 6) + (seed >> 2);

    return seed;
  }
};

template <class Os, class K> Os &operator<<(Os &os, const std::multiset<K> &v) {
  os << '[' << v.size() << "] {";
  bool o{};
  for (const auto &e : v)
    os << (o ? ", " : (o = 1, " ")) << e;
  return os << " }\n";
}

vector<pair<ll, ll>> t(maxN * 4);
int a[maxN + 1];
// build
void build(int a[], ll v = 1, ll tl = 1, ll tr = n) {
  if (tl == tr) {
    t[v].first = tl;
    t[v].second = tl;
    return;
  }
  ll tm = (tl + tr) >> 1;

  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);

  auto x = t[2 * v];
  auto y = t[2 * v + 1];

  if (a[x.first] <= a[y.first]) {
    t[v].first = x.first;
  } else {
    t[v].first = y.first;
  }

  if (a[x.second] >= a[y.second]) {
    t[v].second = x.second;
  } else {
    t[v].second = y.second;
  }
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
pair<ll, ll> sum(ll l, ll r, ll v = 1, ll L = 1, ll R = n) {
  if (R < l || r < L) {
    return {maxN, 0};
  }
  if (l <= L && R <= r) {
    return t[v];
  }
  ll mid = (L + R) >> 1;

  // cout << "dammn \n";

  auto x = sum(l, r, v * 2, L, mid);

  auto y = sum(l, r, v * 2 + 1, mid + 1, R);

  pair<ll, ll> res{};

  // cout << x.first << " " << x.second << "\n";
  // cout << y.first << " " << y.second << "\n";

  if (a[x.first] <= a[y.first]) {
    res.first = x.first;
  } else {
    res.first = y.first;
  }

  if (a[x.second] >= a[y.second]) {
    res.second = x.second;
  } else {
    res.second = y.second;
  }
  return res;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = gcd(a, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);

  return d;
}

pair<ll, ll> factorize(ll a, ll b, ll c) {
  ll x, y;
  ll g = gcd(abs(a), abs(b), x, y);
  if (c % g) {
    return {0, 0};
  }

  x *= c / g;
  y *= c / g;

  if (a < 0) {
    x = -x;
  }
  if (b < 0) {
    y = -y;
  }
  return make_pair(x, y);
}

void solution() {
  // ScopedTimer timer{"solution"};
  //
  // Solve it
  //
  ll x, y;
  cin >> n >> x >> y;

  vector<ll> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll ans = 0;
  unordered_map<pair<ll, ll>, ll, hash_pair> cnt;

  // (a_i + a_j) % x = 0 => (a_i%x + a_j%x)%x = 0
  // Thus either (a_i%x + a_j%x) = x or 0.
  // => a_i%x = (x- a_j%x)%x since (a_i%x + a_j%x) = 0 => a_i%x = -a_j%x but
  // both a_j and a_i > 0.
  // Similarly for (a_i - a_j)%y =0
  // Thus (a_i%y - a_j%y) = y or 0.
  //
  // If (a_i%y - a_j%y) = y => a_i%y = (y+a_j%y)%y = a_j%y
  // a_i%y = a_j%y
  // Go through a in order, take out a_j, then check if (x - a_j%x) % x, a_j%y
  // is present in the map, if so add the count to answer.
  for (ll a_j : a) {
    ll xx = a_j % x, yy = a_j % y;
    ans += cnt[make_pair((x - xx) % x, (y + yy) % y)];
    cnt[make_pair(xx, yy)]++;
  }

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
