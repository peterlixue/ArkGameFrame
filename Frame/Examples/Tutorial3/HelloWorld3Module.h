// -------------------------------------------------------------------------
//    @FileName			:    HelloWorld3.h
//    @Author           :    Ark Game Tech
//    @Date             :    2014-05-14 08:51
//    @Module           :   HelloWorld3
//
// -------------------------------------------------------------------------

#ifndef NFC_HELLO_WORLD3_H
#define NFC_HELLO_WORLD3_H

#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

class HelloWorld3Module
    : public NFIModule
{
public:
    HelloWorld3Module(NFIPluginManager* p)
    {
        pPluginManager = p;
    }

    virtual bool Init();
    virtual bool AfterInit();

    virtual bool Execute();

    virtual bool BeforeShut();
    virtual bool Shut();

protected:
    int OnEvent(const NFGUID& self, const int event, const AFDataList& arg);
    int OnClassCallBackEvent(const NFGUID& self, const std::string& strClassName, const CLASS_OBJECT_EVENT event, const AFDataList& arg);
    int OnPropertyCallBackEvent( const NFGUID& self, const std::string& strProperty, const AFDataList::TData& oldVarList, const AFDataList::TData& newVarList );
    int OnPropertyStrCallBackEvent( const NFGUID& self, const std::string& strProperty, const AFDataList::TData& oldVarList, const AFDataList::TData& newVarList );

    int OnHeartBeat(const NFGUID& self, const std::string& strHeartBeat, const float fTime, const int nCount);

protected:
    unsigned long mLastTime;
protected:
    NFIKernelModule* m_pKernelModule;
    NFIElementModule* m_pElementModule;
};

#endif
