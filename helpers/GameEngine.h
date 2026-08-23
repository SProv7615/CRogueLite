#ifndef CROGUELITE_GAMEENGINE_H
#define CROGUELITE_GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>

class GameState;

class GameEngine
{
    public:
        void Init(const char *title, unsigned width = 800, unsigned height = 600, bool i_fullscreen = false);
        void CleanUp();

        void ChangeState(GameState* state);
        void PushState(GameState* state);
        void PopState();

        void HandleEvents();
        void Update();
        void Draw();

        [[nodiscard]] bool Running() const { return running; }
        void Quit() { running = false; }

        sf::RenderWindow* window;

    private:
        // the stack of states
        std::vector<GameState*> states;

        bool running = true;
        bool fullscreen = false;
};

#endif //CROGUELITE_GAMEENGINE_H
