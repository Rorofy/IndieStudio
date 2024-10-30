/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Controller
*/

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <unordered_map>
#include <vector>
#include <chrono>
#include <functional>
#include <utility>
#include "irrlicht.h"
#include "ecs/Entity.hpp"
#include "ecs/Scene.hpp"

namespace game
{
    typedef std::function<void (indie::Scene &, indie::Entity &)> controllerAction;
    typedef std::function<void (indie::Scene &, indie::Entity &, irl::KeyInput &)> subAction;

    class Controller {
        public:
            class StaticAction {
                public:
                    StaticAction() = default;
                    StaticAction(controllerAction &action, std::size_t cooldown);

                    [[nodiscard]] bool canPlayAction(void);
                    [[nodiscard]] controllerAction &getAction(void);
                    void resetCooldown(void);
                    void setCooldown(std::size_t cooldown);
                private:
                    size_t _cooldown;
                    std::chrono::_V2::system_clock::time_point _clock;
                    long _timer;
                    controllerAction _action;
            };
        public:
            Controller() = default;
            ~Controller() = default;

            void addAction(const std::string &name, controllerAction action);
            void addSub(subAction action);
            void addStaticAction(const std::string &name, controllerAction action, std::size_t cooldown);
            bool haveAction(const std::string &name);
            void playAction(indie::Scene &scene, indie::Entity entity, const std::string &name) const;
            void playStaticAction(indie::Scene &scene, indie::Entity entity, const std::string &name);
            void playSub(indie::Scene &scene, indie::Entity entity, irl::KeyInput &input);
            void changeStaticCooldown(const std::string &name, std::size_t cooldown);

        private:
            std::unordered_map<std::string, controllerAction> _actions;
            std::unordered_map<std::string, StaticAction> _staticActions;
            std::unordered_map<std::string, bool> _actionSub;
            std::vector<subAction> _subs;
    };
}

#endif /* !CONTROLLER_HPP_ */
