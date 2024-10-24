#include <atomic>
#include <iostream>
#include <queue>
#include <thread>

template<typename T>
class LockFreeQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:
    LockFreeQueue() {
        Node* dummy = new Node(T{});  // 더미 노드 사용
        head.store(dummy);
        tail.store(dummy);
    }

    ~LockFreeQueue() {
        while (Node* node = head.load()) {
            head.store(node->next);
            delete node;
        }
    }

    // 큐에 데이터를 삽입
    void enqueue(T value) {
        Node* new_node = new Node(value);
        Node* old_tail = tail.load();

        while (!tail.compare_exchange_weak(old_tail, new_node)) {
            // 실패 시 tail을 다시 로드하고 반복 시도
        }

        old_tail->next = new_node;  // 원자적으로 tail을 업데이트
    }

    // 큐에서 데이터를 제거
    bool dequeue(T& result) {
        Node* old_head = head.load();
        Node* next_node = old_head->next;

        if (next_node == nullptr) {
            return false;  // 큐가 비어있음
        }

        result = next_node->data;

        // CAS를 사용하여 head를 안전하게 갱신
        if (head.compare_exchange_strong(old_head, next_node)) {
            delete old_head;  // 더미 노드를 해제
            return true;
        }

        return false;
    }

    // 큐가 비어있는지 확인
    bool isEmpty() const {
        return head.load()->next == nullptr;
    }
};

using namespace std;

int main() {
    LockFreeQueue<int> queue;

    thread t1([&]
    {
        for (int i=0; i<100; ++i)
        {
            this_thread::sleep_for(5ms);
            queue.enqueue(i);
        }
    });

    thread t2([&]
    {
        for (int i=0; i<100; ++i) 
        {
            this_thread::sleep_for(3ms);
            queue.enqueue(-i);
        }
    });

    thread t3([&]
    {
        for (int i=0; i<100; ++i)
        {
            this_thread::sleep_for(1ms);
            queue.enqueue(i);
        }
    });

    thread t4([&]
    {
        for (int i=0; i<100; ++i)
        {
            this_thread::sleep_for(2ms);
            queue.enqueue(-i);
        }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    int value;
    int ret = 0;
    while (queue.dequeue(value)) {
        std::cout << "Dequeued: " << value << std::endl;
        ret += value;
    }

    cout << ret << endl;

    return 0;
}
