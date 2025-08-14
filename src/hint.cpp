#include "hint.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int HintMenu::run()
{
    const unsigned int width = 1920, height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "How to Play");
    window.setFramerateLimit(60);

    sf::Texture bg_texture;
    bg_texture.loadFromFile("../Horrified_Assets/final.png");
    sf::Sprite bg_sprite;
    bg_sprite.setTexture(bg_texture);
    bg_sprite.setScale(
        float(width) / bg_texture.getSize().x,
        float(height) / bg_texture.getSize().y);

    sf::Font font;
    font.loadFromFile("../Horrified_Assets/creep.ttf");

    sf::Music music;
    music.openFromFile("../sounds/hint.mp3");
    music.setLoop(true);
    music.play();

    vector<string> hero_files = {
        "../Horrified_Assets/Heros/Archaeologist.png",
        "../Horrified_Assets/Heros/Courier.png",
        "../Horrified_Assets/Heros/Mayor.png",
        "../Horrified_Assets/Heros/Scientist.png"};
    vector<string> hero_names = {"Archaeologist", "Courier", "Mayor", "Scientist"};
    vector<string> hero_descriptions = {
        "can pick up item from a neghibour house",
        "Courier: teleport your self to your team mate",
        "Mayor: guid the villager to their safe location to win.",
        "Scientist: increase items power to win"};

    vector<string> monster_files = {
        "../Horrified_Assets/Monsters/Dracula.png",
        "../Horrified_Assets/Monsters/InvisibleMan.png"};
    vector<string> monster_names = {"Drakula", "Invisible Man"};
    vector<string> monster_descriptions = {
        "Drakula: watch his dark charem might be teleported",
        "Invisible Man: use your item to run away,watch the nightterror"};

    vector<string> extra_files = {
        "../Horrified_Assets/perkbut.png",
        "../Horrified_Assets/it.png"};
    vector<string> extra_names = {"Perk Button", "IT"};
    vector<string> extra_descriptions = {
        "use to get more power ,win the game befor monster card finished",
        "IT: use them to do monsters task and kill monsters to win"};

    float start_x = 100.f;
    float y = 50.f;
    float spacing = 220.f;

    vector<sf::Texture> hero_textures(hero_files.size());
    vector<sf::Sprite> hero_sprites(hero_files.size());

    for (size_t i = 0; i < hero_files.size(); ++i)
    {
        hero_textures[i].loadFromFile(hero_files[i]);
        hero_sprites[i].setTexture(hero_textures[i]);
        sf::Vector2u tex_size = hero_textures[i].getSize();
        float scale_x = 200.f / tex_size.x;
        float scale_y = 200.f / tex_size.y;
        hero_sprites[i].setScale(scale_x, scale_y);
        hero_sprites[i].setPosition(start_x + i * spacing, y);
    }

    vector<sf::Texture> monster_textures(monster_files.size());
    vector<sf::Sprite> monster_sprites(monster_files.size());

    for (size_t i = 0; i < monster_files.size(); ++i)
    {
        monster_textures[i].loadFromFile(monster_files[i]);
        monster_sprites[i].setTexture(monster_textures[i]);
        sf::Vector2u tex_size = monster_textures[i].getSize();
        float scale_x = 200.f / tex_size.x;
        float scale_y = 200.f / tex_size.y;
        monster_sprites[i].setScale(scale_x, scale_y);
        monster_sprites[i].setPosition(start_x + (hero_files.size() + i) * spacing, y);
    }

    vector<sf::Texture> extra_textures(extra_files.size());
    vector<sf::Sprite> extra_sprites(extra_files.size());

    for (size_t i = 0; i < extra_files.size(); ++i)
    {
        extra_textures[i].loadFromFile(extra_files[i]);
        extra_sprites[i].setTexture(extra_textures[i]);
        sf::Vector2u tex_size = extra_textures[i].getSize();
        float scale_x = 200.f / tex_size.x;
        float scale_y = 200.f / tex_size.y;
        extra_sprites[i].setScale(scale_x, scale_y);
        extra_sprites[i].setPosition(start_x + (hero_files.size() + monster_files.size() + i) * spacing, y);
    }

    sf::Text back_button;
    back_button.setFont(font);
    back_button.setString("Back to Menu");
    back_button.setCharacterSize(48);
    back_button.setFillColor(sf::Color(173, 216, 230));
    sf::FloatRect back_bounds = back_button.getLocalBounds();
    back_button.setOrigin(back_bounds.width / 2.f, back_bounds.height / 2.f);
    back_button.setPosition(width / 2.f, height - 100.f);

    sf::Text info_text;
    info_text.setFont(font);
    info_text.setCharacterSize(24);
    info_text.setFillColor(sf::Color::Yellow);
    info_text.setPosition(width / 2.f, height / 2.f);
    string current_info;

    int hovered_index = -1;
    bool show_info = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                hovered_index = -1;

                for (size_t i = 0; i < hero_files.size(); ++i)
                {
                    if (hero_sprites[i].getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
                    {
                        hovered_index = static_cast<int>(i);
                        break;
                    }
                }

                if (hovered_index == -1)
                {
                    for (size_t i = 0; i < monster_files.size(); ++i)
                    {
                        int global_i = static_cast<int>(hero_files.size() + i);
                        if (monster_sprites[i].getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
                        {
                            hovered_index = global_i;
                            break;
                        }
                    }
                }

                if (hovered_index == -1)
                {
                    for (size_t i = 0; i < extra_files.size(); ++i)
                    {
                        int global_i = static_cast<int>(hero_files.size() + monster_files.size() + i);
                        if (extra_sprites[i].getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
                        {
                            hovered_index = global_i;
                            break;
                        }
                    }
                }

                // Check back button
                if (hovered_index == -1 && back_button.getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
                {
                    hovered_index = -2;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (hovered_index == -2)
                {
                    music.stop();
                    sf::sleep(sf::seconds(0.2f));
                    window.close();
                    return 0;
                }
                else if (hovered_index >= 0)
                {
                    show_info = true;
                    
                    if (hovered_index < hero_files.size())
                    {
                        current_info = hero_descriptions[hovered_index];
                    }
                    else if (hovered_index < hero_files.size() + monster_files.size())
                    {
                        size_t monster_index = hovered_index - hero_files.size();
                        current_info = monster_descriptions[monster_index];
                    }
                    else if (hovered_index < hero_files.size() + monster_files.size() + extra_files.size())
                    {
                        size_t extra_index = hovered_index - hero_files.size() - monster_files.size();
                        current_info = extra_descriptions[extra_index];
                    }
                }
            }
        }

        if (hovered_index == -2)
        {
            back_button.setFillColor(sf::Color(255, 255, 102));
        }
        else
        {
            back_button.setFillColor(sf::Color(173, 216, 230));
        }

        info_text.setString(current_info);
        sf::FloatRect text_bounds = info_text.getLocalBounds();
        info_text.setOrigin(text_bounds.width / 2.f, text_bounds.height / 2.f);
        info_text.setPosition(width / 2.f, height / 2.f);

        window.clear();
        window.draw(bg_sprite);

        for (size_t i = 0; i < hero_files.size(); ++i)
        {
            window.draw(hero_sprites[i]);
        }
        for (size_t i = 0; i < monster_files.size(); ++i)
        {
            window.draw(monster_sprites[i]);
        }
        for (size_t i = 0; i < extra_files.size(); ++i)
        {
            window.draw(extra_sprites[i]);
        }

        if (show_info)
        {
            sf::RectangleShape text_bg;
            text_bg.setSize(sf::Vector2f(800.f, 100.f));
            text_bg.setFillColor(sf::Color(0, 0, 0, 180));
            text_bg.setOutlineColor(sf::Color::White);
            text_bg.setOutlineThickness(2.f);
            text_bg.setOrigin(400.f, 50.f);
            text_bg.setPosition(width / 2.f, height / 2.f);
            window.draw(text_bg);

            window.draw(info_text);
        }

        window.draw(back_button);
        window.display();
    }

    return 0;
}
