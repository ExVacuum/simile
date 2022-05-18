#include <simile/simile.hpp>

namespace simile {
    void helloWorld(void) {
        spdlog::log(spdlog::level::info, "Hello, world!");
    }
}
