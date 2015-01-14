//
//  tests.m
//  tests
//
//  Created by kuttyb on 11/21/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - (POD - Plain Old Data classes)
struct DataMasterThreeD
{
    int a;
};

struct DataMasterFastBlit
{
    // Composition and not Inheritance
    DataMasterThreeD base;
    int contextid;
};

struct DataMasterFasterBlit
{
    DataMasterFastBlit base;
    int someid;
};

#pragma mark - BRNs
class BRNTable {
public:
    // metagcc is at 4.2 with no support for C++11 (no constexpr)
    const static bool BRN123 = false;
    const static bool BRN234 = false;
};


#pragma mark - Chip Configurations
class ChipG4
{
public:
    typedef DataMasterThreeD    threed;
    typedef DataMasterFastBlit  fastblit;
    // Don't have DataMasterFasterBlit
    
    // Properties
    class BRN : public BRNTable
    {
    public:
        const static bool BRN123 = true;
    };
};

class ChipG4G : public ChipG4
{
public:
    typedef DataMasterFasterBlit fasterblit;
    class BRN : public ChipG4::BRN
    {
    public:
        const static bool BRN123 = false;
    };
};


class ChipG5
{
public:
    typedef DataMasterThreeD      threed;
    typedef DataMasterFasterBlit  fasterblit;
    
    class BRN : public BRNTable
    {
    public:
        const static bool BRN123 = true;
        const static bool BRN234 = true;
    };
};

#pragma mark - Data Master Functions (Specialize by DM)
template <typename T>
void agfProcessSubmittedCommands(T input)
{
    cout << "generic version" << endl;
}

template <>
void agfProcessSubmittedCommands(DataMasterThreeD input)
{
    cout << "3D logic" << endl;
}

template <>
void agfProcessSubmittedCommands(DataMasterFastBlit input)
{
    cout << "Fast Blit logic" << endl;
    agfProcessSubmittedCommands(input.base);
}

template <>
void agfProcessSubmittedCommands(DataMasterFasterBlit input)
{
    cout << "Faster Blit logic" << endl;
    agfProcessSubmittedCommands(input.base);
    cout << "Smore more logic" << endl;
}

#pragma mark - BRNs
template <bool val> void applyBRN123() {}
template <> void applyBRN123<true>()
{
    cout << "Applying BRN123" << endl;
}

template <bool val> void applyBRN234() {}
template <> void applyBRN234<true>()
{
    cout << "Applying BRN234" << endl;
}

#pragma mark - Top level function
template <typename Chip>
void top()
{
    typename Chip::fasterblit var;
    agfProcessSubmittedCommands(var);
    
    applyBRN123<Chip::BRN::BRN123>();
    
    applyBRN234<Chip::BRN::BRN234>();
}

int main(void)
{
    top<ChipG5>();
    cout << "=========" << endl;
    top<ChipG4G>();
    
    return 0;	
}
