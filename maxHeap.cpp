#include "maxHeap.h"
using namespace std;

int maxHeap::getRightChildIndex(int ParentIndex)
{
	return ParentIndex * 2 + 2;
}

int maxHeap::getLeftChildIndex(int ParentIndex)
{
	return ParentIndex * 2 + 1;
}

int maxHeap::getParentIndex(int ChildIndex)
{
	return (ChildIndex - 1) / 2;
}

bool maxHeap::hasRightChild(int ParentIndex)
{
	return getRightChildIndex(ParentIndex) < size;
}

bool maxHeap::hasLeftChild(int ParentIndex)
{
	return getLeftChildIndex(ParentIndex) < size;
}

bool maxHeap::hasParent(int ChildIndex)
{
	return getParentIndex(ChildIndex) >= 0;
}

int maxHeap::getRightChild(int ParentIndex)
{
	return heapArray[getRightChildIndex(ParentIndex)];
}

int maxHeap::getLeftChild(int ParentIndex)
{
	return heapArray[getLeftChildIndex(ParentIndex)];
}

int maxHeap::getParent(int ChildIndex)
{

	return heapArray[getParentIndex(ChildIndex)];
}

void maxHeap::swap(int index1, int index2)
{
	int temp = heapArray[index1];
	heapArray[index1] = heapArray[index2];
	heapArray[index2] = temp;
}

bool maxHeap::needToIncreaseHeapSize()
{
	if (size == capacity) return 1;
	else return 0;
}

bool maxHeap::isEmpty()
{
	return size == 0;
}

void maxHeap::growHeap()
{
	//Copy curr arr into new bigger arr
	int* newHeap = new int[capacity + 5];
	for (int i = 0; i < capacity; i++) {
		newHeap[i] = heapArray[i];
	}
	delete heapArray;
	heapArray = newHeap;

	capacity += 5;
}

void maxHeap::HeapifyUp()
{
	//move upward until at correct position
	int last = size-1;
	while (hasParent(last) && getParent(last) < heapArray[last]) {
		swap(getParentIndex(last), last);
		last = getParentIndex(last);
	}
}

void maxHeap::HeapifyDown()
{	
	//move downward until at correct position
	int first = 0;
	while (hasLeftChild(first)) {
		int largerIndex = getLeftChildIndex(first);
		if (getRightChild(first) > heapArray[largerIndex]) {
			largerIndex = getRightChildIndex(first);
		}

		if (heapArray[first] < heapArray[largerIndex]) {
			//Switch
			swap(first, largerIndex);
			first = largerIndex;
		}
		else break;
	}
}

//Constructor
maxHeap::maxHeap()
{
	cout << "New Heap Created!\n";
	size = 0;
	capacity = 10;
}

int maxHeap::peek()
{
	if (size == 0) {
		cout << "Heap Empty!";
	}
	else {
		return heapArray[0];
	}
}

void maxHeap::insert(int key)
{
	//Check if empty
	if (isEmpty()) {
		heapArray[0] = key;
		size++;
	}
	else {
		//check if needing more room
		if (needToIncreaseHeapSize()) {
			growHeap();
		}
		heapArray[size] = key;

		size++;

		//sift
		HeapifyUp();
	}

}

int maxHeap::Pull()
{
	//Pull out root
	int root = heapArray[0];

	//Switch
	heapArray[0] = heapArray[size - 1];

	//Decrease size
	size--;

	//sift downwards
	HeapifyDown();

	return root;
}

void maxHeap::Print(int index)
{
	//Recursive PreOrder printing method
	if (hasLeftChild(index)) {
		Print(getLeftChildIndex(index));
		if (hasRightChild(index)) {
			Print(getRightChildIndex(index));
		}
	}
	cout << heapArray[index] << " ";
}

