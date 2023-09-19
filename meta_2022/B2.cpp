#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y, int R, int C) {
  return x >= 0 && x < R && y >= 0 && y < C;
}

vector<pair<int, int>>
getTreeNeighbors(int x, int y, vector<vector<char>> canvas, int R, int C) {
  vector<pair<int, int>> neighbors;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx, ny, R, C) && canvas[nx][ny] == '^') {
      neighbors.push_back({nx, ny});
    }
  }
  return neighbors;
}

int countTreeNeighbors(int x, int y, vector<vector<char>> canvas, int R,
                       int C) {
  return getTreeNeighbors(x, y, canvas, R, C).size();
}

string solution(int c) {
  int R, C;
  string ans = "Possible";
  cin >> R >> C;

  vector<vector<char>> canvas(R, vector<char>(C));
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

    int neighbor_count =
        countTreeNeighbors(tree.first, tree.second, canvas, R, C);
    if (neighbor_count < 2) {
      vector<pair<int, int>> neighbors =
          getTreeNeighbors(tree.first, tree.second, canvas, R, C);

      for (pair<int, int> neighbor : neighbors) {
        trees_to_check.push(neighbor);
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
