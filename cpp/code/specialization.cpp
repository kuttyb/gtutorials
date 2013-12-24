#include <iostream>

using std::cout;
using std::endl;

//
// What you saw in comparison.cpp was Full Specialization and Pattern Matching based
// on Template arguments. 
//
// This file deals with Partial Specialization which it appears does not work with
// function templates.
//

// ----------------------------------------------
// Class Partial Specialization
template <class T, class U>
class X
{
public:	
	void func(T one, U two) 
	{
		cout << "printing generic " << one << " " << two << endl;
	}
};

	
template <class U>
class X<int, U>
{
public:	
	void func(int one, U two)
	{
		cout << "printing partially specialized " << one << " " << two << endl;
	}
};

// Fully Specialized Class
template <>
class X<double, double>
{
public:
	void func(double one, double two) 
	{
		cout << "printing fully specialized " << one << " " << two << endl;
	}
};

// ----------------------------------------------


int test_specialization(void)
{
	// This should use the generic versino
	X<float, float> a;
	a.func(2.03f, 3.1f);
	
	// This should use the partially specialized version 
	// with an integer bias
	X<int, float> b;
	b.func(2, 3.4f);

	// This should use the fully specialized version
	X<double, double> c;
	c.func(3.03f, 3.3f);

	return 0;
}
