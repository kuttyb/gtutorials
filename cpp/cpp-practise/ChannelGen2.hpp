//
//  ChannelGen2.h
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/14/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef ChannelGen2_h
#define ChannelGen2_h

#pragma mark - Gen2
template <typename ChipDispatch>
class ChannelGen2 : public ChannelBase<ChipDispatch> {
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        ChannelBase<ChipDispatch>::init();
    }
    
    void compute() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};


#endif /* ChannelGen2_h */
