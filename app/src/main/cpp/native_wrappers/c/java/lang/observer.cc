#include "java\lang\observer.h"

#include "java\lang\observer.hpp"

Observer* Observer_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Observer*>(new ::java::lang::Observer(jobj));
}

jobject Observer_getJniReference(const Observer* observer) {
  return reinterpret_cast<const ::java::lang::Observer*>(observer)->GetImpl();
}

Observer* Observer_implementInterface(Observer_onActionCallback observer_on_action_callback) {
  return reinterpret_cast<Observer*>(::java::lang::Observer::ImplementInterface(reinterpret_cast<::java::lang::Observer::onActionCallback>(observer_on_action_callback)));
}

void Observer_destroy(const Observer* observer) {
  ::java::lang::Observer::destroy(reinterpret_cast<const ::java::lang::Observer*>(observer));
}

void Observer_onAction(const Observer* observer) {
  reinterpret_cast<const ::java::lang::Observer*>(observer)->onAction();
}
