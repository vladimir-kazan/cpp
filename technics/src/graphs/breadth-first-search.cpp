#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int N = 7;
vector<int> adj[N];

bool visited[N];
int dist[N];
queue<int> q;

void traversalBfs(int idx) {
  if (visited[idx]) {
    return;
  }
  visited[idx] = true;
  dist[idx] = 0;
  q.push(idx);
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    // process node
    cout << "Visiting node " << current;
    cout << " with distance " << dist[current] << endl;
    for (auto u : adj[current]) {
      if (visited[u]) {
        continue;
      }
      visited[u] = true;
      dist[u] += dist[current] + 1;
      q.push(u);
    }
  }
}

int main() {
  cout << "Graph Traversal – breadth first O(n + m)" << endl; // n - nodes, m - edges
  cout << "where n - nodes, m - edges:" << endl;
  cout << "1 — 2 — 3" << endl;
  cout << "|   |   |" << endl;
  cout << "4   5 — 6" << endl;
  adj[1].push_back(2);
  adj[1].push_back(4);
  adj[2].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(2);
  adj[3].push_back(6);
  adj[4].push_back(1);
  adj[5].push_back(2);
  adj[5].push_back(6);
  adj[6].push_back(3);
  adj[6].push_back(5);
  traversalBfs(1);
}
