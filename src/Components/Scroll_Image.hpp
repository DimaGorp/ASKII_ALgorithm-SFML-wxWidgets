#pragma once
#include <iostream>
#include <wx/wx.h>
#include <wx/wrapsizer.h>
class ScrImage : public wxScrolled<wxWindow>
{
    wxBitmap image;
    void onPaint(wxPaintEvent&);
    //void onKey(wxCommandEvent);
public:
    ScrImage(wxWindow *parent = nullptr,wxWindowID id = wxID_ANY,const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize);
    void setBitmap(wxString path);
};