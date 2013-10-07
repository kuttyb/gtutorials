#include <iostream>

using std::cout;
using std::endl;

template<class T>
static void function(T input, int x) 
{
	cout<<"generic version" << endl;
}

// When you are specializing the type on your own, 
// leave template<> empty w/o providing the Parameterized
// type
template<>
static void function(int input, int x) 
{
	cout << "integer version" << endl;
}

template<>
static void function(float input, int x)
{
	cout << "float version" << endl;
}


int main(void) 
{
	function<int>(2, 3);

	function<float>(2.02f, 3);
	
	function<double>(2.03f, 3);
	
	
	return 0;
}
