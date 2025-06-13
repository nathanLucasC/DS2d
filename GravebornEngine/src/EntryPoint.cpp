#include "EntryPoint.h"
#include "framework/Application.h"

int main() {

    gb::Application* app = GetApplication();
    app->Run();
    delete app;
}