#include <inttypes.h>
#include <iostream>
#include <cassert>
#include "first.h"

using std::cout;
using std::endl;

// ----------------------------------------------
const uint64_t Base::classvar = 0x32;

// ----------------------------------------------
Base::Base(uint32_t i) : var(i), x(2) {
	cout<<"base ctor..."<<endl;
}

Base::~Base() {
	cout<<"base dtor..."<< endl;
}

void Derived::print(void)  {
	assert(y);
	cout<<"Derived: value is " << localvar << endl;
}

void Base::print(void)  {
	assert(x);
	cout<<" Base: value is " << var << endl;
}

uint64_t Base::getclassvar(void) {
	return classvar;
}

// ----------------------------------------------
Derived::Derived() : Base(0), localvar(200), y(2) {
	cout<<"Derived ctor...."<<endl;
}

Derived::~Derived() {
	cout<<"Derived dtor..."<< endl;
}
// ----------------------------------------------

static void test_reference(Base & base) {
	cout << __FUNCTION__ << " flag value is " << base.flag << endl;
	base.flag = 1200;
	cout << "static value is " << Base::getclassvar() << endl;
}

<<<<<<< local
static void test_pointers(void)
{
    Derived *d = new Derived();
    d->flag = 21;
    test_reference(*d);
    cout<<"pointer has value " << d->flag << endl;
    delete d;
=======
static void test_pointers(void)   {
	Derived *d = new Derived();
	d->flag = 21;
	test_reference(*d);
	cout<<"pointer has value " << d->flag << endl;
	delete d;
>>>>>>> other
}


int main(void) {
<<<<<<< local
    cout << "static value pre object construction is " << Base::getclassvar() << endl;
=======
	cout << "static value pre object construction is " << Base::getclassvar() << endl;
>>>>>>> other

<<<<<<< local
    test_pointers();
=======
	test_pointers();
>>>>>>> other

<<<<<<< local
    return 0;
=======
	return 0;
>>>>>>> other
}
