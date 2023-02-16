#include <jni.h>
#include <string>

#include "gni/gni.h"
#include "gni/common/logger.h"
#include "java/lang/object.h"
#include "java/lang/string.h"
#include "java/lang/char_sequence.h"
#include "androidx/core/app/notification_manager_compat.h"
#include "androidx/core/app/notification_compat.h"
#include "android/content/context.h"
#include "android/app/notification.h"
#include "android/app/notification_manager.h"
#include "android/app/notification_channel.h"

const int32_t IMPORTANCE_HIGH = 4;  // NotificationManager.IMPORTANCE_HIGH
const int32_t PRIORITY_MAX = 2;  // NotificationCompat.PRIORITY_MAX
const int32_t NOTIFICATION_ID = 123;  // A user defined notification id.

// Converts C string into CharSequence.
CharSequence *CharSequenceFromCString(const char *text) {
    String *string = String_fromCString(text);
    // Cast String to CharSequence. In Java, a String implements CharSequence.
    CharSequence *result = GNI_CAST(CharSequence, String, string);
    // Casting creates a new object, so it needs to be destroyed as normal.
    String_destroy(string);
    return result;
}

// Creates a notification.
Notification *
CreateNotification(Context *context, String *channel_id, const char *title, const char *content,
                   int32_t icon_id) {
    // Convert C strings to CharSequence.
    CharSequence *title_chars = CharSequenceFromCString(title);
    CharSequence *content_chars = CharSequenceFromCString(content);

    // Create a NotificationCompat.Builder and set all required properties.
    NotificationCompat_Builder *notification_builder = NotificationCompat_Builder_construct(context,
                                                                                            channel_id);
    NotificationCompat_Builder_setContentTitle(notification_builder,
                                               title_chars);
    NotificationCompat_Builder_setContentText(notification_builder, content_chars);
    NotificationCompat_Builder_setSmallIcon(notification_builder, icon_id);
    NotificationCompat_Builder_setPriority(notification_builder, PRIORITY_MAX);

    // Build a notification.
    Notification *notification = NotificationCompat_Builder_build(notification_builder);

    // Clean up allocated objects.
    NotificationCompat_Builder_destroy(notification_builder);
    CharSequence_destroy(title_chars);
    CharSequence_destroy(content_chars);

    return notification;
}

void CreateNotificationChannel(Context *context, String *channel_id) {
    CharSequence *channel_name = CharSequenceFromCString("channel name");
    String *channel_description = String_fromCString("channel description");
    String *system_service_name = String_fromCString("notification");
    NotificationChannel *channel = NotificationChannel_construct(channel_id,
                                                                 channel_name,
                                                                 IMPORTANCE_HIGH);
    NotificationChannel_setDescription(channel, channel_description);

    Object *notification_manager_as_object = Context_getSystemService(context,
                                                                      system_service_name);
    NotificationManager *notification_manager = GNI_CAST(NotificationManager, Object,
                                                         notification_manager_as_object);

    NotificationManager_createNotificationChannel(notification_manager, channel);

    CharSequence_destroy(channel_name);
    String_destroy(channel_description);
    String_destroy(system_service_name);
    NotificationChannel_destroy(channel);
    Object_destroy(notification_manager_as_object);
    NotificationManager_destroy(notification_manager);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_android_nativenotifications_MainActivity_showNotification(
        JNIEnv *env,
        jobject main_activity,
        int icon_id) {

    JavaVM *java_vm;
    env->GetJavaVM(&java_vm);

    // Initialize the GNI runtime. This function needs to be called before any call to generated code.
    GniCore_init(java_vm, main_activity);

    // Create a Context object by wrapping an existing JNI reference.
    Context *context = Context_wrapJniReference(main_activity);

    // Create a String object.
    String *channel_id = String_fromCString("new_messages");

    // Create a notification channel.
    CreateNotificationChannel(context, channel_id);

    // Create a notification with a given title, content, and icon.
    Notification *notification = CreateNotification(context, channel_id,
                                                    "My Native Notification",
                                                    "Hello!", icon_id);

    // Create a notification manager and use it to show the notification.
    NotificationManagerCompat *notification_manager = NotificationManagerCompat_from(context);
    NotificationManagerCompat_notify(notification_manager, NOTIFICATION_ID, notification);

    // Destroy all objects.
    Context_destroy(context);
    String_destroy(channel_id);
    Notification_destroy(notification);
    NotificationManagerCompat_destroy(notification_manager);
}
