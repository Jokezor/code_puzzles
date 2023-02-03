#include <iostream>
#include <stdio.h>

using namespace std;

void solution() {
  int start = 0;
  int end;
  int n;
  string s;

  cin >> n;
  cin >> s;

  end = n - 1;

  while (start < end) {
    if (s[start] == s[end]) {
      break;
    }
    start++;
    end--;
  }

  cout << (end - start + 1) << endl;
}

int main() {

  int t;

  cin >> t;

  while (t) {
    solution();
    t--;
  }
}
