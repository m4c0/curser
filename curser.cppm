export module curser;
import hai;

export namespace curser {
class guard {
protected:
  constexpr guard() = default;

public:
  virtual ~guard() {}

  guard(const guard &o) = delete;
  guard(guard &&o) = delete;
  guard &operator=(const guard &o) = delete;
  guard &operator=(guard &&o) = delete;
};

[[nodiscard]] hai::uptr<guard> hide();
}; // namespace curser

#if LECO_TARGET_MACOSX
#pragma leco add_impl "osx.cpp"
#pragma leco add_framework CoreGraphics Foundation
#elif LECO_TARGET_WINDOWS
#pragma leco add_impl "windows.cpp"
#else
#pragma leco add_impl "dummy.cpp"
#endif
