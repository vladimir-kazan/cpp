// mutex.cpp
#include <iostream>
#include <mutex>
#include <thread>
#include <sstream>

std::mutex mut;

void workOnResource() {
  std::ostringstream started;
  started << std::this_thread::get_id() << " – is started" << std::endl;
  std::cout << started.str();

  mut.lock(); // it doesn't load a processor
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  mut.unlock();

  std::cout << std::this_thread::get_id() << " – work done" << std::endl;
}

int main() {
  std::cout << "Mutex example." << std::endl;
  std::thread t1(workOnResource);
  std::thread t2(workOnResource);

  t1.join();
  t2.join();
  return 0;
}
