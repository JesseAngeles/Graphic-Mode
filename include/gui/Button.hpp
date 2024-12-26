#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <functional>

#include "gui/Frame.hpp"

class Button : public Frame
{
protected:
    Text text;
    std::function<void()> onClick;

    virtual void updateTextPosition();

    void draw(RenderTarget &target, RenderStates states) const override;
    void handleEvent(const sf::Event &event) override;
    void updatePosition(const Vector2f &relative_position) override;

public:
    Button(const Vector2f &position, const Vector2f &size,
           const Color &color, const Text &text);

    // Setters
    void setOnClick(std::function<void()> callback) { onClick = callback; }
    void setText(const std::string &text_content);
};

#endif // BUTTON_HPP