#include "helpers/Button.h"

#include <utility>

Button::Button(const sf::Font& font, std::string name, const sf::Color fillColor, const sf::Color hoverColor,
               const sf::Color textColor, const unsigned characterSize)
    : m_name(std::move(name)),
      m_label(font, m_name, characterSize),
      m_idleColor(fillColor),
      m_hoverColor(hoverColor)
{
    m_label.setFillColor(textColor);
    m_shape.setFillColor(m_idleColor);
}

void Button::SetBounds(const sf::Vector2f position, const sf::Vector2f size) {
    m_shape.setPosition(position);
    m_shape.setSize(size);
    CenterLabel();
}

void Button::Update(const sf::Vector2f mousePosition) {
    m_shape.setFillColor(Contains(mousePosition) ? m_hoverColor : m_idleColor);
}

void Button::Draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
    window.draw(m_label);
}

bool Button::Contains(const sf::Vector2f point) const {
    return m_shape.getGlobalBounds().contains(point);
}

void Button::CenterLabel() {
    const sf::FloatRect bounds = m_label.getLocalBounds();
    m_label.setOrigin({bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f});

    const sf::Vector2f position = m_shape.getPosition();
    const sf::Vector2f size = m_shape.getSize();
    m_label.setPosition({position.x + size.x / 2.f, position.y + size.y / 2.f});
}
