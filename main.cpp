#include <iostream>

#include "gui/MainWindow.hpp"

#include "gui/ExampleFrame.hpp"
#include "gui/ExampleButton.hpp"

using namespace std;

void exampleFunction();

int main()
{
    Font font;
    if (!font.loadFromFile("./resources/fonts/Roboto-Medium.ttf"))
    {
        std::cerr << "Error al cargar la fuente" << std::endl;
        return -1; // Salida temprana si falla la carga
    }

    Text text;
    text.setFont(font);
    text.setString("Hola");
    text.setFillColor(Color::Black);
    text.setCharacterSize(20);

    ExampleFrame frame({50, 50}, {400, 400}, {150, 200, 150});
    ExampleButton btn(Vector2f(10, 10), Vector2f(300, 50), Color(255, 255, 100), text);

    btn.setOnClick(exampleFunction);

    std::shared_ptr<Frame> btn_frame = std::make_shared<Button>(btn);

    frame.addChild(btn_frame);

    MainWindow gui(500, 500, "Hola mundo", Color::Cyan);
    gui.addFrame(std::make_shared<Frame>(frame));
    gui.run();

    return 0;
}

void exampleFunction()
{
    // Para impresiones en tiempo real añadir salto de linea -> \n
    cout << "Funcion de ejemplo \n";
}