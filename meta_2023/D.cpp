#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

string solution(int c) {
  int N, M, Q;

  cin >> N >> M;

  int graph[N][M];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      graph[i][j] = 0;
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1][b - 1] = 1;
    graph[b - 1][a - 1] = 1;
  }

  // Make a bfs from 7.
  //
  //
  int start_node = 7;
  int end_node = 1;
  auto neighbours = graph[start_node];

  queue<pair<int, int>> q;
  map<pair<int, int>, int> freq;

  ll shortest = M * N;
  set<int> visited;

  q.push(make_pair(0, start_node));
  visited.insert(start_node);

  while (!q.empty()) {
    pair<int, int> node_pair = q.front();

    int length = node_pair.first;
    int node = node_pair.second;

    q.pop();
    auto neighbours = graph[node];

    if (node == end_node) {
      cout << length << "\n";
      if (length < shortest) {
        shortest = length;
      } else {
        if (length % 2 != shortest % 2) {
          cout << "found";
          break;
        }
      }
    }

    for (int j = 0; j < M; j++) {
      if (neighbours[j] && visited.find(j) == visited.end()) {
        freq[{node, j}]++;
        q.push({length + 1, j});
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << "[";
    for (int j = 0; j < M; j++) {
      cout << graph[i][j];
    }
    cout << "]\n";
  }

  // Essentially, we want to find paths with odd length if needed to switch
  // our parity.

  string ans = "YES";

  string output = ("Case #" + to_string(c + 1) + ": " + ans + "\n");
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
