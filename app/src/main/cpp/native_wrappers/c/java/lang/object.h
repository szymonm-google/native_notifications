#ifndef JAVA_LANG_OBJECT_H_
#define JAVA_LANG_OBJECT_H_

#include <cstdint>
#include <jni.h>
#include "java\lang\string.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Object_ Object;

/// Wraps a JNI reference with Object object.
/// @param jobj A JNI reference to be wrapped with Object object.
/// @see Object_destroy
Object* Object_wrapJniReference(jobject jobj);

jobject Object_getJniReference(const Object* object);

/// Destroys object and all internal resources related to it. This function should be
/// called when object is no longer needed.
/// @param object An object to be destroyed.
void Object_destroy(const Object* object);

String* Object_toString(const Object* object);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // JAVA_LANG_OBJECT_H_
