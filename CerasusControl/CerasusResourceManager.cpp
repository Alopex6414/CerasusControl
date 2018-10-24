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
	m_pSprite = NULL;

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

	// ����
	SAFE_DELETE(m_pSprite);
}

//------------------------------------------------------------------
// @Function:	 GetDevice()
// @Purpose: CCerasusResourceManager��ȡ�豸�ӿ�ָ��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
IDirect3DDevice9 * CCerasusResourceManager::GetDevice() const
{
	return m_pD3D9Device;
}

//------------------------------------------------------------------
// @Function:	 GetSprite()
// @Purpose: CCerasusResourceManager��ȡ����ӿ�ָ��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectSprite * CCerasusResourceManager::GetSprite() const
{
	return m_pSprite;
}

//------------------------------------------------------------------
// @Function:	 GetFontCache()
// @Purpose: CCerasusResourceManager��ȡ��Ⱦ����ӿ�ָ��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
vector<DirectFont*> CCerasusResourceManager::GetFontCache() const
{
	return m_pFontCache;
}

//------------------------------------------------------------------
// @Function:	 GetTextureCache()
// @Purpose: CCerasusResourceManager��ȡ��Ⱦ����ӿ�ָ��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
vector<CCerasusUnit*> CCerasusResourceManager::GetTextureCache() const
{
	return m_pTextureCache;
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
// @Function:	 OnD3D9ResetDevice()
// @Purpose: CCerasusResourceManager��ӦD3D9���������豸
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
HRESULT CCerasusResourceManager::OnD3D9ResetDevice()
{
	for (auto iter = m_pFontCache.begin(); iter != m_pFontCache.end(); ++iter)
	{
		VERIFY((*iter)->DirectFontGetFont()->OnResetDevice());
	}

	return S_OK;
}

//------------------------------------------------------------------
// @Function:	 OnD3D9ResetDevice()
// @Purpose: CCerasusResourceManager��ӦD3D9���嶪ʧ�豸
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
HRESULT CCerasusResourceManager::OnD3D9LostDevice()
{
	for (auto iter = m_pFontCache.begin(); iter != m_pFontCache.end(); ++iter)
	{
		VERIFY((*iter)->DirectFontReset());
	}

	for (auto iter = m_pTextureCache.begin(); iter != m_pTextureCache.end(); ++iter)
	{
		VERIFY((*iter)->CCerasusUnitReset());
	}

	return S_OK;
}

//------------------------------------------------------------------
// @Function:	 OnD3D9ResetDevice()
// @Purpose: CCerasusResourceManager��ӦD3D9����ɾ���豸
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CCerasusResourceManager::OnD3D9DestroyDevice()
{
	for (auto iter = m_pFontCache.begin(); iter != m_pFontCache.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_pFontCache.clear();

	for (auto iter = m_pTextureCache.begin(); iter != m_pTextureCache.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_pTextureCache.clear();

}

//------------------------------------------------------------------
// @Function:	 GetFontNode()
// @Purpose: CCerasusResourceManager��ȡ����ڵ�
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectFont * CCerasusResourceManager::GetFontNode(int nIndex)
{
	return m_pFontCache[nIndex];
}

//------------------------------------------------------------------
// @Function:	 GetTextureNode()
// @Purpose: CCerasusResourceManager��ȡ����ڵ�
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusUnit * CCerasusResourceManager::GetTextureNode(int nIndex)
{
	return m_pTextureCache[nIndex];
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
