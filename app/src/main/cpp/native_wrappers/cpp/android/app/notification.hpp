#ifndef CPP_ANDROID_APP_NOTIFICATION
#define CPP_ANDROID_APP_NOTIFICATION

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace app {

class Notification : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Notification* object);
    explicit Notification(jobject object) : ::gni::Object(object) {}
    ~Notification() override = default;
};

}  // namespace app
}  // namespace android

#endif  // CPP_ANDROID_APP_NOTIFICATION

