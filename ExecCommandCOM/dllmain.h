// dllmain.h : モジュール クラスの宣言です。

class CExecCommandCOMModule : public ATL::CAtlDllModuleT< CExecCommandCOMModule >
{
public :
	DECLARE_LIBID(LIBID_ExecCommandCOMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_EXECCOMMANDCOM, "{b429ec3a-1dd5-4af9-9dc0-27d1d37be517}")
};

extern class CExecCommandCOMModule _AtlModule;
