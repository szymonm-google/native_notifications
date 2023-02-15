#ifndef ANDROIDX_CORE_APP_NOTIFICATIONCOMPAT_H_
#define ANDROIDX_CORE_APP_NOTIFICATIONCOMPAT_H_

#include <cstdint>
#include <jni.h>
#include "android\app\notification.h"
#include "android\content\context.h"
#include "java\lang\char_sequence.h"
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NotificationCompat_ NotificationCompat;

typedef struct NotificationCompat_Builder_ NotificationCompat_Builder;

/// Wraps a JNI reference with NotificationCompat object.
/// @param jobj A JNI reference to be wrapped with NotificationCompat object.
/// @see NotificationCompat_destroy
NotificationCompat* NotificationCompat_wrapJniReference(jobject jobj);

jobject NotificationCompat_getJniReference(const NotificationCompat* notification_compat);

/// Destroys notification_compat and all internal resources related to it. This function should be
/// called when notification_compat is no longer needed.
/// @param notification_compat An object to be destroyed.
void NotificationCompat_destroy(const NotificationCompat* notification_compat);

/// Wraps a JNI reference with NotificationCompat_Builder object.
/// @param jobj A JNI reference to be wrapped with NotificationCompat_Builder object.
/// @see NotificationCompat_Builder_destroy
NotificationCompat_Builder* NotificationCompat_Builder_wrapJniReference(jobject jobj);

jobject NotificationCompat_Builder_getJniReference(const NotificationCompat_Builder* notification_compat_builder);

NotificationCompat_Builder* NotificationCompat_Builder_construct(Context* context, String* channel_id);

/// Destroys notification_compat_builder and all internal resources related to it. This function should be
/// called when notification_compat_builder is no longer needed.
/// @param notification_compat_builder An object to be destroyed.
void NotificationCompat_Builder_destroy(const NotificationCompat_Builder* notification_compat_builder);

NotificationCompat_Builder* NotificationCompat_Builder_setContentText(const NotificationCompat_Builder* notification_compat_builder, CharSequence* text);

NotificationCompat_Builder* NotificationCompat_Builder_setContentTitle(const NotificationCompat_Builder* notification_compat_builder, CharSequence* title);

NotificationCompat_Builder* NotificationCompat_Builder_setSmallIcon(const NotificationCompat_Builder* notification_compat_builder, int32_t icon);

NotificationCompat_Builder* NotificationCompat_Builder_setPriority(const NotificationCompat_Builder* notification_compat_builder, int32_t pri);

Notification* NotificationCompat_Builder_build(const NotificationCompat_Builder* notification_compat_builder);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // ANDROIDX_CORE_APP_NOTIFICATIONCOMPAT_H_
