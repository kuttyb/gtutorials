//
//  AccelGen1.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/14/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AccelGen1_h
#define AccelGen1_h

#pragma mark - Gen1
template <typename ChipDispatch>
class AccelGen1 : public AccelBase<ChipDispatch> {
    /* Delegates */
    brn2<ChipDispatch::BRN::brn2, ChipDispatch> b2;
    
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        
        AccelBase<ChipDispatch>::init();
        b2.apply();
        
        /* This is how you access your parent's member variable when you go through Templated inheritance */
        AccelBase<ChipDispatch>::channel->init();
    }
};


#endif /* AccelGen1_h */
