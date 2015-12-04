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

template <typename T>
bool dfs(Node<T> * root, T key) {
	using std::stack;
	assert(root);
	
	stack<Node<T>*> path;
	path.push(root);
	
	while (!path.empty()) {
		Node<T> * temp = path.top();
		path.pop();
		
		if (temp->value == key) return true;
		
		/* Push his children */
		for (Node<T> * a : temp->list) {
			path.push(a);
		}
	}
	
	return false;
}

#endif /* graph_h */
