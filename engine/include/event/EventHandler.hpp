/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** EventHandler
*/

#ifndef EVENTHANDLER_HPP_
#define EVENTHANDLER_HPP_

#include <functional>
#include <event/IEvent.hpp>

namespace indie
{
    class AEventHandler {
        public:
            void run(IEvent &event) const
            {
                call(event);
            }

        protected:
            virtual void call(IEvent &event) const = 0;
    };

    template<class T, class EventType>
    class EventHandler : public AEventHandler {
        public:
            EventHandler(T &subscriber, std::function<void (EventType &)> func) :
                _subscriber(subscriber),
                _subFunc(func) {};

            void call(IEvent &event) const override
            {
                _subFunc(static_cast<EventType &>(event));
            }

            const T &getSubscriber(void) const
            {
                return _subscriber;
            }

        private:
            T &_subscriber;
            std::function<void (EventType &)> _subFunc;
    };
}

#endif /* !EVENTHANDLER_HPP_ */