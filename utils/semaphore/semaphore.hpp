#ifndef SEMAPHORE_HPP_
#define SEMAPHORE_HPP_
#include <condition_variable>
#include <mutex>

namespace naby {
class Semaphore {
private:
  std::condition_variable condition_;
  mutable std::mutex mutex_;
  int32_t count_;

public:
  explicit Semaphore(int32_t count = 0);
  ~Semaphore();

  void Signal();
  void Wait();
  int32_t Count() const;
};

Semaphore::Semaphore(int count) : count_(count) {}

Semaphore::~Semaphore() {}

void Semaphore::Signal() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (++count_ <= 0) {
    condition_.notify_one();
  }
}

void Semaphore::Wait() {
  std::unique_lock<std::mutex> lock(mutex_);
  if (--count_ < 0)
    condition_.wait(lock);
}

int32_t Semaphore::Count() const {
  std::lock_guard<std::mutex> lock(mutex_);
  return count_;
}

} // namespace naby

#endif