#ifndef MYGAME_APPLICATION_APPLICATION_HPP
#define MYGAME_APPLICATION_APPLICATION_HPP

#include <mygame/application/IApplication.hpp>

namespace application
{
enum class ApplicationStatus
{
    NoError = 0,
    Warning = -1,
    Fatal = -2
};

class Application : public IApplication
{
public:
    virtual void exit() const override;

    void setApplicationStatus(ApplicationStatus status);

private:
    ApplicationStatus status_;
};

}  // namespace application

#endif  // MYGAME_APPLICATION_APPLICATION_HPP
