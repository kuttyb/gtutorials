//
//  ExemptPtr.h
//  cpp-code
//
//  Created by kutty banerjee on 5/22/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__ExemptPtr__
#define __cpp_code__ExemptPtr__

template <typename T>
class ExemptPtr {
private:
	T* m_ptr;
	// Get rid of the copy and hide ctor/operators
	ExemptPtr(const ExemptPtr<T>& other) = delete;
	ExemptPtr<T>& operator=(const ExemptPtr<T>& rhs) = delete;
	
	ExemptPtr(ExemptPtr<T>&& other)  = delete;
	ExemptPtr<T>& operator=(ExemptPtr<T>&& rhs) = delete;
	
public:
	ExemptPtr(T *ptr) {
		m_ptr = ptr;
	}
	
	~ExemptPtr() {
		if (m_ptr) {
			delete m_ptr;
		}
	}
	
	// Overloaded dereference and member access operators
	T operator*() const  { return *m_ptr; }
};

#endif /* defined(__cpp_code__ExemptPtr__) */
