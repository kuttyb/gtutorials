#ifndef __t_h__
#define __t_h__

template <class T>
class A
{
private:
	static const int id;
	
public:
	T add(T one, T two);
	virtual T multiply(T one, T two) = 0;
	virtual ~A() {}
	
};

template <class T>
class X : public A<T>
{
public:
	T multiply(T one, T two);
};

#endif //__t_h__
