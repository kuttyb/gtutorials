#include <iostream>

using std::cout;
using std::endl;

// Static Polymorhpism:
//    ===================
//    We will try to mock the following interface.
//    interface X {
//        uint64_t multiply(uint32_t input, uint32_t m);
// 	  uint64_t passthru(uint64_t val);
//    }
template<class T>
class A 
{
private:
	T m_t;
	
public:
	A(T t) : m_t(t) 
	{
	}

	uint64_t multiply(uint32_t input, uint32_t m) 
	{
		return m_t.multiply(input, m);
	}
	
	uint64_t passthru(uint64_t val) 
	{
		return m_t.passthru(val);
	}
};

	

int main(void) 
{
	cout << "lets try out static duck typing " << endl;
	
	return 0;
}
