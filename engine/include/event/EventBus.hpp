/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** EventBus
*/

#ifndef EVENTBUS_HPP_
#define EVENTBUS_HPP_

#include <memory>
#include <unordered_map>
#include <typeinfo>
#include <typeindex>
#include <vector>
#include "event/EventHandler.hpp"
#include "irrlicht/event/KeyInput.hpp"
#include "irrlicht.h"

namespace indie
{
    typedef std::vector<std::unique_ptr<AEventHandler>> handlerVector;
    typedef std::unique_ptr<handlerVector> handler;

    class EventBus {
        public:
            template<typename EventType>
            void publish(std::unique_ptr<EventType> event) const
            {
                publish(*event);
            }

            template<typename EventType>
            void publish(EventType &event) const
            {
                try {
                    const handler &handlers = _subscribers.at(typeid(EventType));

                    if (handlers == nullptr) return;
                    for (auto &handler : *handlers)
                        handler->run(event);
                } catch (const std::out_of_range &exception) {};
            }

            template<class T, class EventType>
            void subscribe(T &subscriber, std::function<void (EventType &)> func)
            {
                handler &handlers = _subscribers[typeid(EventType)];
                auto handler = std::make_unique<EventHandler<T, EventType>>(subscriber, func);

                if (handlers == nullptr) {
                    _subscribers[typeid(EventType)] = std::make_unique<handlerVector>();
                    _subscribers[typeid(EventType)]->push_back(std::move(handler));
                }
                else
                    handlers->push_back(std::move(handler));
            }

            template<class T, class EventType>
            void unsubscribe(T &subscriber)
            {
                auto handlers = static_cast<std::unique_ptr<
                    std::vector<std::unique_ptr<EventHandler<T, EventType>>>>>
                    (_subscribers[typeid(EventType)]);

                if (handlers == nullptr) return;
                for (auto const &handler : *handlers)
                    handler->getSubscriber();
                    
            }

        private:
            std::unordered_map<std::type_index, handler> _subscribers;
    };
}

#endif /* !EVENTBUS_HPP_ */