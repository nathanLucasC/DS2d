#include "framework/Application.h"
#include <framework/Core.h>
#include <iostream>
#include <stdio.h>
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

            float frameDeltaTime = mTickClock.restart().asSeconds();

            accumulatedTime += frameDeltaTime;

            while(accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }

            LOG("FPS: %f", 1.f / frameDeltaTime );
        }

        std::cout << "Build Successful. Application closed." << std::endl; 

    }

    void Application::TickInternal(float deltaTime) {

        Tick(deltaTime);

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