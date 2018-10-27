/***************************************************************
 * Name:      LifeGameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Renaissan (201411231041@bnu.edu.cn)
 * Created:   2016-07-02
 * Copyright: Renaissan ()
 * License:
 **************************************************************/

#include "LifeGameMain.h"
#include <wx/msgdlg.h>
#include <cstdlib>
#include <math.h>
#include <wx/colour.h>
#include <iostream>
#include <time.h>

void delay(int sec)

{
    time_t start_time, cur_time; // 变量声明
    time(&start_time);

    do {
        time(&cur_time);
    }
    while((cur_time - start_time) < sec );
}

//#define T 100 //时间
//(*InternalHeaders(LifeGameFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)



//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

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

//(*IdInit(LifeGameFrame)
const long LifeGameFrame::ID_GRID1 = wxNewId();
const long LifeGameFrame::Start = wxNewId();
const long LifeGameFrame::StillLife = wxNewId();
const long LifeGameFrame::ID_MENUITEM1 = wxNewId();
const long LifeGameFrame::idMenuQuit = wxNewId();
const long LifeGameFrame::stepIn = wxNewId();
const long LifeGameFrame::idMenuAbout = wxNewId();
const long LifeGameFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LifeGameFrame,wxFrame)
    //(*EventTable(LifeGameFrame)
    //*)
END_EVENT_TABLE()

LifeGameFrame::LifeGameFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(LifeGameFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(500,500));
    Move(wxPoint(200,0));
    Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(-20,-20), 0, _T("ID_GRID1"));
    Grid1->CreateGrid(100,100);
    Grid1->SetFocus();
    Grid1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Grid1->EnableEditing(false);
    Grid1->EnableGridLines(true);
    Grid1->SetDefaultRowSize(1, true);
    Grid1->SetDefaultColSize(1, true);
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, Start, _("Start(normal)\ta"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem5 = new wxMenu();
    MenuItem6 = new wxMenuItem(MenuItem5, StillLife, _("StillLifeForm"), wxEmptyString, wxITEM_NORMAL);
    MenuItem5->Append(MenuItem6);
    Menu1->Append(ID_MENUITEM1, _("Start.."), MenuItem5, wxEmptyString);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu3, stepIn, _("step in\ts"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuBar1->Append(Menu3, _("Edit.."));
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

    Connect(Start,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnNormalmode);
    Connect(StillLife,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnStillLifeWorld);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnQuit);
    Connect(stepIn,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnStepIn);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&LifeGameFrame::OnClose);
    //*)

    Grid1->HideColLabels();
    Grid1->HideRowLabels();
}

LifeGameFrame::~LifeGameFrame()
{
    //(*Destroy(LifeGameFrame)
    //*)
}

void LifeGameFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void LifeGameFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

int LifeGameFrame::sum()
{
    int a=0;
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
        a=a+lifeArray[i][j];
    return a;
}

void LifeGameFrame::OnClose(wxCloseEvent& event)
{
    Close();
}

void LifeGameFrame::createLifeSystem()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        {

            lifeArray[i][j]=rand()%3%2;
        }
}

void LifeGameFrame::evolve()
{
    int tmp[102][102];
    for(int x = 1; x <=100; x++)
    {
        for(int y = 1; y <= 100; y++)
        {
            // 计算周围活着的生命数量
            int sum1 = lifeArray[x+1][y] + lifeArray[x+1][y-1] + lifeArray[x][y-1] + lifeArray[x-1][y-1]
                + lifeArray[x-1][y] + lifeArray[x-1][y+1] + lifeArray[x][y+1] + lifeArray[x+1][y+1];
            // 计算当前位置的生命状态
            if(sum1==3)
            {
                tmp[x][y] = 1;
                Grid1->SetCellBackgroundColour(x, y, *wxBLACK);
            }
            else if(sum1==2)
            {
                tmp[x][y] = lifeArray[x][y];
                Grid1->SetCellBackgroundColour(x,y,*wxLIGHT_GREY);
            }
            else{
                tmp[x][y] = 0;
                Grid1->SetCellBackgroundColour(x, y, *wxWHITE);
            }
            }
    }
    memcpy(lifeArray, tmp, 102 * 102 * sizeof(int));
}

void LifeGameFrame::paintWorld()
{
    //int tmp[102][102];
    evolve();
    Grid1->ForceRefresh();
}

void LifeGameFrame::OnNormalmode(wxCommandEvent& event)
{
    createLifeSystem();//Initial World
    //evolve(Grid1);
}

void LifeGameFrame::OnStepIn(wxCommandEvent& event)
{

//    Grid1->ApplyEdit(Grid1);
    evolve();
    Grid1->ForceRefresh ();
}


void LifeGameFrame::OnStillLifeWorld(wxCommandEvent& event)
{
    for(int i=5;i<7;i++)
    {
        lifeArray[i][5]=1;
        lifeArray[i][6]=1;
    }
    Grid1->SetCellValue(1,3,"Block");

    lifeArray[3][19]=1;
    lifeArray[3][20]=1;
    lifeArray[4][18]=1;
    lifeArray[4][21]=1;
    lifeArray[5][19]=1;
    lifeArray[3][20]=1;
    Grid1->SetCellValue(1,15,"Beehive");

    lifeArray[17][4]=1;
    lifeArray[17][5]=1;
    lifeArray[18][3]=1;
    lifeArray[18][6]=1;
    lifeArray[19][5]=1;
    lifeArray[19][6]=1;
    lifeArray[20][5]=1;
    Grid1->SetCellValue(14,5,"Loaf");
}
