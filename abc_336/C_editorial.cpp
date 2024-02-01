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

vector<ll> change_base(ll n, ll base) {
  vector<ll> new_n;

  while (n) {
    new_n.push_back(n % base);
    n /= base;
  }

  return new_n;
}

void solution() {
  // ScopedTimer timer{"solution"};
  //
  // Solve it
  ll n;
  cin >> n;

  // Find the nth smallest good integer.
  // All digits in the decimal notation are even numbers.
  // For a given N, we could get all numbers in k time.
  // Not all even numbers. 10 is not good integer
  // 0 is, 8 is etc.
  //
  // 0, 2, 4, 6, 8|, 20, 22, 24, 26, 28|,40, 42, 44, 46, 48
  // Every 6th is taking a new start.
  //
  // (8/5 + 8%5
  // 8: (8/5)
  //
  // 133 = 26*5 + 3
  // 3rd: 4
  // 26%5: 1
  // 1st: 1
  //
  //
  string ans = "";

  for (ll i = 0; i < b.size(); i++) {
    ans += 2 * b[i] + '0';
  }

  reverse(all(ans));

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;

  while (t--)
    solution();

  return 0;
}