#include "android\app\notification_manager.hpp"
#include <memory>
#include "android\app\notification_channel.hpp"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace app {

jclass NotificationManager::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/app/NotificationManager");
  return cached_class;
}

void NotificationManager::destroy(const NotificationManager* object)
{
  delete object;
}

void NotificationManager::createNotificationChannel(const ::android::app::NotificationChannel& channel) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "createNotificationChannel", "(Landroid/app/NotificationChannel;)V");
  env->CallVoidMethod(GetImpl(), method_id, channel.GetImpl());
}

}  // namespace app
}  // namespace android

