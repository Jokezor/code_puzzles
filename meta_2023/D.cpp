#include <bits/stdc++.h>
#include <fstream>

#define ll long long

using namespace std;

typedef vector<vector<int>> Matrix;

int count_repeated_edges(vector<int> path) {
  int repeated_edges = 0;

  if (path.size() < 1) {
    return -1;
  }
  set<pair<int, int>> edges;

  for (int i = 0; i < path.size() - 1; i++) {
    if (edges.find({path[i], path[i + 1]}) != edges.end()) {
      repeated_edges++;
    }
    edges.insert({path[i], path[i + 1]});
    edges.insert({path[i + 1], path[i]});
  }

  return repeated_edges;
}

vector<int> find_shortest_path(int M, int N, Matrix graph, int start_node,
                               int end_node) {
  queue<vector<int>> q;

  ll shortest = 100000000;
  set<int> visited;
  vector<int> shortest_path;

  q.push(vector<int>{start_node});
  visited.insert(start_node);

  while (!q.empty()) {
    vector<int> path = q.front();
    q.pop();

    int length = path.size() - 1;
    int node = path.back();

    visited.insert(node);

    vector<int> neighbours = graph[node];

    if (node == end_node) {
      shortest = length;
      shortest_path = path;
      break;
    }

    for (int neighbour : neighbours) {
      if (visited.find(neighbour) == visited.end()) {
        vector<int> neighbour_path(path);
        neighbour_path.push_back(neighbour);
        q.push(neighbour_path);
      }
    }
  }
  return shortest_path;
}

int find_repeated_edges_in_shortest_odd_parity_path(int M, int N, Matrix graph,
                                                    int start_node,
                                                    int end_node,
                                                    int shortest) {
  // How to find if there is none?
  queue<vector<int>> q;
  set<int> visited;
  set<pair<int, int>> edges_used;
  vector<int> my_path;
  int min_edges = -1;

  q.push(vector<int>{start_node, 0, 0});
  visited.insert(start_node);

  // How many paths to wait for?
  // Maybe we can control how many edges can be repeated?
  // So first it finds the one with no repeated,
  // Then I increase so it can find 1 repeated etc.
  // Maybe with a frequency counter or multiset?
  int allowed_duplicates = 0;

  while (!q.empty()) {
    vector<int> node_info = q.front();
    q.pop();

    int node = node_info[0];
    int length = node_info[1];
    int repeated_edges = node_info[2];

    if (length >= 2 * M) {
      break;
    }

    if (node == end_node && (length % 2) != (shortest % 2)) {
      // cout << node << " " << length << " " << repeated_edges << "\n";
      if (min_edges == -1 || repeated_edges < min_edges) {
        min_edges = repeated_edges;
      }
    }

    if (length >= M) {
      break;
    }

    vector<int> neighbours = graph[node];
    for (int neighbour : neighbours) {
      if (visited.find(neighbour) == visited.end()) {
        vector<int> new_node_info = {neighbour, length + 1, repeated_edges};
        // This assumes we need to count using the same edge more than once
        if (edges_used.find({node, neighbour}) == edges_used.end() &&
            edges_used.find({neighbour, node}) != edges_used.end()) {
          new_node_info[2]++;
        }
        edges_used.insert({node, neighbour});
        q.push(new_node_info);
      }
    }
  }
  return min_edges;
}

string solution(int c) {
  int N, M, Q, ans = 0;

  cin >> N >> M;

  vector<vector<int>> graph(N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int start_node, end_node;
    cin >> start_node >> end_node;

    start_node--;
    end_node--;

    // Lets first just find the parity of the shortest path.
    vector<int> shortest_path =
        find_shortest_path(M, N, graph, start_node, end_node);

    // cout << shortest_path.size() - 1 << "\n";

    int repeated_edges = find_repeated_edges_in_shortest_odd_parity_path(
        M, N, graph, start_node, end_node, shortest_path.size() - 1);

    cout << repeated_edges << "\n";
    ans += repeated_edges;
  }

  // Now search for different parity path
  // So now we could take the assumption that the first walk with different
  // parity has the least repeated edges. This is not something I'm sure we can
  // count on though.
  //
  // Seems we need to count more paths.
  // I could record the best path directly in the BFS.
  // With the count of repeated edges, I would then check if it increases.

  string output = ("Case #" + to_string(c + 1) + ": " + to_string(ans) + "\n");
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
