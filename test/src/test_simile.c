#include <criterion/criterion.h>
#include "../../inc/simile.h"

void initSimile(void) {

}

void finiSimile(void) {

}

TestSuite(simile, .init = initSimile, .fini = finiSimile);

// Test that GL context is created properly
Test(simile, glVersion) {
    glfwInit();

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "[glad] GL with GLFW", NULL, NULL);
    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);
    
    glfwTerminate();
    cr_assert(version);
}
