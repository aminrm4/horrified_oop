#include "hint.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <filesystem>
using namespace std;

HintMenu::HintMenu(float width, float height, const sf::Font &font)
    : selectedState(HintState::None), hoveredIndex(-1), stateSelected(false), showInfoBox(false), infoBoxIndex(-1)
{
    if (!bgTexture.loadFromFile("../Horrified_Assets/final.png"))
    {
        throw runtime_error("Could not load background image");
    }
    bgSprite.setTexture(bgTexture);
    bgSprite.setColor(sf::Color::White);
    heroNames = {"Archaeologist", "Courier", "Mayor", "Scientist"};
    heroDescriptions = {
        "Archaeologist: Can dig up ancient secrets and decipher runes.",
        "Courier: Moves quickly and delivers items across the map.",
        "Mayor: Influences villagers and can call for help.",
        "Scientist: Analyzes monster weaknesses and crafts items."};
    vector<string> heroFiles = {
        "../Horrified_Assets/Heros/Archaeologist.png",
        "../Horrified_Assets/Heros/Courier.png",
        "../Horrified_Assets/Heros/Mayor.png",
        "../Horrified_Assets/Heros/Scientist.png"};
    heroTextures.resize(heroFiles.size());
    heroSprites.resize(heroFiles.size());
    float startX = 100.f;
    float y = 50.f;
    float spacing = 220.f;
    for (size_t i = 0; i < heroFiles.size(); ++i)
    {
        if (!heroTextures[i].loadFromFile(heroFiles[i]))
        {
            throw runtime_error("Could not load hero asset: " + heroFiles[i]);
        }
        heroSprites[i].setTexture(heroTextures[i]);
        sf::Vector2u texSize = heroTextures[i].getSize();
        float scaleX = 200.f / texSize.x;
        float scaleY = 200.f / texSize.y;
        heroSprites[i].setScale(scaleX, scaleY);
        heroSprites[i].setPosition(startX + i * spacing, y);
    }

    monsterNames = {"Drakula", "Invisible Man"};
    monsterDescriptions = {
        "Drakula: Can mesmerize and drain villagers. Avoid his gaze!",
        "Invisible Man: Sneaks around unseen, sabotaging your plans."};
    vector<string> monsterFiles = {
        "../Horrified_Assets/Monsters/Dracula.png",
        "../Horrified_Assets/Monsters/InvisibleMan.png"};
    monsterTextures.resize(monsterFiles.size());
    monsterSprites.resize(monsterFiles.size());
    for (size_t i = 0; i < monsterFiles.size(); ++i)
    {
        if (!monsterTextures[i].loadFromFile(monsterFiles[i]))
        {
            throw runtime_error("Could not load monster asset: " + monsterFiles[i]);
        }
        monsterSprites[i].setTexture(monsterTextures[i]);
        sf::Vector2u texSize = monsterTextures[i].getSize();
        float scaleX = 200.f / texSize.x;
        float scaleY = 200.f / texSize.y;
        monsterSprites[i].setScale(scaleX, scaleY);
        monsterSprites[i].setPosition(startX + (heroFiles.size() + i) * spacing, y);
    }

    extraNames = {"Perk Button", "IT"};
    extraDescriptions = {
        "Perk Button: Grants special one-time abilities to players.",
        "IT: Special event or item that can change the course of the game."};
    vector<string> extraFiles = {
        "../Horrified_Assets/perkbut.png",
        "../Horrified_Assets/it.png"};
    extraTextures.resize(extraFiles.size());
    extraSprites.resize(extraFiles.size());
    for (size_t i = 0; i < extraFiles.size(); ++i)
    {
        if (!extraTextures[i].loadFromFile(extraFiles[i]))
        {
            throw runtime_error("Could not load extra asset: " + extraFiles[i]);
        }
        extraSprites[i].setTexture(extraTextures[i]);
        sf::Vector2u texSize = extraTextures[i].getSize();
        float scaleX = 200.f / texSize.x;
        float scaleY = 200.f / texSize.y;
        extraSprites[i].setScale(scaleX, scaleY);
        extraSprites[i].setPosition(startX + (heroFiles.size() + monsterFiles.size() + i) * spacing, y);
    }
}

void HintMenu::draw(sf::RenderWindow &window)
{
    sf::Vector2u winSize = window.getSize();
    sf::Vector2u texSize = bgTexture.getSize();
    bgSprite.setScale(
        float(winSize.x) / texSize.x,
        float(winSize.y) / texSize.y);
    window.draw(bgSprite);
    for (size_t i = 0; i < heroSprites.size(); ++i)
    {
        if (hoveredIndex == int(i))
        {
            sf::RectangleShape highlight(sf::Vector2f(200, 200));
            highlight.setFillColor(sf::Color(255, 255, 102, 80));
            highlight.setPosition(heroSprites[i].getPosition());
            window.draw(highlight);
        }
        window.draw(heroSprites[i]);
    }
    for (size_t i = 0; i < monsterSprites.size(); ++i)
    {
        if (hoveredIndex == int(heroSprites.size() + i))
        {
            sf::RectangleShape highlight(sf::Vector2f(200, 200));
            highlight.setFillColor(sf::Color(255, 255, 102, 80));
            highlight.setPosition(monsterSprites[i].getPosition());
            window.draw(highlight);
        }
        window.draw(monsterSprites[i]);
    }
    for (size_t i = 0; i < extraSprites.size(); ++i)
    {
        if (hoveredIndex == int(heroSprites.size() + monsterSprites.size() + i))
        {
            sf::RectangleShape highlight(sf::Vector2f(200, 200));
            highlight.setFillColor(sf::Color(255, 255, 102, 80));
            highlight.setPosition(extraSprites[i].getPosition());
            window.draw(highlight);
        }
        window.draw(extraSprites[i]);
    }
    if (showInfoBox && infoBoxIndex >= 0)
    {
        float scale = infoBoxAnim;
        sf::Vector2f center(960, 540);
        sf::Vector2f infoBoxPos = center;
        sf::RectangleShape box(sf::Vector2f(600, 400));
        box.setFillColor(sf::Color(30, 30, 30, 230));
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(4);
        box.setOrigin(300, 200);
        box.setPosition(infoBoxPos);
        box.setScale(scale, scale);
        window.draw(box);
        sf::Font font;
        if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
            return;
        sf::Text title, desc;
        title.setFont(font);
        desc.setFont(font);
        title.setCharacterSize(40);
        desc.setCharacterSize(28);
        title.setFillColor(sf::Color(255, 255, 102));
        desc.setFillColor(sf::Color(220, 220, 220));
        std::string tStr, dStr;
        if (infoBoxIndex < int(heroNames.size()))
        {
            tStr = heroNames[infoBoxIndex];
            dStr = heroDescriptions[infoBoxIndex];
        }
        else if (infoBoxIndex < int(heroNames.size() + monsterNames.size()))
        {
            int idx = infoBoxIndex - heroNames.size();
            tStr = monsterNames[idx];
            dStr = monsterDescriptions[idx];
        }
        else
        {
            int idx = infoBoxIndex - heroNames.size() - monsterNames.size();
            tStr = extraNames[idx];
            dStr = extraDescriptions[idx];
        }
        title.setString(tStr);
        desc.setString(dStr);
        sf::FloatRect tB = title.getLocalBounds();
        title.setOrigin(tB.width / 2, tB.height / 2);
        title.setPosition(infoBoxPos.x, infoBoxPos.y - 60);
        title.setScale(scale, scale);
        sf::FloatRect dB = desc.getLocalBounds();
        desc.setOrigin(dB.width / 2, dB.height / 2);
        desc.setPosition(infoBoxPos.x, infoBoxPos.y + 30);
        desc.setScale(scale, scale);
        window.draw(title);
        window.draw(desc);
        sf::RectangleShape closeBtn(sf::Vector2f(40, 40));
        closeBtn.setFillColor(sf::Color(200, 80, 80));
        closeBtn.setOrigin(20, 20);
        closeBtn.setPosition(infoBoxPos.x + 300 * scale - 30 * scale, infoBoxPos.y - 200 * scale + 30 * scale);
        closeBtn.setScale(scale, scale);
        window.draw(closeBtn);
        sf::Text xText;
        xText.setFont(font);
        xText.setString("X");
        xText.setCharacterSize(28);
        xText.setFillColor(sf::Color::White);
        sf::FloatRect xB = xText.getLocalBounds();
        xText.setOrigin(xB.width / 2, xB.height / 2);
        xText.setPosition(infoBoxPos.x + 300 * scale - 30 * scale, infoBoxPos.y - 200 * scale + 30 * scale);
        xText.setScale(scale, scale);
        window.draw(xText);
    }
    sf::Font font;
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
        return;
    sf::Text backText;
    backText.setFont(font);
    backText.setString("Back");
    backText.setCharacterSize(48);
    backText.setFillColor(hoveredIndex == -2 ? sf::Color(255, 255, 102) : sf::Color(173, 216, 230));
    backText.setPosition(1760, 900);
    window.draw(backText);
}

void HintMenu::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    if (showInfoBox)
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::FloatRect closeRect(960 + 300 - 30, 540 - 200 + 30, 40, 40);
            if (closeRect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            {
                showInfoBox = false;
                infoBoxIndex = -1;
                return;
            }
            sf::FloatRect boxRect(960 - 300, 540 - 200, 600, 400);
            if (!boxRect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            {
                showInfoBox = false;
                infoBoxIndex = -1;
                return;
            }
        }
        return;
    }
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    hoveredIndex = -1;
    for (size_t i = 0; i < heroSprites.size(); ++i)
    {
        if (heroSprites[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            hoveredIndex = static_cast<int>(i);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                showInfoBox = true;
                infoBoxIndex = i;
                return;
            }
        }
    }
    for (size_t i = 0; i < monsterSprites.size(); ++i)
    {
        if (monsterSprites[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            hoveredIndex = static_cast<int>(heroSprites.size() + i);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                showInfoBox = true;
                infoBoxIndex = heroSprites.size() + i;
                return;
            }
        }
    }
    for (size_t i = 0; i < extraSprites.size(); ++i)
    {
        if (extraSprites[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            hoveredIndex = static_cast<int>(heroSprites.size() + monsterSprites.size() + i);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                showInfoBox = true;
                infoBoxIndex = heroSprites.size() + monsterSprites.size() + i;
                return;
            }
        }
    }
    sf::FloatRect backRect(1760, 900, 120, 60); // moved to right side
    if (backRect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        hoveredIndex = -2;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            stateSelected = true;
            selectedState = HintState::None; // Or a special value for 'back'
            return;
        }
    }
}

HintState HintMenu::getSelectedState() const
{
    return selectedState;
}

bool HintMenu::isStateSelected() const
{
    return stateSelected;
}

void HintMenu::resetSelection()
{
    stateSelected = false;
}

void HintMenu::updateHighlight()
{
}

HintState HintMenu::run()
{
    const unsigned int WIDTH = 1920, HEIGHT = 1080;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "How to Play");
    window.setFramerateLimit(60);

    if (!bgTexture.loadFromFile("../Horrified_Assets/final.png"))
    {
        throw runtime_error("Could not load background image");
    }
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(
        float(WIDTH) / bgTexture.getSize().x,
        float(HEIGHT) / bgTexture.getSize().y);

    sf::Music music;
    if (!music.openFromFile("../sounds/hint.mp3"))
    {
        throw runtime_error("Could not load hint music");
    }
    music.setLoop(true);
    music.play();

    sf::SoundBuffer clickBuffer;
    if (!clickBuffer.loadFromFile("../sounds/click.mp3"))
    {
        throw runtime_error("Could not load click sound");
    }
    sf::Sound clickSound;
    clickSound.setBuffer(clickBuffer);

    sf::Font font;
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
    {
        throw runtime_error("Could not load creep font");
    }
    *this = HintMenu(WIDTH, HEIGHT, font);
    if (!bgTexture.loadFromFile("../Horrified_Assets/final.png"))
    {
        throw runtime_error("Could not load background image");
    }
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(
        float(WIDTH) / bgTexture.getSize().x,
        float(HEIGHT) / bgTexture.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            int prevInfoBox = infoBoxIndex;
            bool prevShowInfoBox = showInfoBox;
            handleEvent(event, window);
            if (!prevShowInfoBox && showInfoBox)
            {
                infoBoxAnim = 0.0f;
                infoBoxJustOpened = true;
            }
        }
        if (showInfoBox && infoBoxAnim < 1.0f)
        {
            infoBoxAnim += 0.12f;
            if (infoBoxAnim > 1.0f)
                infoBoxAnim = 1.0f;
        }
        if (!showInfoBox)
        {
            infoBoxAnim = 1.0f;
            infoBoxJustOpened = false;
        }
        window.clear(sf::Color::Black);
        draw(window);
        window.display();
        if (isStateSelected())
        {
            music.stop();
            sf::sleep(sf::seconds(0.3f));
            window.close();
        }
    }
    music.stop();
    return getSelectedState();
}
