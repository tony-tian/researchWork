/***************************************************************
 * Name:      LifeGameMain.h
 * Purpose:   Defines Application Frame
 * Author:    Renaissan (201411231041@bnu.edu.cn)
 * Created:   2016-07-02
 * Copyright: Renaissan ()
 * License:
 **************************************************************/


#ifndef LIFEGAMEMAIN_H
#define LIFEGAMEMAIN_H
#include <wx/timer.h>

//(*Headers(LifeGameFrame)
#include <wx/menu.h>
#include <wx/textdlg.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class LifeGameFrame: public wxFrame
{
public:

    LifeGameFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~LifeGameFrame();
    void createLifeSystem();
    void evolve();
    void paintWorld();
    int sum();
    void OnTimer(wxTimerEvent& event);
    void CenterText(const wxString& text, wxDC& dc, wxWindow* win);
    //        CustomDialog(const wxString & title);

private:

    //(*Handlers(LifeGameFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    //        void OnGrid1CellLeftClick(wxGridEvent& event);
    //      void OnGrid1CellLeftClick1(wxGridEvent& event);
    void OnNormalmode(wxCommandEvent& event);
    void OnStepIn(wxCommandEvent& event);
    void OnStillLifeWorld(wxCommandEvent& event);
    void OnContinue(wxCommandEvent& event);
    void OnChangeSpeed(wxCommandEvent& event);
    //*)

    //(*Identifiers(LifeGameFrame)
    static const long ID_GRID1;
    static const long Start;
    static const long StillLife;
    static const long ID_MENUITEM1;
    static const long idMenuQuit;
    static const long stepIn;
    static const long continue1;
    static const long changeSpeed;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    static const long ID_TEXTENTRYDIALOG1;
    //*)

    //(*Declarations(LifeGameFrame)
    wxMenuItem* MenuItem8;
    wxMenuItem* MenuItem7;
    wxMenu* Menu3;
    wxMenuItem* MenuItem4;
    wxGrid* Grid1;
    wxMenuItem* MenuItem3;
    wxStatusBar* StatusBar1;
    wxMenuItem* MenuItem6;
    wxTextEntryDialog* TextEntryDialog1;
    wxMenu* MenuItem5;
    //*)

    int lifeArray[102][102];
    wxTimer m_timer;
    float m_usertime;
    DECLARE_EVENT_TABLE()
};

#endif // LIFEGAMEMAIN_H