#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item { int x; int y; };
bool operator==(const Item& left, const Item& right) { return left.x == right.x; }

typedef vector<Item> vItem;

vItem source = {{1}, {1}, {3}};
const int n = 3;
bool choosen[n];


vItem permutation;
void find() {
  if (permutation.size() == n) {
    cout << '[';
    for (auto& item : permutation) {
      // cout << '{' << item.x << ", " << item.y << '}';
      cout << item.x;
      cout << (&item != &permutation.back() ? ", " : "");
    }
    cout << ']' << endl;
  } else {
    for (int i = 0; i < n; i += 1) {
      if (choosen[i]) continue;
      choosen[i] = true;
      permutation.push_back(source[i]);
      find();
      choosen[i] = false;
      permutation.pop_back();
    }
  }
}

int main() {
    cout << "Find all permutations:" << endl;
    find();
    // cout << (source[0] == source[1] ? "true" : "false") << endl;
    return -1;
}

// c++ feature
// do {
//   // process
// } while (next_permutation(permutation.begin(), permutation.end()));
