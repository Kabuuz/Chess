#ifndef MYGAME_APPLICATION_APPLICATION_HPP_
#define MYGAME_APPLICATION_APPLICATION_HPP_

#include <mygame/application/IApplication.hpp>

namespace application{

class Application : public IApplication
{
public:
    virtual void start() const override;
    virtual void exit() const override;
};

}

#endif // MYGAME_APPLICATION_APPLICATION_HPP_
