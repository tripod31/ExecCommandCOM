// ExecCommand.h : CExecCommand の宣言

#pragma once
#include "resource.h"       // メイン シンボル



#include "ExecCommandCOM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM の完全サポートを含んでいない Windows Mobile プラットフォームのような Windows CE プラットフォームでは、単一スレッド COM オブジェクトは正しくサポートされていません。ATL が単一スレッド COM オブジェクトの作成をサポートすること、およびその単一スレッド COM オブジェクトの実装の使用を許可することを強制するには、_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA を定義してください。ご使用の rgs ファイルのスレッド モデルは 'Free' に設定されており、DCOM Windows CE 以外のプラットフォームでサポートされる唯一のスレッド モデルと設定されていました。"
#endif

using namespace ATL;


// CExecCommand

class ATL_NO_VTABLE CExecCommand :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CExecCommand, &CLSID_ExecCommand>,
	public IDispatchImpl<IExecCommand, &IID_IExecCommand, &LIBID_ExecCommandCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	CComBSTR m_exeFile = NULL;
	CComBSTR m_arg = NULL;
	CComBSTR m_err = NULL;
	CComBSTR m_output = NULL;

public:
	CExecCommand()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CExecCommand)
	COM_INTERFACE_ENTRY(IExecCommand)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:


	STDMETHOD(put_ExeFile)(BSTR newVal);
	STDMETHOD(put_Arg)(BSTR newVal);
	STDMETHOD(get_Err)(BSTR* pVal);
	STDMETHOD(get_Output)(BSTR* pVal);
	STDMETHOD(Exec)(LONG* pRet);
};

OBJECT_ENTRY_AUTO(__uuidof(ExecCommand), CExecCommand)
