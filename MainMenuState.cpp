#include "helpers/Logger.h"
#include "helpers/MainMenuState.h"
#include <SFML/Graphics/RenderWindow.hpp>

MainMenuState MainMenuState::m_MainMenuState;

static sf::Font font_cedar_textbox;
static sf::Font font_bitcount_title;
static sf::Font font_loveya_menu;

static void DrawButton(sf::RenderWindow& window, const std::string& label, const sf::Vector2f position, const sf::Vector2f size) {
    sf::RectangleShape button(size);
    button.setPosition(position);
    button.setFillColor(sf::Color::Red);

    sf::Text text(font_loveya_menu, label, 30);
    text.setFillColor(sf::Color::White);
    const sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f});
    text.setPosition({position.x + size.x / 2.f, position.y + size.y / 2.f});

    window.draw(button);
    window.draw(text);
}

void MainMenuState::Init() {
    if (!font_cedar_textbox.openFromFile("assets/fonts/CedarvilleCursive-Regular.ttf")) {
        LOG_ERROR("Missing font file");
    }
    if (!font_bitcount_title.openFromFile("assets/fonts/BitcountGridDouble-VariableFont.ttf")) {
        LOG_ERROR("Missing font file");
    }
    if (!font_loveya_menu.openFromFile("assets/fonts/LoveYaLikeASister-Regular.ttf")) {
        LOG_ERROR("Missing font file");
    }
}

void MainMenuState::CleanUp() {
    LOG_INFO("Cleanup menu state");
}

void MainMenuState::Pause() {
    LOG_INFO("Pausing game.");
}

void MainMenuState::Resume() {
    LOG_INFO("Resuming game.");
}

void MainMenuState::HandleEvents(GameEngine* game) {
    while (const std::optional event = game->window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            LOG_INFO("Game Closed");
            game->Quit();
            game->window->close();
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
    float buttonX = menuPos.x + menuSize.x * 0.1f;
    const float padding = menuSize.y / 25.f; // 12px for a 300px menu

    game->window->clear(sf::Color(133, 255, 165));
    game->window->draw(map_rectangle);
    game->window->draw(menu_rectangle);
    game->window->draw(textbox_rectangle);
    game->window->draw(title);
    game->window->draw(helloText);

    const std::string buttonLabels[] = {"start", "load", "options", "exit"};
    for (int i = 0; i < 4; ++i) {
        float y = menuPos.y + padding + static_cast<float>(i) * (buttonSize.y + padding);
        DrawButton(*game->window, buttonLabels[i], {buttonX, y}, buttonSize);
    }
    game->window->display();
}
