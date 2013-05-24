/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   XLUEExternalObj
*   Author      :   xlue group(xlue@xunlei.com)
*   Create      :   2013-5-16 16:01
*   LastChange  :   2013-5-16 16:01
*   History     :	
*
*   Description :   XLUE��ģ���������ݽṹ����
*
********************************************************************/ 
#ifndef __XLUEDEFINE_H__
#define __XLUEDEFINE_H__

#include "./XLUEHandle.h"
#include <XLLuaRuntime.h>
#include <XLGraphic.h>

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

typedef void* OS_HOSTWND_HANDLE;

typedef enum __CtrlTestType
{
	CtrlTestType_none = 0,
	CtrlTestType_top = 1,
	CtrlTestType_bottom = 2,
	CtrlTestType_left = 3,
	CtrlTestType_right = 4,
	CtrlTestType_topleft = 5,
	CtrlTestType_topright = 6,
	CtrlTestType_bottomleft = 7,
	CtrlTestType_bottomright = 8,
	CtrlTestType_caption = 9

}CtrlTestType;

typedef enum __ObjWantKey
{
	ObjWantKey_None  = 0x00,		// ����Ҫ�κμ�
	ObjWantKey_Tab	 = 0x01,		// ��Ҫ����tab��
	ObjWantKey_Arrow = 0x02			// ��Ҫ�������򵼺���
}ObjWantKey;

// Ԫ���󽹵����
typedef enum __FocusStrategy
{
	FocusStrategy_fuzzy = 0,	// Ĭ�ϲ��ԣ���ȥ�����ж϶����費��Ҫ���㣬ֻҪ��������ͻᱻ���ý��㣬���������ض����յ��ģ���ģ������
	FocusStrategy_auto = 1		// ���ܽ�����ԣ��������û�йҽӼ����¼������߲���edit��flash��Ԫ������ô�����Ĭ�ϲ����ý���
}FocusStrategy;

// Ԫ���󽹵�ԭ��
typedef enum __FocusReason
{
	FocusReason_system = 1,		// ϵͳ�ڲ������Ľ���ı�
	FocusReason_user = 2,		// �û���ʾ����SetFocus���µĽ���ı�
	FocusReason_tab = 3			// �û�ʹ��tab�ͷ�����������µĽ���ı�
}FocusReason;

//centre mode
typedef enum tagAngleChangeAniCentreMode
{	
	LeftTopCoordinate = 0,//������Ϊ0,0�ľ�������
	WidthHeightRate = 1,//���볤���ı�����ʾ����

}AngleChangeAniCentreMode;

//position mode
typedef enum tagAngleChangeAniPositionMode
{
	CentreStay = 0,

}AngleChangeAniPositionMode;

//size limit mode
typedef enum tagAngleChangeAniSizeLimitMode
{
	NoLimit = 0,
	SourceObjectSize = 1,

}AngleChangeAniSizeLimitMode;

//turn object flag
typedef enum tagTurnObjectFlag
{
	RoundX = 0,
	RoundY = 1,

	Deasil = 10,
	Widdershins = 11,

	EffectNormal = 21,
	EffectBlur = 22,

}TurnObjectFlag;

typedef enum tagCmdShow
{
	CS_SW_HIDE = 0,
	CS_SW_SHOWNORMAL = 1,
	CS_SW_SHOWMINIMIZED = 2,
	CS_SW_SHOWMAXIMIZED = 3,
	CS_SW_SHOWNOACTIVATE = 4,
	CS_SW_SHOW = 5,
	CS_SW_MINIMIZE = 6,
	CS_SW_SHOWMINNOACTIVE = 7,
	CS_SW_SHOWNA = 8,
	CS_SW_RESTORE = 9,
	CS_SW_SHOWDEFAULT = 10,
	CS_SW_FORCEMINIMIZE = 11
}CMDSHOW, *LPCMDSHOW;

// ��չԪ���������
typedef enum __ExtObjType
{
	ExtObjType_layoutObj = 0,		// ��չĿ�����ΪLayoutObject��Ĭ��Ϊ������Ⱦ����
	ExtObjType_renderableObj = 1,	// ��չĿ�����ΪLayoutObject��Ĭ�Ͽ���Ⱦ
	ExtObjType_imageObj= 2,			// ��չĿ�����ΪImageObject
	ExtObjType_realObj = 3			// ��չ����Ϊʵ���ڶ��󣬱���WebBrowseObject

}ExtObjType;

// ��չԪ����Ԥע�������
typedef enum __ExtObjPreRegisterType
{
	ExtObjPreRegisterType_module = 0,		// dll+�����ӿڵ���ʽ
	ExtObjPreRegisterType_callBack = 1		// �ص���������ʽ

}ExtObjPreRegisterType;

// �����ϵ��Ϸ��¼�����
typedef enum __DragEventType
{
	DragEventType_query = 0,
	DragEventType_enter = 1,
	DragEventType_over = 2,
	DragEventType_leave = 3,
	DragEventType_drop = 4

}DragEventType;

typedef BOOL (XLUE_STDCALL *LPFNREGISTEREXTOBJCALLBACK)(const char* lpObjClass);

// ��չԪ�����Ԥע��ṹ�壬����ʵ�ְ�����غͳ�ʼ��ָ������չԪ����
typedef struct __ExtObjPreRegisterInfo
{
	// �ṹ��Ĵ�С
	size_t size;

	// Ԥע�����
	ExtObjPreRegisterType type;

	// Ԫ�����class�����ܺ�����Ԫ����class�ظ�
	const char* className;

	// moduleģʽ�µĲ���
	// ��ʼ������չԪ����ʱ�򣬻��ȼ���lpModulePathָ�����ļ���Ȼ����ø�module�ϵ�lpInitFuncName�����������г�ʼ��
	// lpInitFuncName����������ǩ��ʽ�����LPFNREGISTEREXTOBJCALLBACKһ��; ����TRUE��ʶ��Ԫ��������ע��ɹ�
	const wchar_t* lpModulePath;
	const char* lpInitFuncName;

	// callbackģʽ�µĲ���
	// ��ʼ������չԪ����ʱ�򣬻��ȵ��øú���������TRUE��ʶ��Ԫ��������ע��ɹ�
	LPFNREGISTEREXTOBJCALLBACK lpRegisterCallBack;

}ExtObjPreRegisterInfo;

// ��չԪ����Ĵ��������ٹ����ص�
typedef struct __ExtObjCreator
{
	// �ṹ��Ĵ�С
	size_t size;

	// �û��Զ������ݣ���Ϊ�ص�������һ������
	void* userData;

	// ������չԪ������ⲿʵ��������ɹ��򷵻�һ��handle����Ψһ��ʶ
	void* (XLUE_STDCALL *lpfnCreateObj)(void* userData, const char* lpObjClass, XLUE_LAYOUTOBJ_HANDLE hObj);

	// ������չԪ������ⲿʵ����objHandleΪ����ʱ�򷵻ص�handle
	void (XLUE_STDCALL *lpfnDestroyObj)(void* userData, void* objHandle);

}ExtObjCreator;

// ������LayoutObject����ط�������
typedef struct __ExtLayoutObjMethodsVector
{
	// �ṹ��Ĵ�С
	size_t size;

	// �ö����Ƿ����չ��������ֶ�Ϊ�գ���ôExternalObjType=ExternalObjType_renderableʱ�����Ϊ�ö������Ⱦ
	// ������ݸûص������ķ���ֵ�������Ƿ������Ⱦ
	// ����һ������Ⱦ������Ҫ����ʱ������OnPaint/OnPaintEx�ص�
	BOOL (XLUE_STDCALL *lpfnIsRenderable)(void* userData, void* objHandle);

	// Ԫ�����OnBind�¼�
	void (XLUE_STDCALL *lpfnOnBind)(void* userData, void* objHandle);

	// Ԫ�����OnInitControl�¼�
	void (XLUE_STDCALL *lpfnOnInitControl)(void* userData, void* objHandle);

	// Ԫ�����OnDestroy�¼�
	void (XLUE_STDCALL *lpfnOnDestroy)(void* userData, void* objHandle);

	BOOL (XLUE_STDCALL *lpfnOnHitTest)(void* userData, void* objHandle, short x, short y);

	BOOL (XLUE_STDCALL *lpfnOnCtrlHitTest)(void* userData, void* objHandle, short x, short y, CtrlTestType& type);

	const char* (XLUE_STDCALL *lpfnGetCursorID)(void* userData, void* objHandle, long x, long y, unsigned long wParam, unsigned long lParam);

	// ��ȡ��ǰ����Թ����������򣬻��ڶ���������ϵ
	void (XLUE_STDCALL *lpfnGetCaretLimitRect)(void* userData, void* objHandle, RECT* lpLimitRect);

	// �ж϶���������Ҫ������Щ��������Ҫ������������tab��
	// Ĭ�ϲ�����tab�͵�����
	int (XLUE_STDCALL *lpfnOnGetWantKey)(void* userData, void* objHandle);

	// �ж϶����Ƿ���Ҫ���ñ�������,����0��ʾ����Ҫ����0��ʾ��Ҫ
	// Ĭ��ȡ���ڶ���Ľ�����ԣ�ģ�����������ֻҪ�ҽ�����һ�����̺�����¼�����Խ��ս���
	// ���ܽ�������£�ֻ�йҽ���������taborder������¼�������¼��ض��򣬲ſ��Խ��ս���
	int (XLUE_STDCALL *lpfnOnQueryFocus)(void* userData, void* objHandle);

	// ����Ľ���״�������ı�
	void (XLUE_STDCALL *lpfnOnSetFocus)(void* userData, void* objHandle, BOOL bFocus, XLUE_LAYOUTOBJ_HANDLE hOppositeObj, FocusReason reason);

	// ����Ŀؼ�����״̬�����ı�
	void (XLUE_STDCALL *lpfnOnSetControlFocus)(void* userData, void* objHandle, BOOL bFocus,XLUE_LAYOUTOBJ_HANDLE hOppositeObj, FocusReason reason);

	// ����Ŀؼ�����¼�������enter/leave/wheel��
	void (XLUE_STDCALL *lpfnOnControlMouseEnter)(void* userData, void* objHandle, short x, short y, unsigned long flags);
	void (XLUE_STDCALL *lpfnOnControlMouseLeave)(void* userData, void* objHandle, short x, short y, unsigned long flags);
	void (XLUE_STDCALL *lpfnOnControlMouseWheel)(void* userData, void* objHandle, short x, short y, unsigned long flags);

	// �����style�����仯��ֻ��control��Ч
	void (XLUE_STDCALL *lpfnOnStyleUpdate)(void* userData, void* objHandle);

	// �������������Ļ��ƺ�����OnPaint���Բ�����mask�Ļ��ƣ�OnPaintEx�ǹ���mask�Ļ��ƣ�ʹ������������Щ
	// �ڶ�����OnPaintEx������£�����ʹ�øú���

	// ���ƶ����lpSrcClipRect����Ŀ��λͼ��lpDestClipRect��lpDestClipRect��С��lpSrcClipRect��Сһ��
	// lpDestClipRect�ǻ���Ŀ��λͼ����ϵ�ģ�Ҳ�������Ŀ��λͼ��(0,0)λ��
	// lpSrcClipRect�ǻ���Ԫ��������ϵ�ģ�Ҳ������ڸö�������Ͻ�λ��
	// hBitmapDest�п���Clip��������λͼ�������ڴ治һ���������ģ���ȡĳһ�е�buffer����ʹ��XL_GetBitmapBuffer
	void (XLUE_STDCALL *lpfnOnPaint)(void* userData, void* objHandle, XL_BITMAP_HANDLE hBitmapDest, const RECT* lpDestClipRect, const RECT* lpSrcClipRect, unsigned char alpha);
	void (XLUE_STDCALL *lpfnOnPaintEx)(void* userData, void* objHandle, XL_BITMAP_HANDLE hBitmapDest, const RECT* lpDestClipRect, const RECT* lpSrcClipRect, unsigned char alpha, XLGraphicHint* lpHint);


	// �����λ�øı��¼������ڶ�����������ϵ
	void (XLUE_STDCALL *lpfnOnPosChanged)(void* userData, void* objHandle, const RECT* lpOldPos, const RECT* lpNewPos);

	// ����ľ���λ�øı��¼������ڶ���������ϵ��ֻ�б��󶨵�UIObjectTree����¼��Żᱻ����
	void (XLUE_STDCALL *lpfnOnAbsPosChanged)(void* userData, void* objHandle, const RECT* lpOldAbsPos, const RECT* lpNewAbsPos);

	// �����ֱ�ӻ��߼�Ӹ�����ľ���λ�÷����ı䣬 ����Ӷ��������������limitrect�������ô��Ҫ��Ӧ���¼�������
	void (XLUE_STDCALL *lpfnOnFatherAbsPosChanged)(void* userData, void* objHandle);

	// ����Ŀɼ�״̬�����ı�
	void (XLUE_STDCALL *lpfnOnVisibleChange)(void* userData, void* objHandle, BOOL bVisible);

	// �����enable״̬�����ı�
	void (XLUE_STDCALL *lpfnOnEnableChange)(void* userData, void* objHandle, BOOL bEnable);

	// �����capture״̬�����ı�
	void (XLUE_STDCALL *lpfnOnCaptureChange)(void* userData, void* objHandle, BOOL bCapture);
	
	// �����zorder�����ı�
	void (XLUE_STDCALL *lpfnOnZOrderChange)(void* userData, void* objHandle);

	// �����alpha�����ı�
	void (XLUE_STDCALL *lpfnOnAlphaChange)(void* userData, void* objHandle, unsigned char newAlpha, unsigned char oldAlpha);

	// �����cursor�����ı�
	void (XLUE_STDCALL *lpfnOnCursorIDChange)(void* userData, void* objHandle);

	// �����resprovider�����ı�
	void (XLUE_STDCALL* lpfnOnResProviderChange)(void* userData, void* objHandle, XLUE_RESPROVIDER_HANDLE hResProvider);

	// ����󶨵�layer�����ı�
	void (XLUE_STDCALL* lpfnOnBindLayerChange)(void* userData, void* objHandle, XLUE_LAYOUTOBJ_HANDLE hNewLayerObject, XLUE_LAYOUTOBJ_HANDLE hOldLayerObject);

	// �����Ϸ��¼�
	// type = DragEventType_leaveʱ��lpDragDataObj��grfKeyState��pt����������Ч
	// ����TRUE��ʾ�Ѿ��������������תĬ�ϴ���
	BOOL (XLUE_STDCALL* lpfnOnDragEvent)(void* userData, void* objHandle, DragEventType type, void* lpDragDataObj, unsigned long grfKeyState, POINT pt, unsigned long* lpEffect);

	// ǰ���¼������������Դ������ͼ����¼������¼�·�ɵ��ʼ���ã�handled=true�������¼�·�ɵĺ�������
	long (XLUE_STDCALL *lpfnPreInputFilter)(void* userData, void* objHandle, unsigned long actionType, unsigned long wParam, unsigned long lParam, BOOL* lpHandled);
	
	// �����¼������������¼�·�ɵ����ʵ�ʵ���
	long (XLUE_STDCALL *lpfnPostInputFilter)(void* userData, void* objHandle, unsigned long actionType, unsigned long wParam, unsigned long lParam, BOOL* lpHandled);

	// Ԫ�������ڵĶ������󶨵�hostwnd�ʹ�hostwnd�����¼�
	void (XLUE_STDCALL *lpfnOnBindHostWnd)(void* userData, void* objHandle,XLUE_OBJTREE_HANDLE hTree, XLUE_HOSTWND_HANDLE hHostWnd, BOOL bBind);

	// Ԫ�������ڵĶ�������hostwnd�Ĵ����������¼�
	void (XLUE_STDCALL *lpfnOnCreateHostWnd)(void* userData, void* objHandle, XLUE_OBJTREE_HANDLE hTree, XLUE_HOSTWND_HANDLE hHostWnd, BOOL bCreate);
	
}ExtLayoutObjMethodsVector;

// ImageObject����ط�������
typedef struct __ExtImageObjMethodsVector
{
	// �ṹ��Ĵ�С
	size_t size;

}ExtImageObjMethodsVector;

// RealObject����ط�������
typedef struct __ExtRealObjMethodsVector
{
	// �ṹ��Ĵ�С
	size_t size;

	// ָʾ�������Ѿ�����/��Ҫ���٣��ⲿ��չ������Ҫ��������洴��/�����Լ���ϵͳ����,
	// ������XLUE_SetRealObjectWindow���õ�����RealObject�ϻ����Ƴ�
	void (XLUE_STDCALL *lpfnOnCreateRealWindow)(void* userData, void* objHandle, BOOL bCreate, OS_HOSTWND_HANDLE hWnd);

	// Real����Ԫ������¼���ָʾ���ý��㵽�Լ���ϵͳ������,�������Ƴ�����
	void (XLUE_STDCALL *lpfnOnSetRealFocus)(void* userData, void* objHandle, BOOL focus);

	// Real����Ԫ������¼�����ȡ��ǰ������ʾ���������ھ��
	OS_HOSTWND_HANDLE (XLUE_STDCALL *lpfnOnGetRenderWindow)(void* userData, void* objHandle);

}ExtRealObjMethodsVector;

// ExtObjType_layoutObj �� EExtObjType_renderableObj��Ҫ��methodsע�����
typedef struct __ExtLayoutObjMethods
{
	// �ṹ��Ĵ�С
	size_t size;

	// �û��Զ������ݣ���Ϊ�ص�������һ������
	void* userData;

	// ����LayoutObject�ķ���
	ExtLayoutObjMethodsVector layoutObjMethods;

}ExtLayoutObjMethods;

// ExtObjType_imageObj������չ������Ҫ�õ���methodsע�����
typedef struct __ExtImageObjMethods
{
	// �ṹ��Ĵ�С
	size_t size;

	// �û��Զ������ݣ���Ϊ�ص�������һ������
	void* userData;

	// ����LayoutObject�ķ���
	ExtLayoutObjMethodsVector layoutObjMethodVector;

	// ImageObject�����ķ���
	ExtImageObjMethodsVector imageObjMethodVector;

}ExtImageObjMethods;

// ExtObjType_realObj������չ������Ҫ�õ���methodsע�����
typedef struct __ExtRealObjMethods
{
	// �ṹ��Ĵ�С
	size_t size;

	// �û��Զ������ݣ���Ϊ�ص�������һ������
	void* userData;

	// ����LayoutObject�ķ���
	ExtLayoutObjMethodsVector layoutObjMethodVector;

	// ImageObject�����ķ���
	ExtRealObjMethodsVector realObjMethodVector;

}ExtRealObjMethods;

typedef struct __ExtObjParser
{
	// �ṹ��Ĵ�С
	size_t size;

	// �û��Զ������ݣ���Ϊ�ص�������һ������
	void* userData;

	// Ԫ�����xml�����б������¼�
	BOOL (XLUE_STDCALL *lpfnParserAttribute)(void* userData, void* objHandle, const char* key, const char* value);

	// Ԫ�����xml�¼��б������¼���Ϊ�ձ�ʾʹ�������ڲ���Ĭ���¼��������ԣ���չ��������������²���Ҫ���ô��ֶΣ�
	// �����չ������Ҫ���Ƶ��¼�������ʽ����ô��Ҫ���ø��ֶβ��Լ������������
	BOOL (XLUE_STDCALL *lpfnParserEvent)(void* userData, void* objHandle, const char* eventName, XL_LRT_CHUNK_HANDLE hCodeChunk, XL_LRT_RUNTIME_HANDLE hRunTime);
	

}ExtObjParser;

typedef struct __ExtObjLuaHost
{
	// �ṹ��Ĵ�С
	size_t size;

	// �û��Զ������ݣ���Ϊ�ص�������һ������
	void* userData;

	// ��ȡ���е�lua��չapi
	BOOL (XLUE_STDCALL *lpfnGetLuaFunctions)(void* userData, const char* className, XLLRTGlobalAPI** lplpLuaFunctions, size_t* lpFuncCount);

}ExtObjLuaHost;

/*
��չԪ������¼����Ʒ�Ϊ�й�ģʽ�ͷ��й�ģʽ(��Ϊlua����¼�)
�й�ģʽ���¼��Ĺ�����fire�ȶ���Ҫ�ⲿ������������ȽϷ������������ɶȺܴ�
���й�ģʽ���¼��Ĺ�����fire�����ڲ����������ⲿֻ��Ҫ����XLUE_ExtObj_FireEvent�ȼ�����������Դ���ָ���¼�

���ExtObjEvent�ṹ���lpfnAttachListener��lpfnRemoveListener�ֶβ�Ϊ�գ���ô��Ϊ���й�ģʽ��������Ϊ�й�ģʽ
*/

/*
��չԪ������¼�ԭ��Ӧ������������ʽ:
ret, ret1, ret2, ..., retm, handled, callnext OnEvent(param1, param2, ..., paramn)
������һ����n��������m+3������ֵ�ı�׼�¼�OnEvent
��Ҫע��ľ��Ƿ���ֵ������Ĭ�ϲ�������һ��retΪ��׼����ֵ(long)�������ڶ���handled��ʶ���¼��Ƿ񱻴���(bool)��
���һ��callnext��ʶ�Ƿ������һ���¼�(bool)������������ֵ�����õ��¼���������Ҫ�ģ�����ķ���ֵret1-retm���û��������ĵķ���ֵ
�ⲿԪ��������¼������������ʽ���������й�ģʽ��fire�¼��ᵼ�·���ֵ����ȷ��
*/ 

/* �й��¼�ģʽ��fireԪ����������¼���������������
// push n��������luaջ
lua_push(luaState, param1);
...
lua_push(luaState, paramn);

long ret = XLUE_FireExtObjEvent(hObj, eventName, luaState, n, m, handled);

// ��ȡm������ֵ
ret1 = lua_toxxx(luaState, -1);
...
retm = lua_toxxx(luaState, -m);
*/
typedef struct __ExtObjEvent
{
	// �ṹ��Ĵ�С
	size_t size;

	// �û��Զ������ݣ���Ϊ�ص�������һ������
	void* userData;

	// �ж�ָ��������Ԫ�����¼��Ƿ����
	BOOL (XLUE_STDCALL *lpfnEventExists)(void* userData, void* objHandle, const char* eventName);

	/*------------------------------���й�ģʽ---------------------------------*/
	// �ҽ�ָ�����¼���luaFuncRefָ���˸��¼���luafunction��isPushBackָ�����¼��Ƿŵ��¼�����ǰ����ĩβ(ʹ���߿��Ը��ݾ��������ʹ��)
	// ����ҽӳɹ�����ô����TRUE������lpEventCookieָ��һ������0��ֵ�����򷵻�FALSE
	BOOL (XLUE_STDCALL *lpfnAttachListener)(void* userData, void* objHandle, const char* eventName, lua_State* luaState, long luaFuncRef, BOOL isPushBack, unsigned long* lpEventCookie);
	BOOL (XLUE_STDCALL *lpfnRemoveListener)(void* userData, void* objHandle, const char* eventName, unsigned long eventCookie);

	/*------------------------------�й�ģʽ-----------------------------------*/
	// ��ģʽ���¼��������ڲ��������ҽӺ��Ƴ�һ���¼�����OnAttachEvent��OnRemoveEvent֪ͨ(�����Ҫ��ע�Ļ�)
	void (XLUE_STDCALL *lpfnOnAttachListener)(void* userData, void* objHandle, const char* eventName, unsigned long eventCookie);
	void (XLUE_STDCALL *lpfnOnRemoveListener)(void* userData, void* objHandle, const char* eventName, unsigned long eventCookie);

	// ÿ���¼�����ʱ������OnFireEvent��ʹ���߿���ָ��һ���ص���������עfire�¼�״̬������FALSE��cancel�ô��¼�Listener����
	//BOOL (XLUE_STDCALL *lpfnOnFireEvent)(void* userData, void* objHandle, const char* eventName, unsigned long eventCookie, lua_State* luaState, int paramCount, int retCount);

}ExtObjEvent;

// ��չԪ������걸ע����Ϣ
typedef struct __ExtObjRegisterInfo
{
	// �ṹ��Ĵ�С
	size_t size;

	// ��չԪ��������
	ExtObjType type;

	// ��չԪ�����class�����ܺ�����Ԫ����class�ظ�
	const char* className;

	// ��չԪ����Ĵ���/���ٹ����������벻Ϊ��
	ExtObjCreator* lpExtObjCreator;

	// ��չԪ����ĺ��ķ����������������ȡ������չԪ�������
	// ExtObjType_layoutObj/ExtObjType_renderableObj -> ExtObjMethods
	// ExtObjType_imageObj -> ExtImageObjMethods
	// ExtObjType_realObj ->ExtRealObjMethods
	void* lpExtObjMethods;

	// ��չԪ�����xml�������������Ҫ��xml�������ɸ���չ������ô���ֶβ���Ϊ��
	ExtObjParser* lpExtObjParser;

	// ��չԪ�����lua��չ�������Ҫ��lua�����������չ������ô���ֶβ���Ϊ��
	ExtObjLuaHost* lpExtObjLuaHost;

	// ��չԪ�����lua�¼��������Ҫ��lua���������������������¼�����ô���ֶβ���Ϊ��
	ExtObjEvent* lpExtObjEvent;

}ExtObjRegisterInfo;

// ������Դ����
typedef enum __ResType
{
	ResType_unknown = 0,
	ResType_bitmap  = 1,
	ResType_texture = 2,
	ResType_font    = 3,   
	ResType_color   = 4,
	ResType_curve   = 5,
	ResType_imagelist = 6,
	ResType_imageseq = 7,
	ResType_pen = 8,
	ResType_brush = 9,
	ResType_gif	= 10,
	ResType_cursor = 11,

}ResType;

// ��Դ�¼���flag����
typedef enum __ResEventFlag
{
	ResEventFlag_load = 0,
	ResEventFlag_update = 1,
	ResEventFlag_user = 2,

}ResEventFlag;

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus


#endif // __XLUEDEFINE_H__