#include <iostream>
#include "SFML/ASKII.hpp"
#include "help.h"

#ifdef USE_MATH
    //#include "math.hpp"
#endif

#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include "wx/xrc/xmlres.h"

class App:public wxApp
{
    public:
        App();
        virtual bool OnInit();
        ~App();
};

wxIMPLEMENT_APP(App);



class Window:public wxFrame
{
    
    wxPanel * panel;
    wxTextCtrl * result;
    wxFileDialog * openFileDialog;
    askii::ASKII_ALGORITHM *askii;  
    wxSize win_size;

    public:

    Window(const wxString &label,const wxPoint& position,const wxSize& win_size):wxFrame(nullptr,wxID_ANY,label,position,win_size)
    {
        
        this->win_size = win_size;
        this->Center();
            
        wxBoxSizer * main_sizer = new wxBoxSizer(wxHORIZONTAL);
        wxBoxSizer * centre = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer * right = new wxBoxSizer(wxVERTICAL);

    // this = new wxPanel(this);
        wxButton * open = new wxButton(this,wxID_ANY,wxString("Open"),wxPoint((this->win_size.GetWidth()/2)-50,(this->win_size.GetHeight()/2)-25),wxSize(100,50));
        wxButton * convert = new wxButton(this,wxID_ANY,wxString("Convert"),wxPoint(open->GetPosition().x,open->GetPosition().y+50),wxSize(100,50));

        result = new wxTextCtrl(this,wxID_ANY,wxString("Nothing added yet.."),wxPoint(this->win_size.GetWidth()/2+100,50),wxSize(400,600),  wxTE_MULTILINE |wxTE_READONLY | wxHSCROLL);
        right->Add(result,0,wxEXPAND | wxTOP,20);
        
        wxFont  font =  wxFont(wxSize(16, 16), wxFontFamily::wxFONTFAMILY_TELETYPE, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL);//Monospace font
        result->SetFont(font);
    
        open->Bind(wxEVT_BUTTON,&Window::onButtonOpenClick,this);
        centre->Add(open,1,wxEXPAND | wxTOP,300);
        centre->Add(convert,1,wxEXPAND | wxBOTTOM,300);
        main_sizer->Add(centre,1,wxEXPAND | wxALL,5);
        main_sizer->Add(right,0,wxEXPAND | wxALL,5);
        this->SetSizer(main_sizer);
        CreateStatusBar();
    }
    ~Window(){}
    void onButtonOpenClick(wxCommandEvent& ev){
        openFileDialog = new wxFileDialog(this, _("Open PNG file"), "", "",
                        "PNG files (*.png)|*.png", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
        if (openFileDialog->ShowModal() == wxID_CANCEL)
            return;     // the user changed idea...
        
        // proceed loading the file chosen by the user;
        // this can be done with e.g. wxWidgets input streams:
        wxFileInputStream input_stream(openFileDialog->GetPath());
        if (!input_stream.IsOk())
        {
            wxLogError("Cannot open file '%s'.", openFileDialog->GetPath());
            return;
        }
        result->Clear();
        std::ifstream myfile;
        myfile.open(file_T"/index.txt");
        if(myfile.is_open()){
            std::cout<<"file opened sucessfuly\n";
        }else{
            return;
        }
        std::string row;
        askii = new askii::ASKII_ALGORITHM(openFileDialog->GetPath().ToStdString());

        askii->convert_to_aski();
        while (getline (myfile, row))
        {
            
            
            *result<<row<<'\n';
        }
        myfile.close();
        delete askii;
        wxLogStatus(openFileDialog->GetPath());
    }
};


App::App(){

}

bool App::OnInit(){
    Window * window = new Window(wxString("testing wxWidjets build"),wxPoint(500,500),wxSize(1000,500));
    window->Show();
    return true;
}

App::~App(){

}
