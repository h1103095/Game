
// MainFrm.h : CMainFrame Å¬·¡½ºÀÇ ÀÎÅÍÆäÀÌ½º
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // serialization¿¡¼­¸¸ ¸¸µé¾îÁý´Ï´Ù.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Æ¯¼ºÀÔ´Ï´Ù.
public:

// ÀÛ¾÷ÀÔ´Ï´Ù.
public:

// ÀçÁ¤ÀÇÀÔ´Ï´Ù.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ±¸ÇöÀÔ´Ï´Ù.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	short CurrentView;
	enum eView { MENU = 0 , GAME = 1};
	void SwitchView(eView);

// »ý¼ºµÈ ¸Þ½ÃÁö ¸Ê ÇÔ¼ö
protected:
	DECLARE_MESSAGE_MAP()

};


