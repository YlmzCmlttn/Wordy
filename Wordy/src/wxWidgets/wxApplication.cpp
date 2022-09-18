#include "wxWidgets/wxApplication.h"
#include "wxWidgets/wxMainFrame.h"
bool wxApplication::OnExceptionInMainLoop(){
    try{
        throw;
    }catch(const std::exception& e){
        return showExceptionError(e) == wxOK;
    }catch(...){
        return showExceptionError() == wxOK;
    }
}
bool wxApplication::OnInit(){
    try{
        (new wxMainFrame)->Show();
    }
    catch(const std::exception& e){
        showExceptionError(e);
        return false;
    }catch(...){
        showExceptionError();
        return false;
    }
    return true;
}

int wxApplication::showExceptionError(const std::exception& e){
    return wxMessageBox(wxString::Format("Exception occurred in your application. If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n%s", e.what()), "Exception occurred", wxOK|wxCANCEL|wxICON_ERROR);
}
int wxApplication::showExceptionError() {
    return wxMessageBox("Exception occurred/ If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n(Unknown exception)", "Unknown exception occurred", wxOK|wxCANCEL|wxICON_ERROR);
}