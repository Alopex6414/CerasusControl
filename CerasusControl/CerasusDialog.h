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
class CCerasusDialog
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

	int m_nDefaultControlID;			// CCerasusDialog ����Ĭ�Ͽؼ�ID

	static double s_fTimeRefresh;		// CCerasusDialog ����ˢ��ʱ��
	double m_fTimeLastRefresh;			// CCerasusDialog �����ϴ�ˢ��ʱ��

	static CCerasusControl* s_pControlFocus;		// CCerasusDialog ��ý���ؼ�
	static CCerasusControl* s_pControlPressed;      // CCerasusDialog ��ǰ���¿ؼ�

	CCerasusControl* m_pControlMouseOver;           // CCerasusDialog ��ǰ��ͣ�ؼ�

private:
	CCerasusResourceManager* m_pManager;			// CCerasusDialog ������Դ������
	LPCALLBACKCERASUSGUIEVENT m_pCallbackEvent;		// CCerasusDialog �����¼��ص�����
	void* m_pCallbackEventUserContext;				// CCerasusDialog �����¼��ص��û�����

	vector<int> m_vecTextures;			// CCerasusDialog ��������
	vector<int> m_vecFonts;				// CCerasusDialog ��������

	vector<CCerasusControl*> m_vecControls;			// CCerasusDialog ���ڿؼ�����
	//vector<DXUTElementHolder*> m_DefaultElements;

	//CCerasusElement m_CapElement;		// CCerasusDialog ����Ԫ��

	CCerasusDialog* m_pNextDialog;		// CCerasusDialog ��һ������ָ��
	CCerasusDialog* m_pPrevDialog;		// CCerasusDialog ��һ������ָ��

public:
	bool m_bNonUserEvents;				// CCerasusDialog �û��¼���־
	bool m_bKeyboardInput;				// CCerasusDialog ���������־
	bool m_bMouseInput;					// CCerasusDialog ��������־

public:
	CCerasusDialog();					// CCerasusDialog ���캯��
	~CCerasusDialog();					// CCerasusDialog ��������

	void	RemoveAllControls();		// CCerasusDialog �Ƴ����пؼ�

};


#endif // !__CERASUSDIALOG_H_

