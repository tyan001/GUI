/***************************************************************
 * Name:      Version1Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef VERSION1MAIN_H
#define VERSION1MAIN_H

//(*Headers(Version1Frame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include "./imports/Cell.h"
#include "./imports/Util.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <wx/msgdlg.h>
#include <wx/dcbuffer.h>


class Version1Frame: public wxFrame
{
    public:


        Version1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Version1Frame();

    private:
        Cell **** array_of_cells;
        int population_size;
        int x_dim,y_dim,z_dim;
        bool initRun = false;
        bool done = false;
        wxTimer m_timer;
        //(*Handlers(Version1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnSlider1CmdScroll(wxScrollEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnSlider2CmdSliderUpdated(wxScrollEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnSlider3CmdScroll(wxScrollEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        void OnSlider1CmdScroll1(wxScrollEvent& event);
        void OnSlider3CmdScroll1(wxScrollEvent& event);
        void OnSlider3CmdSliderUpdated(wxScrollEvent& event);
        //*)

        //(*Identifiers(Version1Frame)
        static const long ID_PANEL1;
        static const long ID_SLIDER1;
        static const long ID_TEXTCTRL1;
        static const long ID_SLIDER2;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_SLIDER3;
        static const long ID_PANEL2;
        static const long ID_PANEL3;
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Version1Frame)
        wxButton* Button1;
        wxButton* Button2;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxSlider* Slider1;
        wxSlider* Slider2;
        wxSlider* Slider3;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        //*)

        void OnIdle(void);
        void tick(void);

        void animate(void);
        void render(int x, int y);
        void cell_modify(void);

        void OnTimer(wxTimerEvent& event);

       // void movement()

        DECLARE_EVENT_TABLE()
};

#endif // VERSION1MAIN_H
