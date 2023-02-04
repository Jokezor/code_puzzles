#include <bits/stdc++.h>

using namespace std;

void solution() {
  int n;
  string t;

  cin >> n;
  cin >> t;

  // Initialize two vectors of length 26 with default of -1.
  // -1 is to denote that the position is not yet connected in the graph.
  vector<int> source(26, -1);
  vector<int> destination(26, -1);

  // Creating an anonymous lambda function to take the character c
  // Then check while the source of the current character has not been connected
  // So it finds the closest nonvisited position.
  auto get_path_end = [&](int c) {
    int len = 0;
    int cur = c;
    while (source[cur] != -1)
      len++, cur = source[cur];
    return make_pair(cur, len);
  };

  // Create a vector vec to hold the 0-26 int value of the a-z chars.
  vector<int> vec;
  for (char c : t)
    vec.push_back(c - 'a');

  // Go through the full n chars in vec.
  for (int i = 0; i < n; i++) {
    // If the source of the current character has not yet been seen
    // Then go through all characters in the alphabet to see which has not yet
    // been connected.
    if (source[vec[i]] == -1) {
      for (int c = 0; c < 26; c++)
        // character c has not yet been connected
        if (destination[c] == -1) {
          // Find the closest nonvisited char
          // Equivalent to:
          //
          // pair <int,int> path = get_path_end(c);
          // int clast = path.first;
          // int len = path.second;
          auto [clast, len] = get_path_end(c);

          // If the first character not yet visited is not the same as the one
          // in the original string Or if the length is 25, meaning we have a
          // fully connected circle, then we can change the source of the
          // current character to the first character not yet connected Add the
          // current character to the destination of the first character not yet
          // connected. Important to break here since we have found the right
          // character.
          if (clast != vec[i] || len == 25) {
            source[vec[i]] = c;
            destination[c] = vec[i];
            break;
          }
        }
    }
    // To update the characters, change the current character position to that
    // of the source, meaning the first character that is different from the
    // original and not already connected.
    vec[i] = source[vec[i]];
  }

  // Finally, we change the chars back to what we have in our updated vector but
  // with adding 'a' In order to get chars in the correct range back.
  for (int i = 0; i < n; i++)
    t[i] = vec[i] + 'a';

  cout << t << '\n';
}

int main() {
  int t;

  cin >> t;

  while (t--)
    solution();

  return 0;
}
