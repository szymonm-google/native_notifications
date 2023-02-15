#include "java\lang\char_sequence.h"

#include "java\lang\char_sequence.hpp"

CharSequence* CharSequence_wrapJniReference(jobject jobj) {
  return reinterpret_cast<CharSequence*>(new ::java::lang::CharSequence(jobj));
}

jobject CharSequence_getJniReference(const CharSequence* char_sequence) {
  return reinterpret_cast<const ::java::lang::CharSequence*>(char_sequence)->GetImpl();
}

void CharSequence_destroy(const CharSequence* char_sequence) {
  ::java::lang::CharSequence::destroy(reinterpret_cast<const ::java::lang::CharSequence*>(char_sequence));
}
