#ifndef FRAME_HPP
#define FRAME_HPP

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

using namespace sf;

class Frame : public Drawable
{
protected:
    Vector2f position;
    Vector2f size;
    RectangleShape background;
    std::vector<std::shared_ptr<Frame>> children;

    virtual void draw(RenderTarget &target, RenderStates states) const override;

public:
    // Constructor
    Frame(const Vector2f &position, const Vector2f &size, const Color &color = Color(0, 0, 0));

    // Functions
    virtual void handleEvent(const Event &event);
    virtual void updatePosition(const Vector2f &relative_position);
    void addChild(const std::shared_ptr<Frame> &child);

    // Settters
    void setPosition(const Vector2f &new_position);
    void setSize(const Vector2f &new_size);
};

#endif // FRAME_HPP