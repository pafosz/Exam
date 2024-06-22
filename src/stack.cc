#include <iostream>


template<class T>
class LStack {
	struct Node {
		T data;
		Node* next;
		Node(): data{}, next(nullptr){}
		Node(const T& value, Node* next): data(value), next(next){}

	};
	Node* _top;
	size_t _size;

public:
	LStack(): _top(nullptr), _size(0){}
	~LStack() {
		while (_top) {
			pop();
		}
	}
	void push(const T& value) {
		Node* newNode = new Node(value, nullptr);
		if (!_top) {
			_top = newNode;
			_size++;
			return;
		}
		newNode->next = _top;
		_top = newNode;
		_size++;
	}
	void pop() {
		if (!_top) return;
		Node* tmp = _top;
		_top = _top->next;
		delete tmp;
		tmp = nullptr;
	}
	T front() const {
		if (!_top) throw std::invalid_argument("");
		return _top->data;
	}
};

template<class T>
class AStack {
	T* _data;
	size_t _size;

public:
	AStack() : _data(nullptr), _size(0) {}

	~AStack() {
		delete[] _data;
	}

	void push(const T& value) {
		if (!_data) {
			_data = new T[1];
			_data[0] = value;
			_size++;
			return;
		}
		T* newStack = new T[_size + 1];
		newStack[0] = value;
		for (size_t i = 0; i < _size; i++) {
			newStack[i + 1] = _data[i];
		}
		delete[] _data;
		_data = newStack;
		_size++;
	}

	void pop() {
		if (!_size) throw std::invalid_argument("Stack is empty");
		T* newStack = new T[_size - 1];
		for (size_t i = 0; i < _size; i++) {
			newStack[i] = _data[i + 1];
		}
		delete[] _data;
		_data = newStack;
		_size--;
	}

	T front() {
		if (!_size) throw std::invalid_argument("Stack is empty");
		return _data[0];
	}

};