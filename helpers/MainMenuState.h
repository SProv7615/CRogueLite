#ifndef CROGUELITE_MAINMENUSTATE_H
#define CROGUELITE_MAINMENUSTATE_H

#include "Button.h"
#include "GameState.h"

#include <vector>

class MainMenuState : public GameState {
public:
    void Init() override;
    void CleanUp() override;

    void Pause() override;
    void Resume() override;

    void HandleEvents(GameEngine* game) override;
    void Update(GameEngine* game) override;
    void Draw(GameEngine* game) override;

    static MainMenuState* Instance() {
        return &m_MainMenuState;
    }

protected:
    MainMenuState() = default;

private:
    static MainMenuState m_MainMenuState;

    std::vector<Button> m_buttons;
};

#endif //CROGUELITE_MAINMENUSTATE_H
