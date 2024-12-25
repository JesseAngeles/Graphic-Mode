#ifndef EXAMPLE_FRAME_HPP
#define EXAMPLE_FRAME_HPP

#include "gui/Frame.hpp"

class ExampleFrame : public Frame
{ 
public:
    ExampleFrame(const Vector2f &position, const Vector2f &size, const Color &color);

    void handleEvent(const Event& event) override;
};

#endif // EXAMPLE_FRAME_HPP