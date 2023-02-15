#include "java\lang\object.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace java {
namespace lang {

jclass Object::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("java/lang/Object");
  return cached_class;
}

void Object::destroy(const Object* object)
{
  delete object;
}

::java::lang::String& Object::toString() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "toString", "()Ljava/lang/String;");
  ::java::lang::String* ret = new ::java::lang::String(gni::common::ScopedLocalRef<jobject>(env, env->CallObjectMethod(GetImpl(), method_id)).Get());
  return *ret;
}

}  // namespace lang
}  // namespace java

