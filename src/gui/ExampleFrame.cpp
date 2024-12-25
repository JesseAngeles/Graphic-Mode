#include "gui/ExampleFrame.hpp"

// Constructor
ExampleFrame::ExampleFrame(const Vector2f& position, const Vector2f& size, const Color& color)
    : Frame(position, size, color) {
    // Personalizar el frame si es necesario
    background.setOutlineColor(Color::Blue); // Añadir un borde azul
    background.setOutlineThickness(2.f);
}

// Sobrescribir handleEvent para manejar eventos personalizados
void ExampleFrame::handleEvent(const Event& event) {
    if (event.type == Event::MouseButtonPressed) {
        if (background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            // ...
        }
    }

    Frame::handleEvent(event);
}