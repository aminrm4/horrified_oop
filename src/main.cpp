#include "starting_menu.hpp"
#include "programm.hpp"
#include "load_game.hpp"
#include "hint.hpp"

int main()
{
    programm obj1;

    while (true)
    {
        Menu menu(1920, 1080, sf::Font());
        MenuState selected = menu.run();

        switch (selected)
        {
        case MenuState::NewGame:
            obj1.run();
            break;
        case MenuState::LoadGame:
        {
            while (true)
            {
                LoadGameMenu loadMenu(1920, 1080, sf::Font());
                LoadGameState saveSelected = loadMenu.run();
                if (saveSelected == LoadGameState::Back)
                {
                    break;
                }

                break;
            }
            break;
        }
        case MenuState::HowToPlay:
        {
            HintMenu hintMenu(1920, 1080, sf::Font());
            hintMenu.run();
            break;
        }
        case MenuState::Exit:
            return 0;
        default:
            break;
        }
    }
    return 0;
}