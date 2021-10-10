#ifndef MYGAME_APPLICATION_IAPPLICATION_HPP
#define MYGAME_APPLICATION_IAPPLICATION_HPP

namespace application
{
class IApplication
{
   public:
    virtual void start() const = 0;
    virtual void exit() const = 0;

    virtual ~IApplication() = default;
};

}  // namespace application

#endif  // MYGAME_APPLICATION_IAPPLICATION_HPP
