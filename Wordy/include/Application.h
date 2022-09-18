#pragma once
#include <memory>
#include "IGUI.h"
enum class GUIFramework{
    wxWidgets,
    QT
};
class Application{
private:
    Application(const GUIFramework& guiFramework);
    static std::unique_ptr<Application> sInstance;
    std::unique_ptr<IGUI> mGUI;
public:
    static const std::unique_ptr<Application>& Get();
    static void CreateApplication(const GUIFramework& guiFramework);
    bool Run(int argc, char** argv);
};