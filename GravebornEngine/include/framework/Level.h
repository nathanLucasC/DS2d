#pragma once

namespace gb
{
    class Application;
    class Level
    {
    public:
        Level(Application* owningApp);

        void BeginPlayInternal();
        void TickInternal(float deltaTime);

        virtual ~Level();

    private:
        void BeginPlay();
        void Tick(float deltaTime);
        Application *mOwningApp;
        bool mBeganPlay;
    };
}