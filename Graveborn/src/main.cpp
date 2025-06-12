#include <iostream>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"
#include <memory>

int main() {

    std::unique_ptr<gb::Application> app{new gb::Application()};
    app->Run();
    
    
}