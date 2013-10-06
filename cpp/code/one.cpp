#include <iostream>
#include "one.h"

using std::cout;
using std::endl;

// ---------------------------------------------------------
//   Class One
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
	
uint64_t One::value(void) 
{
	return m_x;
}

uint32_t One::latest_value(void) 
{
	return m_y;
}
// ---------------------------------------------------------


// ---------------------------------------------------------
//   Class Two
// ---------------------------------------------------------
Two::Two(void) : One(2, 3, 19) 
{
	cout << "ctor of Two" << endl;
}

Two::~Two(void) 
{
	cout << "dtor of Tw" << endl;
}


// ---------------------------------------------------------

int main(void) 
{
	cout<<"testing the latest software" << endl;
	{
		One one(2, 3, 8);
		one.value();
		
	}
	
	cout <<"tearing down program" << endl;
	
	return 0;
}
