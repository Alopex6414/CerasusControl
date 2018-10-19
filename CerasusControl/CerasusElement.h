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
	UINT m_nTexIndex;						// CCerasusElement 纹理序号
	UINT m_nFontIndex;						// CCerasusElement 字体序号

public:
	CCerasusUnit*	m_pTexElement;			// CCerasusElement 纹理图形(3D图元)
	DirectFont*		m_pFontElement;			// CCerasusElement 字体绘制

public:
	CCerasusElement(IDirect3DDevice9* pD3D9Device);			// CCerasusElement 构造函数
	~CCerasusElement();										// CCerasusElement 析构函数

	// 访问
	CCerasusUnit*	CCerasusElementGetTexElement();			// CCerasusElement 获取纹理图形元素
	DirectFont*		CCerasusElementGetFontElement();		// CCerasusElement 获取字体绘制元素

	// 控制
	void CCerasusElementSetTexElement(CCerasusUnit* pTexElement);			// CCerasusElement 设置纹理图形元素
	void CCerasusElementSetFontElement(DirectFont* pFontElement);			// CCerasusElement 设置字体绘制元素

	// 方法
	void CCerasusElementTexElementInit(UINT nIndex, CUUint sUnit);									// CCerasusElement 初始化纹理图形元素
	void CCerasusElementFontElementInit(UINT nIndex, int nFontSize, LPWSTR lpszFontType);			// CCerasusElement 初始化字体绘制元素

};

#endif // !__CERASUSELEMENT_H_

