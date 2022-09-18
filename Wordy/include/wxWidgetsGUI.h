#pragma once
#include "IGUI.h"
class wxWidgetsGUI : public IGUI
{
public:
    bool LaunchGUI(int argc, char** argv)override;
};
