#pragma once
#include <wx/wx.h>
class wxApplication : public wxApp {
    bool OnExceptionInMainLoop()override;
    bool OnInit() override;
    static int showExceptionError(const std::exception& e);
    static int showExceptionError();
};