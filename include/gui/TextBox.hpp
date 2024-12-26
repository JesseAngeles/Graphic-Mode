#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <functional>

#include "gui/Frame.hpp"

class TextBox : public Frame
{
protected:
    // Attributes
    Text text;
    std::string input_string;
    size_t char_limit;
    bool is_active;
    std::function<void(const std::string &)> onEnter;

    virtual void updateTextPosition();

    void draw(RenderTarget &target, RenderStates states) const override;
    void handleEvent(const Event &event) override;

public:
    // Constructor
    TextBox(const Vector2f &position, const Vector2f &size, const Color &color,
            const Text &text, const std::string &input_string, size_t char_limit = 20);

    // Setters
    void setOnEnter(std::function<void(const std::string &)> callback) { onEnter = callback; }
    void setString(const std::string &input_string);
};

#endif // TEXT_BOX_HPP