#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

struct point {
  int x, y;
  bool operator<(const point &p) const {
    if (x == p.x) return y < p.y;
    else return x < p.x;
  }

};

template<typename T>
string to_string(T data) {
  stringstream ss;
  ss << '{';
  for (auto item :  data) {
    if (item != data.front()) {
      ss << ", ";
    }
    ss << item;
  }
  ss << '}';
  return ss.str();
}
string to_string(vector<point> data) {
  stringstream ss;
  ss << '[';
  int cnt = 0;
  for (auto item :  data) {
    // if (item != data.front()) {
    //   ss << ", ";
    // }
    if (cnt > 0) {
      ss << ", ";
    }
    cnt += 1;
    ss << "{ x: " << item.x << ", y: " << item.y << " }";
  }
  ss << ']';
  return ss.str();
}
string to_string(vector<pair<int, int>> data) {
  stringstream ss;
  ss << '[';
  for (auto item :  data) {
    if (item != data.front()) {
      ss << ", ";
    }
    ss << '(' << item.first << ", " << item.second << ')';
  }
  ss << ']';
  return ss.str();
}
string to_string(vector<tuple<int, int, int>> data) {
  stringstream ss;
  ss << '[';
  for (auto item :  data) {
    if (item != data.front()) {
      ss << ", ";
    }
    ss << '(' << get<0>(item) << ", " << get<1>(item) << ", " << get<2>(item) << ')';
  }
  ss << ']';
  return ss.str();
}
string to_string(int data[], size_t size) {
  stringstream ss;
  ss << '{';
  for (int i = 0; i < size; i += 1) {
    if (i != 0) {
      ss << ", ";
    }
    ss << data[i];
  }
  ss << '}';
  return ss.str();
}

int main() {
  cout << "Vector operations:" << endl;
  vi v1 = {1, 2, 3, 4, -1};
  cout << "initial: " << to_string(v1) << endl;
  sort(v1.begin(), v1.end());
  cout << "sort(v1.begin(), v1.end()): " << to_string(v1) << endl;
  sort(v1.rbegin(), v1.rend());
  cout << "sort(v1.rbegin(), v1.rend()): " << to_string(v1) << endl;

  string myStr = "bca";
  sort(myStr.begin(), myStr.end());
  cout << "sort(myStr.begin(), myStr.end()): " << myStr << endl;

  int n = 7;
  int a[] = {2, 4, 1, 1, 0, -1, 100};
  cout << endl << "sort array: " << to_string(a, n) << endl;
  sort(a, a + n);
  cout << "sort(a, a + n): " << to_string(a, n) << endl;

  vector<pair<int, int>> vPairs;
  vPairs.push_back({1, 5});
  vPairs.push_back({2, 3});
  vPairs.push_back({1, 2});
  cout << endl << "sort pairs: " << to_string(vPairs) << endl;
  sort(vPairs.begin(), vPairs.end());
  cout << "sort(vPairs.begin(), vPairs.end()): " << to_string(vPairs) << endl;


  vector<tuple<int, int, int>> vTuples;
  vTuples.push_back({2, 1, 4});
  vTuples.push_back({7, 1, 3});
  vTuples.push_back({2, 1, 3});
  cout << endl << "sort tuples: " << to_string(vTuples) << endl;
  sort(vTuples.begin(), vTuples.end());
  cout << "sort(vTuples.begin(), vTuples.end()): " << to_string(vTuples) << endl;

  vector<point> vPoints;
  point p1 = {1, 1};
  point p2 = {1, -1};
  vPoints.push_back(p1);
  vPoints.push_back(p2);
  vPoints.push_back((point){-1, 0});
  cout << endl << "sort structures with operator <: " << to_string(vPoints) << endl;
  sort(vPoints.begin(), vPoints.end());
  cout << "sort(vPoints.begin(), vPoints.end()): " << to_string(vPoints) << endl;

  vector<string> vStrings;
  vStrings.push_back("aaaa");
  vStrings.push_back("ddd");
  vStrings.push_back("cc");
  vStrings.push_back("b");
  cout << endl << "with compare function: " << to_string(vStrings) << endl;
  sort(vStrings.begin(), vStrings.end(),
    [](const string& a, const string& b) { return a.size() < b.size(); });
  cout << "sort(vStrings.begin(), vStrings.end(), comp): " << to_string(vStrings) << endl;
}
