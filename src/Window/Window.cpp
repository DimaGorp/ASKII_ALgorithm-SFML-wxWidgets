#include "Window.hpp"
#include "DIRS.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Window::Window(const wxString& title,const wxPoint& position,const wxSize& win_size):wxFrame(nullptr,wxID_ANY,title,position,win_size)
{
    this->position = position;
    this->win_size = win_size;
    std::cout<<win_size.GetWidth() << " " << win_size.GetHeight()<<std::endl;
    
    
    
    
    
    panel = new wxPanel(this);
    wxButton * open = new wxButton(panel,wxID_ANY,wxString("Open"),wxPoint((this->win_size.GetWidth()/2)-50,(this->win_size.GetHeight()/2)-25),wxSize(100,50));
    wxButton * convert = new wxButton(panel,wxID_ANY,wxString("Convert"),wxPoint(open->GetPosition().x,open->GetPosition().y+50),wxSize(100,50));
    wxInitAllImageHandlers();
    image = new wxStaticBitmap(panel,wxID_ANY,wxBitmap(REFS "/Window/ref/no.png",wxBITMAP_TYPE_PNG),wxPoint(this->win_size.GetWidth()/4-200,this->win_size.GetHeight()/4),wxSize(200, 500));
    
    open->Bind(wxEVT_BUTTON,&Window::onButtonOpenClick,this);
    convert->Bind(wxEVT_BUTTON,&Window::onButtonConvertClick,this);


    
    CreateStatusBar();
}

void Window::onButtonOpenClick(wxCommandEvent& ev){
    wxFileDialog openFileDialog(this, _("Open PNG file"), "", "",
                       "PNG files (*.png)|*.png", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    
    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());
    if (!input_stream.IsOk())
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }
    
    delete image;
    wxInitAllImageHandlers();
    image = new wxStaticBitmap(panel,wxID_ANY,wxBitmap(openFileDialog.GetPath(),wxBITMAP_TYPE_PNG),wxPoint(this->win_size.GetWidth()/4-200,this->win_size.GetHeight()/4),wxSize(200, 500));
    wxLogStatus(openFileDialog.GetPath());
}

void Window::onButtonConvertClick(wxCommandEvent& ev){
    wxLogStatus("Convert clicked");
}

Window::~Window(){}