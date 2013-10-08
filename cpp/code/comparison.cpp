#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

template<class T>
void function(T input, int x) 
{
	cout << input << " " << x << " " << endl;
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
	cout << "float version" << input << " " << x << endl;
}

static void function(float* input, int x)
{
	assert(input && x);
	
	cout << "non templated version" << endl;
}


int main(void) 
{
	function<int>(2, 3);

	function<float>(2.02f, 3);
	
	function<double>(2.03f, 3);
	
	float a = 2.03f;
	function(&a, 3);
	
	return 0;
}
