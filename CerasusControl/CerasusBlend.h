/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusBlend.h
* @brief	This File is CerasusBlend DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-19	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CERASUSBLEND_H_
#define __CERASUSBLEND_H_

//Include Direct Common Header File
#include "CerasusUICommon.h"

//Class Definition
class CCerasusBlendTex
{
public:
	CCerasusUnit* m_pTexStates[MAX_CONTROL_STATES];			// CCerasusBlendTex �ؼ�����ȫ��״̬
	CCerasusUnit* m_pTexCurrent;							// CCerasusBlendTex	�ؼ�����ǰ״̬

public:
	CCerasusBlendTex(IDirect3DDevice9* pD3D9Device);		// CCerasusBlendTex ���캯��
	~CCerasusBlendTex();									// CCerasusBlendTex ��������

	void	Init(CUUint sUnitArr[MAX_CONTROL_STATES]);		// CCerasusBlendTex ��ʼ���ؼ�����
	void	Init(CUUintEx sUnitArr[MAX_CONTROL_STATES]);	// CCerasusBlendTex ��ʼ���ؼ�����(����+1)
	void	Blend(UINT nState);								// CCerasusBlendTex ��Ⱦ�ؼ�����

};



#endif // !__CERASUSBLEND_H_
