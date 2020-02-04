#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 6;
vector<int> adj[N];

bool visited[N];

void traversalDfs(int searchIdx) {
  if (visited[searchIdx]) {
    return;
  }
  visited[searchIdx] = true;
  // process node
  cout << "visiting node: " << searchIdx << endl;
  for (auto u: adj[searchIdx]) {
    traversalDfs(u);
  }
}

int main() {
  cout << "Graph Traversal – depth first O(n + m)" << endl; // n - nodes, m - edges
  cout << "where n - nodes, m - edges:" << endl;
  cout << "1 — 2 — 3" << endl;
  cout << "|   |  /" << endl;
  cout << "4    5" << endl;
  adj[1].push_back(2);
  adj[1].push_back(4);
  adj[2].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(2);
  adj[3].push_back(5);
  adj[4].push_back(1);
  adj[5].push_back(3);
  adj[5].push_back(2);
  traversalDfs(1);
}
