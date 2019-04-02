/***************************************************************
 * Name:      Version1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Version1Main.h"
#include <wx/msgdlg.h>
#include <stdio.h>
#include <stdlib.h>

//(*InternalHeaders(Version1Frame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Version1Frame)
const long Version1Frame::ID_PANEL1 = wxNewId();
const long Version1Frame::ID_SLIDER1 = wxNewId();
const long Version1Frame::ID_TEXTCTRL1 = wxNewId();
const long Version1Frame::ID_SLIDER2 = wxNewId();
const long Version1Frame::ID_TEXTCTRL2 = wxNewId();
const long Version1Frame::ID_BUTTON2 = wxNewId();
const long Version1Frame::ID_STATICTEXT1 = wxNewId();
const long Version1Frame::ID_STATICTEXT2 = wxNewId();
const long Version1Frame::ID_STATICTEXT3 = wxNewId();
const long Version1Frame::ID_TEXTCTRL3 = wxNewId();
const long Version1Frame::ID_SLIDER3 = wxNewId();
const long Version1Frame::ID_PANEL2 = wxNewId();
const long Version1Frame::ID_PANEL3 = wxNewId();
const long Version1Frame::ID_BUTTON1 = wxNewId();
const long Version1Frame::idMenuQuit = wxNewId();
const long Version1Frame::idMenuAbout = wxNewId();
const long Version1Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Version1Frame,wxFrame)
    //(*EventTable(Version1Frame)
       EVT_TIMER(wxID_ANY, Version1Frame::OnTimer)
    //*)
END_EVENT_TABLE()

Version1Frame::Version1Frame(wxWindow* parent,wxWindowID id):m_timer(this)
{
    //(*Initialize(Version1Frame)
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(550,450));
    FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(1);
    FlexGridSizer1->AddGrowableRow(0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(300,300), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMaxSize(wxSize(260,260));
    FlexGridSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxSize(200,40), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Slider1 = new wxSlider(Panel2, ID_SLIDER1, 1, 1, 10, wxPoint(8,88), wxSize(79,27), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, _("1"), wxPoint(96,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    Slider2 = new wxSlider(Panel2, ID_SLIDER2, 1, 1, 10, wxPoint(8,152), wxSize(79,27), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    TextCtrl2 = new wxTextCtrl(Panel2, ID_TEXTCTRL2, _("1"), wxPoint(96,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    wxFont TextCtrl2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl2->SetFont(TextCtrl2Font);
    Button2 = new wxButton(Panel2, ID_BUTTON2, _("Stop"), wxPoint(48,248), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Initial Population"), wxPoint(88,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Columns"), wxPoint(112,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Rows"), wxPoint(120,128), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextCtrl3 = new wxTextCtrl(Panel2, ID_TEXTCTRL3, _("1"), wxPoint(96,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    wxFont TextCtrl3Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl3->SetFont(TextCtrl3Font);
    Slider3 = new wxSlider(Panel2, ID_SLIDER3, 0, 0, 100, wxPoint(8,41), wxSize(80,27), 0, wxDefaultValidator, _T("ID_SLIDER3"));
    FlexGridSizer1->Add(Panel2, 1, wxALL|wxEXPAND, 5);
    Panel3 = new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxSize(40,40), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    FlexGridSizer1->Add(Panel3, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(FlexGridSizer1);
    Layout();
    Center();

    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Version1Frame::OnPanel1Paint,0,this);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&Version1Frame::OnSlider1CmdScroll);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Version1Frame::OnTextCtrl1Text);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&Version1Frame::OnSlider2CmdSliderUpdated);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Version1Frame::OnTextCtrl2Text);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Version1Frame::OnButton2Click1);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Version1Frame::OnTextCtrl3Text);
    Connect(ID_SLIDER3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&Version1Frame::OnSlider3CmdSliderUpdated);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Version1Frame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Version1Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Version1Frame::OnAbout);
    //*)

}

Version1Frame::~Version1Frame()
{
    //(*Destroy(Version1Frame)
    //*)
}

void Version1Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Version1Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Version1Frame::tick()
{
    //  for (int i )
}

void Version1Frame::OnIdle()
{
    //render();
}


void Version1Frame::render(int x_dim, int y_dim)
{

    int xCoordinate = 0, yCoordinate = 0;
    int srcDim = 26;

    wxClientDC dc (Panel1);
    wxBitmap bit = wxBitmap(wxT("./index.jpeg"),wxBITMAP_TYPE_PNG);
    wxBufferedDC display (&dc,bit);

    int z_dim =1;
    for (int k = 0; k < z_dim; k++)
    {
        for (int j = 0; j < y_dim; j++)
        {
            for (int i = 0; i < x_dim; i++ )
            {
                wxBitmap btmp1 = array_of_cells[k][j][i]->getBitmap();
                wxMemoryDC srcDC(btmp1);
                display.Blit(xCoordinate,yCoordinate,srcDim,srcDim,&srcDC,0,0,wxCOPY,true);
                xCoordinate += srcDim;
            }
            xCoordinate = 0;
            yCoordinate += srcDim;
        }
    }


}






void Version1Frame::OnButton1Click(wxCommandEvent& event)
{   m_timer.Start(1);

    x_dim = Slider1->GetValue();
    y_dim = Slider2->GetValue();
    z_dim = 1;
    population_size = Slider3->GetValue();
    Panel1->SetSize(x_dim*26,y_dim*26);
    array_of_cells = Util::init(population_size,1,y_dim,x_dim); //error happens in the render function but it starts here probably

    render(x_dim, y_dim);


}

void Version1Frame::OnSlider1CmdScroll(wxScrollEvent& event)
{

    x_dim = Slider1->GetValue();
    wxString myString = wxString::Format(wxT("%i"), x_dim);
    TextCtrl1->ChangeValue(myString);

}

void Version1Frame::OnTextCtrl1Text(wxCommandEvent& event)
{
    wxString myString = TextCtrl1->GetValue();
    int val = wxAtoi(myString);
    Slider1->SetValue(val);
}

void Version1Frame::OnButton2Click(wxCommandEvent& event)
{

    wxString myString = wxString::Format(wxT("%i"), x_dim);
    TextCtrl1->ChangeValue(myString);

}

void Version1Frame::OnSlider2CmdSliderUpdated(wxScrollEvent& event)
{
    y_dim = Slider2->GetValue();
    wxString myString = wxString::Format(wxT("%i"), y_dim);
    TextCtrl2->ChangeValue(myString);

}

void Version1Frame::OnTextCtrl2Text(wxCommandEvent& event)
{
    wxString myString = TextCtrl2->GetValue();
    int val = wxAtoi(myString);
    Slider2->SetValue(val);
}

void Version1Frame::cell_modify(){

    int a,b,row,col,l = 0;

    for (int k = 0; k < z_dim; k++){
		for (int j = 0; j < y_dim; j++){
			for (int i = 0; i < x_dim; i++ ){
                l = 0;
                if(!array_of_cells[k][j][i]->getMember()){

                    for (a = -1; a < 1; a++){
                        row = j+a;
                        if(row < 0)row = 0;
                        else if(row >= y_dim) row = y_dim -1;
                        for (b = -1; b < 1; ++b){
                             col = i+b;
                            if(col < 0)col = 0;
                            else if(col >= x_dim) col = x_dim -1;
                            if (!array_of_cells[k][row][col]->getMember()){
                                ++l;
                            }
                        }
                   }
                   if (l == 2){
                     array_of_cells[k][row][col]->clearCell();
                     array_of_cells[k][j][i]->addMember(1);
                     wxMilliSleep(100);
                     render(x_dim,y_dim);
                    }
               }


		}
    }
}

}

void Version1Frame::OnPanel1Paint(wxPaintEvent& event)
{
    if (!initRun){
        Util::init(10,z_dim,y_dim,x_dim);
        Panel1->SetSize(x_dim*26,y_dim*26);
        initRun = true;
    }
    Panel1->SetSize(x_dim*26,y_dim*26);
    render(x_dim,y_dim);
}

void Version1Frame::OnButton2Click1(wxCommandEvent& event)
{
    m_timer.Stop();
    done = true;
}

void Version1Frame::OnTimer(wxTimerEvent& event){
    m_timer.Stop();
    Util::move_cell(array_of_cells,z_dim,y_dim,x_dim);
    cell_modify();
    render(x_dim,y_dim);
    m_timer.Start(100);
}


void Version1Frame::OnTextCtrl3Text(wxCommandEvent& event)
{
    wxString myString = TextCtrl3->GetValue();
    int val = wxAtoi(myString);
    Slider3->SetValue(val);
}


void Version1Frame::OnSlider3CmdSliderUpdated(wxScrollEvent& event)
{
    population_size = Slider3->GetValue();
    wxString myString = wxString::Format(wxT("%i"), population_size);
    TextCtrl3->ChangeValue(myString);
}
