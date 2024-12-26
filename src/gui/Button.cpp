#include "gui/Button.hpp"

// Constructor
Button::Button(const Vector2f &position, const Vector2f &size,
               const Color &color, const Text &text)
    : Frame(position, size, color), text(text)
{
    updateTextPosition();
}

// Protected functions
void Button::draw(RenderTarget &target, RenderStates states) const
{
    Frame::draw(target, states);
    target.draw(text, states);
}

void Button::updateTextPosition()
{
    FloatRect text_bounds = text.getLocalBounds();
    text.setOrigin(text_bounds.width / 2, text_bounds.height / 2);
    text.setPosition(position.x + size.x / 2, position.y + size.y / 2);
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

void Button::updatePosition(const Vector2f &relative_position)
{
    position += relative_position;
    background.setPosition(position);
    updateTextPosition();
    for (const std::shared_ptr<Frame> &child : children)
        child->updatePosition(relative_position);
}

void Button::setText(const std::string &text_content)
{
    text.setString(text_content);
    updateTextPosition();
}