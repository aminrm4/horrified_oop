#include "starting_menu.hpp"
#include "programm.hpp"
#include "load_game.hpp"
#include "hint.hpp"
#include "free_func.hpp"

int main()
{
    string detector;

    while (true)
    {
        programm obj1;

        Menu menu;
        int selected = menu.run();

        switch (selected)
        {
        case 0: // new game
            obj1.run(false);
            break;
        case 1: // Load game

        {
            LoadGameMenu loadMenu;
            detector = loadMenu.run();

            try
            {
                if (detector == "Save 1")
                {
                    obj1.load_game("../save1");
                    obj1.run(true);
                }
                else if (detector == "Save 2")
                {
                    obj1.load_game("../save2");
                    obj1.run(true);
                }
                else if (detector == "Save 3")
                {
                    obj1.load_game("../save3");
                    obj1.run(true);
                }
                else if (detector == "Save 4")
                {
                    obj1.load_game("../save4");
                    obj1.run(true);
                }
                else if (detector == "Save 5")
                {
                    obj1.load_game("../save5");
                    obj1.run(true);
                }
            }
            catch (std::exception &e)
            {
                cerr << "Error loading game: " << e.what() << endl;
            }
            break;
        }
        case 2: //  how to play
        {
            HintMenu hintMenu;
            hintMenu.run();
            break;
        }
        case 3: // exit
            return 0;
        default:
            break;
        }
    }
    return 0;
}