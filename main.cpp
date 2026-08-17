#include "helpers/Logger.h"
#include "helpers/GameEngine.h"
#include "helpers/MainMenuState.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main()
{
    // Configure log verbosity at game startup
    Logger::getInstance().setLogLevel(LogLevel::DEBUG);

    LOG_INFO("--- Creating new World ---");

    //LOG_INFO("Creating the home text");

    GameEngine game;

    // Initialize the game engine
    LOG_INFO("Initializing the game engine");
    game.Init("CRogueLite");

    // Load the main menu
    LOG_INFO("Loading the main menu");
    game.ChangeState(MainMenuState::Instance());

    // main loop
    LOG_INFO("Initializing the main game loop");
    while (game.Running()) {
        // TODO: bug: game.Running is either not always true, or there's an exit because the window opens then closes immediately
        game.HandleEvents();
        game.Update();
        game.Draw();
    }
    game.CleanUp();
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
