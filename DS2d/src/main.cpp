#include <iostream>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"
#include <memory>

int main() {

    std::unique_ptr<ly::Application> app{new ly::Application()};
    app->Run();
    
}