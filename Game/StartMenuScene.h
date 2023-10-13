#pragma once
#include "afxwin.h"

#ifndef SHARED_HANDLERS
#include "Game.h"
#endif

#include "GameDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class StartMenuScene : public CView
{
public:
	StartMenuScene();

protected:
	DECLARE_DYNCREATE(StartMenuScene)

public:
	CGameDoc* GetDocument() const;

public:
	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:
	virtual ~StartMenuScene();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CBitmap bmpGameStart;
	CBitmap bmpQuitGame;
	virtual void OnInitialUpdate();
	CBitmap bmpMain;
};

#ifndef _DEBUG
inline CGameDoc* StartMenuScene::GetDocument() const
   { return reinterpret_cast<CGameDoc*>(m_pDocument); }
#endif

