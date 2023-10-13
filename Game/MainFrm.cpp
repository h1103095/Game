#include "stdafx.h"
#include "MainFrm.h"


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
END_MESSAGE_MAP()


CMainFrame::CMainFrame()
{

}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs

	if (cs.hMenu != NULL) {
	::DestroyMenu(cs.hMenu);	// delete menu if loaded
	cs.hMenu = NULL;			// no menu for this window
	}

	cs.x = 10;
	cs.y = 20;

	cs.cx = WND_X;
	cs.cy = WND_Y;

	return TRUE;
}

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG



void CMainFrame::SwitchView(SceneID id)
{
    CView* old_view = GetActiveView();
	CView* new_view;
	switch (id) {
	case SceneID::MENU:
		new_view = new StartMenuScene();
		break;
	case SceneID::GAME:
		new_view = new InGameScene();
		break;
	default:
		return;
	}

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	old_view->CloseWindow();
	CCreateContext new_context;
	new_context.m_pNewViewClass = NULL;
	new_context.m_pNewDocTemplate = NULL;
	new_context.m_pLastView = NULL;
	new_context.m_pCurrentFrame = NULL;
	new_context.m_pCurrentDoc = old_view->GetDocument();
	new_view->Create(NULL, NULL, WS_BORDER | WS_CHILD, CFrameWnd::rectDefault, this, AFX_IDW_PANE_FIRST, &new_context);

	old_view->ShowWindow(SW_HIDE);
	new_view->ShowWindow(SW_SHOW);
	SetActiveView(new_view);
	new_view->SetDlgCtrlID(AFX_IDW_PANE_FIRST);

	RecalcLayout();
	new_view->OnInitialUpdate();
 }
