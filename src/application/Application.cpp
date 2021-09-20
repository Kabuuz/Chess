#include <SFML/Graphics.hpp>
#include <iostream>
#include <mygame/application/Application.hpp>

namespace application
{
void Application::exit() const
{
    std::cout << "Exiting with code: " << static_cast<int>(status_) << std::endl;
}

void Application::setApplicationStatus(ApplicationStatus status)
{
    switch (status)
    {
        case ApplicationStatus::NoError:
            //TODO
            break;
        case ApplicationStatus::Warning:
            //TODO
            break;
        case ApplicationStatus::Fatal:
            //TODO
            break;
        default:
            break;
    }
}

}  // namespace application
