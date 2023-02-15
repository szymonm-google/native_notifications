#ifndef CPP_ANDROID_CONTENT_CONTEXT
#define CPP_ANDROID_CONTENT_CONTEXT

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"
#include "java\lang\object.hpp"
#include "java\lang\string.hpp"

namespace android {
namespace content {

class Context : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const Context* object);
    explicit Context(jobject object) : ::gni::Object(object) {}
    ~Context() override = default;
    virtual ::java::lang::Object& getSystemService(const ::java::lang::String& name) const;
};

}  // namespace content
}  // namespace android

#endif  // CPP_ANDROID_CONTENT_CONTEXT

