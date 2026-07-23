#include "helpers/Logger.h"
// #include "helpers/CedervilleCursive-Regular.ttf"
#include <SFML/Graphics.hpp>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main()
{
    // Configure log verbosity at game startup
    Logger::getInstance().setLogLevel(LogLevel::DEBUG);

    LOG_INFO("--- Creating new World ---");

    LOG_INFO("Creating the home text");

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "CRogueLite"
        );

    sf::Font font;
    if (!font.openFromFile("C:/Users/Garpug/source/repos/CRogueLite/helpers/CedarvilleCursive-Regular.ttf")) {
        LOG_ERROR("Missing font file");
        return -1;
    }

    sf::Text text(font, "Hello World!!", 50);
    text.setFillColor(sf::Color::White);
    // define a 120x50 rectangle
    sf::RectangleShape rectangle({window.getSize().x * 1.0f, 200.f});
    rectangle.setPosition({0.f, 400.f});
    // set the shape color to green
    rectangle.setFillColor(sf::Color::Black);
    // 1. Get the local bounds of the text (before any scaling)
    sf::FloatRect textBounds = text.getLocalBounds();

    /*
    // 2. Calculate the scale factors needed to fit the text into the rectangle
    float scaleX = rectangle.getSize().x / textBounds.size.x;
    float scaleY = rectangle.getSize().y / textBounds.size.y;

    // 3. Apply the scaling to the text
    text.setScale({scaleX, scaleY});*/

    // 4. Center the text perfectly inside the shape
    //sf::FloatRect globalBounds = text.getGlobalBounds();
    text.setOrigin({textBounds.position.x + textBounds.size.x / 2.0f,
                   textBounds.position.y + textBounds.size.y / 2.0f});
    text.setPosition({(rectangle.getPosition().x + rectangle.getSize().x / 2.0f),(rectangle.getPosition().y + rectangle.getSize().y / 2.0f)});

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                LOG_INFO("Game Closed");
                window.close();
            }
        }
        window.clear(sf::Color(133,255,165));
        window.draw(rectangle);
        window.draw(text);
        window.display();
    }
    LOG_INFO("--- Exiting main loop ---");
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
