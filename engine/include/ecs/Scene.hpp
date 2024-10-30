/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <bitset>
#include <vector>
#include <set>
#include "irrlicht.h"
#include "ecs/ComponentManager.hpp"
#include "ecs/Component.hpp"
#include "ecs/ComponentMap.hpp"
#include "ecs/Entity.hpp"
#include "ecs/EntityManager.hpp"
#include "ecs/ASystem.hpp"
#include "event/EventBus.hpp"

namespace indie
{
    class Scene {
        public:
            Scene(std::shared_ptr<AComponentMapFactory> compMapFactory);
            ~Scene();

            void init(void);
            void update(void);
            void render(void);
            void post(void);
            [[nodiscard]] Entity spawnEntity();
            void removeEntity(Entity entity);

            template<typename T>
            T &addComponent(Entity e) {
                std::shared_ptr<AComponentMap> old = _maskMap[e]->clone();

                _maskMap[e]->add(Component<T>::getId());
                updateSystems(e, *old);
                return getComponentManager<T>().add(e);
            }

            template<typename T>
            void removeComponent(Entity e) {
                std::shared_ptr<AComponentMap> old = _maskMap[e]->clone();

                _maskMap[e]->remove(Component<T>::getId());
                updateSystems(e, *old);
                getComponentManager<T>().remove(e);
            }

            template<typename T>
            [[nodiscard]] T &getComponent(Entity e) const {
                return getComponentManager<T>().get(e);
            }

            template<typename T>
            [[nodiscard]] bool hasComponent(Entity e) const {
                return getComponentManager<T>().has(e);
            }

            template<typename T>
            [[nodiscard]] const std::unordered_map<indie::Entity, std::size_t> &getEntityWith(void) const {
                return getComponentManager<T>().getEntities();
            }

            void registerComponentManager(std::unique_ptr<AComponentManager> manager);
            void registerSystem(std::unique_ptr<ASystem> system);

            EventBus &getEventBus(void) const;
        private:
            template<typename T>
            [[nodiscard]] ComponentManager<T> &getComponentManager() const {
                return *static_cast<ComponentManager<T> *>(_compManagers.at(Component<T>::getId()).get());
            }

            void updateSystems(Entity e, AComponentMap &old);

            std::vector<std::unique_ptr<AComponentManager>> _compManagers;
            std::vector<std::unique_ptr<ASystem>> _systems;
            std::unordered_map<Entity, std::unique_ptr<AComponentMap>> _maskMap;
            std::shared_ptr<AComponentMapFactory> _compMap;
            EntityManager _entityManager;
            std::unique_ptr<EventBus> _eventBus;
            std::set<Entity> _deads;

    };
}

#endif /* !SCENE_HPP_ */