#include <iostream>

using std::cout;
using std::endl;

#pragma mark - (POD - Plain Old Data classes)
struct DataMasterCommon
{
    int a;
};

struct DataMaster3D
{
    DataMasterCommon b;
    int contextid;	
};

#pragma mark - Properties
class BRNTable {
public:
    constexpr static bool BRN123 = false;
    constexpr static bool BRN234 = false;
};


#pragma mark - Chipurations (aka Chip type)
class ChipG4
{
public:
    // Each of these classes are Dependency Injection points, think GUICE annotation points
    typedef DataMasterCommon ta;
    typedef DataMaster3D     threed;
    // Properties
    class BRN : public BRNTable
    {
    public:
        constexpr static bool BRN123 = true;
    };
};

class ChipG4G : public ChipG4
{
public:
    typedef DataMasterCommon  threed;
    class BRN : public ChipBig::BRN
    {
    public:
        constexpr static bool BRN123 = false;
    };
};


class ChipG5
{
public:
    typedef DataMasterCommon ta;
    typedef DataMaster3D     threed;
    class BRN : public BRNTable
    {
    public:
        constexpr static bool BRN234 = true;
    };
};

#pragma mark - Pure Functions
template <typename T>
void operate(T input)
{
        cout << "generic version" << endl;
}
    
template <>
void operate(One input)
{
        cout << "One speaking" << endl;
}
    
template <>
void operate(Two input)
{
        cout << "Two speaking" << endl;
        operate(input.b);
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
    typename Chip::Linenext var;
    Operation::operate(var);
    
    applyBRN123<Chip::BRN::BRN123>();
    
    applyBRN234<Chip::BRN::BRN234>();
}
