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

class Y : public A<Y> 
{
public:
	uint64_t multiply(uint32_t input, uint32_t m) 
	{
		return input * m + 3;
	}

	uint64_t passthru(uint64_t val) 
	{
		return val + 4;
	}
};
	
static inline A<X>* factory(void) 
{
	return new X();
}


int main(void) 
{
	uint64_t ctr =0;
	A<X> *a = factory();

	
	ctr += a->multiply(2, 3);
	ctr += a->passthru(3);


	delete a;
	return ctr % 100;
}
