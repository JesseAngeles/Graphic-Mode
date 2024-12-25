#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "gui/Frame.hpp"

using namespace sf;

class MainWindow
{
private:
    RenderWindow window;

    // Frames
    std::vector<std::shared_ptr<Frame>> frames;

    void handleEvent();
    void render();

public:
    // Constructor
    MainWindow(int width, int height, const std::string &title);

    void addFrame(std::shared_ptr<Frame> frame) { frames.push_back(frame); }

    // Drawer
    void run();
};

#endif // MAIN_WINDOW_HPP