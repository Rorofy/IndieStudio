/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Pause
*/

#include "ui/Pause.hpp"

void displayPauseMenu(indie::Scene &scene)
{
    indie::Entity pause = scene.spawnEntity();
    indie::Entity resume = scene.spawnEntity();
    indie::Entity menu = scene.spawnEntity();
    indie::Entity save = scene.spawnEntity();

    irl::Text &pauseText = scene.addComponent<irl::Text>(pause);
    irl::Text &resumeText = scene.addComponent<irl::Text>(resume);
    irl::Text &menuText = scene.addComponent<irl::Text>(menu);
    irl::Text &saveText = scene.addComponent<irl::Text>(save);
    game::Position&savePos = scene.addComponent<game::Position>(save);
    game::Position &pausePos = scene.addComponent<game::Position>(pause);
    game::Position &resumePos = scene.addComponent<game::Position>(resume);
    game::Position &menuPos = scene.addComponent<game::Position>(menu);
    game::Button &resumeButton = scene.addComponent<game::Button>(resume);
    game::Button &menuButton = scene.addComponent<game::Button>(menu);
    game::Button &saveButton = scene.addComponent<game::Button>(save);

    pauseText.setString("PAUSE");
    pauseText.setFont("../assets/ui/SherwoodRegular.png");
    pausePos.setPos(1600, 400, 0);
    resumeText.setString("Resume");
    resumeText.setFont("../assets/ui/SherwoodRegular.png");
    resumePos.setPos(1590, 500, 0);
    resumeButton.setHeight(43);
    resumeButton.setWidth(170);
    resumeButton.setOnClick([pause, resume, menu, save](indie::Scene &scene, indie::Entity entity) {
        scene.removeEntity(pause);
        scene.removeEntity(resume);
        scene.removeEntity(menu);
        scene.removeEntity(save);
    });
    savePos.setPos(1600, 600, 0);
    saveText.setString("Save");
    saveText.setFont("../assets/ui/SherwoodRegular.png");
    savePos.setPos(1620, 600, 0);
    saveButton.setHeight(43);
    saveButton.setWidth(100);
    saveButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
    });
    menuText.setString("Main menu");
    menuText.setFont("../assets/ui/SherwoodRegular.png");
    menuPos.setPos(1560, 700, 0);
    menuButton.setHeight(43);
    menuButton.setWidth(240);
    menuButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
        indie::Game::g_instance->removeScene(scene);
        game::createSceneMenu();
    });
    
    
}