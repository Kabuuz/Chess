#ifndef TEMP_IDUMMY_HPP
#define TEMP_IDUMMY_HPP

namespace temp{

class IDummy
{
public:
    virtual void method1() = 0;
    virtual ~IDummy() = default; 
};

}

#endif // TEMP_IDUMMY_HPP
