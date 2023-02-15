#include "androidx\core\app\notification_manager_compat.hpp"
#include <memory>
#include "android\app\notification.hpp"
#include "android\content\context.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace androidx {
namespace core {
namespace app {

jclass NotificationManagerCompat::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("androidx/core/app/NotificationManagerCompat");
  return cached_class;
}

void NotificationManagerCompat::destroy(const NotificationManagerCompat* object)
{
  delete object;
}

::androidx::core::app::NotificationManagerCompat& NotificationManagerCompat::from(const ::android::content::Context& context)
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetStaticMethodID(GetClass(), "from", "(Landroid/content/Context;)Landroidx/core/app/NotificationManagerCompat;");
  ::androidx::core::app::NotificationManagerCompat* ret = new ::androidx::core::app::NotificationManagerCompat(gni::common::ScopedLocalRef<jobject>(env, env->CallStaticObjectMethod(GetClass(), method_id, context.GetImpl())).Get());
  return *ret;
}

void NotificationManagerCompat::notify(int32_t id, const ::android::app::Notification& notification) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "notify", "(ILandroid/app/Notification;)V");
  env->CallVoidMethod(GetImpl(), method_id, id, notification.GetImpl());
}

}  // namespace app
}  // namespace core
}  // namespace androidx

