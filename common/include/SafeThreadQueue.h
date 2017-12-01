#pragma once

#include <mutex>
#include <queue>

template <typename T>
class SafeThreadQueue {
public:
    size_t size() const {
        std::lock_guard<std::mutex> guard(mutex);
        return this->queue.size();
    }

    bool empty() const {
        std::lock_guard<std::mutex> guard(mutex);
        return this->queue.empty();
    }

    void push(const T& value) {
        std::lock_guard<std::mutex> guard(mutex);
        this->queue.push(value);
    }

    T pop() {
        std::lock_guard<std::mutex> guard(mutex);

        T result;
        if (!this->queue.empty()) {
            result = this->queue.front();
            this->queue.pop();
        } 

        return result;
    }
private:
    mutable std::mutex mutex;
    std::queue<T> queue;
};
