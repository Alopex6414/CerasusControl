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

// CreasusUI ��Ⱦ��Դ������(UI)

//------------------------------------------------------------------
// @Function:	 CCerasusResourceManager()
// @Purpose: CCerasusResourceManager���캯��
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
// @Purpose: CCerasusResourceManager��������
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusResourceManager::~CCerasusResourceManager()
{
	// �ڴ���������...

	// ����
	for (auto iter = m_pFontCache.begin(); iter != m_pFontCache.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_pFontCache.clear();

	// ����
	for (auto iter = m_pTextureCache.begin(); iter != m_pTextureCache.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_pTextureCache.clear();

}

//------------------------------------------------------------------
// @Function:	 MsgProc()
// @Purpose: CCerasusResourceManager��Ϣ��Ӧ����
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
// @Purpose: CCerasusResourceManager�������
// @Since: v1.00a
// @Para: LPWSTR strFontName	// ��������
// @Para: int nFontSize			// �����С
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
// @Purpose: CCerasusResourceManager�������
// @Since: v1.00a
// @Para: CUUint sUnit	// ����������
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
// @Purpose: CCerasusResourceManager�������
// @Since: v1.00a
// @Para: CUUintEx sUnit	// ����������
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
