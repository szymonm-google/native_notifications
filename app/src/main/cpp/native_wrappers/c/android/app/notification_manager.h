#ifndef ANDROID_APP_NOTIFICATIONMANAGER_H_
#define ANDROID_APP_NOTIFICATIONMANAGER_H_

#include <cstdint>
#include <jni.h>
#include "android\app\notification_channel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NotificationManager_ NotificationManager;

/// Wraps a JNI reference with NotificationManager object.
/// @param jobj A JNI reference to be wrapped with NotificationManager object.
/// @see NotificationManager_destroy
NotificationManager* NotificationManager_wrapJniReference(jobject jobj);

jobject NotificationManager_getJniReference(const NotificationManager* notification_manager);

/// Destroys notification_manager and all internal resources related to it. This function should be
/// called when notification_manager is no longer needed.
/// @param notification_manager An object to be destroyed.
void NotificationManager_destroy(const NotificationManager* notification_manager);

void NotificationManager_createNotificationChannel(const NotificationManager* notification_manager, NotificationChannel* channel);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_APP_NOTIFICATIONMANAGER_H_
