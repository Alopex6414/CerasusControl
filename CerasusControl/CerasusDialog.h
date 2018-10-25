/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusDialog.h
* @brief	This File is CerasusDialog DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-24	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CERASUSDIALOG_H_
#define __CERASUSDIALOG_H_

//Include Direct Common Header File
#include "CerasusUICommon.h"
#include "CerasusResourceManager.h"

//Macro Definition
#ifdef	CERASUSCONTROL_EXPORTS
#define CERASUSDIALOG_API	__declspec(dllexport)
#else
#define CERASUSDIALOG_API	__declspec(dllimport)
#endif

#define CERASUSDIALOG_CALLMETHOD	__stdcall

//Class Definition
class CERASUSDIALOG_API CCerasusDialog
{
	friend class CCerasusResourceManager;

private:
	int m_nX;			// CCerasusDialog ����X������
	int m_nY;			// CCerasusDialog ����Y������
	int m_nWidth;		// CCerasusDialog ���ڿ��
	int m_nHeight;		// CCerasusDialog ���ڸ߶�

public:
	CCerasusDialog();
	~CCerasusDialog();



};


#endif // !__CERASUSDIALOG_H_

