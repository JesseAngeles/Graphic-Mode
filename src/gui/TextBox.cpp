#include "gui/TextBox.hpp"

// Constructor
TextBox::TextBox(const Vector2f &position, const Vector2f &size, const Color &color,
                 const Text &text, const std::string &input_string, size_t char_limit)
    : Frame(position, size, color), text(text), input_string(input_string), char_limit(char_limit), is_active(false)
{
    updateTextPosition();
    setString(input_string);
}

// Protected functions
void TextBox::updateTextPosition()
{
    FloatRect text_bounds = text.getLocalBounds();
    text.setOrigin(text_bounds.left, text_bounds.top + text_bounds.height / 2);
    text.setPosition(position.x + 5, position.y + size.y / 2);
}

void TextBox::draw(RenderTarget &target, RenderStates states) const
{
    Frame::draw(target, states);
    target.draw(text, states);
}
void TextBox::handleEvent(const Event &event)
{
    // Click event
    if (event.type == Event::MouseButtonPressed)
        if (event.mouseButton.button == Mouse::Left)
            if (background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                is_active = true;
            else
                is_active = false;

    // Key pressed
    if (is_active && event.type == Event::TextEntered)
        if (event.text.unicode == 8)
        { // Backspace
            if (!input_string.empty())
                input_string.pop_back();
        }
        else if (event.text.unicode < 128 && input_string.size() < char_limit)
            // Writtable char
            input_string += static_cast<char>(event.text.unicode);

    // Enter clicked
    if (is_active && event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
    {
        is_active = false;
        if (onEnter)
            onEnter(input_string); // Llamar al callback
    }

    setString(input_string);
}

// Public functions

// Setters
void TextBox::setString(const std::string &newText)
{
    input_string = newText.substr(0, char_limit);
    text.setString(input_string + (is_active ? "|" : ""));
    updateTextPosition();
}
