#include "Application.h"
int main(int argc, char **argv)   
{
    Application::CreateApplication(GUIFramework::wxWidgets);
    return Application::Get()->Run(argc,argv);
}