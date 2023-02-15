#ifndef JAVA_LANG_INTEGER_H_
#define JAVA_LANG_INTEGER_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Integer_ Integer;

/// Wraps a JNI reference with Integer object.
/// @param jobj A JNI reference to be wrapped with Integer object.
/// @see Integer_destroy
Integer* Integer_wrapJniReference(jobject jobj);

jobject Integer_getJniReference(const Integer* integer);

Integer* Integer_construct(int32_t value);

/// Destroys integer and all internal resources related to it. This function should be
/// called when integer is no longer needed.
/// @param integer An object to be destroyed.
void Integer_destroy(const Integer* integer);

int32_t Integer_intValue(const Integer* integer);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // JAVA_LANG_INTEGER_H_
