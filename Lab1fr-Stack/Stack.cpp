#include "Stack.h"
#include <exception>
#include <limits>
#pragma warning( disable: 6386 )

using namespace std;

// O(1)
Stack::Stack() {
	// init memory for the array
	this->capacity = 3;
	this->size = 0;
	this->arr = new TElem[this->capacity];
}

// best O(1)
// worst O(n)
// average O(log n) ?
void Stack::push(TElem e) {
	// add new element
	// allocate new memory if needed
	if (this->size == this->capacity) {
		this->capacity *= 2;
		TElem* newArr = new TElem[this->capacity];
		// copy old elements
		for (size_t i = 0; i < this->size; i++)
			newArr[i] = this->arr[i];
		delete[] this->arr;
		this->arr = newArr;
	}
	this->arr[this->size++] = e;
}

// O(1)
TElem Stack::top() const {
	if (this->size == 0)
		throw exception("Nothing on top");
	return this->arr[this->size - 1];
}

// O(1)
TElem Stack::pop() {
	if (this->size == 0)
		throw exception("Nothing to pop");
	this->size--;
	return this->arr[this->size];
}

// O(1)
bool Stack::isEmpty() const {
	return this->size == 0;
}

// O(1)
Stack::~Stack() {
	delete[] this->arr;
}

// lab LIVE assignment
// worst O(n + n)
// best O(n)
TElem Stack::popMinimum() {
	if (this->isEmpty())
		throw exception("Nothing to pop");
	// find the minimum element
	int min, mini;
	min = INT_MAX;
	mini = -1; // will never be -1 at the end
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] < min) {
			min = this->arr[i];
			mini = i;
		}
	}
	TElem element = this->arr[mini];
	// remove it
	// keep the order of the underlying array
	for (int i = mini; i < this->size - 1; i++) {
		this->arr[i] = this->arr[i + 1];
	}
	this->size--;
	// return
	return element;
}