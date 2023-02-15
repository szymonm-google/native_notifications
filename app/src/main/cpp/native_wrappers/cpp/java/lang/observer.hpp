#ifndef CPP_JAVA_LANG_OBSERVER
#define CPP_JAVA_LANG_OBSERVER

#include <memory>
#include "gni/common/interface_proxy.h"
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

class Observer : virtual public ::gni::Object
{
public:
    using onActionCallback = void (*)();

    static jclass GetClass();
    static void destroy(const Observer* object);
    static Observer* ImplementInterface(onActionCallback on_action_callback);
    explicit Observer(jobject object) : ::gni::Object(object) {}
    ~Observer() override = default;
    virtual void onAction() const;
    onActionCallback on_action_callback_ = nullptr;
};

}  // namespace lang
}  // namespace java

#endif  // CPP_JAVA_LANG_OBSERVER

