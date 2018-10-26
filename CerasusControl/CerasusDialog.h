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
#include "CerasusControl.h"

//Macro Definition
#ifdef	CERASUSCONTROL_EXPORTS
#define CERASUSDIALOG_API	__declspec(dllexport)
#else
#define CERASUSDIALOG_API	__declspec(dllimport)
#endif

#define CERASUSDIALOG_CALLMETHOD	__stdcall

//Function Declaration
typedef VOID(CALLBACK*LPCALLBACKCERASUSGUIEVENT)(UINT nEvent, int nControlID, CCerasusControl* pControl, void* pUserContext);

//Class Definition
class CERASUSDIALOG_API CCerasusDialog
{
	friend class CCerasusResourceManager;

private:
	int	m_nX;					// CCerasusDialog ����X������
	int m_nY;					// CCerasusDialog ����Y������
	int m_nWidth;				// CCerasusDialog ���ڿ��
	int m_nHeight;				// CCerasusDialog ���ڸ߶�
	int m_nCaptionHeight;		// CCerasusDialog ���ڱ���߶�

	bool	m_bVisible;			// CCerasusDialog ���ڿɼ�
	bool	m_bCaption;			// CCerasusDialog ���ڱ������϶�
	bool	m_bMinimized;		// CCerasusDialog ������С��
	bool	m_bDrag;			// CCerasusDialog ������ק

	WCHAR	m_wszCaption[256];	// CCerasusDialog ���ڱ�������

	D3DCOLOR	m_colorTopLeft;			// CCerasusDialog �������ϽǶ�����ɫ
	D3DCOLOR	m_colorTopRight;		// CCerasusDialog �������ϽǶ�����ɫ
	D3DCOLOR	m_colorBottomLeft;		// CCerasusDialog �������½Ƕ�����ɫ
	D3DCOLOR	m_colorBottomRight;		// CCerasusDialog �������½Ƕ�����ɫ

	static double s_fTimeRefresh;		// CCerasusDialog ����ˢ��ʱ��
	double m_fTimeLastRefresh;			// CCerasusDialog �����ϴ�ˢ��ʱ��

private:
	CCerasusResourceManager* m_pManager;			// CCerasusDialog ������Դ������
	LPCALLBACKCERASUSGUIEVENT m_pCallbackEvent;		// CCerasusDialog �����¼��ص�����
	void* m_pCallbackEventUserContext;				// CCerasusDialog �����¼��ص��û�����

public:
	CCerasusDialog();
	~CCerasusDialog();



};


#endif // !__CERASUSDIALOG_H_

