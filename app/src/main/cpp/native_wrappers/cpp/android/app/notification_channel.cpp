#include "android\app\notification_channel.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\char_sequence.hpp"
#include "java\lang\string.hpp"

namespace android {
namespace app {

namespace {

jobject CreateJavaNotificationChannelObject(const ::java::lang::String& id, const ::java::lang::CharSequence& name, int32_t importance) {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(NotificationChannel::GetClass(), "<init>", "(Ljava/lang/String;Ljava/lang/CharSequence;I)V");
  return env->NewObject(NotificationChannel::GetClass(), method_id, id.GetImpl(), name.GetImpl(), importance);
}

}  // namespace

jclass NotificationChannel::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/app/NotificationChannel");
  return cached_class;
}

void NotificationChannel::destroy(const NotificationChannel* object)
{
  delete object;
}

NotificationChannel::NotificationChannel(const ::java::lang::String& id, const ::java::lang::CharSequence& name, int32_t importance) : NotificationChannel(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaNotificationChannelObject(id, name, importance)).Get()) {}

void NotificationChannel::setDescription(const ::java::lang::String& description) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "setDescription", "(Ljava/lang/String;)V");
  env->CallVoidMethod(GetImpl(), method_id, description.GetImpl());
}

}  // namespace app
}  // namespace android

