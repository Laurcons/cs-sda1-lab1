#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

// O(1)
Queue::Queue() {
	this->capacity = 3;
	this->arr = new TElem[this->capacity];
	this->start = 0;
	this->end = -1;
}

Queue::Queue(const Queue& other) {
	this->capacity = other.capacity;
	this->start = other.start;
	this->end = other.end;
	this->arr = new TElem[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->arr[i] = other.arr[i];
	}
}

Queue Queue::operator=(const Queue& other) {
	delete this->arr;
	this->capacity = other.capacity;
	this->start = other.start;
	this->end = other.end;
	this->arr = new TElem[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->arr[i] = other.arr[i];
	}
	return *this;
}

// best O(1)
// worst O(n)
// total ??
void Queue::push(TElem elem) {
	this->end++;
	// if it's the first element:
	if (this->start == 0 && this->end == 0) {
		this->arr[this->end] = elem;
		return;
	}
	// if we're out of bounds:
	if (this->end == this->capacity) {
		this->end = 0;
	}
	// if we're clashing with the first element:
	if (this->end == this->start) {
		// reallocate! restructure! overthrow the government!
		int oldCap = this->capacity;
		this->capacity *= 2;
		TElem* newArr = new TElem[this->capacity];
		this->end = this->start - 1;
		if (this->end < 0)
			this->end = oldCap - 1;
		int curr = 0;
		for (int i = this->start; ; i++) {
			if (i == oldCap)
				i = 0;
			newArr[curr++] = this->arr[i];
			if (i == this->end)
				break;
		}
		this->start = 0;
		this->end = oldCap; // should be - 1, but add 1 so that the last statement in the function works
		delete this->arr;
		this->arr = newArr;
	}
	// put the element
	this->arr[this->end] = elem;
}

// O(1)
TElem Queue::top() const {
	if (this->end == -1)
		throw std::exception("Nothing on top");
	return this->arr[this->start];
}

// O(1)
TElem Queue::pop() {
	if (this->end == -1)
		throw std::exception("Nothing to pop");
	TElem toRet = this->arr[this->start];
	if (this->start == this->end) {
		// we're now empty
		this->start = 0;
		this->end = -1;
	}
	else {
		this->start++;
		// if we've hit the out of bounds
		if (this->start == this->capacity) {
			this->start = 0;
		}
	}
	return toRet;
}

// O(1)
bool Queue::isEmpty() const {
	return this->end == -1;
}

// O(n)
Queue::~Queue() {
	delete[] this->arr;
}

