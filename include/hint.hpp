#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

enum class HintState {
    None,
    Hero_Archaeologist,
    Hero_Courier,
    Hero_Mayor,
    Hero_Scientist,
    Monster_Drakula,
    Monster_InvisibleMan,
    Back
};

class HintMenu {
public:
    HintMenu(float width, float height, const sf::Font& font);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    HintState getSelectedState() const;
    bool isStateSelected() const;
    void resetSelection();
    HintState run();
private:
    std::vector<sf::Sprite> heroSprites;
    std::vector<sf::Sprite> monsterSprites;
    std::vector<std::string> heroNames;
    std::vector<std::string> monsterNames;
    std::vector<std::string> heroDescriptions;
    std::vector<std::string> monsterDescriptions;
    std::vector<std::string> extraNames;
    std::vector<std::string> extraDescriptions;
    std::vector<sf::Texture> extraTextures;
    std::vector<sf::Sprite> extraSprites;
    sf::Texture bgTexture;
    sf::Sprite bgSprite;
    std::vector<sf::Texture> heroTextures;
    std::vector<sf::Texture> monsterTextures;
    HintState selectedState;
    int hoveredIndex;
    bool stateSelected;
    bool showInfoBox;
    int infoBoxIndex;
    void updateHighlight();
    float infoBoxAnim = 1.0f;
    bool infoBoxJustOpened = false;
};
