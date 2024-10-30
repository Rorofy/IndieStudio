/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>
#include <vector>
#include "ecs/Scene.hpp"
#include "ecs/ComponentManager.hpp"
#include "ecs/ComponentMap.hpp"
#include "ecs/ASystem.hpp"
#include "irrlicht/Window.hpp"

namespace indie
{
    class Game {
        public:
            Game();
            ~Game();

            [[nodiscard]] std::shared_ptr<Scene> createScene(void);
            void removeScene(Scene &scene);
            void start(void);

            template<std::size_t T>
            void initComponent(void) {
                _compMap = std::make_shared<ComponentMapFactory<T>>();
            }

            template<typename T>
            void registerComponent(void) {
                _compRegistry.push_back(std::make_unique<ComponentManagerFactory<T>>());
                Component<T>::getId();
            }

            template<typename T>
            void registerSystem(void) {
                _systemRegistry.push_back(std::make_unique<SystemFactory<T>>());
            }

            [[nodiscard]] irl::Window &getWindow(void);
            [[nodiscard]] irr::scene::IMetaTriangleSelector *getSelector(void) const;
            [[nodiscard]] const std::vector<std::shared_ptr<Scene>> &getScenes(void) const;
            [[nodiscard]] video::ITexture *getTexture(const std::string &path);
        public:
            static std::unique_ptr<Game> g_instance;
            static const float g_tps;
            static const float g_delta;
        private:
            void loop(void);
            void update(void);
            void render(void);
            void removeDeads(void);

            std::vector<std::shared_ptr<Scene>> _scenes;
            std::vector<std::shared_ptr<Scene>> _deads;
            std::vector<std::unique_ptr<AComponentManagerFactory>> _compRegistry;
            std::vector<std::unique_ptr<ASystemFactory>> _systemRegistry;
            std::shared_ptr<AComponentMapFactory> _compMap;
            irl::Window _window;
            irr::scene::IMetaTriangleSelector *_selector;
    };

    [[nodiscard]] IrrlichtDevice *getDevice();
    [[nodiscard]] IVideoDriver *getVideoDriver();
    [[nodiscard]] ISceneManager &getSceneManager();
    [[nodiscard]] IGUIEnvironment &getGuiEnv();
}

#endif /* !GAME_HPP_ */