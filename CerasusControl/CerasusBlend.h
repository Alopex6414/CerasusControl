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
	CCerasusUnit* m_pTexStates[MAX_CONTROL_STATES];			// CCerasusBlendTex 控件纹理全部状态
	CCerasusUnit* m_pTexCurrent;							// CCerasusBlendTex	控件纹理当前状态

public:
	CCerasusBlendTex(IDirect3DDevice9* pD3D9Device);		// CCerasusBlendTex 构造函数
	~CCerasusBlendTex();									// CCerasusBlendTex 析构函数

	void	Init(CUUint sUnitArr[MAX_CONTROL_STATES]);		// CCerasusBlendTex 初始化控件纹理
	void	Init(CUUintEx sUnitArr[MAX_CONTROL_STATES]);	// CCerasusBlendTex 初始化控件纹理(重载+1)
	void	Blend(UINT nState);								// CCerasusBlendTex 渲染控件纹理

};



#endif // !__CERASUSBLEND_H_
