#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

template<typename T, typename U>
void function(T input, int x) 
{
	cout << input << " " << x << " " << endl;
	cout<<"generic version" << endl;
}

// When you are specializing the type on your own, 
// leave template<> empty w/o providing the Parameterized
// type
template<typename U>
void function(int input, int x) 
{
	assert(input && x);
	
	cout << "integer version" << endl;
}

template<int>
void function(float input, int x)
{
	cout << "float version" << input << " " << x << endl;
}

static void function(float* input, int x)
{
	assert(input && x);
	
	cout << "non templated version" << endl;
}


int test_comparison(void)
{
	function<int>(2, 3);

	function<float>(2.02f, 3);
	
	function<double>(2.03f, 3);
	
	float a = 2.03f;
	function(&a, 3);
	
	return 0;
}
