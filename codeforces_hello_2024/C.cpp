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

void solution() {
  // Solve it.
  ll n;

  cin >> n;

  vector<ll> a(n);
  vector<ll> s(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;

  // Fuck it? Test with n heaps?
  // each index has a heap with the elements to the right of it.
  // How to construct it?
  // If we start at index 0:
  // We would push all the elements to the right in a heap
  // That or simply binary search with a range to the right?
  //
  // Or can we better choose where to start?
  // We could probably sort
  // and use IOTA to get a list of the indices.
  // Then we need to take the max_ind - min_ind
  int best_s = -1;

  for (int i = 0; i < n; ++i) {
    vector<ll> s_tmp(n, 0);
    s_tmp[i] = a[i];
    int s_tmp_size = 0;
    int k = i;

    for (int j = i + 1; j < n; ++j) {
      if (s_tmp[k] >= a[j]) {
        s_tmp[j] = a[j];
        k = j;
        s_tmp_size++;
      }
    }

    if (s_tmp_size > best_s) {
      s = s_tmp;
      best_s = s_tmp_size;
    }
  }

  vector<ll> t;
  for (int i = 0; i < n; ++i) {
    if (!s[i]) {
      t.push_back(a[i]);
    }
  }

  for (int i = 0; i < max(0, (int)t.size() - 1); ++i) {
    if (t[i] < t[i + 1]) {
      ans++;
    }
  }

  cout << ans << "\n";
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
