#include "gui/components/GraphicFunction.hpp"

// Constructor
GraphicFunction::GraphicFunction(const sf::Vector2f &position, const sf::Vector2f &size,
                                 const sf::Vector2f &origin, const sf::Vector2f &scale)
    : origin(origin), scale(scale), has_dot(false), has_line(false)
{
    min_pos = position;
    max_pos.x = position.x + size.x;
    max_pos.y = position.y + size.y;
}

// Public functions
void GraphicFunction::addPoint(sf::Vector2f position, bool connect_last)
{
    // Draw point
    if (!has_dot)
        return;

    position.x = origin.x + position.x * scale.x;
    position.y = origin.y - position.y * scale.y;

    if (position.x < min_pos.x || position.x > max_pos.x ||
        position.y < min_pos.y || position.y > max_pos.y)
        return;

    sf::Vector2f circle_pos = position;
    circle_pos.x -= default_dot.getRadius();
    circle_pos.y -= default_dot.getRadius();

    sf::CircleShape dot = default_dot;
    dot.setPosition(circle_pos);

    dots.push_back(dot);

    // Draw line
    if (!has_line || dots.size() < 2 || !connect_last)
        return;

    sf::Vector2f last_position = dots[dots.size() - 2].getPosition();
    last_position.x += default_dot.getRadius();
    last_position.y += default_dot.getRadius();

    sf::VertexArray line = default_line;
    line[0].position = last_position;
    line[1].position = position;

    lines.push_back(line);
}

// Setters
void GraphicFunction::setDefaultDot(const sf::CircleShape &default_dot)
{
    this->default_dot = default_dot;
    has_dot = true;
}

void GraphicFunction::setDefaultLine(const sf::VertexArray &default_line)
{
    this->default_line = default_line;
    has_line = true;
}