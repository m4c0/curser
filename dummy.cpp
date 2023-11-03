module curser;
import hai;

namespace curser {
class dummy_guard : public guard {};
} // namespace curser

[[nodiscard]] hai::uptr<curser::guard> curser::hide() {
  return hai::uptr<curser::guard>{new dummy_guard{}};
}
