#include "framework/Application.h"
#include <iostream>
#include <memory>

namespace ly{

    Application::Application() : mWin{sf::VideoMode(800, 600), "Win"} {
        
    }

    void Application::Run(){

        while (mWin.isOpen()) {
            sf::Event winEvent;
            while (mWin.pollEvent(winEvent)) {
                if (winEvent.type == sf::Event::EventType::Closed) {
                mWin.close();
                }
            }
        }
        std::cout << "Build Successful. Application closed." << std::endl; 
    }
}