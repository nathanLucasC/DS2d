#pragma once
#include <SFML/Graphics.hpp>

namespace gb{

    class Application{
        public:
            Application();
            void Run();
        private:
            void TickInternal(float deltaTime);
            void RenderInternal();
            virtual void Render();
            virtual void Tick(float deltaTime);
            sf::RenderWindow mWin;
            float mTargetFramerate;
            sf::Clock mTickClock;
    };
}