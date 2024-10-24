#include <atomic>
#include <iostream>
#include <stack>
#include <thread>

template<typename T>
class LockFreeStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    std::atomic<Node*> head;  // 원자적으로 접근해야 하는 head

public:
    LockFreeStack() : head(nullptr) {}

    // 스택에 데이터를 푸시
    void push(T value) {
        Node* new_node = new Node(value);
        new_node->next = head.load();  // 현재의 head를 새로운 노드의 next에 저장

        // CAS를 사용해 head를 안전하게 갱신
        while (!head.compare_exchange_weak(new_node->next, new_node)) {
            // 실패 시 다른 스레드가 head를 수정했으므로 다시 시도
        }
    }

    // 스택에서 데이터를 팝
    bool pop(T& result) {
        Node* old_head = head.load();

        // CAS를 사용해 head를 안전하게 갱신
        while (old_head && !head.compare_exchange_weak(old_head, old_head->next)) {
            // 실패 시 다시 시도
        }

        if (old_head == nullptr) {
            return false;  // 스택이 비어있음
        }

        result = old_head->data;
        delete old_head;  // 메모리 해제
        return true;
    }

    // 스택이 비어있는지 확인
    bool isEmpty() const {
        return head.load() == nullptr;
    }
};

using namespace std;

int main() {
    //LockFreeStack<int> stack;
    stack<int> stack;

    thread t1([&]
    {
        for (int i=0; i<100; ++i)
        {
            this_thread::sleep_for(5ms);
            stack.push(i);
        }
    });

    thread t2([&]
    {
        for (int i=0; i<100; ++i) 
        {
            this_thread::sleep_for(3ms);
            stack.push(-i);
        }
    });

    thread t3([&]
    {
        for (int i=0; i<100; ++i)
        {
            this_thread::sleep_for(1ms);
            stack.push(i);
        }
    });

    thread t4([&]
    {
        for (int i=0; i<100; ++i)
        {
            this_thread::sleep_for(2ms);
            stack.push(-i);
        }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    int value;
    int ret = 0;
    // while (stack.pop(value)) {
    //     std::cout << "Popped: " << value << std::endl;
    //     ret += value;
    // }
    while (stack.empty() == false)
    {
        auto& t = stack.top();
        stack.pop();
        ret += t;
    }

    cout << ret << endl;

    return 0;
}
