#include <iostream>
#include "free_func.hpp"
#include <filesystem>
namespace fs = std::filesystem;

int showLocationTextBox(sf::RenderWindow &window)
{
    // Load font
    sf::Font font;
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
    {
        // Handle error
        return 0;
    }

    // Prepare the text box (rectangle)
    sf::Vector2u winSize = window.getSize();
    float maxBoxWidth = 1920.f, maxBoxHeight = 1080.f;
    float boxWidth = std::min(winSize.x * 0.8f, maxBoxWidth);
    float boxHeight = std::min(winSize.y * 0.8f, maxBoxHeight);
    sf::Vector2f boxSize(boxWidth, boxHeight);
    sf::RectangleShape textBox(boxSize);
    textBox.setFillColor(sf::Color(30, 30, 30, 220));
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(3.f);
    textBox.setPosition((winSize.x - boxSize.x) / 2, (winSize.y - boxSize.y) / 2);

    // Always load images 0.png to 18.png in order
    std::vector<std::string> imageFiles;
    std::string folder = "../Horrified_Assets/loacation/";
    for (int i = 0; i < 19; ++i)
    {
        std::string path = folder + std::to_string(i) + ".png";
        if (fs::exists(path))
        {
            imageFiles.push_back(path);
        }
        else
        {
            // If any file is missing, fill with empty string (or handle as needed)
            imageFiles.push_back("");
        }
    }
    size_t numImages = imageFiles.size();
    if (numImages == 0)
        return 0;
    size_t cols = 5;
    size_t rows = 4;
    float padding = 20.f;
    float gridWidth = boxSize.x - 2 * padding;
    float gridHeight = boxSize.y - 2 * padding - 40.f; // leave space for text
    float cellWidth = gridWidth / cols;
    float cellHeight = gridHeight / rows;

    // Load textures and sprites
    std::vector<sf::Texture> textures(numImages);
    std::vector<sf::Sprite> sprites(numImages);
    std::vector<sf::FloatRect> spriteBounds(numImages);
    for (size_t i = 0; i < numImages; ++i)
    {
        if (!imageFiles[i].empty() && textures[i].loadFromFile(imageFiles[i]))
        {
            sprites[i].setTexture(textures[i]);
            // Scale to fit inside the cell
            float scaleX = cellWidth / sprites[i].getLocalBounds().width;
            float scaleY = cellHeight / sprites[i].getLocalBounds().height;
            float scale = std::min(scaleX, scaleY) * 0.9f; // add margin
            sprites[i].setScale(scale, scale);
        }
        size_t row = i / cols;
        size_t col = i % cols;
        float x = textBox.getPosition().x + padding + col * cellWidth + (cellWidth - (sprites[i].getLocalBounds().width * sprites[i].getScale().x)) / 2;
        float y = textBox.getPosition().y + padding + row * cellHeight + (cellHeight - (sprites[i].getLocalBounds().height * sprites[i].getScale().y)) / 2;
        sprites[i].setPosition(x, y);
        spriteBounds[i] = sprites[i].getGlobalBounds();
    }

    // Text for instructions
    sf::Text infoText("All locations. Click an image for its number, click outside to close, Esc to close", font, 24);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition(textBox.getPosition().x + 20, textBox.getPosition().y + boxSize.y - 40);

    bool running = true;
    while (window.isOpen() && running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    running = false;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (!textBox.getGlobalBounds().contains(mousePos))
                {
                    return -1; // Return -1 if clicked outside
                }
                else
                {
                    // Check if clicked on any sprite
                    for (size_t i = 0; i < numImages; ++i)
                    {
                        if (!imageFiles[i].empty() && spriteBounds[i].contains(mousePos))
                        {
                            // Return the exact number of the image clicked (0-18)
                            return static_cast<int>(i);
                        }
                    }
                }
            }
        }
        window.clear();
        window.draw(textBox);
        for (size_t i = 0; i < numImages; ++i)
        {
            if (!imageFiles[i].empty())
                window.draw(sprites[i]);
        }
        window.draw(infoText);
        window.display();
    }
    return 0;
}

void showCenteredTextBox(sf::RenderWindow &window, const std::string &text)
{
    // Load font
    sf::Font font;
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
    {
        // Handle error (could throw, or just return)
        return;
    }

    // Prepare the text
    unsigned int characterSize = 32;
    sf::Text displayText(text, font, characterSize);
    displayText.setFillColor(sf::Color::White);

    // Calculate size of the text box based on text bounds
    sf::FloatRect textBounds = displayText.getLocalBounds();
    float padding = 40.f;
    float boxWidth = textBounds.width + 2 * padding;
    float boxHeight = textBounds.height + 2 * padding;

    // Get window size and center the box
    sf::Vector2u winSize = window.getSize();
    float boxX = (winSize.x - boxWidth) / 2.f;
    float boxY = (winSize.y - boxHeight) / 2.f;

    sf::RectangleShape textBox(sf::Vector2f(boxWidth, boxHeight));
    textBox.setFillColor(sf::Color(30, 30, 30, 220));
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(3.f);
    textBox.setPosition(boxX, boxY);

    // Center the text inside the box
    displayText.setPosition(
        boxX + padding - textBounds.left,
        boxY + padding - textBounds.top);

    bool running = true;
    while (window.isOpen() && running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                running = false;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (!textBox.getGlobalBounds().contains(mousePos))
                {
                    running = false;
                }
            }
        }
        window.clear();
        window.draw(textBox);
        window.draw(displayText);
        window.display();
    }
}

int showAssetSelectionBox(sf::RenderWindow &window, const std::string &directory)
{
    namespace fs = std::filesystem;
    // Load font
    sf::Font font;
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
    {
        return -1;
    }

    // Collect image files from the directory
    std::vector<std::string> imageFiles;
    for (const auto &entry : fs::directory_iterator(directory))
    {
        if (entry.is_regular_file())
        {
            std::string path = entry.path().string();
            if (path.ends_with(".png") || path.ends_with(".jpg") || path.ends_with(".jpeg"))
            {
                imageFiles.push_back(path);
            }
        }
    }
    // Sort to ensure consistent order
    std::sort(imageFiles.begin(), imageFiles.end());
    if (imageFiles.empty())
    {
        return -1;
    }
    // Prepare the text box (rectangle)
    sf::Vector2u winSize = window.getSize();
    float maxBoxWidth = 1920.f, maxBoxHeight = 1080.f;
    float boxWidth = std::min(winSize.x * 0.8f, maxBoxWidth);
    float boxHeight = std::min(winSize.y * 0.8f, maxBoxHeight);
    sf::Vector2f boxSize(boxWidth, boxHeight);
    sf::RectangleShape textBox(boxSize);
    textBox.setFillColor(sf::Color(30, 30, 30, 220));
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(3.f);
    textBox.setPosition((winSize.x - boxSize.x) / 2, (winSize.y - boxSize.y) / 2);

    // Grid layout
    size_t numImages = imageFiles.size();
    size_t cols = 5;
    size_t rows = (numImages + cols - 1) / cols;
    float padding = 20.f;
    float gridWidth = boxSize.x - 2 * padding;
    float gridHeight = boxSize.y - 2 * padding - 40.f; // leave space for text
    float cellWidth = gridWidth / cols;
    float cellHeight = gridHeight / std::max(rows, size_t(1));

    // Load textures and sprites
    std::vector<sf::Texture> textures(numImages);
    std::vector<sf::Sprite> sprites(numImages);
    std::vector<sf::FloatRect> spriteBounds(numImages);
    for (size_t i = 0; i < numImages; ++i)
    {
        if (textures[i].loadFromFile(imageFiles[i]))
        {
            sprites[i].setTexture(textures[i]);
            float scaleX = cellWidth / sprites[i].getLocalBounds().width;
            float scaleY = cellHeight / sprites[i].getLocalBounds().height;
            float scale = std::min(scaleX, scaleY) * 0.9f;
            sprites[i].setScale(scale, scale);
        }
        size_t row = i / cols;
        size_t col = i % cols;
        float x = textBox.getPosition().x + padding + col * cellWidth + (cellWidth - (sprites[i].getLocalBounds().width * sprites[i].getScale().x)) / 2;
        float y = textBox.getPosition().y + padding + row * cellHeight + (cellHeight - (sprites[i].getLocalBounds().height * sprites[i].getScale().y)) / 2;
        sprites[i].setPosition(x, y);
        spriteBounds[i] = sprites[i].getGlobalBounds();
    }

    sf::Text infoText("Select an asset. Click an image for its index, click outside to close, Esc to close", font, 24);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition(textBox.getPosition().x + 20, textBox.getPosition().y + boxSize.y - 40);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return -1;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    return -1;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (!textBox.getGlobalBounds().contains(mousePos))
                {
                    return -1;
                }
                else
                {
                    for (size_t i = 0; i < numImages; ++i)
                    {
                        if (spriteBounds[i].contains(mousePos))
                        {
                            return static_cast<int>(i); // Return the index of the clicked image
                        }
                    }
                }
            }
        }
        window.clear();
        window.draw(textBox);
        for (size_t i = 0; i < numImages; ++i)
        {
            window.draw(sprites[i]);
        }
        window.draw(infoText);
        window.display();
    }
    return -1;
}

void showAssetInBox(sf::RenderWindow& window, const std::string& directory, const std::string& assetName) {
    // Load font for optional text (reuse style)
    sf::Font font;
    font.loadFromFile("../Horrified_Assets/creep.ttf");

    // Build the full path to the asset
    std::string assetPath = directory + "/" + assetName;

    // Load the image as a texture
    sf::Texture texture;
    texture.loadFromFile(assetPath);
    sf::Sprite sprite(texture);

    // Prepare the centered box
    sf::Vector2u winSize = window.getSize();
    float maxBoxWidth = 800.f, maxBoxHeight = 600.f;
    float boxWidth = std::min(winSize.x * 0.6f, maxBoxWidth);
    float boxHeight = std::min(winSize.y * 0.6f, maxBoxHeight);
    sf::Vector2f boxSize(boxWidth, boxHeight);
    sf::RectangleShape box(boxSize);
    box.setFillColor(sf::Color(30, 30, 30, 220));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(3.f);
    box.setPosition((winSize.x - boxSize.x) / 2, (winSize.y - boxSize.y) / 2);

    // Scale the sprite to fit inside the box (with margin)
    float margin = 30.f;
    float availableWidth = boxWidth - 2 * margin;
    float availableHeight = boxHeight - 2 * margin;
    float scaleX = availableWidth / sprite.getLocalBounds().width;
    float scaleY = availableHeight / sprite.getLocalBounds().height;
    float scale = std::min(scaleX, scaleY);
    sprite.setScale(scale, scale);
    // Center the sprite in the box
    float spriteX = box.getPosition().x + (boxWidth - sprite.getLocalBounds().width * scale) / 2 - sprite.getLocalBounds().left * scale;
    float spriteY = box.getPosition().y + (boxHeight - sprite.getLocalBounds().height * scale) / 2 - sprite.getLocalBounds().top * scale;
    sprite.setPosition(spriteX, spriteY);

    // Optional: Add a message below the image
    sf::Text infoText("Press Esc or click outside the box to close", font, 22);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition(box.getPosition().x + 20, box.getPosition().y + boxHeight - 36);

    bool running = true;
    while (window.isOpen() && running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                running = false;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (!box.getGlobalBounds().contains(mousePos)) {
                    running = false;
                }
            }
        }
        window.clear();
        window.draw(box);
        window.draw(sprite);
        window.draw(infoText);
        window.display();
    }
}

std::string showTextInputBox(sf::RenderWindow& window, const std::string& prompt) {
    sf::Font font;
    font.loadFromFile("../Horrified_Assets/arial.ttf");

    unsigned int characterSize = 32;
    sf::Text promptText(prompt, font, characterSize);
    promptText.setFillColor(sf::Color::White);

    std::string inputStr;
    sf::Text inputText("", font, characterSize);
    inputText.setFillColor(sf::Color::Yellow);

    float padding = 40.f;
    float minBoxWidth = 400.f;
    float boxHeight = 140.f;
    float boxWidth = std::max(promptText.getLocalBounds().width + 2 * padding, minBoxWidth);

    sf::Vector2u winSize = window.getSize();
    float boxX = (winSize.x - boxWidth) / 2.f;
    float boxY = (winSize.y - boxHeight) / 2.f;
    sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
    box.setFillColor(sf::Color(30, 30, 30, 220));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(3.f);
    box.setPosition(boxX, boxY);

    promptText.setPosition(boxX + padding, boxY + 10.f);
    inputText.setPosition(boxX + padding, boxY + 60.f);

    bool running = true;
    while (window.isOpen() && running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return "";
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    return "";
                }
                if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Return) {
                    running = false;
                }
                if (event.key.code == sf::Keyboard::BackSpace && !inputStr.empty()) {
                    inputStr.pop_back();
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= 32 && event.text.unicode < 127) {
                    inputStr += static_cast<char>(event.text.unicode);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (!box.getGlobalBounds().contains(mousePos)) {
                    return "";
                }
            }
        }
        inputText.setString(inputStr + "|"); // show cursor
        window.clear();
        window.draw(box);
        window.draw(promptText);
        window.draw(inputText);
        window.display();
    }
    return inputStr;
}
