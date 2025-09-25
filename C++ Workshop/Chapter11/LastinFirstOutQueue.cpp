//    FiLO Queue
//1. Write a generic stack using the generic queue as example
//2. alter pop() function to handle a lifo data structure
//3. test the stack in main
#include <iostream>
#include <memory>
#include <algorithm>

template <class T>
class filoQueue {
public:
    filoQueue() { init(); }

    explicit filoQueue(size_t numElements, const T& initialValue = T()) {
        init(numElements, initialValue);
    }

    ~filoQueue() { destroy(); }

    filoQueue(const filoQueue& q) { init(q.front(), q.back() + 1); }

    filoQueue& operator=(const filoQueue& rhs) {
        if (&rhs != this) {
            destroy();
            init(rhs.front(), rhs.back() + 1);
        }
        return *this;
    }

    T* front() { return queueData; }
    const T* front() const { return queueData; }

    T* back() { return queueDataEnd - 1; }
    const T* back() const { return queueDataEnd - 1; }

    size_t size() const { return queueDataEnd - queueData; }
    bool empty() const { return size() == 0; }


    void push(const T& element) {
        if (queueDataEnd == memLimit) {
            resize();
        }
        std::allocator_traits<std::allocator<T>>::construct(alloc, queueDataEnd++, element);
    }

    void pop() {
        if (!empty()) {
            std::allocator_traits<std::allocator<T>>::destroy(alloc, --queueDataEnd);
        }
    }

    T& top() {
        return *(queueDataEnd - 1);
    }

    const T& top() const {
        return *(queueDataEnd - 1);
    }

private:
    void init() {
        queueData = queueDataEnd = memLimit = nullptr;
    }

    void init(size_t numElements, const T& initialValue) {
        queueData = alloc.allocate(numElements);
        uninitialized_fill(queueData, queueData + numElements, initialValue);
        queueDataEnd = queueData + numElements;
        memLimit = queueDataEnd;
    }

    void init(T* front, T* back) {
        size_t size = back - front;
        queueData = alloc.allocate(size);
        queueDataEnd = std::uninitialized_copy(front, back, queueData);
        memLimit = queueData + size;
    }

    void destroy() {
        if (queueData != nullptr) {
            for (T* p = queueDataEnd; p != queueData; ) {
                std::allocator_traits<std::allocator<T>>::destroy(alloc, --p);

            }
            alloc.deallocate(queueData, memLimit - queueData);
        }
        queueData = queueDataEnd = memLimit = nullptr;
    }

    void resize() {
        size_t oldSize = size();
        size_t newSize = std::max(2 * oldSize, size_t(1));
        T* newData = alloc.allocate(newSize);
        T* newDataEnd = std::uninitialized_copy(queueData, queueDataEnd, newData);
        destroy();
        queueData = newData;
        queueDataEnd = newDataEnd;
        memLimit = queueData + newSize;
    }

    std::allocator<T> alloc;

    T* queueData;
    T* queueDataEnd;
    T* memLimit;
};

int main() {
    filoQueue<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.empty()) {
        std::cout << "Top: " << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}
