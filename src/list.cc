#pragma once
#include <iostream>

template<class T>
class List {
	struct Node {
		T data;
		Node* next;

		Node() : data{}, next(nullptr) {}
		Node(const T& data, Node* next) : data(data), next(next) {}
	};
	Node* _head;
	size_t _size;
public:
	List() : _head(nullptr), _size(0) {}

	List(const List& other) {
		if (!other._head) return *this;

		Node* tmp = other._head;
		while (other._head) {
			push_back(tmp->data);
			tmp = tmp->next;
		}
	}

	void push_head(const T& value) {
		Node* newNode = new Node(value, nullptr);
		if (!_head) {
			_head = newNode;
			_size++;
			return;
		}
		newNode->next = _head;
		_head = newNode;
		_size++;
	}

	void push_back(const T& value) {
		if (!_head) {
			push_head(value);
			return;
		}
		Node* tmp = _head;
		while (tmp->next) tmp = tmp->next;
		Node* newNode = new Node(value, nullptr);
		tmp->next = newNode;
		_size++;
	}

	void pop_head() {
		if (!_head) return;
		Node* tmp = _head;
		_head = tmp->next;
		delete tmp;
		tmp = NULL;
		_size--;
	}

	void pop_back() {
		if (!_head) return;
		if (!_head->next) {
			delete _head;
			_head = nullptr;
			return;
		}
		Node* tmp = _head;
		while (tmp->next->next) {
			tmp = tmp->next;
		}

		delete tmp->next;
		tmp->next = nullptr;
		_size--;
	}

	size_t get_size() const {
		return _size;
	}

	void print() const {
		if (!_head) std::cout << "List is empty" << std::endl;
		Node* tmp = _head;
		while (tmp) {
			std::cout << tmp->data << std::endl;
			tmp = tmp->next;
		}
	}
};

template<class T>
class DoublyLinkedList {
	struct Node {
		T data;
		Node* next, * prev;
		Node() : data{}, next(nullptr), prev(nullptr) {}
		Node(const T& value, Node* next = nullptr, Node* prev = nullptr) : data(value), next(next), prev(prev) {}
	};
	Node* _head;
	size_t _size;
public:
	DoublyLinkedList() : _head(nullptr), _size(0) {}
	~DoublyLinkedList() {
		while (_head) {
			pop_head();
		}
	}

	void push_back(const T& value) {
		Node* newNode = new Node(value);
		if (!_head) {
			_head = newNode;
			_size++;
			return;
		}
		Node* tmp = _head;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		newNode->prev = tmp;
		_size++;
	}

	void push_head(const T& value) {
		if (!_head) {
			_head = new Node(value);
			_size++;
			return;
		}
		Node* newNode = new Node(value, _head);
		_head->prev = newNode;
		_head = newNode;
		_size++;
	}

	void insert(size_t pos, const T& value) {
		if (_size <= pos) throw std::overflow_error("");
		size_t i = 0;
		Node* tmp = _head;
		while (i <= pos) {
			tmp = tmp->next;
			++i;
		}
		Node* newNode = new Node(value, tmp, tmp->prev);
		tmp->prev->next = newNode;
		tmp->prev = newNode;
		_size++;
	}

	void pop_head() {
		if (!_head) throw std::invalid_argument("");
		Node* tmp = _head;
		_head = _head->next;
		delete tmp;
		tmp = nullptr;
		_size--;
	}

	void erase(size_t pos) {
		if (_size <= pos) throw std::overflow_error("");

		Node* tmp = _head;
		size_t i = 0;
		while (i <= pos) {
			tmp = tmp->next;
			++i;
		}
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
		tmp = nullptr;
		_size--;
	}

	DoublyLinkedList& includeSort() {
		if (!_head || !_head->next) return *this;
		Node* curr = _head->next;
		while (curr) {
			Node* prev = curr->prev;
			T currData = curr->data;
			while (prev && prev->data > currData) {
				prev->next = curr->next;
				if (curr->next) {
					curr->next->prev = prev;
				}
				curr->next = prev;
				curr->prev = prev->prev;
				if (prev->prev) {
					prev->prev->next = curr;
				}
				else {
					_head = curr;
				}
				prev->prev = curr;
				prev = curr->prev;
			}
			curr = curr->next;
		}	
		return *this;
	}

	void print() const {
		Node* tmp = _head;
		while (tmp) {
			std::cout << tmp->data << "\t";
			tmp = tmp->next;
		}
		std::cout << "\n";
	}

};

template<class T>
class CyclicList {
	struct Node {
		T data;
		Node* next, * prev;
		Node(): data{}, next(nullptr), prev(nullptr){}
		Node(const T& value, Node* next = nullptr, Node* prev = nullptr): data(value), next(next), prev(prev){}
	};
	Node* _spec;
	size_t _size;

public:
	CyclicList(): _spec(new Node()), _size(0){		
		_spec->next = _spec;
		_spec->prev = _spec;
	}

	~CyclicList() {		
		while (_spec->next != _spec) {
			
			pop_back();
		}
		delete _spec;
	}

	void push_back(const T& value) {
		Node* newNode = new Node(value, _spec, _spec->prev);
		if (_spec->next == _spec) {
			_spec->next = newNode;
			_spec->prev = newNode;
			_size++;
			return;
		}
		_spec->prev->next = newNode;
		_spec->prev = newNode;
		_size++;
	}

	void push_front(const T& value) {
		Node* newNode = new Node(value);
		if (_spec->next == _spec) {
			_spec->next = newNode;
			_spec->prev = newNode;
			_size++;
			return;
		}
		_spec->next->prev = newNode;
		_spec->next = newNode;
		_size++;
	}

	void insert(size_t index, const T& value) {
		if (_size <= index) throw std::invalid_argument("The index goes beyond the list");
		Node* tmp = _spec->next;
		size_t i = 0;
		while (i <= index) {
			tmp = tmp->next;
			i++;
		}
		Node* newNode = new Node(value, tmp, tmp->prev);
		tmp->prev->next = newNode;
		tmp->prev = newNode;
		_size++;
	}

	void pop_back() {
		if (_spec->next == _spec) return;
		Node* tmp = _spec->prev;
		tmp->prev->next = _spec;
		_spec->prev = tmp->prev;
		delete tmp;
		tmp = nullptr;
		_size--;
	}

	void pop_front() {
		if (_spec->next == _spec) return;
		Node* tmp = _spec->next;
		tmp->next->prev = _spec;
		_spec->next = tmp->next;
		delete tmp;
		tmp = nullptr;
		_size--;
	}

	void erase(const T& key) {
		if (_spec->next == _spec) return;
		Node* tmp = _spec->next;
		while (tmp != _spec || tmp->data != key) {
			if (tmp->data == key) {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				tmp = nullptr;
				_size--;
				return;
			}
		}
		throw std::invalid_argument("This key does not exist");
	}

	void print() const {
		Node* tmp = _spec->next;
		while (tmp != _spec) {
			std::cout << tmp->data << "\t";
			tmp = tmp->next;
		}
		std::cout << "\n";
	}
};