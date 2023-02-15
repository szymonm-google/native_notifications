#ifndef ANDROID_APP_NOTIFICATIONCHANNEL_H_
#define ANDROID_APP_NOTIFICATIONCHANNEL_H_

#include <cstdint>
#include <jni.h>
#include "java\lang\char_sequence.h"
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NotificationChannel_ NotificationChannel;

/// Wraps a JNI reference with NotificationChannel object.
/// @param jobj A JNI reference to be wrapped with NotificationChannel object.
/// @see NotificationChannel_destroy
NotificationChannel* NotificationChannel_wrapJniReference(jobject jobj);

jobject NotificationChannel_getJniReference(const NotificationChannel* notification_channel);

NotificationChannel* NotificationChannel_construct(String* id, CharSequence* name, int32_t importance);

/// Destroys notification_channel and all internal resources related to it. This function should be
/// called when notification_channel is no longer needed.
/// @param notification_channel An object to be destroyed.
void NotificationChannel_destroy(const NotificationChannel* notification_channel);

void NotificationChannel_setDescription(const NotificationChannel* notification_channel, String* description);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_APP_NOTIFICATIONCHANNEL_H_
