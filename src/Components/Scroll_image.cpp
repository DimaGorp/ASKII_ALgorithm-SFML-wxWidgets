#include "Scroll_Image.hpp"
#include "DIRS.h"

ScrImage::ScrImage(wxPoint2DDouble virtualSize,wxWindow *parent,wxWindowID id ,const wxPoint &pos, const wxSize &size): wxScrolled<wxWindow>(parent,id,pos,size,wxBG_STYLE_PAINT)
{ 
    wxInitAllImageHandlers();
    image.LoadFile(wxString(REFS"no.png"),wxBITMAP_TYPE_PNG);
    virSize = virtualSize;
    SetScrollRate( 10, 10 );
    SetVirtualSize(image.GetWidth()*10, image.GetHeight()*10);
    factor = 1.0f;
    Bind(wxEVT_PAINT,&ScrImage::onPaint,this);
    Bind(wxEVT_MOUSEWHEEL,&ScrImage::onZoom,this);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}


void ScrImage::setBitmap(wxString path)
{
    image.LoadFile(path,wxBITMAP_TYPE_PNG);
    factor =1.0f;
    Refresh();
}

void ScrImage::onPaint(wxPaintEvent& event){
    wxAutoBufferedPaintDC  paintdc(this);
    paintdc.Clear();
    wxGCDC dc(paintdc);
    dc.SetUserScale(factor, factor);
    dc.DrawBitmap(image,0,0);
}



void ScrImage::onZoom(wxMouseEvent& event){
    if (event.GetWheelRotation() > 0 && (image.GetWidth() * factor <image.GetWidth()*10 && image.GetHeight() * factor < image.GetHeight()*10)){
        factor+=0.1f;
    }
    else if(event.GetWheelRotation() < 0 && (image.GetWidth() * factor >=image.GetWidth()/10 && image.GetHeight() * factor >= image.GetHeight()/10) && factor>0.1f){
        factor -=  0.1f;
    }
    Refresh();
}

