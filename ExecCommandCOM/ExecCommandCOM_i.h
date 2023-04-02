

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for ExecCommandCOM.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ExecCommandCOM_i_h__
#define __ExecCommandCOM_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IExecCommand_FWD_DEFINED__
#define __IExecCommand_FWD_DEFINED__
typedef interface IExecCommand IExecCommand;

#endif 	/* __IExecCommand_FWD_DEFINED__ */


#ifndef __ISharedData_FWD_DEFINED__
#define __ISharedData_FWD_DEFINED__
typedef interface ISharedData ISharedData;

#endif 	/* __ISharedData_FWD_DEFINED__ */


#ifndef __ExecCommand_FWD_DEFINED__
#define __ExecCommand_FWD_DEFINED__

#ifdef __cplusplus
typedef class ExecCommand ExecCommand;
#else
typedef struct ExecCommand ExecCommand;
#endif /* __cplusplus */

#endif 	/* __ExecCommand_FWD_DEFINED__ */


#ifndef __SharedData_FWD_DEFINED__
#define __SharedData_FWD_DEFINED__

#ifdef __cplusplus
typedef class SharedData SharedData;
#else
typedef struct SharedData SharedData;
#endif /* __cplusplus */

#endif 	/* __SharedData_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IExecCommand_INTERFACE_DEFINED__
#define __IExecCommand_INTERFACE_DEFINED__

/* interface IExecCommand */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IExecCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5e05d9f6-7671-447c-9d65-9626becf90d5")
    IExecCommand : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ExeFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Arg( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Err( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Output( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Exec( 
            /* [retval][out] */ LONG *pRet) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IExecCommandVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExecCommand * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExecCommand * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExecCommand * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IExecCommand * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IExecCommand * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IExecCommand * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IExecCommand * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IExecCommand, put_ExeFile)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExeFile )( 
            IExecCommand * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IExecCommand, put_Arg)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Arg )( 
            IExecCommand * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IExecCommand, get_Err)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Err )( 
            IExecCommand * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IExecCommand, get_Output)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Output )( 
            IExecCommand * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IExecCommand, Exec)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Exec )( 
            IExecCommand * This,
            /* [retval][out] */ LONG *pRet);
        
        END_INTERFACE
    } IExecCommandVtbl;

    interface IExecCommand
    {
        CONST_VTBL struct IExecCommandVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExecCommand_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExecCommand_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExecCommand_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExecCommand_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IExecCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IExecCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IExecCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IExecCommand_put_ExeFile(This,newVal)	\
    ( (This)->lpVtbl -> put_ExeFile(This,newVal) ) 

#define IExecCommand_put_Arg(This,newVal)	\
    ( (This)->lpVtbl -> put_Arg(This,newVal) ) 

#define IExecCommand_get_Err(This,pVal)	\
    ( (This)->lpVtbl -> get_Err(This,pVal) ) 

#define IExecCommand_get_Output(This,pVal)	\
    ( (This)->lpVtbl -> get_Output(This,pVal) ) 

#define IExecCommand_Exec(This,pRet)	\
    ( (This)->lpVtbl -> Exec(This,pRet) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExecCommand_INTERFACE_DEFINED__ */


#ifndef __ISharedData_INTERFACE_DEFINED__
#define __ISharedData_INTERFACE_DEFINED__

/* interface ISharedData */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISharedData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6cce8c8f-264d-4ba2-b56b-e1ce9651bbcb")
    ISharedData : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetData( 
            /* [in] */ BSTR pStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetData( 
            /* [retval][out] */ BSTR *pStr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISharedDataVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISharedData * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISharedData * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISharedData * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISharedData * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISharedData * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISharedData * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISharedData * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ISharedData, SetData)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetData )( 
            ISharedData * This,
            /* [in] */ BSTR pStr);
        
        DECLSPEC_XFGVIRT(ISharedData, GetData)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISharedData * This,
            /* [retval][out] */ BSTR *pStr);
        
        END_INTERFACE
    } ISharedDataVtbl;

    interface ISharedData
    {
        CONST_VTBL struct ISharedDataVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedData_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISharedData_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISharedData_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISharedData_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISharedData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISharedData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISharedData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISharedData_SetData(This,pStr)	\
    ( (This)->lpVtbl -> SetData(This,pStr) ) 

#define ISharedData_GetData(This,pStr)	\
    ( (This)->lpVtbl -> GetData(This,pStr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISharedData_INTERFACE_DEFINED__ */



#ifndef __ExecCommandCOMLib_LIBRARY_DEFINED__
#define __ExecCommandCOMLib_LIBRARY_DEFINED__

/* library ExecCommandCOMLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ExecCommandCOMLib;

EXTERN_C const CLSID CLSID_ExecCommand;

#ifdef __cplusplus

class DECLSPEC_UUID("83c68132-2614-45a7-ad9f-8a71ae718e37")
ExecCommand;
#endif

EXTERN_C const CLSID CLSID_SharedData;

#ifdef __cplusplus

class DECLSPEC_UUID("45424b12-2f89-476c-b869-8039518b1116")
SharedData;
#endif
#endif /* __ExecCommandCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


