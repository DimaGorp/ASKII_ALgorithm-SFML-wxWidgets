#include "Settings.hpp"

Settings_Window::Settings_Window(const wxString& title,const wxPoint& position,const wxSize& dialog_size):wxDialog(nullptr,wxID_ANY,title,position,dialog_size,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER )
{

    this->position = position;
    this->dialog_size = dialog_size;
    std::cout<<"Settings size: "<<dialog_size.GetWidth() << " " << dialog_size.GetHeight()<<std::endl;
    this->Centre();
    
    Ok = new wxButton(this,wxID_OK,wxString("Ok"));
    Cancel = new wxButton(this,wxID_CANCEL,wxString("Cancel"));

    doted = new wxStaticText(this,wxID_ANY,wxString("Show Dotted Algorithm: "),wxDefaultPosition,wxDefaultSize,wxTE_READONLY);
    

    dot_state = new wxCheckBox(this,wxID_ANY,wxString("false"));
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer_elements = new wxBoxSizer(wxHORIZONTAL);
    
    wxBoxSizer * left = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer * right = new wxBoxSizer(wxVERTICAL);
    
    wxBoxSizer * bottom = new wxBoxSizer(wxHORIZONTAL);
    left->Add(doted);
    
    
    right->Add(dot_state);
    
    bottom->Add(Cancel,0,wxEXPAND | wxRIGHT);
    bottom->Add(Ok,0,wxEXPAND | wxLEFT,325);
    sizer_elements->Add(left,1,wxEXPAND | wxALL,10);
    sizer_elements->Add(right,0,wxEXPAND | wxALL,10);
    sizer->Add(sizer_elements,1,wxEXPAND | wxALL,10);
    sizer->Add(bottom,0,wxEXPAND | wxALL ,10);
    this->SetSizer(sizer);
    //Connect(wxID_ANY, wxEVT_CLOSE_WINDOW, wxCloseEventHandler(Settings_Window::onClose));
}
Settings_Window::~Settings_Window(){

}

void Settings_Window::onClose(wxCloseEvent& evt){
    Destroy();
}