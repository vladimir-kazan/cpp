#include <iostream>
#include <vector>
#include <string>

using namespace std;

// const int n = 16; // 14772512
const int n = 4;
int col[n * n];
int diag1[n * n];
int diag2[n * n];
int cnt = 0;

void search(int y) {
  if (y == n) {
    cnt += 1;
    return;
  } else {
    for (int x = 0; x < n; x += 1) {
      if (col[x] || diag1[x + y] || diag2[x - y + n -1]) continue;
      col[x] = diag1[x + y] = diag2[x - y + n -1] = 1;
      search(y + 1);
      col[x] = diag1[x + y] = diag2[x - y + n -1] = 0;
    }
  }
}

int main() {
  cout << "Number of N=" << n << " Queens placements on NxN board:" << endl;
  search(0);
  cout << "Answer: " << cnt << endl;
  return 0;
}
