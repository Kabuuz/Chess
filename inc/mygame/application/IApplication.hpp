#ifndef MYGAME_APPLICATION_IAPPLICATION_HPP_
#define MYGAME_APPLICATION_IAPPLICATION_HPP_

namespace application{

class IApplication
{
public:
    virtual void start() const = 0;
    virtual void exit() const = 0;

    virtual ~IApplication() = default;
};

}

#endif // MYGAME_APPLICATION_IAPPLICATION_HPP_
