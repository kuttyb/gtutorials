//
//  dlinkedlist.h
//  cpp-practise
//
//  Created by kutty banerjee on 1/13/16.
//  Copyright © 2016 kbanerjee. All rights reserved.
//

#ifndef dlinkedlist_h
#define dlinkedlist_h

#include <iostream>

#pragma mark - List Interface

/* Any data structure that wishes to use List has to specialize the following methods */
#include "linkedlist.hpp"
template <typename T, int val> T** getPrev(T * input);

template <typename T, int Next = 0>
struct DList {
	T * head;
	T * tail;
	uint32_t elements;
	
	DList() : head(nullptr), tail(nullptr), elements(0)
	{}
	
	void insert(T * data) {
		if (!head) {
			head = data;
			tail = data;
		} else {
			*getNext<T, Next>(head) = data;
			*getPrev<T, Next>(data) = head;
			head = data;
		}
		++elements;
	}
	
	T * remove() {
		T * temp = tail;
		if (temp) {
			tail = *getNext<T, Next>(temp);
			elements--;
			
			if (!elements) {
				head = nullptr;
				tail = head;
			} else {
				*getPrev<T, Next>(tail) = nullptr;
			}
			
			*getNext<T, Next>(temp) = nullptr;
			*getPrev<T, Next>(temp) = nullptr;
			
			return temp;
		} else {
			return nullptr;
		}
	}
	
	uint32_t size() {
		return elements;
	}
	
	template <typename Policy>
	void traverseFront(Policy p) {
		std::cout << "============" << std::endl;
		T * itr = tail;
		while (itr) {
			p(*itr);
			T** temp = getNext<T, Next>(itr);
			if (temp) {
				itr = *temp;
			} else {
				itr = nullptr;
			}
		}
	}

	template <typename Policy>
	void traverseBack(Policy p) {
		std::cout << "============" << std::endl;
		T * itr = head;
		while (itr) {
			p(*itr);
			T** temp = getPrev<T, Next>(itr);
			if (temp) {
				itr = *temp;
			} else {
				itr = nullptr;
			}
		}
	}
};

#endif /* dlinkedlist_h */
