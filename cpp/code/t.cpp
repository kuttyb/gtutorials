#include <iostream>
#include "t.h"

using namespace std;

template <typename T> const int A<T>::id = 0x20;

template <typename T> T A<T>::add(T one, T two)
{
	return one + two;
}

// ------------------------------------------
template <typename T> T X<T>::multiply(T one, T two)
{
	return one * two;
}
// ------------------------------------------

int test_t(void)
{
	cout << "hi there" << endl;
	
	X<int> a;
	cout<< a.add(3, 4) << endl;
	cout<< a.multiply(3, 4) << endl;
	
	return 0;
}
