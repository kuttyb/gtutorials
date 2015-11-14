//
//  AccelGen2.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/14/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AccelGen2_h
#define AccelGen2_h

#pragma mark - Gen2
template <typename ChipDispatch>
class AccelGen2 : public AccelGen1<ChipDispatch> {
    /* Delegates */
    brn3<ChipDispatch::BRN::brn3, ChipDispatch> b3;
    
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        /* Punt to Gen1 */
        AccelGen1<ChipDispatch>::init();
        b3.apply();
    }
};

#endif /* AccelGen2_h */
