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
	LPDIRECT3DDEVICE9	m_pD3D9Device;

protected:
	vector<DirectFont*>		m_pFontCache;			// 渲染字体
	vector<CCerasusUnit*>	m_pTextureCache;		// 渲染纹理

public:
	CCerasusResourceManager(LPDIRECT3DDEVICE9 pD3D9Device);
	~CCerasusResourceManager();

public:
	bool	MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	int		AddFont(LPWSTR strFontName, int nFontSize);			// 添加字体(字体名称、字体大小)
	int		AddTexture(CUUint sUnit);							// 添加纹理(文件导入)
	int		AddTexture(CUUintEx sUnit);							// 添加纹理(内存导入)


};

#endif // !__CERASUSRESOURCEMANAGER_H_
