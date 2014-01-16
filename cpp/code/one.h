#ifndef __one_h__
#define __one_h__

#include <stdint.h>

template<typename T>
class One 
{
	friend class ConfigOne;
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
};

template<typename T>
class Two : public One<T>
{
protected:
	Two(T t);
public:
	~Two(void);
	uint32_t latest_value(void);
};

#endif //__one_h__
