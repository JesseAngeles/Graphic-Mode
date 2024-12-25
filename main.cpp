#include <iostream>

#include "gui/MainWindow.hpp"

#include "gui/ExampleFrame.hpp"
#include "gui/ExampleButton.hpp"

using namespace std;

int main()
{
    Font font;
    if(!font.loadFromFile("./resources/fonts/Roboto-Medium.ttf"))
        std::cout << "ayuda";

    Text text;
    text.setString("Hola");
    text.setFillColor(Color::Black);
    text.setCharacterSize(20);

    ExampleFrame frame({50, 50}, {400, 400}, {150, 200, 150});
    std::shared_ptr<Frame> btn = std::make_shared<ExampleButton>(Vector2f(10, 10), 
        Vector2f(300, 50), Color(255, 255, 100), text);

    frame.addChild(btn);

    MainWindow gui(500, 500, "Hola mundo");
    gui.addFrame(std::make_shared<Frame>(frame));
    gui.run();

    return 0;
}