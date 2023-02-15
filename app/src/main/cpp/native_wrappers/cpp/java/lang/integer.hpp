#ifndef CPP_JAVA_LANG_INTEGER
#define CPP_JAVA_LANG_INTEGER

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

class Integer : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Integer* object);
    explicit Integer(jobject object) : ::gni::Object(object) {}
    ~Integer() override = default;
    explicit Integer(int32_t value);
    virtual int32_t intValue() const;
};

}  // namespace lang
}  // namespace java

#endif  // CPP_JAVA_LANG_INTEGER

