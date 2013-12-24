#include <iostream>

using std::cout;
using std::endl;

// The difference between this and duck.cpp being over here the interface that A expects from T is implicit and based on whatever
// usage it puts to T. Since it only invokes the multiply() and assigns the value to int, X is fine.
// 
// In the case of duck.cpp, it is different. We explicitly define the interface that T adheres to and it is that of the Base class.
//
// ----------------------------------------------
template <class T>
class A
{
private:
	T * m_t;
	
public :
	A(void) : m_t(new T())
	{
	}

	~A(void) 
	{
		delete m_t;
	}
	
	int print_all(void);
};

template<class T> int A<T>::print_all(void) 
{
	cout<< "data begins here" << endl;
	int value = m_t->multiply();
	return value;
}

// ----------------------------------------------
class X
{
public:
	int multiply(void) 
	{
		return 20;
	}
	
};

	
int test_static(void)
{
	A<X> a;
	a.print_all();
	
	return 0;
}

