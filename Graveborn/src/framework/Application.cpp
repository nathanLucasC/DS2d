#include "framework/Application.h"
#include <iostream>
#include <memory>

namespace gb{

    Application::Application() : mWin{sf::VideoMode(800, 600), "Win"}, mTargetFramerate{60.f}, mTickClock{} {
        
    }

    void Application::Run(){

        mTickClock.restart();

        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f / mTargetFramerate;

        while (mWin.isOpen()) {
            sf::Event winEvent;
            while (mWin.pollEvent(winEvent)) {
                if (winEvent.type == sf::Event::EventType::Closed) {
                mWin.close();
                }
            }

            accumulatedTime += mTickClock.restart().asSeconds();

            while(accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }

        std::cout << "Build Successful. Application closed." << std::endl; 

    }

    void Application::TickInternal(float deltaTime) {

        Tick(deltaTime);
        std::cout << "Framerate: " << 1.f / deltaTime << std::endl;
    }

    void Application::RenderInternal() {

        mWin.clear();

        Render();
        
        mWin.display();
        
    }

    void Application::Render() {

        
    }

    void Application::Tick(float deltaTime) {


    }
}