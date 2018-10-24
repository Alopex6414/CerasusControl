/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusResourceManager.cpp
* @brief	This File is CerasusResourceManager DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-24	v1.00a	alopex	Create Project.
*/
#include "CerasusResourceManager.h"

// CreasusUI 渲染资源管理类(UI)

//------------------------------------------------------------------
// @Function:	 CCerasusResourceManager()
// @Purpose: CCerasusResourceManager构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusResourceManager::CCerasusResourceManager(LPDIRECT3DDEVICE9 pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;
}

//------------------------------------------------------------------
// @Function:	 ~CCerasusResourceManager()
// @Purpose: CCerasusResourceManager析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusResourceManager::~CCerasusResourceManager()
{
}

//------------------------------------------------------------------
// @Function:	 MsgProc()
// @Purpose: CCerasusResourceManager消息响应处理
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
bool CCerasusResourceManager::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return false;
}
