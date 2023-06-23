#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <bits/stdc++.h>
#include <time.h>

using namespace std;
#define ll long long

int string_score(string s) {
  int score = 0;
  for (int i = 0; i < s.length(); i++) {
    score = score + (s[i] - 'A' + 1);
  }
  return score;
}

int main() {

  clock_t start = clock();

  // Simply read in file, sort it
  // and then map each string.
  // O(Nlog(N)) for sorting.
  // O(N*c) for summing up scores.

  std::ifstream file("names.txt");
  std::string line;
  std::vector<string> names;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    while (iss) {
      string name;
      if (!getline(iss, name, ','))
        break;
      name.erase(remove(name.begin(), name.end(), '\"'), name.end());
      names.push_back(name);
    }
  }

  sort(names.begin(), names.end());

  ll res = 0;

  for (int i = 0; i < names.size(); i++) {
    cout << names[i] << "\n";
    res += (i + 1) * string_score(names[i]);
  }

  assert(string_score("COLIN") == 53);

  cout << res << "\n";

  clock_t end = clock();

  printf("took %lf ms\n", ((double)end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
