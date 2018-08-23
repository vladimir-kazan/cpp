// atomic_bool.cpp
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <atomic>

std::atomic<bool> dataReady(false);
std::vector<int> sharedData;

void processDataWhenReady() {
  std::cout << "Waiting for data" << std::endl;
  while (!dataReady.load()){
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  sharedData[1] = 2;
  std::cout << "Work done " << std::endl;
}

void prepareData() {
  sharedData = {1, 0, 3};
  dataReady = true;
  std::cout << "Data prepared" << std::endl;
}

int main() {
  std::cout << "Example of std::atomic<bool>" << std::endl;
  std::thread t1(processDataWhenReady);
  std::thread t2(prepareData);
  t1.join();
  t2.join();

  for (auto v: sharedData) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
  return 0;
}
