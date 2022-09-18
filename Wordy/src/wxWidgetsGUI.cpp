#include "wxWidgetsGUI.h"
#include "wxWidgets/wxApplication.h"
bool wxWidgetsGUI::LaunchGUI(int argc, char** argv){
	wxApp* pApp = new wxApplication();
	wxApp::SetInstance(pApp);
	wxEntryStart(argc, argv);
	if(!wxTheApp->CallOnInit()){
        wxTheApp->OnExit();
        wxEntryCleanup();
        return -1;
    }
    wxTheApp->OnRun();
    
	wxTheApp->OnExit();
	wxEntryCleanup();
	return 0;
};