#include "Application.hpp"

int main()
{
    Application app;
    
    while (app.IsRunning())
    {
        app.ProcessEvent();
        app.Update();
        app.Render();
    }
    return 0;
}