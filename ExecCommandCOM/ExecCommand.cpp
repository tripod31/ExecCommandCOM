// ExecCommand.cpp : CExecCommand の実装

#include "pch.h"
#include "ExecCommand.h"
#include <string>	//std::string
#include "comdef.h" //_bstr_t

// CExecCommand
STDMETHODIMP CExecCommand::put_ExeFile(BSTR newVal)
{
	// TODO: ここに実装コードを追加します
	m_exeFile = newVal;
	return S_OK;
}

STDMETHODIMP CExecCommand::put_Arg(BSTR newVal)
{
	// TODO: ここに実装コードを追加します
	m_arg = newVal;
	return S_OK;
}

STDMETHODIMP CExecCommand::get_Err(BSTR* pVal)
{
	// TODO: ここに実装コードを追加します
	*pVal = m_err;
	return S_OK;
}

STDMETHODIMP CExecCommand::get_Output(BSTR* pVal)
{
	// TODO: ここに実装コードを追加します
	*pVal = m_output;
	return S_OK;
}

// string->wstring変換
std::wstring StringToWString(std::string oString)
{
	// SJIS → wstring
	int iBufferSize = MultiByteToWideChar(CP_ACP, 0, oString.c_str()
		, -1, (wchar_t*)NULL, 0);

	// バッファの取得
	wchar_t* cpUCS2 = new wchar_t[iBufferSize];

	// SJIS → wstring
	MultiByteToWideChar(CP_ACP, 0, oString.c_str(), -1, cpUCS2
		, iBufferSize);

	// stringの生成
	std::wstring oRet(cpUCS2, cpUCS2 + iBufferSize - 1);

	// バッファの破棄
	delete[] cpUCS2;

	// 変換結果を返す
	return(oRet);
}

// コマンドを実行して標準出力を取得
bool create_cmd_process(LPWSTR command, std::wstring& output,std::wstring& err) {
	output = L"";
	std::string outbuf = "";
	err = L"";

	//create pipe
	HANDLE readPipe;
	HANDLE writePipe;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	if (CreatePipe(&readPipe, &writePipe, &sa, 0) == 0) {
		err = L"createPipeエラー";
		return false;
	}
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	si.hStdOutput = writePipe;
	si.hStdError = writePipe;
	si.wShowWindow = SW_HIDE;

	if (CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi) == 0) {
		err = L"createProcessエラー";
		return false;
	}
	HANDLE childProcess = pi.hProcess;
	CloseHandle(pi.hThread);
	char readBuf[1025];
	bool end = false;
	do {
		DWORD totalLen, len;
		if (WaitForSingleObject(childProcess, 100) == WAIT_OBJECT_0)
			end = true;
		if (PeekNamedPipe(readPipe, NULL, 0, NULL, &totalLen, NULL) == 0)
			break;
		if (0 < totalLen) {
			if (ReadFile(readPipe, readBuf, sizeof(readBuf) - 1, &len, NULL) == 0)
				return false;
			readBuf[len] = 0;
			outbuf.append(readBuf);
			if (totalLen > len)	//プロセスは終了したが、パイプのデータは残っているのでループを続ける
				end = false;
		}
	} while (end == false);

	if (CloseHandle(writePipe) == 0) {
		err=L"closeHandleエラー";
		return false;
	}
	if (CloseHandle(readPipe) == 0) {
		err=L"closeHandleエラー";
		return false;
	}
	CloseHandle(pi.hProcess);

	// wstringへ変換
	output = StringToWString(outbuf);
	return true;
}

STDMETHODIMP CExecCommand::Exec(LONG* pRet)
{
	// TODO: ここに実装コードを追加します
	CComBSTR command = m_exeFile;
	HRESULT hr;
	hr=command.Append(L" ");
	hr=command.Append(m_arg);

	TCHAR pCommand[255];
	_bstr_t bCommand = command;
	swprintf_s(pCommand, L"%s", (LPCTSTR)bCommand);
	std::wstring output;
	std::wstring err;
	bool ret = create_cmd_process(pCommand,output,err);
	m_output = output.c_str();
	m_err = err.c_str();
	*pRet = ret ? 0 : -1;

	return S_OK;
}
