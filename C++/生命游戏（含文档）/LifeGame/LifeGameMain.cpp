/***************************************************************
 * Name:      LifeGameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Renaissan (201411231041@bnu.edu.cn)
 * Created:   2016-07-10
 * Copyright: Renaissan ()
 * License:
 **************************************************************/

#include "LifeGameMain.h"
#include <wx/msgdlg.h>
#include<cstring>
#include <wx/log.h>
#define Timer_ID 1000
//(*InternalHeaders(LifeGameFrame)
#include <wx/settings.h>
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

//(*IdInit(LifeGameFrame)
const long LifeGameFrame::ID_GRID1 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT2 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT3 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT5 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT6 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT7 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT8 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT9 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT4 = wxNewId();
const long LifeGameFrame::ID_PANEL2 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT10 = wxNewId();
const long LifeGameFrame::ID_CHOICE1 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT11 = wxNewId();
const long LifeGameFrame::ID_BUTTON1 = wxNewId();
const long LifeGameFrame::ID_BUTTON2 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT1 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT12 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT13 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT14 = wxNewId();
const long LifeGameFrame::ID_CHOICE2 = wxNewId();
const long LifeGameFrame::ID_STATICTEXT15 = wxNewId();
const long LifeGameFrame::ID_PANEL1 = wxNewId();
const long LifeGameFrame::StartEvolveNormal = wxNewId();
const long LifeGameFrame::StartCrowdedWorld = wxNewId();
const long LifeGameFrame::idMenuQuit = wxNewId();
const long LifeGameFrame::StepButton = wxNewId();
const long LifeGameFrame::NextStep = wxNewId();
const long LifeGameFrame::PauseButton = wxNewId();
const long LifeGameFrame::ContinueButton = wxNewId();
const long LifeGameFrame::idMenuAbout = wxNewId();
const long LifeGameFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LifeGameFrame,wxFrame)
    //(*EventTable(LifeGameFrame)
    //*)
    EVT_TIMER(Timer_ID,LifeGameFrame::OnTimer)
END_EVENT_TABLE()

LifeGameFrame::LifeGameFrame(wxWindow* parent,wxWindowID id):m_timer(this,Timer_ID)
{
    //(*Initialize(LifeGameFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxStaticText* StaticText1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(550,380));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(160,104), wxSize(800,600), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Grid1 = new wxGrid(Panel1, ID_GRID1, wxPoint(8,40), wxSize(305,305), 0, _T("ID_GRID1"));
    Grid1->CreateGrid(20,20);
    Grid1->SetFocus();
    Grid1->EnableEditing(false);
    Grid1->EnableGridLines(true);
    Grid1->SetColLabelSize(1);
    Grid1->SetRowLabelSize(1);
    Grid1->SetDefaultRowSize(1, true);
    Grid1->SetDefaultColSize(1, true);
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    StaticText1 = new wxStaticText(Panel1, wxID_ANY, _("Statistics"), wxPoint(315,20), wxDefaultSize, 0, _T("wxID_ANY"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(16);
    StaticText1Font.SetWeight(wxBOLD);
    StaticText1->SetFont(StaticText1Font);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(310,40), wxSize(200,72), 0, _T("ID_PANEL2"));
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Lifes RT"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Dead LS"), wxPoint(16,48), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Total"), wxPoint(112,48), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticTextLife = new wxStaticText(Panel2, ID_STATICTEXT6, _("0"), wxPoint(80,16), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticTextLife->SetFocus();
    StaticTextDead = new wxStaticText(Panel2, ID_STATICTEXT7, _("0"), wxPoint(80,48), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticTextDead->SetFocus();
    StaticTextLifeSum = new wxStaticText(Panel2, ID_STATICTEXT8, _("0"), wxPoint(160,16), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    StaticTextLifeSum->SetFocus();
    StaticTextDeadSum = new wxStaticText(Panel2, ID_STATICTEXT9, _("0"), wxPoint(160,48), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticTextDeadSum->SetFocus();
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Total"), wxPoint(112,16), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT10, _("WorkSpace"), wxPoint(112,16), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    wxFont StaticText9Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText9Font.Ok() ) StaticText9Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText9Font.SetPointSize(16);
    StaticText9Font.SetStyle(wxFONTSTYLE_NORMAL);
    StaticText9Font.SetWeight(wxBOLD);
    StaticText9Font.SetFamily(wxROMAN);
    StaticText9->SetFont(StaticText9Font);
    Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxPoint(450,120), wxSize(72,20), 0, 0, wxCB_SORT, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("0.5s")) );
    Choice1->Append(_("1s(Default)"));
    Choice1->Append(_("2s"));
    Choice1->Append(_("10s"));
    Choice1->SetMinSize(wxSize(-1,-1));
    Choice1->SetMaxSize(wxSize(-1,-1));
    Choice1->SetFocus();
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Select evolve-speed"), wxPoint(315,123), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    ButtonStart = new wxButton(Panel1, ID_BUTTON1, _("Start"), wxPoint(328,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonPause = new wxButton(Panel1, ID_BUTTON2, _("Pause"), wxPoint(424,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT1, _("System Status"), wxPoint(320,200), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText6Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !StaticText6Font.Ok() ) StaticText6Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText6Font.SetPointSize(16);
    StaticText6Font.SetStyle(wxFONTSTYLE_NORMAL);
    StaticText6Font.SetWeight(wxBOLD);
    StaticText6Font.SetUnderlined(true);
    StaticText6->SetFont(StaticText6Font);
    StaticTextSystemStatus = new wxStaticText(Panel1, ID_STATICTEXT12, _("Label"), wxPoint(456,202), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT13, _("Step"), wxPoint(360,232), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    wxFont StaticText7Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !StaticText7Font.Ok() ) StaticText7Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText7Font.SetPointSize(16);
    StaticText7Font.SetWeight(wxBOLD);
    StaticText7Font.SetUnderlined(true);
    StaticText7->SetFont(StaticText7Font);
    StaticTextStep = new wxStaticText(Panel1, ID_STATICTEXT14, _("0"), wxPoint(470,236), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    Choice2 = new wxChoice(Panel1, ID_CHOICE2, wxPoint(440,280), wxSize(88,20), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->Append(_("Liner 10 Cells"));
    Choice2->Append(_("3 Boats"));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT15, _("Example_Display"), wxPoint(328,282), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, StartEvolveNormal, _("Start(Normal Mode)"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem8 = new wxMenuItem(Menu1, StartCrowdedWorld, _("Start(Crowd Mode)"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem8);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu3, StepButton, _("Step in(Switch)"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuItem7 = new wxMenuItem(Menu3, NextStep, _("Next Step\ts"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem7);
    MenuItem5 = new wxMenuItem(Menu3, PauseButton, _("Pause.."), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ContinueButton, _("Continue.."), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuBar1->Append(Menu3, _("Edit"));
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
    Center();

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnChoice1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LifeGameFrame::OnButtonStartClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LifeGameFrame::OnButtonPauseClick);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnChoice2Select);
    Connect(StartEvolveNormal,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnStartNormalMode);
    Connect(StartCrowdedWorld,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnCreateCrowdWorld);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnQuit);
    Connect(StepButton,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnSwitchStepMode);
    Connect(NextStep,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnNextStep);
    Connect(PauseButton,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnSystemPause);
    Connect(ContinueButton,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnSystemContinue);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LifeGameFrame::OnAbout);
    //*)
    Grid1->HideColLabels();
    Grid1->HideRowLabels();
    StaticTextSystemStatus->SetLabel(_("off"));
    Choice1->SetSelection(1);
    wxMessageDialog dialog( NULL, wxT("LifeGame(or \"Conway\'s Game of Life\), is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves, or, for advanced \"players\", by creating patterns with particular properties."),wxT("Before The LifeGame"),wxYES_DEFAULT|wxYES_NO|wxICON_INFORMATION);
    switch ( dialog.ShowModal() )
    {
    case wxID_YES:
        wxLogStatus(wxT("You pressed \"Yes\""));
        wxMessageBox(wxT("Welcome to LifeGame World!"));
        break;
    case wxID_NO:
        wxLogStatus(wxT("You pressed \"No\""));
        wxMessageBox(wxT("Maybe you need more time to think.."));
        Close();
        break;
    default :
        wxLogError(wxT("Unexpected wxMessageDialog return code!"));
    }

}

LifeIndiv m_life;


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

void LifeGameFrame::prepareStep()
{
    for (int i=0; i<20; i++)
        for(int j=0; j<20; j++)
        {
            if(m_life.getStatus(i+1,j+1)==1)
                Grid1->SetCellBackgroundColour(i, j, *wxBLACK);
            else if(m_life.getStatus(i+1,j+1)==0)
                Grid1->SetCellBackgroundColour(i, j, *wxWHITE);
        }
    setTexts();
    Grid1->ForceRefresh();
}

void LifeGameFrame::OnStartNormalMode(wxCommandEvent& event)
{
    wxString status=StaticTextSystemStatus->GetLabel();
    if(status.IsSameAs(wxT("off")))
    {
        wxMessageDialog dialog( NULL, wxT("The system is off now. Are you going to create a new fresh world and get it continuous(Default 1s per turn)?"),wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
    }
    else
    {
        wxMessageDialog dialog( NULL,wxT("The system has already been on. Are you going to rebuild a new fresh world and get it continuous(Default 1s per turn)?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
        m_life.clearWorld();
    }
    m_life.createWorldRandom();
    prepareStep();
    m_timer.Start(1000);
    StaticTextSystemStatus->SetLabel(_("Started"));
}

void LifeGameFrame::OnTimer(wxTimerEvent &event)
{
    m_life.evolve();
    prepareStep();
}


void LifeGameFrame::OnSwitchStepMode(wxCommandEvent& event)
{
    if(m_timer.IsRunning())
    {
        wxMessageDialog dialog( NULL,wxT("The system is evolving continuously. Are you going to switch to step-in mode?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
        m_timer.Stop();
        wxMessageBox(_("You have switched to step-in Mode"));
    }
    else
    {
        wxMessageDialog dialog( NULL,wxT("The system is not continuous now. Are you going to get system continuous?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the process"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the process"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
        m_timer.Start(1000);
        wxMessageBox(_("You have switched to continuous Mode"));
    }
}

void LifeGameFrame::OnNextStep(wxCommandEvent& event)
{
    m_life.evolve();
    prepareStep();
}

void LifeGameFrame::OnSystemPause(wxCommandEvent& event)
{
    if(m_timer.IsRunning())
    {
        wxMessageDialog dialog( NULL,wxT("Are you going to get system paused?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }

        m_timer.Stop();
        wxMessageBox(_("You have got system paused"));
    }
    else
    {
        wxMessageBox(_("The system was not running"));
    }
}

void LifeGameFrame::OnSystemContinue(wxCommandEvent& event)
{
    wxMessageDialog dialog( NULL,wxT("Are you going to get system continuous?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
    switch ( dialog.ShowModal() )
    {
    case wxID_YES:
        wxLogStatus(wxT("You pressed \"Yes\""));
        wxMessageBox(wxT("Behavior has been confirmed"));
        break;
    case wxID_NO:
        wxLogStatus(wxT("You pressed \"No\""));
        wxMessageBox(wxT("You have rejected the behavior"));
        return;
        break;
    case wxID_CANCEL:
        wxLogStatus(wxT("You pressed \"Cancel\""));
        wxMessageBox(wxT("You have rejected the behavior"));
        return;
        break;
    default :
        wxLogError(wxT("Unexpected wxMessageDialog return code!"));
    }

    if(!m_timer.IsRunning())
    {
        m_timer.Start(1000);
        wxMessageBox(_("You have got system continued"));
    }
    else
    {
        wxMessageBox(_("The system was running"));
    }
}

void LifeGameFrame::setTexts()
{
    wxString life_num,life_sum,dead_num,dead_sum,step_num;
    life_num<<m_life.getStatistics(1);
    dead_num<<m_life.getStatistics(2);
    life_sum<<m_life.getStatistics(3);
    dead_sum<<m_life.getStatistics(4);
    step_num<<m_life.getStep();
    StaticTextLife->SetLabel(life_num);
    StaticTextDead->SetLabel(dead_num);
    StaticTextLifeSum->SetLabel(life_sum);
    StaticTextDeadSum->SetLabel(dead_sum);
    StaticTextStep->SetLabel(step_num);
}

void LifeGameFrame::OnButtonStartClick(wxCommandEvent& event)
{
    wxString status=StaticTextSystemStatus->GetLabel();
    if(status.IsSameAs(_T("off")))
    {
        wxMessageBox(_("The system is not running. You need create a new world first."));
        return;
    }
    if(!m_timer.IsRunning())
    {
        int choice_row=Choice1->GetSelection();
        switch (choice_row)
        {
        case 0:
            m_timer.Start(500);
            break;

        case 1:
            m_timer.Start(1000);
            break;

        case 2:
            m_timer.Start(2000);
            break;

        case 3:
            m_timer.Start(10000);
            break;
        default:
            break;
        }
        wxMessageBox(_("You have got system continued"));
    }
    else
    {
        wxMessageBox(_("The system was running"));
    }
}

void LifeGameFrame::OnButtonPauseClick(wxCommandEvent& event)
{
    wxString status=StaticTextSystemStatus->GetLabel();
    if(status.IsSameAs(_T("off")))
    {
        wxMessageBox(_("The system is not running. You need create a new world first."));
        return;
    }
    if(m_timer.IsRunning())
    {
        m_timer.Stop();
        wxMessageBox(_("You have got system paused"));
    }
    else
    {
        wxMessageBox(_("The system was not running"));
    }
}

void LifeGameFrame::OnChoice1Select(wxCommandEvent& event)
{
    wxString status=StaticTextSystemStatus->GetLabel();
    if(status.IsSameAs(_T("off")))
    {
        wxMessageBox(_("The system is not running. You need create a new world first."));
        return;
    }
    if(m_timer.IsRunning())
    {
        wxMessageDialog dialog( NULL,wxT("Are you going to get system continuous in selected mode?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        m_timer.Stop();
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
        int choice_row=Choice1->GetSelection();
        switch (choice_row)
        {
        case 0:
            m_timer.Start(500);
            wxMessageBox(wxT("0.5"));
            break;

        case 1:
            m_timer.Start(1000);
            wxMessageBox(wxT("1"));
            break;

        case 2:
            m_timer.Start(2000);
            wxMessageBox(wxT("2"));
            break;

        case 3:
            m_timer.Start(10000);
            wxMessageBox(wxT("10"));
            break;
        default:
            break;
        }
    }
}

void LifeGameFrame::OnCreateCrowdWorld(wxCommandEvent& event)
{
    wxString status=StaticTextSystemStatus->GetLabel();
    if(status.IsSameAs(wxT("off")))
    {
        wxMessageDialog dialog( NULL, wxT("The system is off now. Are you going to create a new fresh world and get it continuous(Default 1s per turn)?"),wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
    }
    else
    {
        wxMessageDialog dialog( NULL,wxT("The system has already been on. Are you going to rebuild a new fresh world and get it continuous(Default 1s per turn)?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        switch ( dialog.ShowModal() )
        {
        case wxID_YES:
            wxLogStatus(wxT("You pressed \"Yes\""));
            wxMessageBox(wxT("Behavior has been confirmed"));
            break;
        case wxID_NO:
            wxLogStatus(wxT("You pressed \"No\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        case wxID_CANCEL:
            wxLogStatus(wxT("You pressed \"Cancel\""));
            wxMessageBox(wxT("You have rejected the behavior"));
            return;
            break;
        default :
            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
        m_life.clearWorld();
    }
    m_life.createWorldCrowd();
    prepareStep();
    m_timer.Start(1000);
    StaticTextSystemStatus->SetLabel(_("Started"));
}

void LifeGameFrame::OnChoice2Select(wxCommandEvent& event)
{
    wxString status=StaticTextSystemStatus->GetLabel();
    if(status.IsSameAs(_T("Started")))
    {
        wxMessageBox(_("The system is running. You need to make a confirmation next."));
    }
    if(m_timer.IsRunning())
    {
        wxMessageDialog dialog( NULL,wxT("Are you going to display the examples?"), wxT("Message Confirmation"),wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_INFORMATION);
        m_timer.Stop();
        switch ( dialog.ShowModal() )
        {
            case wxID_YES:
                wxLogStatus(wxT("You pressed \"Yes\""));
                wxMessageBox(wxT("Behavior has been confirmed"));
                break;
            case wxID_NO:
                wxLogStatus(wxT("You pressed \"No\""));
                wxMessageBox(wxT("You have rejected the behavior"));
                return;
                break;
            case wxID_CANCEL:
                wxLogStatus(wxT("You pressed \"Cancel\""));
                wxMessageBox(wxT("You have rejected the behavior"));
                return;
                break;
            default :
                wxLogError(wxT("Unexpected wxMessageDialog return code!"));
        }
    }
    int choice_row=Choice2->GetSelection();
    switch (choice_row)
    {
        case 0:
            m_life.create10Cell();
            break;

        case 1:
            m_life.create3Boats();
            break;

//        case 2:
//            wxMessageBox(wxT("2"));
//            break;
//
//        case 3:
//            wxMessageBox(wxT("10"));
//            break;
        default:
            break;
    }
    prepareStep();
    wxMessageBox(wxT("Please click Start to run the system"));
    StaticTextSystemStatus->SetLabel(_("Started"));
}
