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

	static double s_fTimeRefresh;		// CCerasusDialog 窗口刷新时间
	double m_fTimeLastRefresh;			// CCerasusDialog 窗口上次刷新时间

private:
	CCerasusResourceManager* m_pManager;			// CCerasusDialog 窗口资源管理类
	LPCALLBACKCERASUSGUIEVENT m_pCallbackEvent;		// CCerasusDialog 窗口事件回调函数
	void* m_pCallbackEventUserContext;				// CCerasusDialog 窗口事件回调用户参数

public:
	CCerasusDialog();
	~CCerasusDialog();



};


#endif // !__CERASUSDIALOG_H_

