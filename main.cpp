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

    sf::Font font_cedar_textbox;
    sf::Font font_bitcount_title;
    sf::Font font_loveya_menu;
    if (!font_cedar_textbox.openFromFile("C:/Users/Garpug/source/repos/CRogueLite/helpers/CedarvilleCursive-Regular.ttf")) {
        LOG_ERROR("Missing font file");
        return -1;
    }
    if (!font_bitcount_title.openFromFile("C:/Users/Garpug/source/repos/CRogueLite/helpers/BitcountGridDouble-VariableFont.ttf")) {
        LOG_ERROR("Missing font file");
        return -1;
    }
    if (!font_loveya_menu.openFromFile("C:/Users/Garpug/source/repos/CRogueLite/helpers/LoveYaLikeASister-Regular.ttf")) {
        LOG_ERROR("Missing font file");
        return -1;
    }

    sf::Text text(font_cedar_textbox, "Hello World!!", 50);
    sf::Text title(font_bitcount_title, "CRogueLite", 50);
    sf::Text menu_start(font_loveya_menu, "start", 50);
    sf::Text menu_load(font_loveya_menu, "load", 50);
    sf::Text menu_options(font_loveya_menu, "options", 50);
    sf::Text menu_exit(font_loveya_menu, "exit", 50);
    text.setFillColor(sf::Color::White);
    title.setFillColor(sf::Color::Black);
    menu_start.setFillColor(sf::Color::White);
    menu_load.setFillColor(sf::Color::White);
    menu_options.setFillColor(sf::Color::White);
    menu_exit.setFillColor(sf::Color::White);

    // define a 120x50 rectangle
    sf::RectangleShape textbox_rectangle({window.getSize().x * 1.0f, 200.f});
    sf::RectangleShape map_rectangle({window.getSize().x * 1.0f, 400.f});
    sf::RectangleShape menu_rectangle({window.getSize().x * 0.25f, 300.f});
    sf::RectangleShape menu_start_button({menu_rectangle.getSize().x * 4 / 5.0f, menu_rectangle.getSize().y / 5.0f});
    sf::RectangleShape menu_load_button({menu_rectangle.getSize().x * 4 / 5.0f, menu_rectangle.getSize().y / 5.0f});
    sf::RectangleShape menu_options_button({menu_rectangle.getSize().x * 4 / 5.0f, menu_rectangle.getSize().y / 5.0f});
    sf::RectangleShape menu_exit_button({menu_rectangle.getSize().x * 4 / 5.0f, menu_rectangle.getSize().y / 5.0f});
    textbox_rectangle.setPosition({0.f, 400.f});
    map_rectangle.setPosition({0.f, 0.f});
    menu_rectangle.setPosition({300.f, 50.f});
    menu_start_button.setPosition({menu_rectangle.getPosition().x + (menu_rectangle.getSize().x * 0.1f), menu_rectangle.getPosition().y + menu_rectangle.getSize().y / 25});
    // set the shape color to green
    textbox_rectangle.setFillColor(sf::Color::Black);
    map_rectangle.setFillColor(sf::Color::White);
    menu_rectangle.setFillColor(sf::Color(100, 100, 100));
    menu_start_button.setFillColor(sf::Color::Red);

    // 1. Get the local bounds of the text (before any scaling)
    sf::FloatRect textBounds = text.getLocalBounds();
    sf::FloatRect titleBounds = title.getLocalBounds();
    sf::FloatRect menuStartBounds = menu_start.getLocalBounds();
    // sf::FloatRect menuLoadBounds = menu_load.getLocalBounds();
    // sf::FloatRect menuOptionsBounds = menu_options.getLocalBounds();
    // sf::FloatRect menuExitBounds = menu_exit.getLocalBounds();

    /*
    // 2. Calculate the scale factors needed to fit the text into the rectangle
    float scaleX = rectangle.getSize().x / textBounds.size.x;
    float scaleY = rectangle.getSize().y / textBounds.size.y;

    // 3. Apply the scaling to the text
    text.setScale({scaleX, scaleY});*/

    // 4. Center the text perfectly inside the shape
    //sf::FloatRect globalBounds = text.getGlobalBounds();
    text.setOrigin({textBounds.position.x + textBounds.size.x / 2.0f, textBounds.position.y + textBounds.size.y / 2.0f});
    text.setPosition({(textbox_rectangle.getPosition().x + textbox_rectangle.getSize().x / 2.0f),(textbox_rectangle.getPosition().y + textbox_rectangle.getSize().y / 2.0f)});

    // Title
    //title.setOrigin({window.getPosition().x + window.getSize().x / 2.0f, window.getPosition().y + window.getSize().y / 2.0f});
    //title.setPosition({window.getPosition().x + window.getSize().x / 2.0f, window.getPosition().y + window.getSize().y / 2.0f});
    title.setOrigin({titleBounds.position.x + titleBounds.size.x / 2.0f, titleBounds.position.y + titleBounds.size.y / 2.0f});
    title.setPosition({(menu_rectangle.getPosition().x + menu_rectangle.getSize().x / 2.0f),(menu_rectangle.getPosition().y - 25)});

    //Menu Start
    menu_start.setOrigin({menuStartBounds.position.x + menuStartBounds.size.x / 2.0f, menuStartBounds.position.y + menuStartBounds.size.y / 2.0f});
    menu_start.setPosition({(menu_start_button.getPosition().x + menu_start_button.getSize().x / 2.0f),(menu_start_button.getPosition().y + menu_start_button.getSize().y / 2.0f)});


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
        window.draw(map_rectangle);
        window.draw(menu_rectangle);
        window.draw(textbox_rectangle);
        window.draw(menu_start_button);
        window.draw(menu_start);
        window.draw(text);
        window.draw(title);
        window.display();
    }
    LOG_INFO("--- Exiting main loop ---");
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
