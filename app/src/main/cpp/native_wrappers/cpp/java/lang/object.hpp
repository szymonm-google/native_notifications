#ifndef CPP_JAVA_LANG_OBJECT
#define CPP_JAVA_LANG_OBJECT

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\string.hpp"

namespace java {
namespace lang {

class Object : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Object* object);
    explicit Object(jobject object) : ::gni::Object(object) {}
    ~Object() override = default;
    virtual ::java::lang::String& toString() const;
};

}  // namespace lang
}  // namespace java

#endif  // CPP_JAVA_LANG_OBJECT

