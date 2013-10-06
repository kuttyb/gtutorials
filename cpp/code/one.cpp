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
	cout << "One::latest_value" << endl;
	
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

uint32_t Two::latest_value(void) 
{
	cout << "Two::latest_value" << endl;
	
	return static_cast<uint32_t>(local / 2);
}


// ---------------------------------------------------------

int main(void) 
{
	// by value
	cout<<"testing the latest software" << endl;
	{
		One one(2, 3, 8);
		one.value();
		
	}
	cout << "----------------------------" << endl;

	// by pointer
	{
		One *two = new Two();
		two->value();
		two->latest_value();
		delete two;
	}
	cout << "----------------------------" << endl;

	// by reference
	{
		Two two;
		One  &ref = two;
		ref.latest_value();
	}
	cout << "----------------------------" << endl;

	// by reference (from a pointer)
	{
		One *one = new Two();
		One &ref = *one;
		ref.latest_value();
		delete one;
	}
	cout << "----------------------------" << endl;
	
	// Array Initialization
	{
		One list[] = 
			{
				One(2, 3, 8), One(1, 5, 2), One(1, 1, 1), One(1, 2, 3)
			};
		cout << "printing array values " << endl;
		
		for (uint32_t i = 0; i < sizeof(list) / sizeof(One); i++) 
		{
			cout << list[i].latest_value() << endl;
		}
	}
	cout << "----------------------------" << endl;

	cout <<"tearing down program" << endl;
	
	return 0;
}
