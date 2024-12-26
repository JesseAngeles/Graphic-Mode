#include "gui/Frame.hpp"

// Constructor
Frame::Frame(const Vector2f &position, const Vector2f &size, const Color &color)
    : position(position), size(size)
{
    background.setPosition(position);
    background.setSize(size);
    background.setFillColor(color);
}

// Protected functions
void Frame::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(background, states);
    for (const std::shared_ptr<Frame> &child : children)
        target.draw(*child, states);
}

// Public functions
void Frame::handleEvent(const Event &event)
{
    for (const std::shared_ptr<Frame> &child : children)
        child->handleEvent(event);
}

void Frame::addChild(std::shared_ptr<Frame> &child)
{
    children.push_back(child);
    child->updatePosition(this->position);
}

void Frame::updatePosition(const Vector2f &relative_position)
{
    position += relative_position;
    background.setPosition(position);
    for (const std::shared_ptr<Frame> &child : children)
        child->updatePosition(relative_position);
}

// Settters
void Frame::setPosition(const Vector2f &new_position)
{
    position = new_position;
    background.setPosition(position);
    for (const std::shared_ptr<Frame> &child : children)
        child->updatePosition(this->position);
}

void Frame::setSize(const Vector2f &new_size)
{
    size = new_size;
    background.setSize(size);
}
