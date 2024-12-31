#include <iostream>

#include "gui/MainWindow.hpp"

#include "gui/ExampleFrame.hpp"
#include "gui/ExampleButton.hpp"
#include "gui/ExampleTextBox.hpp"
#include "gui/ExampleGraphic.hpp"

using namespace std;

int main()
{
    MainWindow gui(1000, 500, "Hola mundo", Color::Cyan);

    Font font;
    font.loadFromFile("./resources/fonts/Roboto-Medium.ttf");

    Text text_default_format;
    text_default_format.setFont(font);
    text_default_format.setFillColor(Color::Black);
    text_default_format.setCharacterSize(20);

    ExampleFrame frame;
    ExampleButton btn(text_default_format);
    ExampleTextBox text_box(text_default_format);
    ExampleGraphic graphic;

    frame.addChild(std::make_shared<ExampleButton>(btn));
    frame.addChild(std::make_shared<ExampleTextBox>(text_box));
    frame.addChild(std::make_shared<ExampleGraphic>(graphic));
    
    gui.addFrame(frame);
    gui.run();

    return 0;
}