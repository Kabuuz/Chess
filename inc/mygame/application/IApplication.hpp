#ifndef INC_MYGAME_APPLICATION_IAPPLICATION
#define INC_MYGAME_APPLICATION_IAPPLICATION

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

#endif  // INC_MYGAME_APPLICATION_IAPPLICATION
