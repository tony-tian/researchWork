/***************************************************************
 * Name:      LifeGameApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Renaissan (201411231041@bnu.edu.cn)
 * Created:   2016-07-10
 * Copyright: Renaissan ()
 * License:
 **************************************************************/

#include "LifeGameApp.h"

//(*AppHeaders
#include "LifeGameMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LifeGameApp);

bool LifeGameApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LifeGameFrame* Frame = new LifeGameFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
