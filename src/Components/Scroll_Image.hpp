#pragma once
#include <iostream>
#include <wx/wx.h>

#define ZOOM_IN_MAX 100.0f
#define ZOOM_OUT_MAX 1.0f
class ScrImage : public wxScrolled<wxWindow>
{
    wxBitmap image;
    double factor;
    wxPoint2DDouble virSize;
    void onPaint(wxPaintEvent& event);
    void onZoom(wxMouseEvent& event);
public:
    ScrImage(wxPoint2DDouble virtualSize = wxPoint2DDouble(1000.0f,1000.0f),wxWindow *parent = nullptr,wxWindowID id = wxID_ANY,const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize);
    void setBitmap(wxString path);
};