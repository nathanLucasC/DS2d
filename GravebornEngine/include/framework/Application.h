#pragma once
#include <SFML/Graphics.hpp>
#include <framework/Core.h>
#include <framework/Level.h>

namespace gb{

    class Level;

    class Application{
        public:
            Application();
            void Run();

            template<typename LevelType>
            weak<LevelType> LoadLevel();

        private:
            void TickInternal(float deltaTime);
            void RenderInternal();
            virtual void Render();
            virtual void Tick(float deltaTime);
            sf::RenderWindow mWin;
            float mTargetFramerate;
            sf::Clock mTickClock;

            shared<Level> currentLevel;
    };

    template<typename LevelType>
    weak<LevelType> Application::LoadLevel()
    {
        shared<LevelType> newLevel{new LevelType{this}};
        currentLevel = newLevel;
        currentLevel->BeginPlayInternal();
        return newLevel;
    }
}