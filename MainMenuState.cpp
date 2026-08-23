#include "helpers/Logger.h"
#include "helpers/MainMenuState.h"
#include <SFML/Graphics/RenderWindow.hpp>

MainMenuState MainMenuState::m_MainMenuState;

static sf::Font font_cedar_textbox;
static sf::Font font_bitcount_title;
static sf::Font font_loveya_menu;

void MainMenuState::Init() {
    if (!font_cedar_textbox.openFromFile("assets/fonts/CedarvilleCursive-Regular.ttf")) {
        LOG_ERROR("Missing font file: cedarville");
    }
    if (!font_bitcount_title.openFromFile("assets/fonts/BitcountGridDouble-VariableFont.ttf")) {
        LOG_ERROR("Missing font file: bitcounter");
    }
    if (!font_loveya_menu.openFromFile("assets/fonts/LoveYaLikeASister-Regular.ttf")) {
        LOG_ERROR("Missing font file: loveya");
    }

    // Init() can run more than once over the process lifetime (this state is a singleton that
    // ChangeState may re-enter), so rebuild the list rather than appending to it.
    m_buttons.clear();
    for (const char* label : {"start", "load", "options", "exit"}) {
        m_buttons.emplace_back(font_loveya_menu, label);
    }
}

void MainMenuState::CleanUp() {
    LOG_INFO("Cleanup main menu state");
}

void MainMenuState::Pause() {
    LOG_INFO("Pausing game in main menu.");
}

void MainMenuState::Resume() {
    LOG_INFO("Resuming game in main menu.");
}

void MainMenuState::HandleEvents(GameEngine* game) {
    while (const std::optional event = game->window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            LOG_INFO("Game Closed");
            game->Quit();
            game->window->close();
        }
        else if (const auto* moved = event->getIf<sf::Event::MouseMoved>()) {
            const sf::Vector2f position = game->window->mapPixelToCoords(moved->position);
            for (Button& button : m_buttons) {
                button.Update(position);
            }
        }
        else if (const auto* pressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (pressed->button != sf::Mouse::Button::Left) { continue; }

            const sf::Vector2f position = game->window->mapPixelToCoords(pressed->position);
            for (const Button& button : m_buttons) {
                if (!button.Contains(position)) { continue; }

                LOG_INFO("Button clicked: " + button.Name());
                if (button.Name() == "exit") {
                    game->Quit();
                    game->window->close();
                }
            }
        }
    }
}

void MainMenuState::Update(GameEngine*) {
}

void MainMenuState::Draw(GameEngine* game) {
    const float w = static_cast<float>(game->window->getSize().x);

    // Map area (top)
    sf::RectangleShape map_rectangle({w, 400.f});
    map_rectangle.setPosition({0.f, 0.f});
    map_rectangle.setFillColor(sf::Color::White);

    // Textbox (bottom)
    sf::RectangleShape textbox_rectangle({w, 200.f});
    textbox_rectangle.setPosition({0.f, 400.f});
    textbox_rectangle.setFillColor(sf::Color::Black);

    // Main Textbox text
    sf::Text helloText(font_cedar_textbox, "Hello World!!", 50);
    helloText.setFillColor(sf::Color::White);
    const sf::FloatRect textBounds = helloText.getLocalBounds();
    helloText.setOrigin({textBounds.position.x + textBounds.size.x / 2.f, textBounds.position.y + textBounds.size.y / 2.f});
    helloText.setPosition({w / 2.f, 500.f}); // center of textbox (400 + 200/2)

    // Menu panel (centered horizontally)
    const sf::Vector2f menuSize = {w * 0.25f, 300.f};
    const sf::Vector2f menuPos = {(w - menuSize.x) / 2.f, 50.f};
    sf::RectangleShape menu_rectangle(menuSize);
    menu_rectangle.setPosition(menuPos);
    menu_rectangle.setFillColor(sf::Color(100, 100, 100));

    // Title above menu panel
    sf::Text title(font_bitcount_title, "CRogueLite", 50);
    title.setFillColor(sf::Color::Black);
    const sf::FloatRect titleBounds = title.getLocalBounds();
    title.setOrigin({titleBounds.position.x + titleBounds.size.x / 2.f, titleBounds.position.y + titleBounds.size.y / 2.f});
    title.setPosition({menuPos.x + menuSize.x / 2.f, menuPos.y - 25.f});

    // Buttons stacked in menu panel
    const sf::Vector2f buttonSize = {menuSize.x * (4.f / 5.f), menuSize.y / 5.f};
    const float buttonX = menuPos.x + menuSize.x * 0.1f;
    const float padding = menuSize.y / 25.f; // 12px for a 300px menu

    // Draw in game engine window
    game->window->clear(sf::Color(133, 255, 165));
    game->window->draw(map_rectangle);
    game->window->draw(menu_rectangle);
    game->window->draw(textbox_rectangle);
    game->window->draw(title);
    game->window->draw(helloText);

    // Lay the buttons out against the current window size, then let each draw itself
    for (std::size_t i = 0; i < m_buttons.size(); ++i) {
        const float y = menuPos.y + padding + static_cast<float>(i) * (buttonSize.y + padding);
        m_buttons[i].SetBounds({buttonX, y}, buttonSize);
        m_buttons[i].Draw(*game->window);
    }
    game->window->display();
}
