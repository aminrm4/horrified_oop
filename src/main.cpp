#include "starting_menu.hpp"
#include "programm.hpp"
#include "load_game.hpp"

int main() {
    programm obj1;

    while (true) {
        // Create a Menu object (font will be loaded in run)
        Menu menu(1920, 1080, sf::Font());
        MenuState selected = menu.run();

        // Handle the selected menu state
        switch (selected) {
            case MenuState::NewGame:
                obj1.run();
                // Start new game logic here
                break;
            case MenuState::LoadGame: {
                // Show load game screen
                while (true) {
                    LoadGameMenu loadMenu(1920, 1080, sf::Font());
                    LoadGameState saveSelected = loadMenu.run();
                    if (saveSelected == LoadGameState::Back) {
                        // Go back to main menu
                        break;
                    }
                    // Otherwise, handle loading the selected save slot here
                    // Example: if (saveSelected == LoadGameState::Save1) { ... }
                    // After loading, you may want to break or continue as needed
                    break;
                }
                break;
            }
            case MenuState::HowToPlay:
                // Show instructions logic here
                break;
            case MenuState::Exit:
                // Exit logic here
                return 0;
            default:
                break;
        }
    }
    return 0;
}