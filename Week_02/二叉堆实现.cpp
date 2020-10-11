#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef struct biHeap biHeap;
struct biHeap { //小顶堆未实现
    vector<int> heap;
    bool is_big_heap;
    int total_size;
    int cur_size;

    biHeap() {
        is_big_heap = true;
        total_size = 0;
        cur_size = 0;
    }
    biHeap(const biHeap& BH) {
        is_big_heap = BH.is_big_heap;
        heap.resize(BH.heap.size());
        for (int i = 0; i < heap.size(); i++) {
            heap[i] = BH.heap[i];
        }
        total_size = BH.total_size;
        cur_size = BH.total_size;
    }
    int parent(int index) {
        if (index == 0) return -1;
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return (2 * index + 1);
    }

    int rightChild(int index) {
        return (2 * index + 2);
    }

    void heapifyUp(int index) {
        int insertValue = heap[index];
        while (index > 0 && heap[index] > heap[parent(index)]) {
            heap[index] = heap[parent(index)];
            index = parent(index);
        }
        heap[index] = insertValue;
    }

    void insert_node(int value) {
        if (cur_size == total_size) {
            heap.push_back(value);
            cur_size++;
            total_size++;
            heapifyUp(cur_size - 1);
        }
        else {
            heap[cur_size] = value;
            cur_size++;
            heapifyUp(cur_size - 1);
        }
    }

    int maxChild(int index) {
        if (index < 0 || index >= cur_size) return -1;
        if (leftChild(index) < cur_size && rightChild(index) >= cur_size) {
            return leftChild(index);
        }
        else return (heap[leftChild(index)] >= heap[rightChild(index)] ? heap[leftChild(index)] : heap[rightChild(index)]);
    }

    void heapifyDown(int index) {
        int child;
        int temp = heap[index];
        while (leftChild(index) < cur_size) {
            child = maxChild(index);
            if (temp >= heap[child]) break;
            heap[index] = heap[child];
            index = child;
        }
        heap[index] = temp;
    }

    bool delete_node(int value) {
        int index = search_node(value);
        if (index == -1) return false;
        heap[index] = heap[cur_size - 1];
        cur_size--;
        heapifyDown(index);
        return true;
    }

    int search_node(int value, int index = 0) {
        if (index < 0) return -1;
        if (index >= cur_size) return -1;
        if (heap[index] == value) return index;
        int ans1 = search_node(value, leftChild(index));
        int ans2 = search_node(value, rightChild(index));
        if (ans1 == -1 && ans2 != -1) return ans2;
        else if (ans1 != -1 && ans2 == -1) return ans1;
        else if (ans1 == -1 && ans2 == -1) return -1;
        else return ans1;
    }

    int getTop() {
        if (cur_size == 0) return INT_MIN;
        return heap[0];
    }
};