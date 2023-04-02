// SharedData.cpp : CSharedData の実装

#include "pch.h"
#include "SharedData.h"
#include "comdef.h" //_bstr_t

LPCWSTR SHARED_MEM_NAME = L"shard_mem";
int SHARED_MEM_SIZE = 1024;

// CSharedData
STDMETHODIMP CSharedData::SetData(BSTR pStr)
{
    HANDLE hSharedMemory;
    hSharedMemory = OpenFileMapping(FILE_MAP_ALL_ACCESS,FALSE,SHARED_MEM_NAME);
    if (hSharedMemory == NULL) {
        hSharedMemory = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, NULL, SHARED_MEM_SIZE, SHARED_MEM_NAME);
        if (hSharedMemory == NULL) {
            return S_OK;
        }
    }
    char* pMemory = (char*)MapViewOfFile(hSharedMemory, FILE_MAP_ALL_ACCESS, NULL, NULL, SHARED_MEM_SIZE);
    if (pMemory == NULL) 
    {
        return S_OK;
    }

    //文字列を共有メモリに書き込む
    _bstr_t bstr(pStr);
    strcpy_s(pMemory, SHARED_MEM_SIZE,(char*)bstr);

    UnmapViewOfFile(pMemory);
    //CloseHandle(hSharedMemory);

    return S_OK;
}

BSTR charToBSTR(char* str_org)
{
    //BSTRに必要なバッファサイズを求める
    int bstrlen = (int)MultiByteToWideChar(
        CP_ACP,			// コードページ ANSI コードページ
        0,			    // 文字の種類を指定するフラグ
        str_org,			// マップ元文字列のアドレス
        strlen(str_org),	// マップ元文字列のバイト数
        NULL,			// マップ先ワイド文字列を入れるバッファのアドレス
        0			    // バッファのサイズ
    );
    //バッファを確保する
    BSTR bstr = SysAllocStringLen(NULL, bstrlen);

    //BSTRに複製
    MultiByteToWideChar(
        CP_ACP,
        0,
        str_org,
        strlen(str_org),
        bstr,
        bstrlen
    );
    return bstr;
}

STDMETHODIMP CSharedData::GetData(BSTR* pStr)
{
    HANDLE hSharedMemory = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHARED_MEM_NAME);
    if (hSharedMemory == NULL) {
        return S_OK;
    }
    char* pMemory = (char*)MapViewOfFile(hSharedMemory, FILE_MAP_ALL_ACCESS, NULL, NULL, SHARED_MEM_SIZE);
    if (pMemory == NULL)
    {
        return S_OK;
    }

    char sBuf[1024+1];
    strcpy_s(sBuf, SHARED_MEM_SIZE, pMemory);
    BSTR ret = charToBSTR(sBuf);
    *pStr = ret;

    UnmapViewOfFile(pMemory);
    //CloseHandle(hSharedMemory);

	return S_OK;
}