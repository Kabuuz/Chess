#include <gmock/gmock.h>

#include <mygame/temp/IDummy.hpp>

namespace temp
{

class IDummyMock : public IDummy
{
    public:
    MOCK_METHOD0(method1, void());
};

}