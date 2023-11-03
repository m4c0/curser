module;
#include <CoreGraphics/CoreGraphics.h>
#include <objc/message.h>
#include <objc/runtime.h>

module curser;
import hai;

namespace curser {
void send(const char *sel_name) {
  auto cls = objc_getRequiredClass("NSCursor");
  auto sel = sel_getUid(sel_name);
  auto fn = reinterpret_cast<void (*)(Class, SEL)>(&objc_msgSend);
  fn(cls, sel);
}

class osx_guard : public guard {
public:
  osx_guard() {
    send("hide");
    CGAssociateMouseAndMouseCursorPosition(0);
  }
  ~osx_guard() {
    CGAssociateMouseAndMouseCursorPosition(1);
    send("unhide");
  }
};
} // namespace curser

[[nodiscard]] hai::uptr<curser::guard> curser::hide() {
  return hai::uptr<curser::guard>{new osx_guard{}};
}
