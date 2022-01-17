#include "render/window.hpp"

int main() {
    auto window = myra::Window::create(800, 600, "Myra");
    if (!window) { return -1; }

    window->setClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while (!window->shouldWindowClose()) {
        window->clear();

        window->endFrame();
    }
    return 0;
}
