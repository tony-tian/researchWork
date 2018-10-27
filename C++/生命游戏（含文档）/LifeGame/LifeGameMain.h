/***************************************************************
 * Name:      LifeGameMain.h
 * Purpose:   Defines Application Frame
 * Author:    Renaissan (201411231041@bnu.edu.cn)
 * Created:   2016-07-10
 * Copyright: Renaissan ()
 * License:
 **************************************************************/

#ifndef LIFEGAMEMAIN_H
#define LIFEGAMEMAIN_H
#include "LifeIndiv.hpp"
#include <wx/timer.h>
//(*Headers(LifeGameFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class LifeGameFrame: public wxFrame
{
public:

    LifeGameFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~LifeGameFrame();
    friend wxGrid* GetGrid();
    friend class LifeIndiv;
    void prepareStep();
    void setTexts();

private:

    //(*Handlers(LifeGameFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnPanel2Paint(wxPaintEvent& event);
    void OnStartNormalMode(wxCommandEvent& event);
    void OnSwitchStepMode(wxCommandEvent& event);
    void OnNextStep(wxCommandEvent& event);
    void OnSystemPause(wxCommandEvent& event);
    void OnSystemContinue(wxCommandEvent& event);
    void OnButtonStartClick(wxCommandEvent& event);
    void OnButtonPauseClick(wxCommandEvent& event);
    void OnChoice1Select(wxCommandEvent& event);
    void OnCreateCrowdWorld(wxCommandEvent& event);
    void OnChoice2Select(wxCommandEvent& event);
    //*)

    //(*Identifiers(LifeGameFrame)
    static const long ID_GRID1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT7;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT4;
    static const long ID_PANEL2;
    static const long ID_STATICTEXT10;
    static const long ID_CHOICE1;
    static const long ID_STATICTEXT11;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT12;
    static const long ID_STATICTEXT13;
    static const long ID_STATICTEXT14;
    static const long ID_CHOICE2;
    static const long ID_STATICTEXT15;
    static const long ID_PANEL1;
    static const long StartEvolveNormal;
    static const long StartCrowdedWorld;
    static const long idMenuQuit;
    static const long StepButton;
    static const long NextStep;
    static const long PauseButton;
    static const long ContinueButton;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)

    //(*Declarations(LifeGameFrame)
    wxStaticText* StaticText10;
    wxStaticText* StaticText9;
    wxMenuItem* MenuItem8;
    wxMenuItem* MenuItem7;
    wxStaticText* StaticTextDead;
    wxStaticText* StaticTextLife;
    wxMenuItem* MenuItem5;
    wxStaticText* StaticText2;
    wxMenu* Menu3;
    wxStaticText* StaticText6;
    wxMenuItem* MenuItem4;
    wxStaticText* StaticText8;
    wxPanel* Panel1;
    wxStaticText* StaticText3;
    wxGrid* Grid1;
    wxMenuItem* MenuItem3;
    wxStaticText* StaticText5;
    wxStaticText* StaticText7;
    wxStaticText* StaticTextSystemStatus;
    wxStaticText* StaticTextLifeSum;
    wxStatusBar* StatusBar1;
    wxMenuItem* MenuItem6;
    wxStaticText* StaticTextStep;
    wxButton* ButtonStart;
    wxStaticText* StaticTextDeadSum;
    wxPanel* Panel2;
    wxStaticText* StaticText4;
    wxButton* ButtonPause;
    wxChoice* Choice1;
    wxChoice* Choice2;
    //*)
    wxTimer m_timer;
    void OnTimer(wxTimerEvent &event);
    //void evolve(LifeIndiv &l);
    //void evolveProceed(wxGrid *grid);

    DECLARE_EVENT_TABLE()
};

#endif // LIFEGAMEMAIN_H
