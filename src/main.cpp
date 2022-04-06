#include <iostream>

#include "App.hpp"

class MyApp : public Graphics::App
{
    virtual void onUpdate() override
    {

    }
};

int main()
{
    auto myApp = std::make_unique<MyApp>();

    int returnCode = myApp->start(1024, 768, "Test App");
    return returnCode;
}