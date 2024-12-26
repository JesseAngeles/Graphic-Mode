#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <functional>

#include "gui/Frame.hpp"

class Button : public Frame
{
private:
    Text text;

    std::function<void()> onClick;

protected:
    void draw(RenderTarget &target, RenderStates states) const override;

    void updateTextPosition();
public:
    Button(const Vector2f &position, const Vector2f &size,
           const Color &color, const Text &text);

    void handleEvent(const sf::Event &event) override;

    void updatePosition(const Vector2f &relative_position) override;

    // Setters
    void setOnClick(std::function<void()> callback) { onClick = callback; }
    void setText(const std::string &text_content);
};

#endif // BUTTON_HPP