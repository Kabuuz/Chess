#ifndef MYGAME_APPLICATION_FWD_HPP
#define MYGAME_APPLICATION_FWD_HPP

#include <memory>

namespace application
{
class IApplication;
using IApplicationPtr = std::unique_ptr<IApplication>;

}  // namespace application

#endif  // MYGAME_APPLICATION_FWD_HPP
