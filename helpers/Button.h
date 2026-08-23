#ifndef CROGUELITE_BUTTON_H
#define CROGUELITE_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
    public:
        // The font is taken by const reference and must outlive the Button: sf::Text stores a
        // pointer to it, not a copy. Passing sf::Font by value would also fail to compile,
        // because sf::Text(const Font&&) is explicitly deleted.
        Button(const sf::Font& font, std::string name,
               sf::Color fillColor = sf::Color::Red,
               sf::Color hoverColor = sf::Color(200, 80, 80),
               sf::Color textColor = sf::Color::White,
               unsigned characterSize = 30);

        // Position/size are applied after construction so the owning state can re-run layout
        // when the window size changes.
        void SetBounds(sf::Vector2f position, sf::Vector2f size);

        void Update(sf::Vector2f mousePosition);
        void Draw(sf::RenderWindow& window) const;

        [[nodiscard]] bool Contains(sf::Vector2f point) const;
        [[nodiscard]] const std::string& Name() const { return m_name; }

    private:
        void CenterLabel();

        // Declaration order matters: m_label's initializer reads m_name, so m_name must come first.
        std::string        m_name;
        sf::RectangleShape m_shape;
        sf::Text           m_label;
        sf::Color          m_idleColor;
        sf::Color          m_hoverColor;
};

#endif //CROGUELITE_BUTTON_H
