#include <bits/stdc++.h>
#include <gmpxx.h>
#include <time.h>

using namespace std;

vector<mpz_class> continued_fractions(mpf_class a, mpf_class b) {
  // https://en.wikipedia.org/wiki/Continued_fraction
  mpf_class eps = mpf_class("1e-400");
  vector<mpz_class> fractions;

  while (a > eps && b > eps) {
    fractions.push_back(mpz_class(a / b));
    mpf_class temp = b;
    b = a - b * mpz_class(a / b);
    a = temp;
  }

  return fractions;
}

int main() {

  clock_t start = clock();

  mpf_set_default_prec(10000);

  mpz_class max_h = 0;
  mpz_class max_n = -1;

  for (int n = 2; n <= 1000; n++) {
    mpf_class a;
    mpf_sqrt(a.get_mpf_t(), mpf_class(n).get_mpf_t());
    mpq_class b = 1;

    // Start by getting the continued fractions
    vector<mpz_class> fractions = continued_fractions(a, b);

    vector<mpz_class> h(fractions.size() + 2);
    vector<mpz_class> k(fractions.size() + 2);

    h[0] = 0;
    h[1] = 1;

    k[0] = 1;
    k[1] = 0;

    // calculate convergents
    for (int i = 0; i < fractions.size(); i++) {
      h[i + 2] = fractions[i] * h[i + 1] + h[i];
      k[i + 2] = fractions[i] * k[i + 1] + k[i];
    }
    /*
    cout << "a: [";
    for (int i = 0; i < fractions.size() - 1; i++) {
      cout << fractions[i] << ", ";
    }
    cout << fractions[fractions.size() - 1] << "]\n";

    cout << "h: [";
    for (int i = 0; i < h.size() - 1; i++) {
      cout << h[i] << ", ";
    }
    cout << h[h.size() - 1] << "]\n";

    cout << "k: [";
    for (int i = 0; i < k.size() - 1; i++) {
      cout << k[i] << ", ";
    }
    cout << k[k.size() - 1] << "]\n";
    */

    // Now take and calculate pell's approximation of h^2 - n*k^2 which should
    // be 1.
    for (int i = 2; i < h.size(); i++) {
      if ((h[i] * h[i] - mpz_class(n) * k[i] * k[i]) == 1) {
        cout << h[i] << " " << k[i] << "\n";
        if (h[i] > max_h) {
          max_h = h[i];
          max_n = n;
        }
        break;
      }
    }
  }

  cout << max_n << " " << max_h << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
