#pragma once
#include <any>
#include <wx/wx.h>
class CustomEvent;
wxDECLARE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);

class CustomEvent : public wxCommandEvent {
public:
    CustomEvent(wxEventType commandType = WX_EVT_CUSTOM_EVENT, int id = 0);
    CustomEvent(const CustomEvent& event);
    CustomEvent(CustomEvent&& event);

    std::any getValue()const;
    void setValue(const std::any& value);
private:
    std::any mValue;
};
