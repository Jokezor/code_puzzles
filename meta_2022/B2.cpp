#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int R, C;
  string ans = "Possible";
  cin >> R >> C;

  char canvas[R][C];
  set<pair<int, int>> original_trees;

  // Read and set all trees possible
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> canvas[i][j];
      if (canvas[i][j] == '^') {
        original_trees.insert({i, j});
      }
      if (canvas[i][j] != '#') {
        canvas[i][j] = '^';
      }
    }
  }

  // Make a queue to check for neighbors
  queue<pair<int, int>> trees_to_check;

  // Add all trees
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (canvas[i][j] == '^') {
        trees_to_check.push({i, j});
      }
    }
  }

  while (!trees_to_check.empty()) {
    pair<int, int> tree = trees_to_check.front();
    trees_to_check.pop();

    int neighbor_count = 0;
    // Down
    if (tree.first + 1 < R) {
      if (canvas[tree.first + 1][tree.second] == '^') {
        neighbor_count++;
      }
    }
    // Up
    if (tree.first != 0) {
      if (canvas[tree.first - 1][tree.second] == '^') {
        neighbor_count++;
      }
    }
    // left
    if (tree.second != 0) {
      if (canvas[tree.first][tree.second - 1] == '^') {
        neighbor_count++;
      }
    }
    // right
    if (tree.second + 1 < C) {
      if (canvas[tree.first][tree.second + 1] == '^') {
        neighbor_count++;
      }
    }

    if (neighbor_count < 2) {
      if (tree.first + 1 < R) {
        if (canvas[tree.first + 1][tree.second] == '^') {
          trees_to_check.push({tree.first + 1, tree.second});
        }
      }
      // Up
      if (tree.first != 0) {
        if (canvas[tree.first - 1][tree.second] == '^') {
          trees_to_check.push({tree.first - 1, tree.second});
        }
      }
      // left
      if (tree.second != 0) {
        if (canvas[tree.first][tree.second - 1] == '^') {
          trees_to_check.push({tree.first, tree.second - 1});
        }
      }
      // right
      if (tree.second + 1 < C) {
        if (canvas[tree.first][tree.second + 1] == '^') {
          trees_to_check.push({tree.first, tree.second + 1});
        }
      }
      if (original_trees.find(tree) != original_trees.end()) {
        ans = "Impossible";
        break;
      }
      canvas[tree.first][tree.second] = '.';
    }
  }

  string output = ("Case #" + to_string(c + 1) + ": " + ans + "\n");
  if (ans == "Possible") {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        output += canvas[i][j];
      }
      output += "\n";
    }
  }

  cout << output;

  return output;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ofstream MyFile("output.txt");

  int t;
  cin >> t;

  for (int c = 0; c < t; c++) {
    MyFile << solution(c);
  }
  MyFile.close();
}
