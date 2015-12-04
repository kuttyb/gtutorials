//
//  graph.hpp
//  cpp-practise
//
//  Created by kuttyb on 12/4/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <vector>
#include <stack>
#include <queue>
#include <assert.h>

template <typename T>
struct Node {
	T value;
	std::vector<Node<T>*> list;
	
	explicit Node(T input) : value(input) {}
	
	void addChild(Node<T> * child) {
		list.push_back(child);
	}
};

/* FIFO */
template <typename T, bool isLIFO>
struct Deque {
	std::queue<Node<T>*> data;
	
	void add(Node<T> * input) {
		data.push(input);
	}
	
	Node<T> * get() {
		Node<T> * retvalue = data.front();
		data.pop();
		return retvalue;
	}
	
	bool empty() {
		return data.empty();
	}
};

/* LIFO */
template <typename T>
struct Deque<T, true> {
	std::stack<Node<T>*> data;
	
	void add(Node<T> * input) {
		data.push(input);
	}
	
	Node<T> * get() {
		Node<T> * retvalue = data.top();
		data.pop();
		return retvalue;
	}
	
	bool empty() {
		return data.empty();
	}
};

template <typename T, bool isLIFO>
bool search(Node<T> * root, T key) {
	assert(root);
	
	Deque<T, isLIFO> path;
	path.add(root);
	
	while (!path.empty()) {
		Node<T> * temp = path.get();
		
		if (temp->value == key) return true;
		
		/* Push his children */
		for (Node<T> * a : temp->list) {
			path.add(a);
		}
	}
	
	return false;
}

#endif /* graph_h */
