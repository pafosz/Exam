#include <iostream>
#include <optional>

template<class T>
class LQueue {
	struct Node {
		T data;
		Node* next;
		Node() : data{}, next(nullptr) {}
		Node(const T& value, Node* next) : data(value), next(next) {}
	};
	Node* _top;
	size_t _size;
public:
	LQueue() : _top(nullptr), _size(0) {}

	~LQueue() {
		while (!empty()) pop();
	}
	void push(const T& value) {
		Node* newNode = new Node(value, nullptr);
		if (empty()) {
			_top = newNode;
			_size++;
			return;
		}
		Node* tmp = _top;
		while (tmp->next) tmp = tmp->next;
		tmp->next = newNode;
		_size++;
	}
	void pop() {
		if (empty()) throw std::invalid_argument("Queue is empty");
		Node* tmp = _top;
		_top = _top->next;
		delete tmp;
		tmp = nullptr;
	}
	T front() {
		if (empty()) throw std::invalid_argument("Queue is empty");

		return _top->data;
	}
	T back() {
		if (empty()) throw std::invalid_argument("Queue is empty");
		Node* tmp = _top;
		while (tmp->next) tmp = tmp->next;
		return tmp->data;
	}
	void size() {
		return _size;
	}
	bool empty() {
		return _top == nullptr;
	}
};

template<class T>
class AQueue {
	T* _data;
	size_t _size;

public:
	AQueue() : _data(nullptr), _size(0) {}
	~AQueue() {
		delete[] _data;
	}

	void push(const T& value) {
		if (empty()) {
			_data = new T[1];
			_data[0] = value;
			_size++;
			return;
		}
		T* newQueue = new T[_size + 1];
		for (size_t i = 0; i < _size; i++) {
			newQueue[i] = _data[i];
		}
		newQueue[_size] = value;
		delete[] _data;
		_data = newQueue;
		_size++;
	}
	void pop() {
		if (empty()) throw std::invalid_argument("Queue is empty");
		T* newQueue = new T[_size - 1];
		for (size_t i = 0; i < _size; i++) {
			newQueue[i] = _data[i + 1];
		}
		delete[] _data;
		_data = newQueue;
		_size--;
	}
	T front() {
		if (empty()) throw std::invalid_argument("Queue is empty");
		return _data[0];
	}
	T back() {
		if (empty()) throw std::invalid_argument("Queue is empty");
		return _data[_size - 1];
	}
	size_t size() {
		return _size;
	}
	bool empty() {
		return _data == nullptr;
	}
};