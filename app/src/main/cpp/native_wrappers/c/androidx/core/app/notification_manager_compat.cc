#include "androidx\core\app\notification_manager_compat.h"

#include "androidx\core\app\notification_manager_compat.hpp"

NotificationManagerCompat* NotificationManagerCompat_wrapJniReference(jobject jobj) {
  return reinterpret_cast<NotificationManagerCompat*>(new ::androidx::core::app::NotificationManagerCompat(jobj));
}

jobject NotificationManagerCompat_getJniReference(const NotificationManagerCompat* notification_manager_compat) {
  return reinterpret_cast<const ::androidx::core::app::NotificationManagerCompat*>(notification_manager_compat)->GetImpl();
}

void NotificationManagerCompat_destroy(const NotificationManagerCompat* notification_manager_compat) {
  ::androidx::core::app::NotificationManagerCompat::destroy(reinterpret_cast<const ::androidx::core::app::NotificationManagerCompat*>(notification_manager_compat));
}

NotificationManagerCompat* NotificationManagerCompat_from(Context* context) {
  return reinterpret_cast<NotificationManagerCompat*>(&::androidx::core::app::NotificationManagerCompat::from(*reinterpret_cast<const ::android::content::Context*>(context)));
}

void NotificationManagerCompat_notify(const NotificationManagerCompat* notification_manager_compat, int32_t id, Notification* notification) {
  reinterpret_cast<const ::androidx::core::app::NotificationManagerCompat*>(notification_manager_compat)->notify(id, *reinterpret_cast<const ::android::app::Notification*>(notification));
}
