#include "Application.h"
#include "wxWidgetsGUI.h"
#include "QtGUI.h"
std::unique_ptr<Application> Application::sInstance=NULL;
Application::Application(const GUIFramework& guiFramework){
    if(guiFramework == GUIFramework::QT)
        mGUI = std::unique_ptr<QtGUI>(new QtGUI());
    else
        mGUI = std::unique_ptr<wxWidgetsGUI>(new wxWidgetsGUI());
}
void Application::CreateApplication(const GUIFramework& guiFramework)
{
    sInstance = std::unique_ptr<Application>(new Application(guiFramework));
}

const std::unique_ptr<Application>& Application::Get(){
    return sInstance;
}

bool Application::Run(int argc, char** argv){
    return mGUI->LaunchGUI(argc,argv);
}