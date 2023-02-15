#ifndef CPP_ANDROID_APP_NOTIFICATIONMANAGER
#define CPP_ANDROID_APP_NOTIFICATIONMANAGER

#include <memory>
#include "android\app\notification_channel.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace app {

class NotificationManager : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const NotificationManager* object);
    explicit NotificationManager(jobject object) : ::gni::Object(object) {}
    ~NotificationManager() override = default;
    virtual void createNotificationChannel(const ::android::app::NotificationChannel& channel) const;
};

}  // namespace app
}  // namespace android

#endif  // CPP_ANDROID_APP_NOTIFICATIONMANAGER

