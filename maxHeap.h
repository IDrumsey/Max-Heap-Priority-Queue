#pragma once

#include <iostream>

class maxHeap
{
private:
	int size;
	int capacity;

	int getRightChildIndex(int ParentIndex);
	int getLeftChildIndex(int ParentIndex);
	int getParentIndex(int ChildIndex);

	bool hasRightChild(int ParentIndex);
	bool hasLeftChild(int ParentIndex);
	bool hasParent(int ChildIndex);

	int getRightChild(int ParentIndex);
	int getLeftChild(int ParentIndex);
	int getParent(int ChildIndex);

	void swap(int index1, int index2);

	bool needToIncreaseHeapSize();

	bool isEmpty();

	void growHeap();

	void HeapifyUp();

	void HeapifyDown();

public:
	int* heapArray = new int[capacity];

	maxHeap();

	int peek();

	void insert(int key);

	int Pull();

	void Print(int index);
};


