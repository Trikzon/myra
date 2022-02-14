#include "log.hpp"
#include "render/shader.hpp"
#include "render/window.hpp"

int main() {
    myra::debug("Hello, World!");

    auto window = myra::Window::create(800, 600, "Myra");
    if (!window) { return -1; }

    window->setClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    myra::Shader testShader("assets/shaders/triangle.glsl");

    while (!window->shouldWindowClose()) {
        window->clear();
        testShader.use();

        window->endFrame();
    }
    return 0;
}
