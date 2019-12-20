#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<pair<int, int>> vp;

string to_string(pair<int, int> data) {
  stringstream ss;
  ss << '{' << data.first << ", " << data.second << '}';
  return ss.str();
}
string to_string(vp data) {
  stringstream ss;
  ss << '[';
  for (auto item : data) {
    if (item != data.front()) {
      ss << ", ";
    }
    ss << to_string(item);
  }
  ss << ']';
  return ss.str();
}

int main() {
  cout << "To schedula as many events as possible (greedy):" << endl;
  vp events = {{1, 10}, {2, 3}, {4, 5}};
  cout << "events: " << to_string(events) << endl;
  auto comp = [] (const pair<int, int> a, const pair<int, int> b) {
    return a.second < b.second;
  };
  // sort by ending of events
  sort(events.begin(), events.end(), comp);
  cout << "sorted: " << to_string(events) << endl;
  vp answer;
  for (auto p : events) {
    cout << p.first << endl;
  }
}
