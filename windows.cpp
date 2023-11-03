module;
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

module curser;
import hai;

namespace curser {
class win_guard : public guard {
  RECT m_old_clip;

public:
  win_guard() {
    GetClipCursor(&m_old_clip);

    POINT pos;
    GetCursorPos(&pos);

    RECT clip;
    clip.left = clip.right = pos.x;
    clip.top = clip.bottom = pos.y;
    ClipCursor(&clip);

    ShowCursor(FALSE);
  }
  ~win_guard() {
    ClipCursor(&m_old_clip);
    ShowCursor(TRUE);
  }
};
} // namespace curser

[[nodiscard]] hai::uptr<curser::guard> curser::hide() {
  return hai::uptr<curser::guard>{new win_guard{}};
}
