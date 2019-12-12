#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

typedef vector<int> vi;

template<typename T>
string str(T data) {
}
template<>
string str(vi data) {
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


string ar_str(int data[], size_t size) {
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

void merge(vi& data, int a, int b, int k) {
  // We have low to mid and mid+1 to high already sorted.
  // cout << "a: "<< a << ", b: " << b << ", k: " << k << endl;
  int temp[b - a + 1];
  int i = a;
  int j = k + 1;
  int m = 0;
  while (i <= k && j <= b) {
    if (data[i] < data[j]) {
      temp[m] = data[i];
      i += 1;
    } else {
      temp[m] = data[j];
      j += 1;
    }
    m += 1;
  }

  // from i to mid into temp[]
	while (i <= k) {
		temp[m] = data[i];
		m += 1;
		i += 1;
	}

  // from j to high into temp[].
  while (j <= b) {
		temp[m] = data[j];
		m += 1;
		j += 1;
	}

  // size_t len = sizeof(temp) / sizeof(temp[0]);

  for (i = a; i <= b; i += 1) {
		data[i] = temp[i - a];
	}
}

void mergeSort(vi& data, int a, int b) {
  if (a == b) {
    return;
  }
  int k = (a + b) / 2;

  mergeSort(data, a, k);
  mergeSort(data, k + 1, b);

  merge(data, a, b, k);
}

template<class Iter>
void merge_sort_v2(Iter first, Iter last) {
  if ((last - first) > 1) {
    Iter middle = first + (last - first) / 2;
    merge_sort_v2(first, middle);
    merge_sort_v2(middle, last);
    std::inplace_merge(first, middle, last);
  }
}

int main() {
  cout << "Merge sort O(n log n):" << endl;
  vi data = {-1, 2, 4, -3, 5, 2, -5, 2};

  cout << "Before: " << str(data) << endl;
  // mergeSort(data, 0, data.size() - 1);
  mergeSort(data, 0, data.size() - 1);
  cout << "After: "  << str(data) << endl;

  cout << endl << "v2:"  << endl;
  vi data2 = {-1, 2, 4, -3, 5, 2, -5, 2};
  cout << "Before: " << str(data2) << endl;
  merge_sort_v2(data2.begin(), data2.end());
  cout << "After: "  << str(data2) << endl;
}
