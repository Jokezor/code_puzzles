#include <iostream>
#include <vector>

using namespace std;

long int backtrack(vector<int> allowed, vector<int> combination, long int combinations) {
  for (int i=0; i < 10; i++) {
    int count = 0;
    
    cout << i << endl;

    if (combination[i]) {
      count++;
    }

    if (count == 2) {
      cout << "am here" << endl;
      for (int j = 0; j < 10; j++) {
        combination[j] = 0;
      }
      return 1;
    }
  }
  
  for (int i=pos; i < 10; i++) {
    if (allowed[i] and !combination[i]) {
      combination[i] = 1;
      combinations += backtrack(allowed, i, combination, combinations);
    }
  }
  return combinations;
}

long int getPasswordCombinations() {
  int n;
  long int combinations = 0;
  vector<int> allowed(10, 1);
  vector<int> combination(10, 0);

  cin >> n;

  while (n--) {
    int i = 0;
    cin >> i;
    allowed[i] = 0;
  }

  return backtrack(allowed, combination, combinations);
}

int main() {
  int t;
  cin >> t;

  while (t--)
    cout << getPasswordCombinations() << endl;

  return t;

}

