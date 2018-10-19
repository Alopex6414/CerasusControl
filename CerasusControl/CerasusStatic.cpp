/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CerasusStatic.cpp
* @brief	This File is CerasusStatic DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-10-19	v1.00a	alopex	Create Project.
*/
#include "CerasusStatic.h"

// CreasusUI ��̬�ؼ�(CCerasusStatic)

//------------------------------------------------------------------
// @Function:	 CCerasusStatic()
// @Purpose: CCerasusStatic���캯��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CCerasusStatic::CCerasusStatic()
{
	m_eType = CERASUS_CONTROL_STATIC;

	ZeroMemory(m_strText, sizeof(m_strText));

}

//------------------------------------------------------------------
// @Function:	 Render()
// @Purpose: CCerasusStatic��Ⱦ�ؼ�
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CERASUSSTATIC_CALLMODE CCerasusStatic::Render()
{
	
}

//------------------------------------------------------------------
// @Function:	 ContainsPoint()
// @Purpose: CCerasusStatic������ڿؼ���
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL CERASUSSTATIC_CALLMODE CCerasusStatic::ContainsPoint(POINT pt)
{
	return FALSE;
}
