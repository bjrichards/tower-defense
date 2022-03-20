// #define SDL_MAIN_HANDLED
#include <Engine.h>
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Starting main\n";

    Engine *engine = new Engine();

    engine->Init();
    engine->Run();
    engine->Cleanup();

    return 0;
}