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
	LPDIRECT3DDEVICE9	m_pD3D9Device;				// D3D9渲染设备

protected:
	DirectSprite*		m_pSprite;					// D3DX点精灵

protected:
	vector<DirectFont*>		m_pFontCache;			// 渲染字体
	vector<CCerasusUnit*>	m_pTextureCache;		// 渲染纹理

public:
	CCerasusResourceManager(LPDIRECT3DDEVICE9 pD3D9Device);
	~CCerasusResourceManager();

	IDirect3DDevice9*		GetDevice()			const;			// 获取设备接口指针
	DirectSprite*			GetSprite()			const;			// 获取精灵接口指针
	vector<DirectFont*>		GetFontCache()		const;			// 获取渲染字体数组
	vector<CCerasusUnit*>	GetTextureCache()	const;			// 获取渲染纹理数组

public:
	bool	MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	HRESULT	OnD3D9ResetDevice();					// 重置设备
	HRESULT	OnD3D9LostDevice();						// 丢失设备
	void	OnD3D9DestroyDevice();					// 删除设备

public:
	DirectFont*		GetFontNode(int nIndex);		// 获取字体节点
	CCerasusUnit*	GetTextureNode(int nIndex);		// 获取纹理节点

	int		AddFont(LPWSTR strFontName, int nFontSize);			// 添加字体(字体名称、字体大小)
	int		AddTexture(CUUint sUnit);							// 添加纹理(文件导入)
	int		AddTexture(CUUintEx sUnit);							// 添加纹理(内存导入)


};

#endif // !__CERASUSRESOURCEMANAGER_H_
