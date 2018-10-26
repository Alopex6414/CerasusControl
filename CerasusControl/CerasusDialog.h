/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusDialog.h
* @brief	This File is CerasusDialog DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-24	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CERASUSDIALOG_H_
#define __CERASUSDIALOG_H_

//Include Direct Common Header File
#include "CerasusUICommon.h"
#include "CerasusControl.h"

//Macro Definition
#ifdef	CERASUSCONTROL_EXPORTS
#define CERASUSDIALOG_API	__declspec(dllexport)
#else
#define CERASUSDIALOG_API	__declspec(dllimport)
#endif

#define CERASUSDIALOG_CALLMETHOD	__stdcall

//Function Declaration
typedef VOID(CALLBACK*LPCALLBACKCERASUSGUIEVENT)(UINT nEvent, int nControlID, CCerasusControl* pControl, void* pUserContext);

//Class Definition
class CERASUSDIALOG_API CCerasusDialog
{
	friend class CCerasusResourceManager;

private:
	int	m_nX;					// CCerasusDialog 窗口X轴坐标
	int m_nY;					// CCerasusDialog 窗口Y轴坐标
	int m_nWidth;				// CCerasusDialog 窗口宽度
	int m_nHeight;				// CCerasusDialog 窗口高度
	int m_nCaptionHeight;		// CCerasusDialog 窗口标题高度

	bool	m_bVisible;			// CCerasusDialog 窗口可见
	bool	m_bCaption;			// CCerasusDialog 窗口标题栏拖动
	bool	m_bMinimized;		// CCerasusDialog 窗口最小化
	bool	m_bDrag;			// CCerasusDialog 窗口拖拽

	WCHAR	m_wszCaption[256];	// CCerasusDialog 窗口标题名称

	D3DCOLOR	m_colorTopLeft;			// CCerasusDialog 窗口左上角顶点颜色
	D3DCOLOR	m_colorTopRight;		// CCerasusDialog 窗口右上角顶点颜色
	D3DCOLOR	m_colorBottomLeft;		// CCerasusDialog 窗口左下角顶点颜色
	D3DCOLOR	m_colorBottomRight;		// CCerasusDialog 窗口右下角顶点颜色

	int m_nDefaultControlID;			// CCerasusDialog 窗口默认控件ID

	static double s_fTimeRefresh;		// CCerasusDialog 窗口刷新时间
	double m_fTimeLastRefresh;			// CCerasusDialog 窗口上次刷新时间

	static CCerasusControl* s_pControlFocus;		// CCerasusDialog 获得焦点控件
	static CCerasusControl* s_pControlPressed;      // CCerasusDialog 当前按下控件

	CCerasusControl* m_pControlMouseOver;           // CCerasusDialog 当前悬停控件

private:
	CCerasusResourceManager* m_pManager;			// CCerasusDialog 窗口资源管理类
	LPCALLBACKCERASUSGUIEVENT m_pCallbackEvent;		// CCerasusDialog 窗口事件回调函数
	void* m_pCallbackEventUserContext;				// CCerasusDialog 窗口事件回调用户参数

	vector<int> m_vecTextures;			// CCerasusDialog 纹理数组
	vector<int> m_vecFonts;				// CCerasusDialog 字体数组

	vector<CCerasusControl*> m_vecControls;			// CCerasusDialog 窗口控件数组
	//vector<DXUTElementHolder*> m_DefaultElements;

	//CCerasusElement m_CapElement;		// CCerasusDialog 标题元素

	CCerasusDialog* m_pNextDialog;		// CCerasusDialog 下一个窗口指针
	CCerasusDialog* m_pPrevDialog;		// CCerasusDialog 上一个窗口指针

public:
	bool m_bNonUserEvents;				// CCerasusDialog 用户事件标志
	bool m_bKeyboardInput;				// CCerasusDialog 键盘输入标志
	bool m_bMouseInput;					// CCerasusDialog 鼠标输入标志

public:
	CCerasusDialog();					// CCerasusDialog 构造函数
	~CCerasusDialog();					// CCerasusDialog 析构函数



};


#endif // !__CERASUSDIALOG_H_

