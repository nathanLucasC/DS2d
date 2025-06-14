#include "gameFramework/GameApplication.h"
#include "framework/Level.h"

gb::Application* GetApplication() {

    return new gb::GameApplication{};

}

namespace gb 
{
    GameApplication::GameApplication()
    {
        LoadLevel<Level>();
    }
}