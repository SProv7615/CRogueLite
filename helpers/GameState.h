#ifndef CROGUELITE_GAMESTATE_H
#define CROGUELITE_GAMESTATE_H

#include "GameEngine.h"

class GameState
{
public:
    virtual ~GameState() = default;

    virtual void Init() = 0;
    virtual void CleanUp() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents(GameEngine* game) = 0;
    virtual void Update(GameEngine* game) = 0;
    virtual void Draw(GameEngine* game) = 0;

    static void ChangeState(GameEngine* game, GameState* state) {
        game->ChangeState(state);
    }

protected:
    GameState() = default;
};

#endif //CROGUELITE_GAMESTATE_H
