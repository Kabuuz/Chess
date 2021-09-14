#ifndef TEMP_DUMMY_HPP
#define TEMP_DUMMY_HPP

#include <mygame/temp/IDummy.hpp>

namespace temp{

class Dummy
{
public:
    Dummy();
    Dummy(IDummy* dummy);

    void hello();

private:
    IDummy* dummy_;
};

}

#endif // TEMP_DUMMY_HPP
