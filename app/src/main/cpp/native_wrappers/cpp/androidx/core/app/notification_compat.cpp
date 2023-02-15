#include "androidx\core\app\notification_compat.hpp"
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

namespace {

jobject CreateJavaNotificationCompatBuilderObject(const ::android::content::Context& context, const ::java::lang::String& channelId) {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(NotificationCompat::Builder::GetClass(), "<init>", "(Landroid/content/Context;Ljava/lang/String;)V");
  return env->NewObject(NotificationCompat::Builder::GetClass(), method_id, context.GetImpl(), channelId.GetImpl());
}

}  // namespace

jclass NotificationCompat::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("androidx/core/app/NotificationCompat");
  return cached_class;
}

void NotificationCompat::destroy(const NotificationCompat* object)
{
  delete object;
}

jclass NotificationCompat::Builder::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("androidx/core/app/NotificationCompat$Builder");
  return cached_class;
}

void NotificationCompat::Builder::destroy(const NotificationCompat::Builder* object)
{
  delete object;
}

NotificationCompat::Builder::Builder(const ::android::content::Context& context, const ::java::lang::String& channelId) : NotificationCompat::Builder(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaNotificationCompatBuilderObject(context, channelId)).Get()) {}

::androidx::core::app::NotificationCompat::Builder& NotificationCompat::Builder::setContentText(const ::java::lang::CharSequence& text) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setContentText", "(Ljava/lang/CharSequence;)Landroidx/core/app/NotificationCompat$Builder;");
  ::androidx::core::app::NotificationCompat::Builder* ret = new ::androidx::core::app::NotificationCompat::Builder(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id, text.GetImpl())).Get());
  return *ret;
}

::androidx::core::app::NotificationCompat::Builder& NotificationCompat::Builder::setContentTitle(const ::java::lang::CharSequence& title) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setContentTitle", "(Ljava/lang/CharSequence;)Landroidx/core/app/NotificationCompat$Builder;");
  ::androidx::core::app::NotificationCompat::Builder* ret = new ::androidx::core::app::NotificationCompat::Builder(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id, title.GetImpl())).Get());
  return *ret;
}

::androidx::core::app::NotificationCompat::Builder& NotificationCompat::Builder::setSmallIcon(int32_t icon) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setSmallIcon", "(I)Landroidx/core/app/NotificationCompat$Builder;");
  ::androidx::core::app::NotificationCompat::Builder* ret = new ::androidx::core::app::NotificationCompat::Builder(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id, icon)).Get());
  return *ret;
}

::androidx::core::app::NotificationCompat::Builder& NotificationCompat::Builder::setPriority(int32_t pri) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setPriority", "(I)Landroidx/core/app/NotificationCompat$Builder;");
  ::androidx::core::app::NotificationCompat::Builder* ret = new ::androidx::core::app::NotificationCompat::Builder(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id, pri)).Get());
  return *ret;
}

::android::app::Notification& NotificationCompat::Builder::build() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "build", "()Landroid/app/Notification;");
  ::android::app::Notification* ret = new ::android::app::Notification(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

}  // namespace app
}  // namespace core
}  // namespace androidx

