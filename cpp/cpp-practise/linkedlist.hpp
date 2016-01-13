//
//  linkedlist.hpp
//  cpp-practise
//
//  Created by kutty banerjee on 1/13/16.
//  Copyright © 2016 kbanerjee. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>

#pragma mark - List Interface

/* Any data structure that wishes to use List has to specialize the following methods */
template <typename T, int val> T** getNext(T * input);
template <typename T> uint32_t hashCode(T * input);

template <typename T, int Next>
struct List {
	T * head;
	T * tail;
	uint32_t elements;
	
	List() : head(nullptr), tail(nullptr), elements(0) {}
	
	void insert(T * data) {
		if (!head) {
			head = data;
			tail = data;
		} else {
			*getNext<T, Next>(head) = data;
			head = data;
		}
		++elements;
	}
	
	T * remove() {
		T * temp = tail;
		if (temp) {
			tail = *getNext<T, Next>(temp);
			elements--;
			return temp;
		} else {
			return nullptr;
		}
	}
	
	uint32_t size() {
		return elements;
	}
	
	void traverse() {
		T * itr = tail;
		while (itr) {
			std::cout << hashCode<T>(itr) << std::endl;
			itr = *getNext<T, Next>(itr);
		}
	}
};


#endif /* linkedlist_h */
