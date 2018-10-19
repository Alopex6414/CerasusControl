/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusElement.h
* @brief	This File is CerasusElement DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-16	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CERASUSELEMENT_H_
#define __CERASUSELEMENT_H_

//Include Direct Common Header File
#include "CerasusUICommon.h"

//Class Definition
class CCerasusElement
{
public:
	UINT m_nTexIndex;						// CCerasusElement �������
	UINT m_nFontIndex;						// CCerasusElement �������

public:
	CCerasusUnit*	m_pTexElement;			// CCerasusElement ����ͼ��(3DͼԪ)
	DirectFont*		m_pFontElement;			// CCerasusElement �������

public:
	CCerasusElement(IDirect3DDevice9* pD3D9Device);			// CCerasusElement ���캯��
	~CCerasusElement();										// CCerasusElement ��������

	// ����
	CCerasusUnit*	CCerasusElementGetTexElement();			// CCerasusElement ��ȡ����ͼ��Ԫ��
	DirectFont*		CCerasusElementGetFontElement();		// CCerasusElement ��ȡ�������Ԫ��

	// ����
	void CCerasusElementSetTexElement(CCerasusUnit* pTexElement);			// CCerasusElement ��������ͼ��Ԫ��
	void CCerasusElementSetFontElement(DirectFont* pFontElement);			// CCerasusElement �����������Ԫ��

	// ����
	void CCerasusElementTexElementInit(UINT nIndex, CUUint sUnit);									// CCerasusElement ��ʼ������ͼ��Ԫ��
	void CCerasusElementFontElementInit(UINT nIndex, int nFontSize, LPWSTR lpszFontType);			// CCerasusElement ��ʼ���������Ԫ��

};

#endif // !__CERASUSELEMENT_H_

