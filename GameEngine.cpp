#include "helpers/GameEngine.h"
#include "helpers/GameState.h"
#include <SFML/Graphics.hpp>

void GameEngine::Init(const char *title, unsigned width, unsigned height, const bool i_fullscreen)
{
    window = new sf::RenderWindow(sf::VideoMode({width, height}), title);
    running = true;
    fullscreen = i_fullscreen;
}

void GameEngine::CleanUp() {
    // cleanup all states
    while ( !states.empty()) {
        states.back()->CleanUp();
        states.pop_back();
    }
}

void GameEngine::ChangeState(GameState* state) {
    // cleanup current state
    if (!states.empty()) {
        states.back()->CleanUp();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init();
}

void GameEngine::PushState(GameState* state) {
    // pause current state
    if (!states.empty()) {
        states.back()->Pause();
    }
    // store and init the new state
    states.push_back(state);
    states.back()->Init();
}

void GameEngine::PopState() {
    // cleanup the current state
    if (!states.empty()) {
        states.back()->CleanUp();
        states.pop_back();
    }

    // resume previous state
    if (!states.empty()) {
        states.back()->Resume();
    }
}

void GameEngine::HandleEvents() {
    // let the state handle events
    states.back()->HandleEvents(this);
}

void GameEngine::Update() {
    // let the state update the game
    states.back()->Update(this);
}
void GameEngine::Draw() {
    // let the state draw the screen
    states.back()->Draw(this);
}
