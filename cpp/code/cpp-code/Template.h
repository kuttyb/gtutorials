//
//  Template.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/23/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_Template_h
#define cpp_cmd_Template_h

// Use CRTP when using Implementation Inheritance
#define CRTP_CAST(T)  static_cast<T*>(this)

// Use this when using Composition for Strategy or Decorator
#define ASSERT_TYPE_START private: static const bool x_y =
#define ASSERT_TYPE_INHERITS_FROM(U, V)   ((U*)NULL == (V*)NULL) &&
#define ASSERT_TYPE_END    false;

#endif
