/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CreasusControl.h
* @brief	This File is CreasusControl DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-16	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CREASUSCONTROL_H_
#define __CREASUSCONTROL_H_

//Include Direct Common Header File
#include "DirectCommon.h"
#include "DirectGraphics3D.h"
#include "DirectThreadSafe.h"

#include "CerasusUICommon.h"
#include "CerasusUnit.h"

//Macro Definition
#ifdef	CERASUSCONTROL_EXPORTS
#define CERASUSCONTROL_API	__declspec(dllexport)
#else
#define CERASUSCONTROL_API	__declspec(dllimport)
#endif

#define CERASUSCONTROL_CALLMODE	__stdcall

//Class Definition
class CERASUSCONTROL_API CCerasusControl
{
private:
	int m_nX;					// CCerasusControl 控件X坐标
	int m_nY;					// CCerasusControl 控件Y坐标
	int m_nWidth;				// CCerasusControl 控件宽度
	int m_nHeight;				// CCerasusControl 控件高度

	bool m_bVisible;			// CCerasusControl 控件是否可见(true:显示/false:隐藏)
	bool m_bMouseOver;			// CCerasusControl 鼠标指针在控件上(true:是/false:否)
	bool m_bHasFocus;			// CCerasusControl 控件是否拥有输入焦点(true:是/false:否)
	bool m_bIsDefault;			// CCerasusControl 控件是否是默认控件(true:是/false:否)

	//CDXUTDialog* m_pDialog;    // CCerasusControl Parent container
	UINT m_nIndex;              // CCerasusControl 控件列表中控件索引

protected:
	int m_nID;						// CCerasusControl 控件序号
	CERASUS_CONTROL_TYPE m_eType;	// CCerasusControl 控件类型

	UINT m_nHotkey;					// CCerasusControl 虚拟按键编码
	LPVOID m_pUserData;				// CCerasusControl 用户数据地址

	bool m_bEnabled;				// CCerasusControl 控件是否使能(true:是/false:否)
	RECT m_rcBoundingBox;			// CCerasusControl 控件使能区域

public:
	CCerasusControl();				// CCerasusControl 构造函数
	virtual ~CCerasusControl();		// CCerasusControl 析构函数

	virtual HRESULT CERASUSCONTROL_CALLMODE OnInit();					// CCerasusControl 初始化控件
	virtual void	CERASUSCONTROL_CALLMODE Refresh();					// CCerasusControl 刷新控件
	virtual void	CERASUSCONTROL_CALLMODE Render();					// CCerasusControl 渲染控件

	virtual bool	CERASUSCONTROL_CALLMODE MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);			// CCerasusControl 消息处理
	virtual bool	CERASUSCONTROL_CALLMODE HandleKeyboard(UINT uMsg, WPARAM wParam, LPARAM lParam);	// CCerasusControl 键盘消息处理
	virtual bool	CERASUSCONTROL_CALLMODE HandleMouse(UINT uMsg, WPARAM wParam, LPARAM lParam);		// CCerasusControl 鼠标消息处理

	virtual bool	CERASUSCONTROL_CALLMODE	CanHaveFocus();				// CCerasusControl 是否拥有焦点
	virtual void	CERASUSCONTROL_CALLMODE	OnFocusIn();				// CCerasusControl 设置焦点
	virtual void	CERASUSCONTROL_CALLMODE	OnFocusOut();				// CCerasusControl 丢失焦点

};


#endif // !__CREASUSCONTROL_H_

