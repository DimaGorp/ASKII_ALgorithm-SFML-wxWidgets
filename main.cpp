#include <iostream>
#include <wx/wx.h>
#include "Window.hpp"

class App:public wxApp
{
    public:
    App();
    bool OnInit() override;
    ~App();
};

wxIMPLEMENT_APP(App);

App::App(){

}
bool App::OnInit() 
{
    myWindow * window = new myWindow("IT WORKS!!!",wxPoint(100,100),wxSize(1000,750));
    
    window->Show();
    return true;
    
}

App::~App(){}
 