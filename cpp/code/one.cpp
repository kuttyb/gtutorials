#include <iostream>
#include "one.h"

using std::cout;
using std::endl;

void func_name(void)
{
    printf("this is the data\n");
}

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

