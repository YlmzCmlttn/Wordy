#include <wx/wx.h>
#include "wxWidgets/wxCustomEvent.h"
CustomEvent::CustomEvent(wxEventType commandType, int id) : wxCommandEvent(commandType, id) { 

}
CustomEvent::CustomEvent(const CustomEvent& event) : wxCommandEvent(event), mValue(event.mValue) {

}

CustomEvent::CustomEvent(CustomEvent&& event) : wxCommandEvent(std::move(event)), mValue(std::move(event.mValue)) {

}

std::any CustomEvent::getValue()const{
    return mValue;
}
void CustomEvent::setValue(const std::any& value){
    mValue = value;
}
wxDEFINE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);