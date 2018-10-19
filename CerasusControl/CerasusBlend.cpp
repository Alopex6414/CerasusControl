/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusBlend.cpp
* @brief	This File is CerasusBlend DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-19	v1.00a	alopex	Create Project.
*/
#include "CerasusBlend.h"

// CreasusUI 渲染单元(UI)

//------------------------------------------------------------------
// @Function:	 CCerasusBlendTex()
// @Purpose: CCerasusBlendTex构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusBlendTex::CCerasusBlendTex(IDirect3DDevice9* pD3D9Device)
{
	for (int i = 0; i < MAX_CONTROL_STATES; ++i)
	{
		m_pTexStates[i] = new CCerasusUnit(pD3D9Device);
	}

	m_pTexCurrent = m_pTexStates[CERASUS_STATE_NORMAL];
}

//------------------------------------------------------------------
// @Function:	 ~CCerasusBlendTex()
// @Purpose: CCerasusBlendTex析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusBlendTex::~CCerasusBlendTex()
{
	for (int i = 0; i < MAX_CONTROL_STATES; ++i)
	{
		SAFE_DELETE(m_pTexStates[i]);
	}

	m_pTexCurrent = NULL;
}

//------------------------------------------------------------------
// @Function:	 Init()
// @Purpose: CCerasusBlendTex初始化控件纹理
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CCerasusBlendTex::Init(CUUint sUnitArr[MAX_CONTROL_STATES])
{
	for (int i = 0; i < MAX_CONTROL_STATES; ++i)
	{
		m_pTexStates[i]->CCerasusUnitInit(sUnitArr[i]);
	}

}

//------------------------------------------------------------------
// @Function:	 Init()
// @Purpose: CCerasusBlendTex初始化控件纹理
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CCerasusBlendTex::Init(CUUintEx sUnitArr[MAX_CONTROL_STATES])
{
	for (int i = 0; i < MAX_CONTROL_STATES; ++i)
	{
		m_pTexStates[i]->CCerasusUnitInit(sUnitArr[i]);
	}

}

//------------------------------------------------------------------
// @Function:	 Blend()
// @Purpose: CCerasusBlendTex渲染控件纹理
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CCerasusBlendTex::Blend(UINT nState)
{
	m_pTexCurrent = m_pTexStates[nState];

	m_pTexCurrent->CCerasusUnitPaddingVertexAndIndex();		// 填充缓冲
	m_pTexCurrent->CCerasusUnitMatrixTransform();			// 矩阵变换
	m_pTexCurrent->CCerasusUnitSetAlphaBlendEnable();		// 开启Alpha缓冲
	m_pTexCurrent->CCerasusUnitSetRenderState();			// 设置渲染状态
	m_pTexCurrent->CCerasusUnitRender();					// 渲染图形
	m_pTexCurrent->CCerasusUnitSetAlphaBlendDisable();		// 关闭Alpha缓冲
}
