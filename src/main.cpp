#include "starting_menu.hpp"
#include "programm.hpp"
#include "load_game.hpp"
#include "hint.hpp"
#include "free_func.hpp"

int main()
{
    string detector;
    programm obj1;
    sf::RenderWindow window({1920, 1080}, "Horrified board game");

    while (true)
    {
        Menu menu(1920, 1080, sf::Font());
        MenuState selected = menu.run();

        switch (selected)
        {
        case MenuState::NewGame:
            obj1.run(false);
            break;
        case MenuState::LoadGame:
        {

            while (true)
            {
                LoadGameMenu menu;
                detector = menu.run();
                try
                {

                    if (detector == "save1")
                    {
                        obj1.load_game("../save1");
                    }
                    if (detector == "save2")
                    {
                        obj1.load_game("../save2");
                    }
                    if (detector == "save3")
                    {
                        obj1.load_game("../save3");
                    }
                    if (detector == "save4")
                    {
                        obj1.load_game("../save4");
                    }
                    if (detector == "save5")
                    {
                        obj1.load_game("../save5");
                    }

                    if (detector=="back")
                    {
                        break;
                        window.setActive(false);
                    }
                
                
                }
                catch (std::exception &e)
                {
                    cerr << e.what();
                    showCenteredTextBox(window, e.what());
                }
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