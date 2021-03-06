// -------------------------------------------------------------------------
//    @FileName			:    NFCGameServerNet_ServerModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-01-02
//    @Module           :    NFCGameServerNet_ServerModule
//    @Desc             :
// -------------------------------------------------------------------------

#ifndef NFC_GAMESERVER_SERVER_MODULE_H
#define NFC_GAMESERVER_SERVER_MODULE_H

#include <memory>
#include "NFComm/NFMessageDefine/NFMsgDefine.h"
#include "NFComm/NFPluginModule/NFINetModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFISceneProcessModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFISceneAOIModule.h"
#include "NFComm/NFPluginModule/NFIGameServerToWorldModule.h"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFIPlayerRedisModule.h"
////////////////////////////////////////////////////////////////////////////



class NFCGameServerNet_ServerModule
    : public NFIGameServerNet_ServerModule
{
public:
    NFCGameServerNet_ServerModule(NFIPluginManager* p)
    {
        pPluginManager = p;
    }
    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    virtual bool AfterInit();

    virtual void SendMsgPBToGate(const uint16_t nMsgID, google::protobuf::Message& xMsg, const NFGUID& self);
    virtual void SendMsgPBToGate(const uint16_t nMsgID, const std::string& strMsg, const NFGUID& self);
	virtual void SendMsgPBToGate(const uint16_t nMsgID, google::protobuf::Message& xMsg, const int nSceneID, const int nGroupID);
	virtual void SendMsgPBToGate(const uint16_t nMsgID, const std::string& strMsg, const int nSceneID, const int nGroupID);

    virtual bool AddPlayerGateInfo(const NFGUID& nRoleID, const NFGUID& nClientID, const int nGateID);
    virtual bool RemovePlayerGateInfo(const NFGUID& nRoleID);
    virtual NF_SHARE_PTR<GateBaseInfo> GetPlayerGateInfo(const NFGUID& nRoleID);

    virtual NF_SHARE_PTR<GateServerInfo> GetGateServerInfo(const int nGateID);
    virtual NF_SHARE_PTR<GateServerInfo> GetGateServerInfoBySockIndex(const NFSOCK nSockIndex);


protected:
    void OnSocketPSEvent(const NFSOCK nSockIndex, const NF_NET_EVENT eEvent, NFINet* pNet);
    void OnClientDisconnect(const NFSOCK nSockIndex);
    void OnClientConnected(const NFSOCK nSockIndex);

protected:
    void OnProxyServerRegisteredProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
    void OnProxyServerUnRegisteredProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
    void OnRefreshProxyServerInfoProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

protected:
    void OnReqRoleListProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);
    void OnCreateRoleGameProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
    void OnDeleteRoleGameProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
    void OnClientEnterGameProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);
    void OnClientLeaveGameProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);
	void OnClientSwapSceneProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);
	void OnClientReqMoveProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);
	void OnClientReqMoveImmuneProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);
	void OnClientReqStateSyncProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);
	void OnClientEnterGameFinishProcess(const NFSOCK nSockIndex, const int nMsgID, const char *msg, const uint32_t nLen);

    ///////////WORLD_START///////////////////////////////////////////////////////////////
    void OnTransWorld(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnGuildTransWorld(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

protected:
	void OnClientPropertyIntProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientPropertyFloatProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientPropertyStringProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientPropertyObjectProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientPropertyVector2Process(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientPropertyVector3Process(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

	void OnClientAddRowProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientRemoveRowProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientSwapRowProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientRecordIntProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientRecordFloatProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientRecordStringProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientRecordObjectProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientRecordVector2Process(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnClientRecordVector3Process(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

protected:

	int OnObjectClassEvent(const NFGUID& self, const std::string& strClassName, const CLASS_OBJECT_EVENT eClassEvent, const NFDataList& var);

	//////////////////////////////////////////
	int OnSceneEvent(const NFGUID & self, const int nSceneID, const int nGroupID, const int nType, const NFDataList& argList);

	//broad the data of argvar to self
	int OnObjectListEnter(const NFDataList& self, const NFDataList& argVar);
	int OnObjectDataFinished(const NFDataList& self, const NFDataList& argVar);
	int OnObjectListLeave(const NFDataList& self, const NFDataList& argVar);

	//broad the data of self to argvar 
	int OnPropertyEnter(const NFDataList& argVar, const NFGUID& self);
	int OnRecordEnter(const NFDataList& argVar, const NFGUID& self);

	int OnPropertyEvent(const NFGUID& self, const std::string& strProperty, const NFData& oldVar, const NFData& newVar, const NFDataList& argVar);
	int OnRecordEvent(const NFGUID& self, const std::string& strRecord, const RECORD_EVENT_DATA& xEventData, const NFData& oldVar, const NFData& newVar, const NFDataList& argVar);

private:
    
    NFMapEx<NFGUID, GateBaseInfo> mRoleBaseData;
    //gateid,data
    NFMapEx<int, GateServerInfo> mProxyMap;

    //////////////////////////////////////////////////////////////////////////
    NFIKernelModule* m_pKernelModule;
    NFIClassModule* m_pClassModule;
    NFILogModule* m_pLogModule;
    NFISceneProcessModule* m_pSceneProcessModule;
    NFIElementModule* m_pElementModule;
	NFINetModule* m_pNetModule;
	NFIEventModule* m_pEventModule;
	NFISceneAOIModule* m_pSceneAOIModule;
    NFINetClientModule* m_pNetClientModule;
};
#endif
