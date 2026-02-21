// #include "../../include/data_structures/max_heap.h"
#include "max_heap.h"
#include <algorithm>
#include <stdexcept>
using namespace std;
int ProductMaxHeap::parent(int index) const
{
    return (index - 1) / 2;
}
int ProductMaxHeap::left(int index) const
{
    return (index * 2 ) + 1;
}

int ProductMaxHeap::right(int index) const
{
    return (index * 2 ) + 2;
}

void ProductMaxHeap::heapifyUp(int index)
{
    while (index > 0)
    {
        int p = parent(index);

        if (heap[index]->getSoldCount() > heap[p]->getSoldCount())
        {
            std::swap(heap[index], heap[p]);

            indexMap[heap[index]] = index;
            indexMap[heap[p]] = p;

            index = p;
        }
        else
        {
            break;
        }
    }
}

void ProductMaxHeap::heapifyDown(int index)
{
      int n = heap.size();
    while (true){
        int largest = index;
        int leftt = left(index);
        int rightt = right(index);
        if(leftt < n && heap[leftt]->getSoldCount() > heap[largest]->getSoldCount()){
            largest = leftt;
        }
        if(rightt < n&& heap[rightt]->getSoldCount() > heap[largest]->getSoldCount())
        {
            largest = rightt;
        }
        if(largest == index){
            break;
        }
        std::swap(heap[index], heap[largest]);
        indexMap[heap[index]] = index;
        indexMap[heap[largest]] = largest;
        index = largest;


        
    }
    
}

void ProductMaxHeap::insert(Product *product)
{
    heap.push_back(product);
    indexMap[product] = size() - 1;
    heapifyUp(size() - 1);
}

Product *ProductMaxHeap::top() const
{   
    if(!empty())
        return heap[0];
    else{
        throw std::runtime_error("Heap is empty");
        return nullptr;
    }
}


Product* ProductMaxHeap::extractMax()
{
    if (empty())
        throw std::runtime_error("Heap is empty");

    Product* root = heap[0];

    if (size() == 1)
    {
        heap.pop_back();
        indexMap.erase(root);
        return root;
    }

    heap[0] = heap.back();
    indexMap[heap[0]] = 0;

    heap.pop_back();
    indexMap.erase(root);

    heapifyDown(0);

    return root;
}
bool ProductMaxHeap::empty() const
{
    return heap.empty();
}

size_t ProductMaxHeap::size() const
{
    return heap.size();
}

void ProductMaxHeap::increaseKey(Product* product)
{
    auto it = indexMap.find(product);
    if (it == indexMap.end())
        throw std::runtime_error("Product not found in heap");

    heapifyUp(it->second);
}