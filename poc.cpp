#pragma leco tool

import curser;

int main() {
  auto guard = curser::hide();
  // cursor is hidden
  {
    auto guard1 = curser::hide();
    // nothing is done since there is another guard active
  }
  // cursor will be shown after this method ends
}
