#ifndef CPP_ANDROIDX_CORE_APP_NOTIFICATIONMANAGERCOMPAT
#define CPP_ANDROIDX_CORE_APP_NOTIFICATIONMANAGERCOMPAT

#include <memory>
#include "android\app\notification.hpp"
#include "android\content\context.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace androidx {
namespace core {
namespace app {

class NotificationManagerCompat : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const NotificationManagerCompat* object);
    explicit NotificationManagerCompat(jobject object) : ::gni::Object(object) {}
    ~NotificationManagerCompat() override = default;
    static ::androidx::core::app::NotificationManagerCompat& from(const ::android::content::Context& context);
    virtual void notify(int32_t id, const ::android::app::Notification& notification) const;
};

}  // namespace app
}  // namespace core
}  // namespace androidx

#endif  // CPP_ANDROIDX_CORE_APP_NOTIFICATIONMANAGERCOMPAT

