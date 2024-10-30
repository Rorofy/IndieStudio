/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

#include <bitset>
#include <vector>
#include <memory>
#include "ecs/Entity.hpp"
#include "ecs/ComponentMap.hpp"
#include "ecs/Component.hpp"

namespace indie
{
    class Scene;

    class ASystem {
        public:
            ASystem(Scene &scene);
            virtual ~ASystem() = default;

            virtual void init() = 0;
            virtual void update() = 0;
            virtual void render() = 0;

        public:
            template<typename T> void trackComponent() {
                _compSignature->add(Component<T>::getId());
            }

            template<typename T> void untrackComponent() {
                _compSignature->remove(Component<T>::getId());
            }

            void trackEntity(Entity id);
            void untrackEntity(Entity id);
            [[nodiscard]] AComponentMap &getSignature(void);
            void setSignature(std::unique_ptr<AComponentMap> map);

        protected:
            Scene &_scene;
            std::vector<Entity> _entityRegistry;

        private:
            std::unique_ptr<AComponentMap> _compSignature;
    };

    class ASystemFactory {
        public:
            virtual ~ASystemFactory() {};

            [[nodiscard]] virtual std::unique_ptr<ASystem> factory(Scene &scene) = 0;
    };

    template<typename T>
    class SystemFactory : public ASystemFactory {
        public:
            SystemFactory() {};
            ~SystemFactory() {};

            [[nodiscard]] std::unique_ptr<ASystem> factory(Scene &scene) override {
                return std::make_unique<T>(scene);
            };
    };
}

#endif /* !ASYSTEM_HPP_ */