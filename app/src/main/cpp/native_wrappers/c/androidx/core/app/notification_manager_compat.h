#ifndef ANDROIDX_CORE_APP_NOTIFICATIONMANAGERCOMPAT_H_
#define ANDROIDX_CORE_APP_NOTIFICATIONMANAGERCOMPAT_H_

#include <cstdint>
#include <jni.h>
#include "android\app\notification.h"
#include "android\content\context.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NotificationManagerCompat_ NotificationManagerCompat;

/// Wraps a JNI reference with NotificationManagerCompat object.
/// @param jobj A JNI reference to be wrapped with NotificationManagerCompat object.
/// @see NotificationManagerCompat_destroy
NotificationManagerCompat* NotificationManagerCompat_wrapJniReference(jobject jobj);

jobject NotificationManagerCompat_getJniReference(const NotificationManagerCompat* notification_manager_compat);

/// Destroys notification_manager_compat and all internal resources related to it. This function should be
/// called when notification_manager_compat is no longer needed.
/// @param notification_manager_compat An object to be destroyed.
void NotificationManagerCompat_destroy(const NotificationManagerCompat* notification_manager_compat);

NotificationManagerCompat* NotificationManagerCompat_from(Context* context);

void NotificationManagerCompat_notify(const NotificationManagerCompat* notification_manager_compat, int32_t id, Notification* notification);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROIDX_CORE_APP_NOTIFICATIONMANAGERCOMPAT_H_
