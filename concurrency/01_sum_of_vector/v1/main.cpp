#include <chrono>
#include <iostream>
#include <random>
#include <vector>

constexpr long long size = 100000000;

int main() {
  std::cout << std::endl;
  std::cout << "Generate 100 000 000 random values from 1 to 10 and summarize them." << std::endl;
  std::vector<int> randValues;
  randValues.reserve(size); // -1 second on macbook

  // random values
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(1, 10);

  const auto sta = std::chrono::steady_clock::now();
  for (long long i = 0; i < size; ++i) {
    randValues.push_back(uniformDist(engine));
  }

  // unsigned long long sum = {};
  // for (auto n: randValues) {
  //   sum += n;
  // }
  const unsigned long long sum = std::accumulate(randValues.begin(), randValues.end(), 0);

  const std::chrono::duration<double> dur =
    std::chrono::steady_clock::now() - sta;

  std::cout << "Time: " << dur.count() << " seconds" << std::endl;
  std::cout << "Result: " << sum << std::endl;
}
