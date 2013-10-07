#include <iostream>

using std::cout;
using std::endl;


template <class T, class U>
void func(T one, U two) 
{
	cout << "printing generic " << one << two << endl;
}


int main(void) 
{
	return 0;
}
