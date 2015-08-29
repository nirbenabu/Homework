#ifndef ARRAY_EXCEPTION_HPP_INCLUDED
#define ARRAY_EXCEPTION_HPP_INCLUDED

#if !defined (NULL)
#define NULL ((void*)0)
#endif

class ArrayException {

private:
    char* _info;
public:
    ArrayException(char* info=(char*)NULL): _info(info) { }
    virtual void printInfo();
};

#endif // ARRAY_EXCEPTION_HPP_INCLUDED
