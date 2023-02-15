#include "android\app\notification_manager.h"

#include "android\app\notification_manager.hpp"

NotificationManager* NotificationManager_wrapJniReference(jobject jobj) {
  return reinterpret_cast<NotificationManager*>(new ::android::app::NotificationManager(jobj));
}

jobject NotificationManager_getJniReference(const NotificationManager* notification_manager) {
  return reinterpret_cast<const ::android::app::NotificationManager*>(notification_manager)->GetImpl();
}

void NotificationManager_destroy(const NotificationManager* notification_manager) {
  ::android::app::NotificationManager::destroy(reinterpret_cast<const ::android::app::NotificationManager*>(notification_manager));
}

void NotificationManager_createNotificationChannel(const NotificationManager* notification_manager, NotificationChannel* channel) {
  reinterpret_cast<const ::android::app::NotificationManager*>(notification_manager)->createNotificationChannel(*reinterpret_cast<const ::android::app::NotificationChannel*>(channel));
}
