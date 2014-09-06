//
//  Header.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_Header_h
#define cpp_cmd_Header_h

template <typename T>
class Pipeline {
public:
    void createContext(T  & input);
    void destroyContext(T & input);

#if 0
    void execute(T & input);
    void pushWork(T & input);
#endif
};

template <typename T>
class AsynchronousPipeline : public Pipeline<T> {
public:
    void executeResponse(T & input);
};

template <typename T>
class LongPipeline : public Pipeline<T>{
public:
    void createContext(T & input);
    void destroyContext(T & input);
};

#endif
