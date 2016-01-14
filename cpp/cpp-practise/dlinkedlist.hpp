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

template <typename T, int Next>
struct DList {
	T * head;
	T * tail;
#if ASSERT
	uint32_t elements;
#endif
	
	DList() : head(nullptr), tail(nullptr)
#if ASSERT
	, elements(0)
#endif
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
#if ASSERT
		++elements;
#endif
	}
	
	T * remove() {
		T * temp = tail;
		if (temp) {
			tail = *getNext<T, Next>(temp);
#if ASSERT
			elements--;
#endif
			*getPrev<T, Next>(tail) = nullptr;
			
			*getNext<T, Next>(temp) = nullptr;
			*getPrev<T, Next>(temp) = nullptr;
			
			return temp;
		} else {
			return nullptr;
		}
	}
	
#if ASSERT
	uint32_t size() {
		return elements;
	}
#endif
	
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
