#pragma once

#include <iostream>

template<class T>
class SearchTree {
	struct Node {
		T key;
		Node* left, * right;
		Node(): key{}, left(nullptr), right(nullptr){}
		Node(const T& key, Node* left = nullptr, Node* right = nullptr): key(key), left(left), right(right){}
	};
	Node* _root;
	size_t _size;

	Node* add_helper(const T& key, Node* node) {
		if (!node) {
			_size++;
			return new Node(key);
		}
		if (key < node->key) node->left = add_helper(key, node->left);
		if (key > node->key) node->right = add_helper(key, node->right);
		return node;
	}

	void print_helper(Node* node) const {
		if (node) {
			print_helper(node->left);
			std::cout << node->key << "\t";
			print_helper(node->right);
		}
	}

	 bool conatains_helper(const T& key, Node* node) const {
		 if (!node) return false;
		 if (key == node->key) 
			 return true;
		 else if (key < node->key) 
			 return conatains_helper(key, node->left);
		 else 
			 return conatains_helper(key, node->right);
		 return false;
	}

	 Node* find_min_node(Node* node) {
		 if (!node) return nullptr;
		 while (node->left) {
			 node = node->left;
		 }
		 return node;
	 }

	 Node* erase_helper(const T& key, Node* node) {
		 if (!node) 
			 return nullptr;
		 if (key < node->key)
			 node->left = erase_helper(key, node->left);
		 else if (key > node->key)
			 node->right = erase_helper(key, node->right);
		 else {
			 if (!node->left && !node->right) {
				 delete node;
				 return nullptr;
			 }
			 else if (!node->left) {
				 Node* tmp = node->right;
				 delete node;
				 return tmp;
			 }
			 else if (!node->right) {
				 Node* tmp = node->left;
				 delete node;
				 return tmp;
			 }
			 else {
				 node->key = find_min_node(node->right)->key;
				 node->right = erase_helper(node->key, node->right);
			 }
		 }
		 return node;
	 }

public:
	SearchTree(): _root(nullptr), _size(0){}

	bool add(const T& key) {
		if (contains(key))
			return false;
		_root = add_helper(key, _root);
		return true;
	}

	void print() const {
		print_helper(_root);
		std::cout << "\n";
	}

	bool contains(const T& key) const {
		return conatains_helper(key, _root);
	}

	bool erase(const T& key) {
		if (!contains(key))
			return false;
		_root = erase_helper(key, _root);
		_size--;
		return true;
	}

	T find_min() {
		return find_min_node(_root)->key;
	}
	
};