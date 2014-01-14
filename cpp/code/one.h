#ifndef __one_h__
#define __one_h__

#include <stdint.h>

template<class T>
class One 
{
private:
	uint32_t m_x;
	uint32_t m_y;
	T m_t;
	
protected:
	One(uint32_t x, uint32_t y, uint64_t local, T t);
	uint64_t local;
	static const uint32_t uuid;
	static uint32_t var_id;

public:
	virtual ~One(void);
	uint64_t value(void);
	virtual uint32_t latest_value(void);
	// Types that are allowed tobe instantiated
	static One<uint64_t> createInteger(uint32_t one, uint32_t two, uint64_t three, uint64_t four);
	static One<float> createFloat(uint32_t one, uint32_t two, uint64_t local, float t);
};

template<class T>
class Two : public One<T>
{
protected:
	Two(T t);
public:
	~Two(void);
	uint32_t latest_value(void);
};




#endif //__one_h__
