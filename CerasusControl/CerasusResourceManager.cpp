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

	m_pFontCache.clear();
	m_pTextureCache.clear();
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
	// 内存垃圾回收...

	// 字体
	for (auto iter = m_pFontCache.begin(); iter != m_pFontCache.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_pFontCache.clear();

	// 纹理
	for (auto iter = m_pTextureCache.begin(); iter != m_pTextureCache.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_pTextureCache.clear();

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

//------------------------------------------------------------------
// @Function:	 AddFont()
// @Purpose: CCerasusResourceManager添加字体
// @Since: v1.00a
// @Para: LPWSTR strFontName	// 字体名称
// @Para: int nFontSize			// 字体大小
// @Return: None
//------------------------------------------------------------------
int CCerasusResourceManager::AddFont(LPWSTR strFontName, int nFontSize)
{
	DirectFont* pFontNode = new DirectFont(m_pD3D9Device);

	if (pFontNode == NULL)
	{
		return -1;
	}

	HRESULT hr = pFontNode->DirectFontInit(nFontSize, strFontName);
	if (FAILED(hr))
	{
		return -2;
	}

	int nFont = 0;

	m_pFontCache.push_back(pFontNode);
	nFont = m_pFontCache.size() - 1;

	return nFont;
}

//------------------------------------------------------------------
// @Function:	 AddTexture()
// @Purpose: CCerasusResourceManager添加纹理
// @Since: v1.00a
// @Para: CUUint sUnit	// 添加纹理参数
// @Return: None
//------------------------------------------------------------------
int CCerasusResourceManager::AddTexture(CUUint sUnit)
{
	CCerasusUnit* pTextureNode = new CCerasusUnit(m_pD3D9Device);

	if (pTextureNode == NULL)
	{
		return -1;
	}

	HRESULT hr = pTextureNode->CCerasusUnitInit(sUnit);
	if (FAILED(hr))
	{
		return -2;
	}

	int nTexture = 0;

	m_pTextureCache.push_back(pTextureNode);
	nTexture = m_pTextureCache.size() - 1;

	return nTexture;
}

//------------------------------------------------------------------
// @Function:	 AddTexture()
// @Purpose: CCerasusResourceManager添加纹理
// @Since: v1.00a
// @Para: CUUintEx sUnit	// 添加纹理参数
// @Return: None
//------------------------------------------------------------------
int CCerasusResourceManager::AddTexture(CUUintEx sUnit)
{
	CCerasusUnit* pTextureNode = new CCerasusUnit(m_pD3D9Device);

	if (pTextureNode == NULL)
	{
		return -1;
	}

	HRESULT hr = pTextureNode->CCerasusUnitInit(sUnit);
	if (FAILED(hr))
	{
		return -2;
	}

	int nTexture = 0;

	m_pTextureCache.push_back(pTextureNode);
	nTexture = m_pTextureCache.size() - 1;

	return nTexture;
}
