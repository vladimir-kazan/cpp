// atomic_flag.cpp
#include <iostream>
#include <atomic>
#include <thread>
#include <sstream>

class SpinLock {
 std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
  // SpinLock(): flag() {}
  // SpinLock() {}

  void lock() {
    std::thread::id t_id = std::this_thread::get_id();
    std::ostringstream oss;
    oss << "Thread " << t_id << " is waiting..." << std::endl;
    while( flag.test_and_set() ) {
      std::cout << oss.str();
    };
  }

  void unlock(){
    flag.clear();
  }
};

SpinLock spin;

void workOnResource() {
  std::thread::id this_id = std::this_thread::get_id();
  std::ostringstream oss;
  oss << "Thread " << this_id << " is done." << std::endl;
  spin.lock();
  // working with shared resource
  std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(3000));
  std::cout << oss.str();
  spin.unlock();
}

int main() {
  std::cout << "Atomic flag example" << std::endl;

  std::thread t1(workOnResource);
  std::thread t2(workOnResource);

  t1.join();
  t2.join();
  // Output:
  // Atomic flag example
  // Thread 0x70000cecd000 is waiting...
  // Thread 0x70000cecd000 is waiting...
  // Thread 0x70000cecd000 is waiting...
  // Thread 0x70000cecd000 is waiting...
  // Thread 0x70000ce4a000 is done.
  // Thread 0x70000cecd000 is waiting...
  // Thread 0x70000cecd000 is done.
}
