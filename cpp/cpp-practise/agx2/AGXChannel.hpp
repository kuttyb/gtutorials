//
//  AGXChannel.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXChannel_hpp
#define AGXChannel_hpp

class AGXChannel {
public:
    virtual void init()  = 0;
    virtual void close() = 0;
};

class AGXChannelG4 : public AGXChannel {
public:
    void init()  override;
    void close() override;
};

#endif /* AGXChannel_hpp */
