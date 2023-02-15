#include "android\app\notification.h"

#include "android\app\notification.hpp"

Notification* Notification_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Notification*>(new ::android::app::Notification(jobj));
}

jobject Notification_getJniReference(const Notification* notification) {
  return reinterpret_cast<const ::android::app::Notification*>(notification)->GetImpl();
}

void Notification_destroy(const Notification* notification) {
  ::android::app::Notification::destroy(reinterpret_cast<const ::android::app::Notification*>(notification));
}
