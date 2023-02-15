#include "android\app\notification.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace android {
namespace app {

jclass Notification::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/app/Notification");
  return cached_class;
}

void Notification::destroy(const Notification* object)
{
  delete object;
}

}  // namespace app
}  // namespace android

