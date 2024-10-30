/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SceneSettings
*/

#include "scene/Scenes.hpp"
#include "irrlicht/Sprite.hpp"
#include "Position.hpp"
#include "ui/Button.hpp"
#include "irrlicht/Text.hpp"
#include "component/Script.hpp"
#include "Settings.hpp"
#include "ui/ScriptKeybind.hpp"


void createRectEntity(std::shared_ptr<indie::Scene> &scene, int x, int y)
{
    indie::Entity settingRect = scene->spawnEntity();
    irl::Sprite &settingRectSprite = scene->addComponent<irl::Sprite>(settingRect);
    game::Position &settingRectPos = scene->addComponent<game::Position>(settingRect);
    irl::Texture settingRectTexture = irl::Texture("../assets/ui/SettingRectangle.png", 0, 0, 387, 95);
    
    settingRectSprite.appendTexture(settingRectTexture);
    settingRectPos.setPos(x, y, 0);
}

void createSpriteEntity(std::shared_ptr<indie::Scene> &scene, int x, int y, int w, int h, std::string filepath)
{
    indie::Entity entity = scene->spawnEntity();
    irl::Sprite &entitySprite = scene->addComponent<irl::Sprite>(entity);
    game::Position &entityPos = scene->addComponent<game::Position>(entity);
    irl::Texture entityTexture = irl::Texture(filepath.c_str(), 0, 0, w, h);

    entitySprite.appendTexture(entityTexture);
    entityPos.setPos(x, y, 0);
}

void createTextEntity(std::shared_ptr<indie::Scene> &scene, int y, int width, std::string text, std::string value)
{
    indie::Entity entity = scene->spawnEntity();
    irl::Text &entityText = scene->addComponent<irl::Text>(entity);
    game::Position &entityPos = scene->addComponent<game::Position>(entity);
    indie::Entity entityValue = scene->spawnEntity();
    irl::Text &entityValueText = scene->addComponent<irl::Text>(entityValue);
    game::Position &entityValuePos = scene->addComponent<game::Position>(entityValue);
    game::Button &entityValueButton = scene->addComponent<game::Button>(entityValue);

    entityPos.setPos(820, y, 0);
    entityText.setString(text.c_str());
    entityText.setFont("../assets/ui/SherwoodRegular.png");
    entityValuePos.setPos(1320, y, 0);
    entityValueText.setString(value.c_str());
    entityValueText.setFont("../assets/ui/SherwoodRegular.png");
    entityValueButton.setHeight(43);
    entityValueButton.setWidth(width);
}

void createButtonTextEntity(std::shared_ptr<indie::Scene> &scene, int y, const irr::core::stringw &text,
    const std::string &button)
{
    indie::Entity entity = scene->spawnEntity();
    irl::Text &entityText = scene->addComponent<irl::Text>(entity);
    game::Position &entityPos = scene->addComponent<game::Position>(entity);
    indie::Entity entityValue = scene->spawnEntity();
    irl::Text &entityValueText = scene->addComponent<irl::Text>(entityValue);
    game::Position &entityValuePos = scene->addComponent<game::Position>(entityValue);
    game::Button &entityValueButton = scene->addComponent<game::Button>(entityValue);
    indie::Script &entityScript = scene->addComponent<indie::Script>(entityValue);
    irr::core::stringw nw = L"";

    nw += game::g_settings->getKey(button);
    entityPos.setPos(820, y, 0);
    entityText.setString(text);
    entityText.setFont("../assets/ui/SherwoodRegular.png");
    entityValuePos.setPos(1320, y, 0);
    entityValueText.setString(nw);
    entityValueText.setFont("../assets/ui/SherwoodRegular.png");
    entityValueButton.setHeight(43);
    entityValueButton.setWidth(43);
    entityValueButton.setName("keybind");
    entityValueButton.setValue(button);
    entityScript.setScript(std::make_unique<game::ScriptKeybind>(*scene, entityValue));
}

void createSimpleTextEntity(std::shared_ptr<indie::Scene> &scene, int x, int y, std::string text)
{
    indie::Entity entity = scene->spawnEntity();
    irl::Text &entityText = scene->addComponent<irl::Text>(entity);
    game::Position &entityPos = scene->addComponent<game::Position>(entity);

    entityPos.setPos(x, y, 0);
    entityText.setString(text.c_str());
    entityText.setFont("../assets/ui/SherwoodRegular.png");
}

void createPlayerButton(std::shared_ptr<indie::Scene> &scene, int i)
{
    indie::Entity playerT = scene->spawnEntity();
    irl::Text &playerTText = scene->addComponent<irl::Text>(playerT);
    game::Position &playerTPos = scene->addComponent<game::Position>(playerT);
    indie::Entity playerS = scene->spawnEntity();
    game::Button &playerSButton = scene->addComponent<game::Button>(playerS);
    irl::Sprite &playerSSprite = scene->addComponent<irl::Sprite>(playerS);
    game::Position &playerSPos = scene->addComponent<game::Position>(playerS);
    irl::Texture playerSTexture = irl::Texture("../assets/ui/blueRect.png", 0, 0, 402, 129);

    playerTPos.setPos(50, 250, 0);
    if (i == 1)
        playerTText.setString("Player 1");
    else 
        playerTText.setString("Player 2");
    playerTText.setFont("../assets/ui/SherwoodRegular.png");
    playerSSprite.appendTexture(playerSTexture);
    playerSPos.setPos(20, 220, 0);
    playerSButton.setHeight(129);
    playerSButton.setWidth(390);
    playerSButton.setOnClick([i](indie::Scene &scene, indie::Entity entity) {
        indie::Game::g_instance->removeScene(scene);
        if (i == 1)
            game::createSceneSettings2();
        else
            game::createSceneSettings();
    });
}

void createQuitButton(std::shared_ptr<indie::Scene> &scene)
{
    indie::Entity quitT = scene->spawnEntity();
    irl::Text &quitTText = scene->addComponent<irl::Text>(quitT);
    game::Position &quitTPos = scene->addComponent<game::Position>(quitT);
    indie::Entity quitS = scene->spawnEntity();
    game::Button &quitSButton = scene->addComponent<game::Button>(quitS);
    irl::Sprite &quitSSprite = scene->addComponent<irl::Sprite>(quitS);
    game::Position &quitSPos = scene->addComponent<game::Position>(quitS);
    irl::Texture quitSTexture = irl::Texture("../assets/ui/blueRect.png", 0, 0, 402, 129);

    quitTPos.setPos(50, 850, 0);
    quitTText.setString("Quit");
    quitTText.setFont("../assets/ui/SherwoodRegular.png");
    quitSSprite.appendTexture(quitSTexture);
    quitSPos.setPos(20, 820, 0);
    quitSButton.setHeight(129);
    quitSButton.setWidth(390);
    quitSButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
        indie::Game::g_instance->removeScene(scene);
        game::createSceneMenu();
    });
}

std::shared_ptr<indie::Scene> game::createSceneSettings(void)
{
    std::shared_ptr<indie::Scene> scene = indie::Game::g_instance->createScene();
    auto &s = game::g_settings;
    irr::core::stringw nw = L"";

    createSpriteEntity(scene, 540, 5, 1372, 1000, "../assets/ui/SettingsBackground.png");
    createSimpleTextEntity(scene, 50, 50, "Settings");
    createSpriteEntity(scene, 20, 20, 402, 129, "../assets/ui/blueRect.png");
    createPlayerButton(scene, 1);
    createQuitButton(scene);
    createButtonTextEntity(scene, 80, "Up Key", "up1");
    createRectEntity(scene, 780, 60);
    createButtonTextEntity(scene, 180, "Down Key", "down1");
    createRectEntity(scene, 780, 160);
    createButtonTextEntity(scene, 280, "Left Key", "left1");
    createRectEntity(scene, 780, 260);
    createButtonTextEntity(scene, 380, "Right Key", "right1");
    createRectEntity(scene, 780, 360);
    createButtonTextEntity(scene, 480, "Bomb Key", "bomb1");
    createRectEntity(scene, 780, 460);
    createButtonTextEntity(scene, 580, "Pause Key", "pause");
    createRectEntity(scene, 780, 560);
    return scene;
}


std::shared_ptr<indie::Scene> game::createSceneSettings2(void)
{
    std::shared_ptr<indie::Scene> scene = indie::Game::g_instance->createScene();

    createSpriteEntity(scene, 540, 5, 1372, 1000, "../assets/ui/SettingsBackground.png");
    createSimpleTextEntity(scene, 50, 50, "Settings");
    createSpriteEntity(scene, 20, 20, 402, 129, "../assets/ui/blueRect.png");
    createPlayerButton(scene, 2);
    createQuitButton(scene);
    createButtonTextEntity(scene, 80, "Up Key", "up2");
    createRectEntity(scene, 780, 60);
    createButtonTextEntity(scene, 180, "Down Key", "down2");
    createRectEntity(scene, 780, 160);
    createButtonTextEntity(scene, 280, "Left Key", "left2");
    createRectEntity(scene, 780, 260);
    createButtonTextEntity(scene, 380, "Right Key", "right2");
    createRectEntity(scene, 780, 360);
    createButtonTextEntity(scene, 480, "Bomb Key", "bomb2");
    createRectEntity(scene, 780, 460);
    return scene;
}
