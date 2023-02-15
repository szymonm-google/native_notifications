#include "java\lang\char_sequence.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

jclass CharSequence::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("java/lang/CharSequence");
  return cached_class;
}

void CharSequence::destroy(const CharSequence* object)
{
  delete object;
}

}  // namespace lang
}  // namespace java

