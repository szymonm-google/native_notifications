#include "java\lang\observer.hpp"
#include <memory>
#include "gni/common/interface_proxy.h"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

namespace {

jobject ObserverProxyCallback(void* object_pointer, const char* method_name, jobject* arguments, uint32_t arguments_count)
{
  if (strcmp(method_name, "onAction") == 0)
  {
    reinterpret_cast<Observer*>(object_pointer)->on_action_callback_();
  }

  return nullptr;
}

}  // namespace

Observer* Observer::ImplementInterface(onActionCallback on_action_callback)
{
  Observer* instance = new Observer(nullptr);
  instance->SetImpl(gni::GniCore::GetInstance()->GetJniEnv()->NewGlobalRef(gni::common::interface_proxy::RegisterCallback("java/lang/Observer", instance, ObserverProxyCallback)));
  instance->on_action_callback_ = on_action_callback;
  return instance;
}

jclass Observer::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("java/lang/Observer");
  return cached_class;
}

void Observer::destroy(const Observer* object)
{
  delete object;
}

void Observer::onAction() const
{
  JNIEnv *env = gni::GniCore::GetInstance()->GetJniEnv();
  static const jmethodID method_id = env->GetMethodID(GetClass(), "onAction", "()V");
  env->CallVoidMethod(GetImpl(), method_id);
}

}  // namespace lang
}  // namespace java

