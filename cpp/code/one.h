#ifndef __one_h__
#define __one_h__

#include <stdint.h>

class One 
{
private:
	uint32_t m_x;
	uint32_t m_y;
	
protected:
	uint64_t local;
	static const uint32_t uuid;
	static uint32_t var_id;

public:
	One(uint32_t x, uint32_t y, uint64_t local);
	virtual ~One(void);
	uint64_t value(void);
	uint32_t latest_value(void);
};



#endif //__one_h__
