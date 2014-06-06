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

// Specialize branches within a function optimized for certain paths
template <bool N>
void perform(int input) {
    cout << input << endl;
    if (N == true) {
        cout << "generic version: true path "  << endl;
    } else {
        cout << "generic version: false path " << endl;
    }
}

template <>
void perform<true>(int input) {
    cout << input << endl;
    cout << "generic version: true path " << endl;
}

template <>
void perform<false>(int input) {
    cout << input << endl;
    cout << "generic version: false path" << endl;
}

int test_comparison(void)
{
	function<int>(2, 3);

	function<float>(2.02f, 3);
	
	function<double>(2.03f, 3);
	
	float a = 2.03f;
	function(&a, 3);
	
    perform<true>(3);
    perform<false>(2);
    
	return 0;
}
