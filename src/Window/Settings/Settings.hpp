
#pragma once
#include <iostream>
#include <wx/wx.h>

class Settings_Window: public wxDialog
{
    wxPanel * panel;
    wxSize dialog_size;
    wxPoint position;

    wxButton * Ok;
    wxButton * Cancel;
    wxStaticText * doted;

    wxCheckBox * dot_state;
    public:
    Settings_Window(const wxString& title = "no",const wxPoint& pos = wxDefaultPosition, const wxSize& size= wxDefaultSize);

    ~Settings_Window();
    private:
    void onClose(wxCloseEvent& evt);
};