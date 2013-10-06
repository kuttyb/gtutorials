#include <iostream>
#include "one.h"

using std::cout;
using std::endl;

// ---------------------------------------------------------
const uint32_t One::uuid = 0x10;
uint32_t One::var_id = 12;

One::One(uint32_t x, uint32_t y, uint64_t _local) : m_x(x), m_y(y), local(_local) 
{
	cout << "ctor of One" <<endl;
}


One::~One(void) 
{
	cout <<"dtor of One" << endl;
}
	


// ---------------------------------------------------------

int main(void) 
{
	cout<<"testing the latest software" << endl;
	return 0;
}
