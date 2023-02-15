#include "androidx\core\app\notification_compat.h"

#include "androidx\core\app\notification_compat.hpp"

NotificationCompat* NotificationCompat_wrapJniReference(jobject jobj) {
  return reinterpret_cast<NotificationCompat*>(new ::androidx::core::app::NotificationCompat(jobj));
}

jobject NotificationCompat_getJniReference(const NotificationCompat* notification_compat) {
  return reinterpret_cast<const ::androidx::core::app::NotificationCompat*>(notification_compat)->GetImpl();
}

void NotificationCompat_destroy(const NotificationCompat* notification_compat) {
  ::androidx::core::app::NotificationCompat::destroy(reinterpret_cast<const ::androidx::core::app::NotificationCompat*>(notification_compat));
}

NotificationCompat_Builder* NotificationCompat_Builder_wrapJniReference(jobject jobj) {
  return reinterpret_cast<NotificationCompat_Builder*>(new ::androidx::core::app::NotificationCompat::Builder(jobj));
}

jobject NotificationCompat_Builder_getJniReference(const NotificationCompat_Builder* notification_compat_builder) {
  return reinterpret_cast<const ::androidx::core::app::NotificationCompat::Builder*>(notification_compat_builder)->GetImpl();
}

NotificationCompat_Builder* NotificationCompat_Builder_construct(Context* context, String* channel_id) {
  return reinterpret_cast<NotificationCompat_Builder*>(new ::androidx::core::app::NotificationCompat::Builder(*reinterpret_cast<const ::android::content::Context*>(context), *reinterpret_cast<const ::java::lang::String*>(channel_id)));
}

void NotificationCompat_Builder_destroy(const NotificationCompat_Builder* notification_compat_builder) {
  ::androidx::core::app::NotificationCompat::Builder::destroy(reinterpret_cast<const ::androidx::core::app::NotificationCompat::Builder*>(notification_compat_builder));
}

NotificationCompat_Builder* NotificationCompat_Builder_setContentText(const NotificationCompat_Builder* notification_compat_builder, CharSequence* text) {
  return reinterpret_cast<NotificationCompat_Builder*>(&reinterpret_cast<const ::androidx::core::app::NotificationCompat::Builder*>(notification_compat_builder)->setContentText(*reinterpret_cast<const ::java::lang::CharSequence*>(text)));
}

NotificationCompat_Builder* NotificationCompat_Builder_setContentTitle(const NotificationCompat_Builder* notification_compat_builder, CharSequence* title) {
  return reinterpret_cast<NotificationCompat_Builder*>(&reinterpret_cast<const ::androidx::core::app::NotificationCompat::Builder*>(notification_compat_builder)->setContentTitle(*reinterpret_cast<const ::java::lang::CharSequence*>(title)));
}

NotificationCompat_Builder* NotificationCompat_Builder_setSmallIcon(const NotificationCompat_Builder* notification_compat_builder, int32_t icon) {
  return reinterpret_cast<NotificationCompat_Builder*>(&reinterpret_cast<const ::androidx::core::app::NotificationCompat::Builder*>(notification_compat_builder)->setSmallIcon(icon));
}

NotificationCompat_Builder* NotificationCompat_Builder_setPriority(const NotificationCompat_Builder* notification_compat_builder, int32_t pri) {
  return reinterpret_cast<NotificationCompat_Builder*>(&reinterpret_cast<const ::androidx::core::app::NotificationCompat::Builder*>(notification_compat_builder)->setPriority(pri));
}

Notification* NotificationCompat_Builder_build(const NotificationCompat_Builder* notification_compat_builder) {
  return reinterpret_cast<Notification*>(&reinterpret_cast<const ::androidx::core::app::NotificationCompat::Builder*>(notification_compat_builder)->build());
}
