#include "../../include/data_structures/StablePriorityQueue.h"
#include <algorithm>
#include <stdexcept>
using namespace std;

bool OrderPriorityQueue::empty() const
{
    return heap.empty();
}

size_t OrderPriorityQueue::size() const
{
    return heap.size();
}

void OrderPriorityQueue::push(const Order& order)
{
    heap.push_back( order );
    heapifyUp(size() -1);
}

Order OrderPriorityQueue::pop()
{
    if (heap.empty()) {
        throw std::runtime_error("Priority queue is empty");
    }

    Order root = heap[0];

    if (heap.size() == 1) {
        heap.pop_back();
        return root;
    }

    heap[0] = heap.back();
    heap.pop_back();

    heapifyDown(0);

    return root;
}


Order OrderPriorityQueue::top() const
{
    if(!empty())
    return heap.at(0);
    else
    throw std::runtime_error("Priority queue is empty");

}

bool OrderPriorityQueue::comparator(const Order& a, const Order& b)const
{
    return (a.getFrozenScore() > b.getFrozenScore()) ||
       (a.getFrozenScore() == b.getFrozenScore() &&
        a.getTimeStamp() < b.getTimeStamp());
}

void OrderPriorityQueue::heapifyUp( int index)
{
    
    while (index > 0)
    {    
        int parent = (index -1) / 2; 
        if(comparator(heap.at(index), heap.at(parent))){
                swap(heap.at(index), heap.at(parent));
                index = parent;
        }
        else{
            break;
        }

    }
    
}

void OrderPriorityQueue::heapifyDown(int index)
{
    int n = heap.size();

    while (true)
    {
        int left  = 2 * index + 1;
        int right = 2 * index + 2;

        int largest = index;

        if (left < n && comparator(heap[left], heap[largest]))
        {
            largest = left;
        }

        if (right < n && comparator(heap[right], heap[largest]))
        {
            largest = right;
        }

        if (largest == index)
        {
            break;
        }

        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}

