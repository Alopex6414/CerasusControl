/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusResourceManager.h
* @brief	This File is CerasusResourceManager DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-24	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CERASUSRESOURCEMANAGER_H_
#define __CERASUSRESOURCEMANAGER_H_

//Include Direct Common Header File
#include "CerasusUICommon.h"

//Class Definition
class CCerasusResourceManager
{
protected:
	LPDIRECT3DDEVICE9 m_pD3D9Device;

public:
	CCerasusResourceManager(LPDIRECT3DDEVICE9 pD3D9Device);
	~CCerasusResourceManager();

public:
	bool	MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


};

#endif // !__CERASUSRESOURCEMANAGER_H_
