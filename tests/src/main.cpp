#include <iostream>
#include "help.h"
#ifdef USE_MATH
    #include "math.hpp"
#endif

#include <wx/wx.h>


class App:public wxApp
{
    public:
        App();
        virtual bool OnInit();
        ~App();
};





class Window:public wxFrame
{
    public:
    Window(const wxString &label,const wxPoint& position,const wxSize& win_size):wxFrame(nullptr,wxID_ANY,label,position,win_size)
    {
        this->Center();

    }
    ~Window(){}
};

wxIMPLEMENT_APP(App);
App::App(){

}

bool App::OnInit(){
    Window * window = new Window(wxString("testing wxWidjets build"),wxPoint(500,500),wxSize(1000,500));
    window->Show(true);
    return true;
}

App::~App(){

}
