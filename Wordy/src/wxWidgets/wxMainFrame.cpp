#include "wxWidgets/wxMainFrame.h"
#include "Config.h"
#include "wxWidgets/wxCustomEvent.h"
#include <iomanip>
const int NUMBER_UPDATE_ID = 100000;
wxMainFrame::wxMainFrame():wxFrame{nullptr,wxID_ANY,"Wordy"}
{   
    this->SetMinSize(wxSize(1024,600));
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    wxStatusBar* statusBar = new wxStatusBar(this);
    
    statusBar->SetStatusText("Ready");
    SetStatusBar(statusBar);

    wxBoxSizer *panel_VB = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *keywords_HB = new wxBoxSizer(wxHORIZONTAL);    
    wxStaticText *keywords_Label =  new wxStaticText(panel, wxID_ANY, 
        wxT("Keywords (etc: :),:-),:-D)"));
        
    wxTextCtrl *keywords_InputText = new wxTextCtrl(panel, wxID_ANY);
    keywords_InputText->WriteText(":),:-),:-D");
    keywords_HB->Add(keywords_Label, 0, wxRIGHT | wxCENTER, 10);
    keywords_HB->Add(keywords_InputText, 1);

    panel_VB->Add(keywords_HB, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    panel_VB->Add(-1, 10);

    wxBoxSizer *inputSelection_HB = new wxBoxSizer(wxHORIZONTAL);
    wxCheckBox *fileInput_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("File Input"));

    wxButton *fileInput_PB = new wxButton(panel, wxID_ANY, wxT("Open"));
    wxStaticText* fileName_L = new wxStaticText(panel, wxID_ANY, "File: (Not Selected)", {10, 40});

    inputSelection_HB->Add(fileInput_CB, 0, wxRIGHT | wxCENTER, 10);
    inputSelection_HB->Add(fileInput_PB, 1,wxRIGHT | wxCENTER,10);
    inputSelection_HB->Add(fileName_L, 2,wxRIGHT | wxCENTER,10);

    panel_VB->Add(inputSelection_HB, 0, wxLEFT | wxTOP, 10);
    panel_VB->Add(-1, 10);

    fileInput_CB->SetValue(true);
    Config::setInputType(WordCounter::InputType::FILE);
    

    wxBoxSizer *textInput_HB = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *textInput_L = new wxStaticText(panel, wxID_ANY, 
        wxT("Text Input"));

    textInput_HB->Add(textInput_L, 0);

    panel_VB->Add(textInput_HB, 0, wxLEFT | wxTOP, 10);
    panel_VB->Add(-1, 10);

    wxBoxSizer *textInputField_HB = new wxBoxSizer(wxHORIZONTAL);
    wxTextCtrl *textInput_TextField = new wxTextCtrl(panel, wxID_ANY, wxT(""), 
        wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);


    textInput_TextField->WriteText("Disabled! File Input selected.");
    textInput_TextField->Disable();

    textInputField_HB->Add(textInput_TextField, 1, wxEXPAND);
    panel_VB->Add(textInputField_HB, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);
    panel_VB->Add(-1, 1);


    wxBoxSizer *delimiter_HL = new wxBoxSizer(wxHORIZONTAL);
    wxCheckBox *newLine_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("Use new line as a delimiter"));
    wxTextCtrl *delimiter_InputText = new wxTextCtrl(panel, wxID_ANY);


    delimiter_HL->Add(newLine_CB, 0, wxRIGHT | wxCENTER, 10);
    delimiter_HL->Add(delimiter_InputText, 1);
    panel_VB->Add(delimiter_HL, 0, wxLEFT | wxTOP, 10);
    panel_VB->Add(-1, 10);

    wxBoxSizer *filters_HB = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *filters_L = new wxStaticText(panel, wxID_ANY, 
        wxT("Filters"));

    filters_HB->Add(filters_L, 0);
    panel_VB->Add(filters_HB, 0, wxLEFT | wxTOP, 10);
    panel_VB->Add(-1, 10);
    

    wxBoxSizer *filters_CB_HL = new wxBoxSizer(wxHORIZONTAL);
    wxCheckBox *all_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("All"));
    wxCheckBox *alpha_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("Alphabetic"));
    wxCheckBox *numeric_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("Numeric"));
    wxCheckBox *lowerCase_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("Lower-Case"));
    wxCheckBox *upperCase_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("Upper-Case"));
    wxCheckBox *space_CB = new wxCheckBox(panel, wxID_ANY, 
        wxT("Space"));

    filters_CB_HL->Add(all_CB);
    filters_CB_HL->Add(alpha_CB, 0, wxLEFT, 10);
    filters_CB_HL->Add(numeric_CB, 0, wxLEFT, 10);
    filters_CB_HL->Add(lowerCase_CB, 0, wxLEFT, 10);
    filters_CB_HL->Add(upperCase_CB, 0, wxLEFT, 10);
    filters_CB_HL->Add(space_CB, 0, wxLEFT, 10);

    panel_VB->Add(filters_CB_HL, 0, wxLEFT, 10);
    panel_VB->Add(-1, 25);

    Config::setFilterType(Config::filterType | FilterType::ALL | FilterType::ALPHA | FilterType::NUMERIC | FilterType::LOWERCASE | FilterType::UPPERCASE | FilterType::SPACE);
    all_CB->Set3StateValue(wxCHK_CHECKED);
    alpha_CB->Set3StateValue(wxCHK_CHECKED);
    numeric_CB->Set3StateValue(wxCHK_CHECKED);
    lowerCase_CB->Set3StateValue(wxCHK_CHECKED);
    upperCase_CB->Set3StateValue(wxCHK_CHECKED);
    space_CB->Set3StateValue(wxCHK_CHECKED);


    wxBoxSizer *operation_HL = new wxBoxSizer(wxHORIZONTAL);
    wxButton *start_PB = new wxButton(panel, wxID_ANY, wxT("Start"));
    wxGauge* progressBar = new wxGauge(panel,wxID_ANY,100);

    operation_HL->Add(progressBar, 100,wxLEFT | wxRIGHT | wxEXPAND | wxTop , 10);
    operation_HL->Add(start_PB, 1,wxLEFT , 10);
    panel_VB->Add(operation_HL, 0, wxALIGN_RIGHT | wxRIGHT, 10);

    panel->SetSizerAndFit(panel_VB);


    

    

    Centre();
    
    Bind(WX_EVT_CUSTOM_EVENT,[=](CustomEvent& event){
        if(std::any_cast<bool>(event.getValue()))
            start_PB->Enable();            
        else
            start_PB->Disable();
    },0);
    
    
    
    fileInput_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(fileInput_CB->Get3StateValue()==wxCHK_CHECKED){
            fileInput_PB->Enable();
            textInput_TextField->Clear();
            textInput_TextField->WriteText("Disabled! File Input selected.");
            textInput_TextField->Disable();
            Config::setInputType(WordCounter::InputType::FILE);
            Config::setInput("");
        }else{
            fileInput_PB->Disable();
            textInput_TextField->Enable();
            fileName_L->SetLabelText("File: (Not Selected)");
            textInput_TextField->Clear();
            Config::setInputType(WordCounter::InputType::TEXT);
            Config::setInput("");
        }
    });

    newLine_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(newLine_CB->Get3StateValue()==wxCHK_CHECKED){
            delimiter_InputText->Disable();
        }else{
            delimiter_InputText->Enable();
        }
    });
    
    
    all_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(all_CB->Get3StateValue()==wxCHK_CHECKED){
            Config::setFilterType(Config::filterType | FilterType::ALL | FilterType::ALPHA | FilterType::NUMERIC | FilterType::LOWERCASE | FilterType::UPPERCASE | FilterType::SPACE);
            alpha_CB->Set3StateValue(wxCHK_CHECKED);
            numeric_CB->Set3StateValue(wxCHK_CHECKED);
            lowerCase_CB->Set3StateValue(wxCHK_CHECKED);
            upperCase_CB->Set3StateValue(wxCHK_CHECKED);
            space_CB->Set3StateValue(wxCHK_CHECKED);
        }else{
            Config::setFilterType(Config::filterType ^ FilterType::ALL);
        }
    });
    alpha_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){        
        if(alpha_CB->Get3StateValue()==wxCHK_CHECKED){
            Config::setFilterType(Config::filterType | FilterType::ALPHA);
        }else{
            if(all_CB->Get3StateValue()==wxCHK_CHECKED){
                Config::setFilterType(Config::filterType ^ FilterType::ALL);
                all_CB->Set3StateValue(wxCHK_UNCHECKED);
            }            
            Config::setFilterType(Config::filterType ^ FilterType::ALPHA);
        }
    });
    numeric_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(numeric_CB->Get3StateValue()==wxCHK_CHECKED){
            Config::setFilterType(Config::filterType | FilterType::NUMERIC);
        }else{
            if(all_CB->Get3StateValue()==wxCHK_CHECKED){
                Config::setFilterType(Config::filterType ^ FilterType::ALL);
                all_CB->Set3StateValue(wxCHK_UNCHECKED);
            }
            Config::setFilterType(Config::filterType ^ FilterType::NUMERIC);
        }
    });
    lowerCase_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(lowerCase_CB->Get3StateValue()==wxCHK_CHECKED){
            Config::setFilterType(Config::filterType | FilterType::LOWERCASE);
        }else{
            if(all_CB->Get3StateValue()==wxCHK_CHECKED){
                Config::setFilterType(Config::filterType ^ FilterType::ALL);
                all_CB->Set3StateValue(wxCHK_UNCHECKED);
            }
            Config::setFilterType(Config::filterType ^ FilterType::LOWERCASE);
        }
    });
    upperCase_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(upperCase_CB->Get3StateValue()==wxCHK_CHECKED){
            Config::setFilterType(Config::filterType | FilterType::UPPERCASE);
        }else{
            if(all_CB->Get3StateValue()==wxCHK_CHECKED){
                Config::setFilterType(Config::filterType ^ FilterType::ALL);
                all_CB->Set3StateValue(wxCHK_UNCHECKED);
            }
            Config::setFilterType(Config::filterType ^ FilterType::UPPERCASE);
        }
    });
    space_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(space_CB->Get3StateValue()==wxCHK_CHECKED){
            Config::setFilterType(Config::filterType | FilterType::SPACE);
        }else{
            if(all_CB->Get3StateValue()==wxCHK_CHECKED){
                Config::setFilterType(Config::filterType ^ FilterType::ALL);
                all_CB->Set3StateValue(wxCHK_UNCHECKED);
            }
            Config::setFilterType(Config::filterType ^ FilterType::SPACE);
        }
    });
    
    newLine_CB->Bind(wxEVT_CHECKBOX,[=]([[maybe_unused]] wxCommandEvent& event){
        if(newLine_CB->Get3StateValue()==wxCHK_CHECKED){
            delimiter_InputText->Clear();
            delimiter_InputText->Disable();
            delimiter_InputText->WriteText("Disabled!");
        }else{
            delimiter_InputText->Clear();
            delimiter_InputText->Enable();
        }
    });
    
        
    fileInput_PB->Bind(wxEVT_BUTTON,[=]([[maybe_unused]] wxCommandEvent& event){
        wxFileDialog openFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
        openFileDialog.SetFilterIndex(0);
        if (openFileDialog.ShowModal() == wxID_OK) {
            fileName_L->SetLabelText(wxString::Format("File: %s",  openFileDialog.GetPath()));
            Config::setInput(openFileDialog.GetPath().ToStdString());
        }
    });
    start_PB->Bind(wxEVT_BUTTON,[=]([[maybe_unused]] wxCommandEvent& event){
        if(newLine_CB->Get3StateValue()==wxCHK_CHECKED){
            Config::setDelimiter(std::nullopt);
        }else{
            const auto delimiter = delimiter_InputText->GetValue().ToStdString();
            if(delimiter.size()==1){
                Config::setDelimiter(delimiter[0]);
            }else{
                throw std::invalid_argument("Length of delimiter must be 1");
            }
        }
        if(Config::inputType == WordCounter::InputType::FILE && Config::input.empty()){
            throw std::invalid_argument("Input file not selected");
        }
        if(Config::inputType == WordCounter::InputType::TEXT){
            const auto inputText =  textInput_TextField->GetValue().ToStdString();
            if(inputText.empty()){
                throw std::invalid_argument("Input text is empty");
            }else{
                Config::setInput(inputText);
            }
        }
        auto keywords = keywords_InputText->GetValue().ToStdString();
        if(keywords.empty()){
            throw std::invalid_argument("Keywords input-field is empty");
        }else{
            size_t pos = 0;
            std::string token;
            std::vector<std::string> search;
            std::string delimiter = ",";
            while ((pos = keywords.find(delimiter)) != std::string::npos) {
                token = keywords.substr(0, pos);
                search.push_back(token);
                keywords.erase(0, pos + delimiter.length());
            }
            search.push_back(keywords);
            Config::setSearch(search);
        }        
        wordCounterThread = std::thread([this](){
            {
                std::unique_lock<std::mutex> lck(mtx);
                wordCounter = WordCounter::create()
                                                .input()
                                                    .input(Config::input, Config::inputType)
                                                .settings()
                                                    .search(Config::search)
                                                    .filter(Config::filterType)
                                                    .delimiter(Config::delimiter);
                

                {
                    auto event = new CustomEvent(WX_EVT_CUSTOM_EVENT, 0);
                    event->setValue(std::make_any<bool>(false));
                    wxQueueEvent(this, event);
                }
            }
            wordCounter->detect();
            {
                auto event = new CustomEvent(WX_EVT_CUSTOM_EVENT, 0);
                event->setValue(std::make_any<bool>(true));
                wxQueueEvent(this, event);
            }
            
        });
        

        std::thread wordCounterProgressThread = std::thread([this](){
            {
            std::unique_lock<std::mutex> lck(mtx);
            }
            while(true){
                const double progress = wordCounter->getStatus();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                {
                    auto event = new CustomEvent(WX_EVT_CUSTOM_EVENT, 1);
                    event->setValue(std::make_any<double>(progress));
                    wxQueueEvent(this, event);
                }
                if(progress == 1.0){
                    if(wordCounterThread.joinable()){
                        wordCounterThread.join();
                        break;
                    }
                }
            }
            {
                auto event = new CustomEvent(WX_EVT_CUSTOM_EVENT, 2);
                event->setValue(std::make_any<bool>(true));
                wxQueueEvent(this, event);
            }
        });
        wordCounterProgressThread.detach();
    });

    Bind(WX_EVT_CUSTOM_EVENT,[=](CustomEvent& event){
        const double ret = std::any_cast<double>(event.getValue());
        statusBar->SetStatusText("Running : %"+wxString::FromDouble(ret*100.0));
        progressBar->SetValue(ret*100.0);
    },1);

    Bind(WX_EVT_CUSTOM_EVENT,[=](CustomEvent& event){        
        start_PB->Enable();
        if(std::any_cast<bool>(event.getValue())){
            statusBar->SetStatusText("Done");
            progressBar->SetValue(100);
            const auto& searched = wordCounter->getSearched();
            const auto& topten = wordCounter->getTopTen();
            std::stringstream ss;
            ss<<"Search Completed!\n";
            ss<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
            ss<<"\n";
            if(searched.empty()){
                ss<<"Does not contain any keywords\n";
            }else{
                ss<<"Keywords Found:\n";
                for(const auto&s : searched)
                    ss<<s.second<<" times "<<std::quoted(s.first)<<" found\n";
            }
            ss<<"\n";
            if(topten.empty()){
                ss<<"Does not contain any words\n";
            }else{
                ss<<"Top "<<topten.size()<<" Words: \n";
                for(const auto&s : topten)
                    ss<<std::quoted(s.first)<<" used "<<s.second<<" times\n";
            }
            wxMessageBox(wxString{ss.str()},"Search Completed", wxICON_INFORMATION|wxOK);
            
        }
    },2);
}