#ifndef __first_h__
#define __first_h__

class Base {
private:
    uint32_t var;
    const uint32_t x;
    static const uint64_t classvar;

public:
    uint64_t flag;
    Base(uint32_t i);
    virtual void print(void);
    virtual ~Base();
    static uint64_t getclassvar(void);
};


class Derived : public Base {
private:
    const uint32_t localvar;
    uint32_t y;
public:
    Derived();
    ~Derived();
    void print(void);
};

#endif // __first_h__
