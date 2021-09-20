#ifndef INC_MYGAME_APPLICATION_FWD
#define INC_MYGAME_APPLICATION_FWD

#include <memory>

namespace application
{
class IApplication;
using IApplicationPtr = std::unique_ptr<IApplication>;

}  // namespace application

#endif  // INC_MYGAME_APPLICATION_FWD
