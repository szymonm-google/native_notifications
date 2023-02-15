#ifndef CPP_ANDROIDX_CORE_APP_NOTIFICATIONCOMPAT
#define CPP_ANDROIDX_CORE_APP_NOTIFICATIONCOMPAT

#include <memory>
#include "android\app\notification.hpp"
#include "android\content\context.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\char_sequence.hpp"
#include "java\lang\string.hpp"

namespace androidx {
namespace core {
namespace app {

class NotificationCompat : virtual public ::gni::Object
{
public:
    class Builder;

    static jclass GetClass();
    static void destroy(const NotificationCompat* object);
    explicit NotificationCompat(jobject object) : ::gni::Object(object) {}
    ~NotificationCompat() override = default;

    class Builder : virtual public ::gni::Object
    {
    public:
        static jclass GetClass();
        static void destroy(const Builder* object);
        explicit Builder(jobject object) : ::gni::Object(object) {}
        ~Builder() override = default;
        explicit Builder(const ::android::content::Context& context, const ::java::lang::String& channelId);
        virtual ::androidx::core::app::NotificationCompat::Builder& setContentText(const ::java::lang::CharSequence& text) const;
        virtual ::androidx::core::app::NotificationCompat::Builder& setContentTitle(const ::java::lang::CharSequence& title) const;
        virtual ::androidx::core::app::NotificationCompat::Builder& setSmallIcon(int32_t icon) const;
        virtual ::androidx::core::app::NotificationCompat::Builder& setPriority(int32_t pri) const;
        virtual ::android::app::Notification& build() const;
    };
};

}  // namespace app
}  // namespace core
}  // namespace androidx

#endif  // CPP_ANDROIDX_CORE_APP_NOTIFICATIONCOMPAT

