#include "android\app\notification_channel.h"

#include "android\app\notification_channel.hpp"

NotificationChannel* NotificationChannel_wrapJniReference(jobject jobj) {
  return reinterpret_cast<NotificationChannel*>(new ::android::app::NotificationChannel(jobj));
}

jobject NotificationChannel_getJniReference(const NotificationChannel* notification_channel) {
  return reinterpret_cast<const ::android::app::NotificationChannel*>(notification_channel)->GetImpl();
}

NotificationChannel* NotificationChannel_construct(String* id, CharSequence* name, int32_t importance) {
  return reinterpret_cast<NotificationChannel*>(new ::android::app::NotificationChannel(*reinterpret_cast<const ::java::lang::String*>(id), *reinterpret_cast<const ::java::lang::CharSequence*>(name), importance));
}

void NotificationChannel_destroy(const NotificationChannel* notification_channel) {
  ::android::app::NotificationChannel::destroy(reinterpret_cast<const ::android::app::NotificationChannel*>(notification_channel));
}

void NotificationChannel_setDescription(const NotificationChannel* notification_channel, String* description) {
  reinterpret_cast<const ::android::app::NotificationChannel*>(notification_channel)->setDescription(*reinterpret_cast<const ::java::lang::String*>(description));
}
