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
#if ASSERT
	uint32_t elements;
#endif
	
	List() : head(nullptr), tail(nullptr)
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
	void traverse(Policy policy) {
		T * itr = tail;
		while (itr) {
//			std::cout << hashCode<T>(itr) << std::endl;
			policy(*itr);
			
			T** temp = getNext<T, Next>(itr);
			if (temp) {
				itr = *temp;
			} else {
				itr = nullptr;
			}
		}
	}
};


#endif /* linkedlist_h */
