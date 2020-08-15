#pragma once

class DisplayManager
{
private:
    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    GLFWwindow* window;
    unsigned int scr_width;
    unsigned int scr_height;
    std::string win_title;
public:
    DisplayManager(unsigned int width, unsigned int height, std::string title);
    ~DisplayManager();
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    bool windowShouldClose();
    void update();
    void setBackgroundColor(unsigned int r, unsigned int g, unsigned int b) const;
};