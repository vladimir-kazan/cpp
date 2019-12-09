#include <iostream>
#include <bitset>

using namespace std;

template<typename T>
string toBinary(const T& t) {
  int n = sizeof(T) * 8;
  string s = "";
  for (int k = n - 1; k >= 0; k -= 1) {
    s += (t & (1 << k)) ? '1' : '0';
  }
  return s;
}

void printTable(int a, int b, int result, char c) {
  cout << "  " << bitset<6>(a) << " (" << a << ')' << endl;
  cout << c << " " << bitset<6>(b) << " (" << b << ')' << endl;
  cout << "= " << bitset<6>(result) << " (" << result << ")." << endl;
}

int main() {
  cout << "Bit manipulation:" << endl << endl;

  cout << "bitset<8>(10) = " << bitset<8>(10) << endl;
  cout << "bitset<8>('a') = " << bitset<8>('a') << endl << endl;

  cout << "toBinary(10) = " << toBinary(10) << endl << endl;

  cout << "29 = " << toBinary(29) << endl;
  cout << "-30 = " << toBinary(-30) << endl;
  cout << "~29 = " << toBinary(~29) << endl << endl;

  cout << "  AND" << endl;
  printTable(22, 26, 22 & 26, '&');
  cout << endl;

  cout << "  OR" << endl;
  printTable(22, 26, 22 | 26, '|');
  cout << endl;

  cout << "  XOR" << endl;
  printTable(22, 26, 22 ^ 26, '^');
  cout << endl;

  cout << "  NOT" << endl;
  cout << "  29 = " << toBinary(29) << " (" << 29 << ')' << endl;
  cout << " ~29 = " << toBinary(~29) << " (" << ~29 << ')' << endl << endl;

  cout << "  LEFT SHIFT x << k = x * 2 ^ k" << endl;
  cout << "  3 = " << toBinary(3) << endl;
  cout << "  3 << 1 = " << (3 << 1) << "   " << toBinary(3 << 1) << endl;
  cout << "  3 << 2 = " << (3 << 2) << "  " << toBinary(3 << 2)<< endl;
  cout << "  3 << 3 = " << (3 << 3) << "  " << toBinary(3 << 3)<< endl;
  cout << endl;

  cout << "  RIGHT SHIFT x >> k = x / 2 ^ k (rounded down to int)" << endl;
  cout << "  100 = " << toBinary(100) << endl;
  cout << "  100 >> 1 = " << (100 >> 1) << "  " << toBinary(100 >> 1) << endl;
  cout << "  100 >> 2 = " << (100 >> 2) << "  " << toBinary(100 >> 2) << endl;
  cout << "  100 >> 3 = " << (100 >> 3) << "  " << toBinary(100 >> 3) << endl;
  cout << "  100 >> 4 = " << (100 >> 4) << "   " << toBinary(100 >> 4) << endl;
  cout << endl;

  cout << " BIT MASKS 1 << k" << endl;
  cout << "  check if bit #3 enabled (it starts from zero index)" << endl;
  cout << "  3 = " << "  " << toBinary(3) << endl;
  cout << "  1 << 3 = " << (1 << 3) << "  " << toBinary(1 << 3) << endl;
  cout << "  3 & (1 << 3) = " << (3 & (1 << 3)) << "  " << toBinary(3 & (1 << 3)) << endl;
  cout << "  3 & (1 << 1) = " << (3 & (1 << 1)) << "  " << toBinary(3 & (1 << 1)) << endl;
  cout << endl;

  cout << "  for 9 check if bit #3 (1 << 3) = 8 enabled" << endl;
  printTable(9, 1 << 3, 9 & (1 << 3), '&');
  cout << endl;

  cout << "  for 9 check if bit #2 (1 << 2) = 4 enabled" << endl;
  printTable(9, 1 << 2, 9 & (1 << 2), '&');
  cout << endl;

  cout << "  Built-in functions:" << endl;
  int x = 713;
  cout << "  713 = " << toBinary(713) << endl;
  cout << "  number of zeros at the beginning — __builtin_clz(x): " << __builtin_clz(x) << endl;
  cout << "  number of zeros at the end — __builtin_ctz(x): " << __builtin_ctz(x) << endl;
  cout << "  number of ones — __builtin_popcount(x): " << __builtin_popcount(x) << endl;
  cout << "  the parity (even or odd) of ones — __builtin_parity(x): " << __builtin_parity(x) << endl;
  cout << endl;

  cout << "  enable bits:" << endl;
  int x1 = 0;
  x1 |= (1<<1);
  cout << "  0 | (1<<1): " << toBinary(x1) << endl;
  x1 |= (1<<3);
  cout << "  x1 |= (1<<3): " << toBinary(x1) << endl;
  x1 |= (1<<7);
  cout << "  x1 |= (1<<7): " << toBinary(x1) << endl;
  cout << "  x1 = " << x1 << endl;
  return 0;
}
