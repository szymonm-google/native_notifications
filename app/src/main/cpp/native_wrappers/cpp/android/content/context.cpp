#include "android\content\context.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\object.hpp"
#include "java\lang\string.hpp"

namespace android {
namespace content {

jclass Context::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("android/content/Context");
  return cached_class;
}

void Context::destroy(const Context* object)
{
  delete object;
}

::java::lang::Object& Context::getSystemService(const ::java::lang::String& name) const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");
  ::java::lang::Object* ret = new ::java::lang::Object(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id, name.GetImpl())).Get());
  return *ret;
}

}  // namespace content
}  // namespace android

