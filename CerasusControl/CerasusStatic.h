/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusStatic.h
* @brief	This File is CerasusStatic DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-19	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CERASUSSTATIC_H_
#define __CERASUSSTATIC_H_

//Include CerasusUI Common Header File
#include "CerasusUICommon.h"
#include "CerasusControl.h"

//Macro Definition
#ifdef	CERASUSCONTROL_EXPORTS
#define CERASUSSTATIC_API	__declspec(dllexport)
#else
#define CERASUSSTATIC_API	__declspec(dllimport)
#endif

#define CERASUSSTATIC_CALLMODE	__stdcall

//Class Definition
class CCerasusStatic : public CCerasusControl
{
protected:
	WCHAR m_strText[MAX_PATH];			// CCerasusStatic 静态控件文本

public:
	CCerasusStatic(CCerasusDialog* pDialog = NULL);							// CCerasusStatic 构造函数

	virtual void	CERASUSSTATIC_CALLMODE Render(float fElapsedTime);		// CCerasusStatic 渲染控件
	virtual BOOL	CERASUSSTATIC_CALLMODE ContainsPoint(POINT pt);			// CCerasusStatic 鼠标落在控件内

	HRESULT         CERASUSSTATIC_CALLMODE GetTextCopy(__out_ecount(bufferCount) LPWSTR strDest, UINT bufferCount);			// CCerasusStatic 获取文本拷贝

	LPCWSTR			CERASUSSTATIC_CALLMODE GetText();						// CCerasusStatic 获取当前文本
	HRESULT			CERASUSSTATIC_CALLMODE SetText(LPCWSTR strText);		// CCerasusStatic 设置当前文本

};



#endif // !__CERASUSSTATIC_H_
