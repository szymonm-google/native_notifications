#ifndef CPP_ANDROID_APP_NOTIFICATIONCHANNEL
#define CPP_ANDROID_APP_NOTIFICATIONCHANNEL

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\char_sequence.hpp"
#include "java\lang\string.hpp"

namespace android {
namespace app {

class NotificationChannel : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const NotificationChannel* object);
    explicit NotificationChannel(jobject object) : ::gni::Object(object) {}
    ~NotificationChannel() override = default;
    explicit NotificationChannel(const ::java::lang::String& id, const ::java::lang::CharSequence& name, int32_t importance);
    virtual void setDescription(const ::java::lang::String& description) const;
};

}  // namespace app
}  // namespace android

#endif  // CPP_ANDROID_APP_NOTIFICATIONCHANNEL

