#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <vendor/stb_image.h>
#include <vendor/glm/glm.hpp>
#include <vendor/glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>


#include <shaders/shader.h>
#include <renderEngine/DisplayManager.h>
#include <quads/QuadShader.h>
#include <quads/Quads.h>
#include <renderEngine/Renderer.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    
    DisplayManager displayManager(SCR_WIDTH, SCR_HEIGHT, "Game Engine Sandbox");

    glm::vec3 camera(0,0,0);
    Quad quad(0.0f, 0.0f, 0.5f, 0.5f, camera);   
    Quad quad2(0.0f, 0.0f, 0.5f, 0.5f, camera);

    displayManager.setBackgroundColor(52, 143, 235);

    float offset = 0.05f, i=0.05f;

    quad2.getShader().use();
    quad2.getShader().setVec3("aColor", 255/255.0f, 160/255.0f, 71/255.0f);

    while(!displayManager.windowShouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        quad.getShader().use();
        quad.getShader().setVec3("aColor", offset, 0.3f, 0.8f);
        offset += i;
    
        quad.setCamera(camera);
        camera.x += 0.01f;
        if(offset > 1.0f) i = -0.05f;
        else if(offset < 0.0f) i=0.05f;

        quad2.draw();
        quad.draw();
        displayManager.update();
    }

    return 0;
}
