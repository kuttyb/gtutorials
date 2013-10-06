#include <inttypes.h>

template<class T>
class A 
{
public:
	uint64_t multiply(uint32_t input, uint32_t m) 
	{
		return static_cast<T*>(this)->multiply(input, m);
	}
	
	uint64_t passthru(uint64_t val) 
	{
		return static_cast<T*>(this)->passthru(val);
	}
};

class X : public A<X> 
{
public:
	uint64_t multiply(uint32_t input, uint32_t m) 
	{
		return input * m;
	}

	uint64_t passthru(uint64_t val) 
	{
		return val;
	}
};

	

int main(void) 
{
	uint64_t ctr =0;

	{
		A<X> *a = new X();
		ctr += a->multiply(2, 3);
		ctr += a->passthru(3);
		delete a;
	}

	return ctr % 100;
}
