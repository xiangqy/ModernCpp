#include "semaphore.hpp"
#include <iostream>
#include <queue>
#include <thread>

std::mutex g_mutex;
std::queue<int> g_queue;
naby::Semaphore g_semaphore;
bool g_exit = false;

void simulate_customer() {
  int queue_data;
  while (!g_exit) {
    g_semaphore.Wait();
    {
      std::lock_guard<std::mutex> lock(g_mutex);
      queue_data = g_queue.front();
      g_queue.pop();
    }

    std::cout << queue_data << std::endl;
  }
}

void simulate_productor() {
  int index = 0;
  while (!g_exit) {
    {
      std::lock_guard<std::mutex> lock(g_mutex);
      g_queue.push(index++);
    }
    g_semaphore.Signal();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

int main(int argc, char **argv) {
  std::thread customer_thread(simulate_customer);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 10));
  std::thread productor_thread(simulate_productor);

  char ch;
  while (true) {
    ch = std::cin.get();
    if (ch == 'x') {
      g_exit = true;

      productor_thread.join();
      g_semaphore.Signal();
      customer_thread.join();
    }
  }
  return 0;
}