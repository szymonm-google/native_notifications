#ifndef JAVA_LANG_CHARSEQUENCE_H_
#define JAVA_LANG_CHARSEQUENCE_H_

#include <cstdint>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CharSequence_ CharSequence;

/// Wraps a JNI reference with CharSequence object.
/// @param jobj A JNI reference to be wrapped with CharSequence object.
/// @see CharSequence_destroy
CharSequence* CharSequence_wrapJniReference(jobject jobj);

jobject CharSequence_getJniReference(const CharSequence* char_sequence);

/// Destroys char_sequence and all internal resources related to it. This function should be
/// called when char_sequence is no longer needed.
/// @param char_sequence An object to be destroyed.
void CharSequence_destroy(const CharSequence* char_sequence);

#ifdef __cplusplus
};  // extern "C"
#endif

#endif  // JAVA_LANG_CHARSEQUENCE_H_
