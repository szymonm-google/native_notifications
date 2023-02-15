#ifndef CPP_JAVA_LANG_CHARSEQUENCE
#define CPP_JAVA_LANG_CHARSEQUENCE

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

class CharSequence : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const CharSequence* object);
    explicit CharSequence(jobject object) : ::gni::Object(object) {}
    ~CharSequence() override = default;
};

}  // namespace lang
}  // namespace java

#endif  // CPP_JAVA_LANG_CHARSEQUENCE

