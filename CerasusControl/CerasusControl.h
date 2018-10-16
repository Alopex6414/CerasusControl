/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CreasusControl.h
* @brief	This File is CreasusControl DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-16	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __CREASUSCONTROL_H_
#define __CREASUSCONTROL_H_

//Include Direct Common Header File
#include "DirectCommon.h"
#include "DirectGraphics3D.h"
#include "DirectThreadSafe.h"

#include "CerasusUICommon.h"
#include "CerasusUnit.h"

//Macro Definition
#ifdef	CERASUSCONTROL_EXPORTS
#define CERASUSCONTROL_API	__declspec(dllexport)
#else
#define CERASUSCONTROL_API	__declspec(dllimport)
#endif

#define CERASUSCONTROL_CALLMODE	__stdcall

//Class Definition
class CERASUSCONTROL_API CCerasusControl
{
private:
	int m_nX;					// CCerasusControl �ؼ�X����
	int m_nY;					// CCerasusControl �ؼ�Y����
	int m_nWidth;				// CCerasusControl �ؼ����
	int m_nHeight;				// CCerasusControl �ؼ��߶�

	bool m_bVisible;			// CCerasusControl �ؼ��Ƿ�ɼ�(true:��ʾ/false:����)
	bool m_bMouseOver;			// CCerasusControl ���ָ���ڿؼ���(true:��/false:��)
	bool m_bHasFocus;			// CCerasusControl �ؼ��Ƿ�ӵ�����뽹��(true:��/false:��)
	bool m_bIsDefault;			// CCerasusControl �ؼ��Ƿ���Ĭ�Ͽؼ�(true:��/false:��)

	//CDXUTDialog* m_pDialog;    // CCerasusControl Parent container
	UINT m_nIndex;              // CCerasusControl �ؼ��б��пؼ�����

protected:
	int m_nID;						// CCerasusControl �ؼ����
	CERASUS_CONTROL_TYPE m_eType;	// CCerasusControl �ؼ�����

	UINT m_nHotkey;					// CCerasusControl ���ⰴ������
	LPVOID m_pUserData;				// CCerasusControl �û����ݵ�ַ

	bool m_bEnabled;				// CCerasusControl �ؼ��Ƿ�ʹ��(true:��/false:��)
	RECT m_rcBoundingBox;			// CCerasusControl �ؼ�ʹ������

public:
	CCerasusControl();				// CCerasusControl ���캯��
	virtual ~CCerasusControl();		// CCerasusControl ��������

	virtual HRESULT CERASUSCONTROL_CALLMODE OnInit();					// CCerasusControl ��ʼ���ؼ�
	virtual void	CERASUSCONTROL_CALLMODE Refresh();					// CCerasusControl ˢ�¿ؼ�
	virtual void	CERASUSCONTROL_CALLMODE Render();					// CCerasusControl ��Ⱦ�ؼ�

	virtual bool	CERASUSCONTROL_CALLMODE MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);			// CCerasusControl ��Ϣ����
	virtual bool	CERASUSCONTROL_CALLMODE HandleKeyboard(UINT uMsg, WPARAM wParam, LPARAM lParam);	// CCerasusControl ������Ϣ����
	virtual bool	CERASUSCONTROL_CALLMODE HandleMouse(UINT uMsg, WPARAM wParam, LPARAM lParam);		// CCerasusControl �����Ϣ����

	virtual bool	CERASUSCONTROL_CALLMODE	CanHaveFocus();				// CCerasusControl �Ƿ�ӵ�н���
	virtual void	CERASUSCONTROL_CALLMODE	OnFocusIn();				// CCerasusControl ���ý���
	virtual void	CERASUSCONTROL_CALLMODE	OnFocusOut();				// CCerasusControl ��ʧ����
	virtual void	CERASUSCONTROL_CALLMODE	OnMouseEnter();				// CCerasusControl ������
	virtual void	CERASUSCONTROL_CALLMODE OnMouseLeave();				// CCerasusControl ����뿪
	virtual void	CERASUSCONTROL_CALLMODE OnHotkey();					// CCerasusControl ����ȼ�
	virtual BOOL	CERASUSCONTROL_CALLMODE ContainsPoint(POINT pt);	// CCerasusControl ������ڿؼ���
	virtual void	CERASUSCONTROL_CALLMODE SetEnabled(bool bEnabled);	// CCerasusControl ���ÿؼ�ʹ��
	virtual bool	CERASUSCONTROL_CALLMODE GetEnabled();				// CCerasusControl ��ȡ�ؼ�ʹ��

};


#endif // !__CREASUSCONTROL_H_

