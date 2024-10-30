/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
**  ComponentManager
*/

#ifndef _COMPONENTMANAGER_HPP_
#define _COMPONENTMANAGER_HPP_

#include <memory>
#include <unordered_map>
#include "ecs/Component.hpp"
#include "Entity.hpp"

namespace indie
{
    class AComponentManager {
        public:
            virtual ~AComponentManager() = default;

            virtual void update(void) = 0;
            virtual void remove(Entity entity) = 0;
            [[nodiscard]] virtual std::size_t getComponentId(void) = 0;
    };

    template<typename T>
    class ComponentManager : public AComponentManager {
        public:
            ComponentManager() : _size(1), _max(10000) {
                _data = std::make_unique<T[]>(_max);
            };

            ~ComponentManager() {};

            [[nodiscard]] T &get(Entity entity) {
                return _data[_map.at(entity)];
            }

            void del(Entity entity) {
                Entity old = 0;
                size_t newIndex = 0;

                if (entity == 0) return;
                newIndex = _map[entity];
                _data[newIndex] = _data[_size-1];
                old = _reverse[_size-1];
                _map[old] = newIndex;
                _reverse[newIndex] = old;
                _reverse.erase(_size-1);
                _map.erase(entity);
                _size--;
            }

            void remove(Entity entity) override {
                _deads.push_back(entity);
            }

            void update(void) override {
                auto dead = _deads.begin();

                while (dead != _deads.end()) {
                    del(*dead);
                    dead = _deads.erase(dead);
                }
            }

            T &add(Entity entity) {
                if (_size >= _max) resize(_size + 255); //TODO REWORK
                _map[entity] = _size;
                _reverse[_size] = entity;
                return _data[_size++];
            }

            [[nodiscard]] std::size_t getComponentId(void) override {
                return Component<T>::getId();
            }

            [[nodiscard]] const std::unordered_map<indie::Entity, std::size_t> &getEntities(void) const
            {
                return _map;
            }

            [[nodiscard]] bool has(Entity entity)
            {
                return _map[entity] != 0;
            }
        private:
            void resize(std::size_t newSize) {
                std::unique_ptr<T[]> newArray = std::make_unique<T[]>(newSize);

                for (std::size_t i = 1; i < _size; i++) newArray[i] = _data[i];
                _data = std::move(newArray);
                _max = newSize;
            }

            std::unordered_map<indie::Entity, std::size_t> _map;
            std::unordered_map<std::size_t, indie::Entity> _reverse;
            std::unique_ptr<T[]> _data;
            std::vector<indie::Entity> _deads;
            std::size_t _size;
            std::size_t _max;
    };

    class AComponentManagerFactory {
        public:
            virtual ~AComponentManagerFactory() {};

            [[nodiscard]] virtual std::unique_ptr<AComponentManager> factory() = 0;
    };

    template<typename T>
    class ComponentManagerFactory : public AComponentManagerFactory {
        public:
            ~ComponentManagerFactory() {};

            [[nodiscard]] std::unique_ptr<AComponentManager> factory() override {
                return std::make_unique<ComponentManager<T>>();
            };
    };
}

#endif /* !_COMPONENTMANAGER_HPP_ */