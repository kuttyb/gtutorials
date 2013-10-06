#include <inttypes.h>

template<class T>
class A 
{
private:
	T* m_t;
	
public:
	A(T* t) : m_t(t) 
	{
	}

	uint64_t multiply(uint32_t input, uint32_t m) 
	{
		return m_t->multiply(input, m);
	}
	
	uint64_t passthru(uint64_t val) 
	{
		return m_t->passthru(val);
	}
};

class X : public A<X> 
{
public:
	X(void) : A<X>(this)
	{
	}
	
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
