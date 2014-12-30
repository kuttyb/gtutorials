#include <iostream>

using std::cout;
using std::endl;

template <typename T, typename V>
int method(T first, V second) 
{
  return first.value + second.value;	
}

struct A 
{
	int value;	
};

struct B 
{
	int value;
};

int main(void) 
{
	cout << "Hello world\n" << endl;	
	A a;
	B b;
	return method(a, b);
}
