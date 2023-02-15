#include <jni.h>
#include <string>

#include "gni/gni.h"
#include "gni/common/logger.h"
#include "java/lang/integer.h"
#include "java/lang/object.h"
#include "java/lang/string.h"
#include "java/lang/char_sequence.h"
#include "androidx/core/app/notification_manager_compat.h"
#include "androidx/core/app/notification_compat.h"
#include "android/content/context.h"
#include "android/app/notification.h"
#include "android/app/notification_manager.h"
#include "android/app/notification_channel.h"

#define GNI_CAST(DST_TYPE, SRC_TYPE, SRC_POINTER) DST_TYPE##_wrapJniReference(SRC_TYPE##_getJniReference(SRC_POINTER))

void CreateNotificationChannel(Context *context, String *channel_id) {

    CharSequence *aaa =  GNI_CAST(CharSequence, String, String_fromCString("channel name"));

    String *channel_name = String_fromCString("channel name");
    String *channel_description = String_fromCString("channel description");
    String *system_service_name = String_fromCString("notification");
    uint32_t importance = 4; // NotificationManager.IMPORTANCE_DEFAULT;
    NotificationChannel *channel = NotificationChannel_construct(channel_id,
                                                                 CharSequence_wrapJniReference(
                                                                         String_getJniReference(
                                                                                 channel_name)),
                                                                 importance);
    NotificationChannel_setDescription(channel, channel_description);
    NotificationManager *notification_manager = NotificationManager_wrapJniReference(
            Object_getJniReference(Context_getSystemService(context, system_service_name)));
    NotificationManager_createNotificationChannel(notification_manager, channel);

    String_destroy(channel_name);
    String_destroy(channel_description);
    String_destroy(system_service_name);
    NotificationChannel_destroy(channel);
    NotificationManager_destroy(notification_manager);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_android_nativenotifications_MainActivity_showNotification(
        JNIEnv *env,
        jobject main_activity,
        int icon_id) {

    JavaVM *java_vm;
    env->GetJavaVM(&java_vm);
    GniCore_init(java_vm, main_activity);

    Context *context = Context_wrapJniReference(main_activity);

    String *channel_id = String_fromCString("new_messages");
    CreateNotificationChannel(context, channel_id);

    NotificationCompat_Builder *notification_builder = NotificationCompat_Builder_construct(context,
                                                                                            channel_id);
    String *title = String_fromCString("my title");
    CharSequence *title_chars = CharSequence_wrapJniReference(
            String_getJniReference(title));
    String *content = String_fromCString("my content");
    CharSequence *content_chars = CharSequence_wrapJniReference(
            String_getJniReference(content));
    NotificationCompat_Builder_setContentTitle(notification_builder,
                                               title_chars);
    NotificationCompat_Builder_setContentText(notification_builder, content_chars);
    NotificationCompat_Builder_setSmallIcon(notification_builder, icon_id);
    NotificationCompat_Builder_setPriority(notification_builder, 2);

    Notification *notification = NotificationCompat_Builder_build(notification_builder);

    NotificationManagerCompat *notification_manager = NotificationManagerCompat_from(context);
    NotificationManagerCompat_notify(notification_manager, 11, notification);

    Context_destroy(context);
    String_destroy(channel_id);
    NotificationCompat_Builder_destroy(notification_builder);
    String_destroy(title);
    CharSequence_destroy(title_chars);
    String_destroy(content);
    CharSequence_destroy(content_chars);
    Notification_destroy(notification);
    NotificationManagerCompat_destroy(notification_manager);
}
