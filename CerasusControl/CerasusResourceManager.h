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
	LPDIRECT3DDEVICE9	m_pD3D9Device;				// D3D9��Ⱦ�豸

protected:
	DirectSprite*		m_pSprite;					// D3DX�㾫��

protected:
	vector<DirectFont*>		m_pFontCache;			// ��Ⱦ����
	vector<CCerasusUnit*>	m_pTextureCache;		// ��Ⱦ����

public:
	CCerasusResourceManager(LPDIRECT3DDEVICE9 pD3D9Device);
	~CCerasusResourceManager();

	IDirect3DDevice9*		GetDevice()			const;			// ��ȡ�豸�ӿ�ָ��
	DirectSprite*			GetSprite()			const;			// ��ȡ����ӿ�ָ��
	vector<DirectFont*>		GetFontCache()		const;			// ��ȡ��Ⱦ��������
	vector<CCerasusUnit*>	GetTextureCache()	const;			// ��ȡ��Ⱦ��������

public:
	bool	MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	HRESULT	OnD3D9ResetDevice();					// �����豸
	HRESULT	OnD3D9LostDevice();						// ��ʧ�豸
	void	OnD3D9DestroyDevice();					// ɾ���豸

public:
	DirectFont*		GetFontNode(int nIndex);		// ��ȡ����ڵ�
	CCerasusUnit*	GetTextureNode(int nIndex);		// ��ȡ����ڵ�

	int		AddFont(LPWSTR strFontName, int nFontSize);			// �������(�������ơ������С)
	int		AddTexture(CUUint sUnit);							// �������(�ļ�����)
	int		AddTexture(CUUintEx sUnit);							// �������(�ڴ浼��)


};

#endif // !__CERASUSRESOURCEMANAGER_H_
