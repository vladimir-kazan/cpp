#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;

template<typename T>
string str(T data) {
  stringstream ss;
  ss << '{';
  for (auto& item : data) {
    ss << item;
    ss << (&item != &data.back() ? ", ": "");
  }
  ss << '}';
  return ss.str();
}

int main() {
  cout << "Bubble sort O(n^2):" << endl;
  vi data = {1, 3, 8, 2, 9, 2, 5, 6};
  cout << str(data) << endl;
  for (int i = 0; i < data.size(); i += 1) {
    for (int j = 0; j < data.size() - 1; j += 1) {
      if (data[j] > data[j + 1]) {
        swap(data[j], data[j + 1]);
      }
    }
  }
  cout << str(data) << endl;
}
