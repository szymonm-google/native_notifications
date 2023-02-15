#ifndef JAVA_LANG_OBSERVER_H_
#define JAVA_LANG_OBSERVER_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Observer_ Observer;

typedef void (*Observer_onActionCallback)();

/// Wraps a JNI reference with Observer object.
/// @param jobj A JNI reference to be wrapped with Observer object.
/// @see Observer_destroy
Observer* Observer_wrapJniReference(jobject jobj);

jobject Observer_getJniReference(const Observer* observer);

Observer* Observer_implementInterface(Observer_onActionCallback observer_on_action_callback);

/// Destroys observer and all internal resources related to it. This function should be
/// called when observer is no longer needed.
/// @param observer An object to be destroyed.
void Observer_destroy(const Observer* observer);

void Observer_onAction(const Observer* observer);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // JAVA_LANG_OBSERVER_H_
