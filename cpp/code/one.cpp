#include <iostream>
#include "one.h"

using std::cout;
using std::endl;


// ---------------------------------------------------------
//   Class One
// ---------------------------------------------------------
template<class T>const uint32_t One<T>::uuid = 0x10;
template<class T> uint32_t One<T>::var_id = 12;

template<class T> One<T>::One(uint32_t x, uint32_t y, uint64_t _local, T t) : m_x(x), m_y(y), m_t(t), local(_local)
{
	cout << "ctor of One" <<endl;
}


template<class T> One<T>::~One(void) 
{
	cout <<"dtor of One" << endl;
}
	
template<class T> uint64_t One<T>::value(void) 
{
	return m_x;
}

template<class T> uint32_t One<T>::latest_value(void) 
{
	cout << "One::latest_value" << endl;
	
	return m_y;
}
// ---------------------------------------------------------


// ---------------------------------------------------------
//   Class Two
// ---------------------------------------------------------
template<class T> Two<T>::Two(T t) : One<T>(2, 3, 19, t) 
{
	cout << "ctor of Two" << endl;
}

template<class T> Two<T>::~Two(void) 
{
	cout << "dtor of Tw" << endl;
}

template<class T> uint32_t Two<T>::latest_value(void) 
{
	cout << "Two::latest_value" << endl;
	
	return static_cast<uint32_t>(this->local / 2);
}


// ---------------------------------------------------------
int test_one(void)
{
	// by value
	cout<<"testing the latest software" << endl;
	{
		One<uint64_t> one(2, 3, 8, 1);
		one.value();
		
	}
	cout << "----------------------------" << endl;

	// by pointer
	{
		One<uint64_t> *two = new Two<uint64_t>(2);
		two->value();
		two->latest_value();
		delete two;
	}
	cout << "----------------------------" << endl;

	// by reference
	{
		Two<uint64_t> two(2);
		One<uint64_t>  &ref = two;
		ref.latest_value();
	}
	cout << "----------------------------" << endl;

	// by reference (from a pointer)
	{
		One<uint64_t> *one = new Two<uint64_t>(2);
		One<uint64_t> &ref = *one;
		ref.latest_value();
		delete one;
	}
	cout << "----------------------------" << endl;
	
	// Array Initialization
	{
		One<uint64_t> list[] = 
			{
				One<uint64_t>(2, 3, 8, 1), One<uint64_t>(1, 5, 2, 2), One<uint64_t>(1, 1, 1, 3), One<uint64_t>(1, 2, 3, 4)
			};
		cout << "printing array values " << endl;
		
		for (uint32_t i = 0; i < sizeof(list) / sizeof(One<uint64_t>); i++) 
		{
			cout << list[i].latest_value() << endl;
		}
	}
	cout << "----------------------------" << endl;

	cout <<"tearing down program" << endl;
	
	return 0;
}
