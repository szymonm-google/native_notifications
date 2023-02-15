#include "java\lang\object.h"

#include "java\lang\object.hpp"

Object* Object_wrapJniReference(jobject jobj) {
  return reinterpret_cast<Object*>(new ::java::lang::Object(jobj));
}

jobject Object_getJniReference(const Object* object) {
  return reinterpret_cast<const ::java::lang::Object*>(object)->GetImpl();
}

void Object_destroy(const Object* object) {
  ::java::lang::Object::destroy(reinterpret_cast<const ::java::lang::Object*>(object));
}

String* Object_toString(const Object* object) {
  return reinterpret_cast<String*>(&reinterpret_cast<const ::java::lang::Object*>(object)->toString());
}
