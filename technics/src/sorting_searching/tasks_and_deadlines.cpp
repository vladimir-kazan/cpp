#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// name, duration, deadline
typedef tuple<string, int, int> task;

string to_string(vector<task>& tasks) {
  stringstream ss;
  cout << "task\tduration\tdeadline" << endl;
  for (auto t : tasks) {
    cout << get<0>(t);
    cout << "\t" << get<1>(t);
    cout << "\t\t" << get<2>(t);
    cout << endl;
  }
  return ss.str();
}

int getPoints(vector<task>& tasks) {
  int sum = 0;
  int now = 0;
  for (auto t : tasks) {
    int duration = get<1>(t);
    int deadline = get<2>(t);
    now += duration;
    sum += (deadline - now);

  }
  return sum;
}

int main() {
  cout << "Tasks and Deadlines:" << endl;
  cout << "d - deadline, x - end time of a task" << endl;
  cout << "(d - x) = points to maximize" << endl;
  // choose the order to perform tasks
  // deadline, durations (d-x) = points
  // where d - deadline, x - end time;
  vector<task> tasks;
  tasks.push_back({"A", 4, 2});
  tasks.push_back({"B", 3, 10});
  tasks.push_back({"C", 2, 8});
  tasks.push_back({"D", 4, 15});
  cout << endl << to_string(tasks);
  cout << "points: " << getPoints(tasks) << endl;

  // sort tasks by duration in increasing order
  auto comp = [](const task a, const task b) {
    return get<1>(a) < get<1>(b);
  };
  sort(tasks.begin(), tasks.end(), comp);
  cout << endl << "sorted by duration:" << endl;
  cout << to_string(tasks);
  cout << "points: " << getPoints(tasks) << endl;
}
