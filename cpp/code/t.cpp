#include <iostream>
#include "t.h"

using namespace std;

template <class T> const int A<T>::id = 0x20;

template <class T> T A<T>::add(T one, T two) 
{
	return one + two;
}

// ------------------------------------------
template <class T>
class X : public A<T>
{
public:
	T multiply(T one, T two);
};


template <class T> T X<T>::multiply(T one, T two) 
{
	return one * two;
}
// ------------------------------------------

int main(void) 
{
	cout << "hi there" << endl;
	
	X<int> a;
	cout<< a.add(3, 4) << endl;

	return 0;
}
