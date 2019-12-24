#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string to_string(vector<int>& data) {
  stringstream ss;
  ss << '{';
  for (auto item : data) {
    if (item != data.front()) {
      ss << ", ";
    }
    ss << item;
  }
  ss << '}';
  return ss.str();
}

int main() {
  cout << "Binary search:" << endl;

  vector<int> data = {1, 3, 3, 4, 5, 5, 6, 9, 10, 12, 12, 15};
  int n = data.size();
  cout << "data: " << to_string(data) << ", n = " << n << endl;
  int x = 9;
  cout << "x: " << x << endl;

  int a = 0, b = n - 1;
  cout << endl << "method #1 with O(log n), split array on each step:" << endl;
  while (a <= b) {
    int k = (a + b) / 2;
    cout << "current pointer: " << k << ", value: " << data[k] << endl;
    if (data[k] == x) {
      cout << "found " << x << " at position: " << k << endl;
      break;
    }
    if (data[k] < x) a = k + 1;
    else b = k - 1;
  }

  cout << endl << "method #2 with O(log n), calculating index with jumps:" << endl;
  int k = 0;
  for (int b = n / 2; b >= 1; b /= 2) {
    cout << "current jump size: " << b << endl;
    while (k + b < n && data[k + b] <= x) {
      k += b;
      cout <<  "  offset: " << k << ", value: " << data[k] << endl;
    }
  }
  if (data[k] == x) {
     cout << "found " << x << " at position: " << k << endl;
  }
  return 0;
}
