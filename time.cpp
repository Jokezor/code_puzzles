#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
  auto start =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();
  // insert awesome algorithm here
  auto stop =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();
  cerr << "Took " << stop - start << "ms" << endl;
}
