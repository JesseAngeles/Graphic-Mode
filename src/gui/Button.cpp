#include "gui/Button.hpp"

// Constructor
Button::Button(const Vector2f &position, const Vector2f &size,
               const Color &color, const Text &text)
    : Frame(position, size, color), text(text)
{
    setText(text);
}

// Protected functions
void Button::draw(RenderTarget &target, RenderStates states) const
{
    Frame::draw(target, states);
    target.draw(text, states);
}

// Public functions
void Button::handleEvent(const Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == Mouse::Left)
            if (background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                if (onClick)
                    onClick();
}

// Setters
void Button::setText(const Text &text)
{
    this->text = text;
    sf::FloatRect text_bounds = text.getLocalBounds();
    this->text.setOrigin(text_bounds.width / 2, text_bounds.height / 2);
    this->text.setPosition(position.x + size.x / 2, position.y + size.y / 2);
}