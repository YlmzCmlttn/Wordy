#pragma once
#include <wx/wx.h>
#include <thread>
#include <mutex>
#include "WordCounter.h"
#include "WordCounterBuilder.h"
#include "WordCounterSettingsBuilder.h"
#include "WordCounterInputBuilder.h"
class wxMainFrame : public wxFrame
{
private:    
    std::thread wordCounterThread;
    WordCounterPtr wordCounter;
    std::mutex mtx;
public:
    wxMainFrame();
};