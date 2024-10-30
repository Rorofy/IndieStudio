/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** ComponentMap
*/

#ifndef COMPONENTMAP_HPP_
#define COMPONENTMAP_HPP_

#include <bitset>
#include <memory>

namespace indie
{
    class AComponentMap {
        public:
            virtual ~AComponentMap() = default;

            virtual void add(std::size_t id) = 0;
            [[nodiscard]] virtual bool get(std::size_t id) = 0;
            virtual void remove(std::size_t id) = 0;
            virtual void clear(void) = 0;
            [[nodiscard]] virtual bool contain(AComponentMap &map) = 0;
            [[nodiscard]] virtual std::shared_ptr<AComponentMap> clone(void) = 0;

            [[nodiscard]] virtual bool oldContain(AComponentMap &old, AComponentMap &map);
            [[nodiscard]] virtual bool oldRemove(AComponentMap &old, AComponentMap &map);
    };

    template<std::size_t T>
    class ComponentMap : public AComponentMap {
        public:
            ComponentMap() = default;

            void add(std::size_t id) override {
                _map[id] = true;
            }

            [[nodiscard]] bool get(std::size_t id) override {
                return _map[id];
            }

            void remove(std::size_t id) override {
                _map[id] = false;
            }

            void clear(void) override {
                _map.reset();
            }

            [[nodiscard]] bool contain(AComponentMap &map) override {
                ComponentMap &mask = dynamic_cast<ComponentMap &>(map);

                return (mask._map & _map) == mask._map;
            }

            [[nodiscard]] std::shared_ptr<AComponentMap> clone() override {
                return std::make_shared<ComponentMap>(*this);
            }

            std::bitset<T> _map;
    };

    class AComponentMapFactory {
        public:
            virtual ~AComponentMapFactory() = default;

            virtual std::unique_ptr<AComponentMap> factory() = 0;
    };

    template<std::size_t T>
    class ComponentMapFactory : public AComponentMapFactory {
        public:
            ComponentMapFactory() = default;

            std::unique_ptr<AComponentMap> factory() override {
                return std::make_unique<ComponentMap<T>>();
            }
    };
}

#endif /* !COMPONENTMAP_HPP_ */