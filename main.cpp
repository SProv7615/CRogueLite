#include "helpers/Logger.h"
#include <SFML/Graphics.hpp>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main()
{
    // Configure log verbosity at game startup
    Logger::getInstance().setLogLevel(LogLevel::DEBUG);

    LOG_INFO("--- Creating new World ---");

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "CRogueLite"
        );
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                LOG_INFO("Game Closed");
                window.close();
            }
        }
        window.clear();
        window.display();
    }
    LOG_INFO("Exiting main loop");
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
