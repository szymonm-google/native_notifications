#ifndef ANDROID_APP_NOTIFICATION_H_
#define ANDROID_APP_NOTIFICATION_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Notification_ Notification;

/// Wraps a JNI reference with Notification object.
/// @param jobj A JNI reference to be wrapped with Notification object.
/// @see Notification_destroy
Notification* Notification_wrapJniReference(jobject jobj);

jobject Notification_getJniReference(const Notification* notification);

/// Destroys notification and all internal resources related to it. This function should be
/// called when notification is no longer needed.
/// @param notification An object to be destroyed.
void Notification_destroy(const Notification* notification);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROID_APP_NOTIFICATION_H_
