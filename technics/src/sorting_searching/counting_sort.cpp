#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

typedef vector<int> vi;

template<typename T>
string str(T vector) {
  stringstream ss;
  ss << '{';
  for (auto item : vector) {
    if (item != vector.front()) {
      ss << ", ";
    }
    ss << item;
  }
  ss << '}';
  return ss.str();
}

template<typename T>
string to_string(T begin, T end) {
  stringstream ss;
  ss << '{';
  for (auto it = begin; it != end; ++it) {
    if (it != begin) {
      ss << ", ";
    }
    ss << *it;
  }
  ss << '}';
  return ss.str();
}

// it works only for fixed size arrays
// template <typename T, size_t N> const T* mybegin(const T (&a)[N]) { return a; }
// template <typename T, size_t N> const T* myend  (const T (&a)[N]) { return a+N; }

// template<class T>
// void counting_sort(T begin, T end) {
//   auto min_max = std::minmax_element(begin, end);
//   int len = *min_max.second - *min_max.first;
//   int book[len];
//   size_t size = sizeof(book) / sizeof(*book);
//   cout << "size " << size << endl;
// }


template<class T>
void counting_sort(T begin, T end) {
  map<int, int> book; // using map here for simplicity, but slow
  for(auto it = begin; it != end; ++it) {
    book[*it]++;
  }
  auto it = begin;
  for(auto mapIt = book.begin(); mapIt != book.end(); ++mapIt) {
      int key = (*mapIt).first;
      int occurence = (*mapIt).second;
      for (int i = 0; i < occurence; i += 1) {
        *it = key;
        it += 1;
      }
  }
}

int main () {
  cout << "Counting sort O(n):" << endl;
  vi data = {10, 9, 8, -1, 0, 1, 2, 3, 1};
  cout << str(data) << endl;
  counting_sort(data.begin(), data.end());
  cout << to_string(data.begin(), data.end()) << endl;;
}
