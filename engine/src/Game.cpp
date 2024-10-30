/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** Game
*/

#include <chrono>
#include <thread>
#include <algorithm>
#include "Game.hpp"
#include "irrlicht.h"
#include "irrlicht/event/EventReceiver.hpp"
#include "exception/AssetNotFound.hpp"

using namespace indie;

std::unique_ptr<Game> Game::g_instance = std::unique_ptr<Game>(nullptr);
const float Game::g_tps = 60;
const float Game::g_delta = 1000/Game::g_tps;

Game::Game() :
    _window(1920, 1080, L"Test The Game")
{
}

Game::~Game()
{
    _scenes.clear();
    delete _window.getDevice()->getEventReceiver();
    _selector->removeAllTriangleSelectors();
    _selector->drop();
}

void Game::start(void)
{
    _window.getDevice()->setEventReceiver(new irl::EventReceiver());
    _selector = _window.getSceneManager().createMetaTriangleSelector();
    try {
        loop();
    } catch (indie::IndieException &e) {
        std::cerr << e.what() << std::endl;
        _window.getDevice()->closeDevice();
    }
}

void Game::loop(void)
{
    int accumulator = 0;
    long elasp = Game::g_delta;

    while (_window.checkCloseEvent()) {
        long begin = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        accumulator += elasp;
        while (accumulator >= Game::g_delta) {
            accumulator -= Game::g_delta;
            update();
        }
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds((int)Game::g_delta - accumulator));
        elasp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - begin;
    }
}

void Game::removeDeads(void)
{
    auto dead = _deads.begin();
    while (dead != _deads.end()) {
        auto scene = std::find(_scenes.begin(), _scenes.end(), *dead);
        if (scene != _scenes.end()) _scenes.erase(scene);
        dead = _deads.erase(dead);
    }
}

void Game::update(void)
{
    for (auto &i : _scenes)
        i->update();
    removeDeads();
}

void Game::render(void)
{
    _window.beginDraw();
    for (auto &i : _scenes)
        i->render();
    _window.endDraw();
}

std::shared_ptr<Scene> Game::createScene(void)
{
    std::shared_ptr<Scene> scene = std::make_shared<Scene>(_compMap);

    _scenes.push_back(scene);
    for (auto &i : _compRegistry)
        scene->registerComponentManager(std::move(i->factory()));
    for (auto &i : _systemRegistry) {
        auto system = i->factory(*scene);
        system->setSignature(_compMap->factory());
        scene->registerSystem(std::move(system));
    }
    scene->init();
    return scene;
}

void Game::removeScene(Scene &scene)
{
    for (auto &sce : _scenes)
        if (sce.get() == &scene)
            _deads.push_back(sce);
}

video::ITexture *Game::getTexture(const std::string &path)
{
    auto texture = _window.getVideoDriver()->getTexture(path.c_str());

    if (texture == NULL)
        throw indie::AssetNotFound("Texture", path);
    return texture;    
}

irl::Window &Game::getWindow(void)
{
    return _window;
}

irr::scene::IMetaTriangleSelector *Game::getSelector(void) const
{
    return _selector;
}

const std::vector<std::shared_ptr<Scene>> &Game::getScenes(void) const
{
    return _scenes;
}

IrrlichtDevice *indie::getDevice(void)
{
    return indie::Game::g_instance->getWindow().getDevice();
}

IVideoDriver *indie::getVideoDriver(void)
{
    return indie::Game::g_instance->getWindow().getVideoDriver();
}

ISceneManager &indie::getSceneManager(void)
{
    return indie::Game::g_instance->getWindow().getSceneManager();
}

IGUIEnvironment &indie::getGuiEnv(void)
{
    return indie::Game::g_instance->getWindow().getGuiEnv();
}