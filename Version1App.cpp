/***************************************************************
 * Name:      Version1App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2019-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Version1App.h"

//(*AppHeaders
#include "Version1Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Version1App);

bool Version1App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Version1Frame* Frame = new Version1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
