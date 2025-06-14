#include "framework/Level.h"
#include "framework/Core.h"

namespace gb
{
    Level::Level(Application *owningApp)
        : mOwningApp{owningApp},
          mBeganPlay{false}
    {
    }

    void Level::BeginPlayInternal()
    {
        if (!mBeganPlay)
        {
            mBeganPlay = true;
            BeginPlay();
        }
    }

    void Level::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
    }

    Level::~Level()
    {
    }

    void Level::BeginPlay()
    {
        LOG("BeginPlay()");
    }

    void Level::Tick(float deltaTime)
    {
        LOG("Tick(%f)", 1.f / deltaTime);
    }
}