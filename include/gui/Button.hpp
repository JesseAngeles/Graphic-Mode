#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <functional>

#include "gui/Frame.hpp"

class Button : public Frame
{
private:
    Text text;
    Font font;

    std::function<void()> onClick;

protected:
    void draw(RenderTarget &target, RenderStates states) const override;

public:
    Button(const Vector2f &position, const Vector2f &size,
           const Color &color, const Text &text);

    void handleEvent(const sf::Event &event) override;

    // Setters
    void setOnClick(std::function<void()> callback) { onClick = callback; }
    void setText(const Text &text);
};

#endif // BUTTON_HPP