#include "Scroll_Image.hpp"
#include "DIRS.h"

ScrImage::ScrImage(wxWindow *parent,wxWindowID id ,const wxPoint &pos, const wxSize &size): wxScrolled<wxWindow>(parent,id,pos,size,wxBG_STYLE_PAINT)
{ 
    wxInitAllImageHandlers();
    image.LoadFile(wxString(REFS"no.png"),wxBITMAP_TYPE_PNG);
    SetScrollRate( 10, 10 );
    SetVirtualSize( 1000, 1000 );
    this->Bind(wxEVT_PAINT,&ScrImage::onPaint,this);


}

void ScrImage::onPaint(wxPaintEvent&){
    wxPaintDC dc(this);
    PrepareDC(dc);
    dc.Clear();
    dc.DrawBitmap(image,-1,-1);
    Refresh();
}

void ScrImage::setBitmap(wxString path)
{
    image.LoadFile(path,wxBITMAP_TYPE_PNG);
    SetVirtualSize(image.GetWidth(),image.GetHeight());
    Refresh();
}
