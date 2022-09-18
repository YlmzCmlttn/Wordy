#pragma once
#include "IGUI.h"
class QtGUI : public IGUI
{
public:
    bool LaunchGUI(int argc, char** argv)override;
};
