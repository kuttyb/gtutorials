#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

template<class T>
void function(T input, int x) 
{
	assert(input && x);
	
	cout<<"generic version" << endl;
}

// When you are specializing the type on your own, 
// leave template<> empty w/o providing the Parameterized
// type
template<>
void function(int input, int x) 
{
	assert(input && x);
	
	cout << "integer version" << endl;
}

template<>
void function(float input, int x)
{
	assert(input && x);
	
	cout << "float version" << endl;
}


int main(void) 
{
	function<int>(2, 3);

	function<float>(2.02f, 3);
	
	function<double>(2.03f, 3);
	
	
	return 0;
}
