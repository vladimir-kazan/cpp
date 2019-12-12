#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

typedef vector<int> vi;

template<typename T>
string str(T begin, T end)
{
    stringstream ss;
    bool first = true;
    ss << '{';
    for (; begin != end; begin++)
    {
        if (!first)
            ss << ", ";
        ss << *begin;
        first = false;
    }
    ss << '}';
    return ss.str();
}


int main() {
  cout << "Max subarray sum O(n):" << endl;
  vi data = {-1, 2, 4, -3, 5, 2, -5, 2};
  cout << str(data.begin(), data.end()) << endl;
  int best = 0, sum =0;
  for (int i = 0; i < data.size(); i += 1) {
    sum = max(data[i], sum + data[i]);
    best = max(best, sum);
  }
  cout << "max sum: " << best << endl;
  return 0;
}
