#include "java\lang\integer.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

namespace {

jobject CreateJavaIntegerObject(int32_t value) {
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(Integer::GetClass(), "<init>", "(I)V");
  return env->NewObject(Integer::GetClass(), method_id, value);
}

}  // namespace

jclass Integer::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("java/lang/Integer");
  return cached_class;
}

void Integer::destroy(const Integer* object)
{
  delete object;
}

Integer::Integer(int32_t value) : Integer(gni::common::ScopedLocalRef<jobject>(gni::GniCore::GetInstance()->GetJniEnv(), CreateJavaIntegerObject(value)).Get()) {}

int32_t Integer::intValue() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "intValue", "()I");
  int32_t ret = env->CallIntMethod(GetImpl(), method_id);
  return ret;
}

}  // namespace lang
}  // namespace java

