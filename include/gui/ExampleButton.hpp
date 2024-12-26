#ifndef EXAMPLE_BUTTON_HPP
#define EXAMPLE_BUTTON_HPP

#include <iostream>
#include <functional> // Incluir para std::function

#include "gui/Button.hpp"

class ExampleButton : public Button
{
private:
    std::function<void()> fun; // Usar std::function para la función de callback
public:
    // Constructor
    ExampleButton(const Text &text);

    void functionButton(); 

};

#endif // EXAMPLE_BUTTON_HPP
