/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CreasusControl.cpp
* @brief	This File is CreasusControl DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-16	v1.00a	alopex	Create Project.
*/
#include "CerasusControl.h"

// CreasusUI 控件基类(CreasusControl)

//------------------------------------------------------------------
// @Function:	 CCerasusControl()
// @Purpose: CCerasusControl构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusControl::CCerasusControl()
{
	m_nX = 0;
	m_nY = 0;
	m_nWidth = 0;
	m_nHeight = 0;

	m_bEnabled = true;
	m_bVisible = true;
	m_bMouseOver = false;
	m_bHasFocus = false;
	m_bIsDefault = false;

	m_nID = 0;
	m_nIndex = 0;
	m_pUserData = NULL;
	m_eType = CERASUS_CONTROL_BUTTON;

	ZeroMemory(&m_rcBoundingBox, sizeof(m_rcBoundingBox));
}

//------------------------------------------------------------------
// @Function:	 ~CCerasusControl()
// @Purpose: CCerasusControl析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusControl::~CCerasusControl()
{
}

//------------------------------------------------------------------
// @Function:	 OnInit()
// @Purpose: CCerasusControl初始化控件
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
HRESULT CERASUSCONTROL_CALLMODE CCerasusControl::OnInit()
{
	return S_OK;
}

//------------------------------------------------------------------
// @Function:	 Refresh()
// @Purpose: CCerasusControl刷新控件
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CERASUSCONTROL_CALLMODE CCerasusControl::Refresh()
{
	m_bMouseOver = false;
	m_bHasFocus = false;
}

//------------------------------------------------------------------
// @Function:	 Render()
// @Purpose: CCerasusControl渲染控件
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CERASUSCONTROL_CALLMODE CCerasusControl::Render()
{
	
}

//------------------------------------------------------------------
// @Function:	 MsgProc()
// @Purpose: CCerasusControl消息处理
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
bool CERASUSCONTROL_CALLMODE CCerasusControl::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return false;
}

//------------------------------------------------------------------
// @Function:	 HandleKeyboard()
// @Purpose: CCerasusControl键盘消息处理
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
bool CERASUSCONTROL_CALLMODE CCerasusControl::HandleKeyboard(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return false;
}

//------------------------------------------------------------------
// @Function:	 HandleMouse()
// @Purpose: CCerasusControl鼠标消息处理
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
bool CERASUSCONTROL_CALLMODE CCerasusControl::HandleMouse(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return false;
}

//------------------------------------------------------------------
// @Function:	 CanHaveFocus()
// @Purpose: CCerasusControl是否获取焦点
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
bool CERASUSCONTROL_CALLMODE CCerasusControl::CanHaveFocus()
{
	return false;
}

//------------------------------------------------------------------
// @Function:	 OnFocusIn()
// @Purpose: CCerasusControl设置焦点
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CERASUSCONTROL_CALLMODE CCerasusControl::OnFocusIn()
{
	m_bHasFocus = true;
}

//------------------------------------------------------------------
// @Function:	 OnFocusOut()
// @Purpose: CCerasusControl丢失焦点
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CERASUSCONTROL_CALLMODE CCerasusControl::OnFocusOut()
{
	m_bHasFocus = false;
}
