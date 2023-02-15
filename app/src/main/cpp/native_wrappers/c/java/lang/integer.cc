#include "java\lang\integer.h"

#include "java\lang\integer.hpp"

Integer* Integer_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Integer*>(new ::java::lang::Integer(jobj));
}

jobject Integer_getJniReference(const Integer* integer) {
  return reinterpret_cast<const ::java::lang::Integer*>(integer)->GetImpl();
}

Integer* Integer_construct(int32_t value) {
  return reinterpret_cast<Integer*>(new ::java::lang::Integer(value));
}

void Integer_destroy(const Integer* integer) {
  ::java::lang::Integer::destroy(reinterpret_cast<const ::java::lang::Integer*>(integer));
}

int32_t Integer_intValue(const Integer* integer) {
  return reinterpret_cast<const ::java::lang::Integer*>(integer)->intValue();
}
