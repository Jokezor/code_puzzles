#include <bits/stdc++.h>

using namespace std;

int manhattan_distance(pair<int, int> p1, pair<int, int> p2) {
  return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void solution() {
  int R, C;

  cin >> R >> C;

  char B[R][C];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> B[i][j];
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int bomb_power = B[i][j] - '0';
      if (bomb_power <= 9 && bomb_power >= 1) {
        // Explode the bomb.
        B[i][j] = '.';
        // Need to search [i - bomb_power, i + bomb_power] and [j - bomb_power,
        // j + bomb_power]
        int left = max(i - bomb_power, 0);
        int right = min(i + bomb_power, R - 1);
        int up = max(j - bomb_power, 0);
        int down = min(j + bomb_power, C - 1);

        // Check left
        for (int r = i; r >= left; r--) {
          // Check up
          for (int c = j; c >= up; c--) {
            if (isdigit(B[r][c])) {
              continue;
            }
            if (manhattan_distance(make_pair(r, c), make_pair(i, j)) <=
                bomb_power) {
              B[r][c] = '.';
            }
          }

          // Check down
          for (int c = j; c <= down; c++) {
            if (isdigit(B[r][c])) {
              continue;
            }
            if (manhattan_distance(make_pair(r, c), make_pair(i, j)) <=
                bomb_power) {
              B[r][c] = '.';
            }
          }
        }

        // Check right
        for (int r = i; r <= right; r++) {
          // Check up
          for (int c = j; c >= up; c--) {
            if (isdigit(B[r][c])) {
              continue;
            }

            if (manhattan_distance(make_pair(r, c), make_pair(i, j)) <=
                bomb_power) {
              B[r][c] = '.';
            }
          }

          // Check down
          for (int c = j; c <= down; c++) {
            if (isdigit(B[r][c])) {
              continue;
            }

            if (manhattan_distance(make_pair(r, c), make_pair(i, j)) <=
                bomb_power) {
              B[r][c] = '.';
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << B[i][j];
    }
    cout << "\n";
  }
}

/*
for (int r = 0; r < bomb_power + 4; r++) {
          for (int c = 0; c < bomb_power + 4; c++) {
            if (manhattan_distance(make_pair(i + r, j + c), make_pair(i, j)) <=
                bomb_power) {
              if (i + r < R && j + c < C &&
                  ((B[i + r][j + c] - '0' < 0) || (B[i + r][j + c] - '0' > 9) ||
                   (r == 0 && c == 0))) {

                B[i + r][j + c] = '.';
              }
            }
            if (manhattan_distance(make_pair(i + r, j), make_pair(i, j)) <=
                bomb_power) {
              if (i + r < R &&
                  ((B[i + r][j] - '0' < 0) || (B[i + r][j] - '0' > 9) ||
                   (r == 0 && c == 0))) {

                B[i + r][j] = '.';
              }
            }
            if (manhattan_distance(make_pair(i, j + c), make_pair(i, j)) <=
                bomb_power) {
              if (j + c < C &&
                  ((B[i][j + c] - '0' < 0) || (B[i][j + c] - '0' > 9) ||
                   (r == 0 && c == 0))) {

                B[i][j + c] = '.';
              }
            }
            if (manhattan_distance(make_pair(i - r, j), make_pair(i, j)) <=
                bomb_power) {
              if (i - r < R &&
                  ((B[i - r][j] - '0') < 0 || (B[i - r][j] - '0') > 9 ||
                   (r == 0 && c == 0))) {

                B[i - r][j] = '.';
              }
            }
            if (manhattan_distance(make_pair(i, j - c), make_pair(i, j)) <=
                bomb_power) {
              if (j - c < C &&
                  ((B[i][j - c] - '0' < 0) || (B[i][j - c] - '0' > 9) ||
                   (r == 0 && c == 0))) {

                B[i][j - c] = '.';
              }
            }
            if (manhattan_distance(make_pair(i - r, j - c), make_pair(i, j)) <=
                bomb_power) {
              if (i - r >= 0 && j - c >= 0 &&
                  ((B[i - r][j - c] - '0') < 0 || (B[i - r][j - c] - '0') > 9 ||
                   (r == 0 && c == 0))) {
                B[i - r][j - c] = '.';
              }
            }
          }
        }
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
