// not tested

#include <iostream>
#include <vector>

using namespace std;

void push_heap(vector<int>& heap, const int value)
{
    heap.push_back(value);

    int idx = heap.size() - 1;

    while(idx > 0 && heap[(idx-1) / 2] < heap[idx])
    {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void remove_heap(vector<int>& heap)
{
    heap[0] = heap.back();
    heap.pop_back();

    int cur = 0;

    while (true)
    {
        int left = cur * 2 + 1;
        int right = cur * 2 + 2;

        if (left >= heap.size()) break;

        int next = cur;
        if (heap[next] < heap[left]) next = left;

        if (right < heap.size() && heap[next] < heap[right]) next = right;

        if (next == cur) break;

        swap(heap[cur], heap[next]);
        cur = next;
    }
}