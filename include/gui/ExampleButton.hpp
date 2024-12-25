#ifndef EXAMPLE_BUTTON_HPP
#define EXAMPLE_BUTTON_HPP

#include "gui/Button.hpp"

class ExampleButton : public Button
{
private:
public:
    // Constructor
    ExampleButton(const Vector2f &position, const Vector2f &size,
                  const Color &color, const Text &text);
};

#endif // EXAMPLE_BUTTON_HPP