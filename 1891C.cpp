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

struct hash_pair {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);

    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

const int maxN = 200013;
int n;

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

void solution() {
  // ScopedTimer timer{"solution"};
  //
  // Solve it
  cin >> n;

  // min attacks to kill all monsters
  //
  // Attack 1: Choose a monster i in the horde, kill one monster and increase
  // combo That is, choose i, a[i]--, x++;
  //
  // Attack 2: choose a number i in the horde, s.t. a[i] >= x, a[i]-=x, x=0.
  // That is, choose i a[i] >= x, a[i]-=x, x=0;

  // The attack value of attack 1 is thus 1
  // Attack value of attack 2 is x.
  vector<ll> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // minimum attacks:
  // Attack with first type
  // Say we have 10 5
  // we do 5 attacks on first, then we do 1 attack on second:
  // 5 0: 6 used
  // 2 normal attacks, 1 2nd and 1 first: 4
  // Thus 10 attacks.
  // If only 10, we only need 6 attacks.
  //
  // 1 3 1 1
  // use 1st on all except 2nd.: 4 attacks.
  //
  //
  // 1 2 1 1
  // Use 1st attack on 3, 4.: 2 attacks
  // Then 2nd attack on 2.: 3 attacks
  // Then 1st attack on 1: 4 attacks.
  //
  // 3 2 1 5 2 4
  // 3 2 0 5 2 4: 1, x=1
  // 3 2 0 4 2 4: 2, x=2
  // 3 0 0 4 2 4: 3, x=0
  // 2 0 0 4 2 4: 4, x=1
  // 2 0 0 3 2 4: 5, x=2
  // 0 0 0 3 2 4: 6, x=0
  // 0 0 0 3 2 3: 7, x=1
  // 0 0 0 2 2 3: 8, x=2
  // 0 0 0 0 2 3: 9, x=0
  // 0 0 0 0 2 2: 10, x=1
  // 0 0 0 0 1 2: 11, x=2
  // 0 0 0 0 1 0: 12, x=0
  // 0 0 0 0 0 0: 13, x=1
  //
  // This is not optimal.
  //
  //
  // 1 6
  // 0 6: 1, x=1
  // 0 5: 2, x=2
  // 0 4: 3, x=3
  // 0 1: 4, x=0
  // 0 0: 0, x=1
  //
  //
  // Try this again:
  // 3 2 1 5 2 4
  // 3 2 0 5 2 4: 1, x=1
  // 3 1 0 5 2 4: 2, x=2
  // 3 0 0 5 2 4: 3, x=3
  // 3 0 0 5 1 4: 4, x=4
  // 3 0 0 5 0 4: 5, x=5
  // 3 0 0 0 0 4: 6, x=0
  // 2 0 0 0 0 4: 7, x=1
  // 1 0 0 0 0 4: 8, x=2
  // 0 0 0 0 0 4: 9, x=3
  // 0 0 0 0 0 1: 10, x=0
  // 0 0 0 0 0 0: 11, x=1
  //
  // This is optimal.
  //
  // Always take the lowest value we have, decrement until we match the biggest.
  // If the biggest is the last one, then use attack 2 when
  // biggest - x = 1.
  // Then the answer is 2 rounds.
  //
  // Now to the actual solution, should we sort, use a set of alive ones or
  // what? Brute force is to use a set, then take the smallest and decrement by
  // 1 until we match the biggest.

  set<ll> alive;

  for (int i = 0; i < n; ++i) {
    alive.insert(i);
  }

  ll ans = 0;
  ll x = 0;

  while (alive.size() > 0) {
    ll low = *alive.begin();
    ll high = *alive.rbegin();

    if (a[high] == x) {
      alive.erase(high);
      x = 0;
      ans++;
    } else if (alive.size() != 1) {
      x += a[low];
      ans += a[low];
      alive.erase(low);
    } else {
      // How to handle the case with the lone survivor?
      // 0 6, x=1
      // 0 5, x=2
      // 0 4, x=3
      // a[high]-1==x
      // x%(a[high]-1) + 1
      //
      ans += x % (a[high] - 1) + 1;
    }
  }
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
