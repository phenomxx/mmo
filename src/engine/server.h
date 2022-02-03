/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef ENGINE_SERVER_H
#define ENGINE_SERVER_H
#include "kernel.h"
#include "message.h"
#include <game/generated/protocol.h>
#include <engine/shared/protocol.h>

/* INFECTION MODIFICATION START ***************************************/
enum
{
	INFWEAPON_NONE,
	INFWEAPON_HAMMER,
	INFWEAPON_GUN,
	INFWEAPON_SHOTGUN,
	INFWEAPON_GRENADE,
	INFWEAPON_RIFLE,
	INFWEAPON_NINJA,
	NB_INFWEAPON
};

enum
{
	BOT_L1MONSTER=0,
	BOT_L2MONSTER,
	BOT_L3MONSTER,
	BOT_NPC,
	BOT_BOSSSLIME,
	BOT_NPCW,
	BOT_FARMER,
};

enum
{
	USEDDROP,
	USEDSELL,
	USEDUSE,
};

// votes
enum
{
	NOAUTH,
	AUTH,
	CLMENU,
	UPGRADE,	
	CLAN,
	CLANLIST,
	CSETTING,
	CSHOP,
	CMONEY,
	RESLIST,
	QUEST,
	INVENTORY,
	SELITEM,
	CRAFTING,
	ACHUPGRADE,

	TOPMENU,
	EVENTLIST,
	SETTINGS,
	CHOUSE,
	CDONATE,
	INTITLE,
	JOBSSET,
	MAILMENU,
	ARMORMENU,
	RULEMENU,
	MAXMENU,
	
};

// items
enum
{
	NOPE = 0,
	MONEYBAG,
	PIGPORNO,
	KWAHGANDON,
	HOOKDAMAGE,
	IGUN,
	ISHOTGUN,
	IGRENADE,
	ILASER,
	AMULETCLEEVER,
	RINGNOSELFDMG,
	AHAPPY,
	AEVIL,
	ASUPRRISE,
	ABLINK,
	APAIN,
	CLANTICKET,
	MODULEEMOTE,

	ALPHABOX,
	SKILLUPBOX,
	
	LEATHER,
	SNAPHPREGEN,
	SNAPDAMAGE,
	SNAPHANDLE,
	SNAPAMMOREGEN,
	
	RARERINGSLIME,
	RARESLIMEDIRT,
	FORMULAFORRING,
	
	EXGUN,
	EXSHOTGUN,
	EXLASER,
	
	WEAPONPRESSED,
	
	HEADBOOMER,
	RINGBOOMER,
	
	FORMULAEARRINGS,
	FORMULAWEAPON,
	MODULESHOTGUNSLIME,
	
	EARRINGSKWAH,
	FOOTKWAH,
	
	BOOKMONEYMIN,
	BOOKEXPMIN,
	RELRINGS,
	
	MODULEHOOKEXPLODE,
	HAMMERAUTO,
	GUNAUTO,
	
	GHOSTGUN,
	GHOSTSHOTGUN,
	GHOSTGRENADE,
	
	WHITETICKET,
	FREEAZER,
	RANDOMCRAFTITEM,

	EVENTBOX,
	RAREEVENTHAMMER,

	GUNBOUNCE,
	HYBRIDSG,
	GRENADEBOUNCE,

	MOONO2,
	LAMPHAMMER,

	ZOMBIEBRAIN,
	ZOMBIEEYE,
	ZOMIBEBIGEYE,

	SKELETSBONE,
	SKELETSSBONE,
	SKELETSKULL,

	NIMFHEART,
	NIMFEARS,
	NIMFBODY,

	CLANBOXEXP,
	CUSTOMSKIN,

	RESETINGUPGRADE,
	RESETINGSKILL,

	ENDEXPLOSION,
	SCHAT,
	SDROP,

	SKWALL,
	SKHEAL,

	VIPPACKAGE,
	SANTIPVP,
	SPECSNAPDRAW,
	X2MONEYEXPVIP,
	SSWORD,

	BOSSDIE,
	PIGPIG,
	BIGCRAFT,
	SHEALSUMMER,
	ESUMMER,
	TITLESUMMER,

	POTATO,
	TOMATE,
	CARROT,

	JUMPIMPULS,
	FARMLEVEL,
	FARMBOX,
	TITLEQUESTS,
	WOOD,
	COOPERORE,
	COOPERPIX,
	IRONORE,
	IRONPIX,
	GOLDORE,
	GOLDPIX,
	DIAMONDORE,
	DIAMONDPIX,
	MINEREXP,
	BIGWOOD,
	DRAGONORE,
	EVENTCUSTOMSOUL,
	MATERIAL,
	LOADEREXP,
	PIZDAMET,
	LEATHERBODY,
	LEATHERFEET,
	STCLASIC,
	COOPERBODY,
	COOPERFEET,
	IRONBODY,
	IRONFEET,
	GOLDBODY,
	GOLDFEET,
	DIAMONDBODY,
	DIAMONDFEET,
	DRAGONBODY,
	DRAGONFEET,
	TITLEENCHANT,

	BOSSBOX,
	SLIMESPHERE,
	SLIMENECKLACKE,
	PRESSEDPIECE,
	BOSSBOX2,
	VAMPIREFANG,
	BOSSBOX3,
	KINGSOUL,
	ORIHALCUM,
	ORIHALCUMBODY,
	ORIHALCUMFEET,
	PALLADIN,
	PALLADIUMCHEST,
	PALLADIUMBOOTS,
	IMMORTALINGOT,
	IMMORTALCHEST,
	IMMORTALBOOTS,
	
	PIG_XP,
	KWAH_XP,
	BOOM_XP,

	PIGKILLER_1,
	PIGKILLER_2,
	PIGKILLER_3,
	PIGKILLER_4,
	PIGKILLER_5,

	KWAHKILLER_1,
	KWAHKILLER_2,
	KWAHKILLER_3,
	KWAHKILLER_4,
	KWAHKILLER_5,

	BOOMKILLER_1,
	BOOMKILLER_2,
	BOOMKILLER_3,
	BOOMKILLER_4,
	BOOMKILLER_5,

	CRAFTMASTER_1,
	CRAFTMASTER_2,
	CRAFTMASTER_3,
	CRAFTMASTER_4,
	CRAFTMASTER_5,
	CRAFTMASTER_6,
	CRAFTMASTER_7,

	MITHRIL_BODY,
	MITHRIL_FEET,
	MITHRILORE,

	ORIHALCIUM_BODY,
	ORIHALCIUM_FEET,
	ORIHALCIUMORE,

	TITANIUM_BODY,
	TITANIUM_FEET,
	TITANIUMORE,

	ASTRALIUM_BODY,
	ASTRALIUM_FEET,
	ASTRALIUMORE,

	SLIMESOUL,

	CRAFT_XP,

	ACHIEVMENT_POINT,

	UP_BONUS_XP,
	UP_BONUS_SILVER,
	UP_BONUS_DMG,

	FISHINGLEVEL,
	COMMON_FISH,
	UNCOMMON_FISH,
	RARE_FISH,
	EPIC_FISH,
	LEGENDARY_FISH,

	PET_ICE_FISH,
	PET_PIGGY,
	PET_FROG,
	PET_BOMB,
	PET_DOLPHIN,
	PET_IGOR,
	PET_TIGER,
	PET_MONKEY,
	PET_MITHRIL_GOLEM,
	PET_CROW,
	PET_CLEVER,

	ICE_FISH, // Winter season

	MAX_ITEM,

	// 1 - Weapon Upgradins, 2 - Rare Artifacts, 3 - Quest Item's, 4 - Useds Items, 5 - Crafted Item
	// Sufix S - SettingsItem
};

enum
{
	DLEVEL,
	DEXP,
	DMONEY,
	DDONATE,
	DGOLD,
	DREL,
	DJAIL,
	DUSERNAME,
	DCLASS,
	DQUEST,
	DSECC,
	DKILL,
	DWINAREA,
	DADDEXP,
	DADDMONEY,
	DCLANADDED,
	DCHAIRHOUSE,

	DCOUNTUCLAN,
	DMAXCOUNTUCLAN,
	
	UHAMMERRANGE,
	PASIVE2,
	SUPGRADE,
	SKILLPOINT,
	
	HHEALTH,
	BDAMAGE,
	ASPEED,
	HPREGEN,
	AMMOREGEN,
	AMMO,
	SPRAY,
	MANA,
};

enum
{
	PLUS,
	MINUS,
};

enum
{
	PLAYERSCOREMODE_CLASS = 0,
	PLAYERSCOREMODE_SCORE,
	PLAYERSCOREMODE_TIME,
	NB_PLAYERSCOREMODE,
};

enum
{
	CHATCATEGORY_DEFAULT=0,
	CHATCATEGORY_HEALER,
	CHATCATEGORY_BERSERK,
	CHATCATEGORY_ASSASINS,
	CHATCATEGORY_NOAUTH,
	CHATCATEGORY_ACCUSATION,
};

/* INFECTION MODIFICATION END *****************************************/

class IServer : public IInterface
{
	MACRO_INTERFACE("server", 0)
protected:
	int m_CurrentGameTick;
	int m_TickSpeed;

public:
	class CLocalization* m_pLocalization;

	
public:
	/*
		Structure: CClientInfo
	*/
	struct CClientInfo
	{
		const char *m_pName;
		int m_Latency;
		bool m_CustClt;
	};

	virtual ~IServer() {};
	
	inline class CLocalization* Localization() { return m_pLocalization; }

	int Tick() const { return m_CurrentGameTick; }
	int TickSpeed() const { return m_TickSpeed; }

	virtual const char *GetItemName(int ClientID, int ItemID, bool tlang = true) = 0;
	virtual const char *GetItemDesc(int ClientID, int ItemID) = 0;
	virtual int GetItemCount(int ClientID, int ItemID) = 0;
	virtual int GetItemSettings(int ClientID, int ItemID) = 0;
	virtual int GetItemType(int ClientID, int ItemID) = 0;
	virtual void SetItemSettings(int ClientID, int ItemID, int ItemType = 0) = 0;
	virtual int GetItemEnquip(int ClientID, int ItemType) = 0;
	virtual int GetItemEnchant(int ClientID, int ItemID) = 0;
	virtual void SetItemEnchant(int ClientID, int ItemID, int Price) = 0;
	virtual void SetItemSettingsCount(int ClientID, int ItemID, int Count) = 0; 
	virtual int GetBonusEnchant(int ClientID, int ItemID, int Armor) = 0;
	virtual void UpdateItemSettings(int ClientID, int ItemID) = 0;
	virtual void GiveItem(int ClientID, int ItemID, int Count, int Settings = 0, int Enchant = 0) = 0;
	virtual void RemItem(int ClientID, int ItemID, int Count, int Type) = 0;
	virtual void SetItemPrice(int ClientID, int ItemID, int Level, int Price) = 0;
	virtual int GetItemPrice(int ClientID, int ItemID, int Type) = 0;
	virtual void Logout(int ClientID) = 0;

	virtual int MaxClients() const = 0;
	virtual const char *ClientName(int ClientID) = 0;
	virtual const char *ClientUsername(int ClientID) = 0;
	virtual const char *ClientClan(int ClientID) = 0;
	virtual const char *GetSelectName(int ClientID, int SelID) = 0;

	virtual bool GetLeader(int ClientID, int ClanID) = 0;
	virtual int ClientCountry(int ClientID) = 0;
	virtual bool ClientIngame(int ClientID) = 0;
	virtual int GetClientInfo(int ClientID, CClientInfo *pInfo) = 0;
	virtual void GetClientAddr(int ClientID, char *pAddrStr, int Size) = 0;

	virtual int GetOwnHouse(int ClientID) = 0;
	virtual bool GetSpawnInClanHouse(int ClientID, int HouseID) = 0;
	virtual int GetTopHouse(int HouseID) = 0;
	virtual bool GetHouse(int ClientID) = 0;
	virtual bool GetOpenHouse(int HouseID) = 0;
	virtual bool SetOpenHouse(int HouseID) = 0;

	virtual void InitMailID(int ClientID) = 0;
	virtual void SendMail(int AuthedID, const char* pText, int ItemID, int ItemNum) = 0;
	virtual void RemMail(int IDMail) = 0;
	virtual int GetMailRewardDell(int ClientID, int ID) = 0;

	virtual void SetRewardMail(int ClientID, int ID, int ItemID, int ItemNum) = 0;
	virtual int GetRewardMail(int ClientID, int ID, int Type) = 0;

	virtual void InitMaterialID() = 0;
	virtual void SaveMaterials(int ID) = 0;
	virtual int GetMaterials(int ID) = 0;
	virtual void SetMaterials(int ID, int Count) = 0;

	virtual int SendMsg(CMsgPacker *pMsg, int Flags, int ClientID) = 0;

	template<class T>
	int SendPackMsg(T *pMsg, int Flags, int ClientID)
	{
		int result = 0;
		T tmp;
		if (ClientID == -1)
		{
			for(int i = 0; i < MAX_CLIENTS; i++)
				if(ClientIngame(i))
				{
					mem_copy(&tmp, pMsg, sizeof(T));
					result = SendPackMsgTranslate(&tmp, Flags, i);
				}
		} else 
		{
			mem_copy(&tmp, pMsg, sizeof(T));
			result = SendPackMsgTranslate(&tmp, Flags, ClientID);
		}
		return result;
	}

	template<class T>
	int SendPackMsgTranslate(T *pMsg, int Flags, int ClientID)
	{
		return SendPackMsgOne(pMsg, Flags, ClientID);
	}

	int SendPackMsgTranslate(CNetMsg_Sv_Emoticon *pMsg, int Flags, int ClientID)
	{
		return Translate(pMsg->m_ClientID, ClientID) && SendPackMsgOne(pMsg, Flags, ClientID);
	}

	char msgbuf[1000];
	int SendPackMsgTranslate(CNetMsg_Sv_Chat *pMsg, int Flags, int ClientID)
	{
		if (pMsg->m_ClientID >= 0 && !Translate(pMsg->m_ClientID, ClientID))
		{
			str_format(msgbuf, sizeof(msgbuf), "%s: %s", ClientName(pMsg->m_ClientID), pMsg->m_pMessage);
			pMsg->m_pMessage = msgbuf;
			pMsg->m_ClientID = VANILLA_MAX_CLIENTS - 1;
		}
		return SendPackMsgOne(pMsg, Flags, ClientID);
	}

	int SendPackMsgTranslate(CNetMsg_Sv_KillMsg *pMsg, int Flags, int ClientID)
	{
		if (!Translate(pMsg->m_Victim, ClientID)) return 0;
		if (!Translate(pMsg->m_Killer, ClientID)) pMsg->m_Killer = pMsg->m_Victim;
		return SendPackMsgOne(pMsg, Flags, ClientID);
	}

	template<class T>
	int SendPackMsgOne(T *pMsg, int Flags, int ClientID)
	{
		CMsgPacker Packer(pMsg->MsgID());
		if(pMsg->Pack(&Packer))
			return -1;
		return SendMsg(&Packer, Flags, ClientID);
	}

	bool Translate(int& target, int client)
	{
		CClientInfo info;
		GetClientInfo(client, &info);
		if (info.m_CustClt)
			return true;
		int* map = GetIdMap(client);
		bool found = false;
		for (int i = 0; i < VANILLA_MAX_CLIENTS; i++)
		{
			if (target == map[i])
			{
				target = i;
				found = true;
				break;
			}
		}
		return found;
	}

	bool ReverseTranslate(int& target, int client)
	{
		CClientInfo info;
		GetClientInfo(client, &info);
		if (info.m_CustClt)
			return true;
		int* map = GetIdMap(client);
		if (map[target] == -1)
			return false;
		target = map[target];
		return true;
	}

	virtual void SetClientName(int ClientID, char const *pName) = 0;
	virtual void SetClientClan(int ClientID, char const *pClan) = 0;
	virtual void SetClientCountry(int ClientID, int Country) = 0;

	virtual int SnapNewID() = 0;
	virtual void SnapFreeID(int ID) = 0;
	virtual void *SnapNewItem(int Type, int ID, int Size) = 0;

	virtual void SnapSetStaticsize(int ItemType, int Size) = 0;

	enum
	{
		RCON_CID_SERV=-1,
		RCON_CID_VOTE=-2,
	};
	virtual void SetRconCID(int ClientID) = 0;
	virtual bool IsAuthed(int ClientID) = 0;
	virtual void Kick(int ClientID, const char *pReason) = 0;

	virtual int GetUserID(int ClientID) = 0;

	virtual int GetClientAntiPing(int ClientID) = 0;
	virtual void SetClientAntiPing(int ClientID, int Value) = 0;
	
	virtual const char* GetClientLanguage(int ClientID) = 0;
	virtual void SetClientLanguage(int ClientID, const char* pLanguage) = 0;
	
	virtual int GetFireDelay(int ClientID, int WID) = 0;
	virtual void SetFireDelay(int ClientID, int WID, int Time) = 0;
	
	virtual int GetAmmoRegenTime(int ClientID, int WID) = 0;
	virtual void SetAmmoRegenTime(int ClientID, int WID, int Time) = 0;
	
	virtual int GetMaxAmmo(int ClientID, int WID) = 0;
	virtual void SetMaxAmmo(int ClientID, int WID, int n) = 0;
	
	virtual int GetSeccurity(int ClientID) = 0;
	virtual void SetSeccurity(int ClientID, int n) = 0;
	
	virtual int GetStat(int ClientID, int Type) = 0;
	virtual int GetUpgrade(int ClientID, int Type) = 0;
	virtual void UpdateStat(int ClientID, int Type, int Size) = 0;
	virtual void UpdateUpgrade(int ClientID, int Type, int Size) = 0;

	virtual bool IsClientLogged(int ClientID) = 0;
	virtual int GetClanID(int ClientID) = 0;
	virtual void ShowTop10(int ClientID, const char* Type, int TypeGet) = 0;
	virtual void ShowTop10Clans(int ClientID, const char* Type, int TypeGet) = 0;
	virtual void GetTopClanHouse() = 0;
	// ----- Кланы
	
	// Функции вход выход
	virtual void NewClan(int ClientID, const char* pName) = 0;
	virtual void EnterClan(int ClientID, int ClanID) = 0;
	virtual void ListClan(int ClientID, int ClanID) = 0;
	virtual void ExitClanOff(int ClientID, const char* pName) = 0;
	virtual void ChangeLeader(int ClanID, const char* pName) = 0;
	
	// Инициализция сохранения
	virtual void InitClan() = 0;
	virtual void InitClanID(int ClanID, bool Need, const char* SubType, int Price, bool Save) = 0;
	virtual void UpdClanCount(int ClanID) = 0;
	
	// ----- Инвентарь
	virtual void InitInvID(int ClientID = -1, int ItemID = -1) = 0;
	virtual void GetItem(int ItemID, int ClientID, int Count, int Settings = 0, int Enchant = 0) = 0;
	virtual void RemItems(int ItemID, int ClientID, int Count, int Type) = 0;
	virtual void ListInventory(int ClientID, int Type, int GetCount = false) = 0;
	virtual int GetItemCountType(int ClientID, int Type) = 0;

	// ----- Аккаунт
	
	// Функции вход выход
	virtual void Login(int ClientID, const char* pUsername, const char* pPassword) = 0;
	virtual void FirstInit(int ClientID) = 0;
	virtual void Register(int ClientID, const char* pUsername, const char* pPassword, const char* pEmail) = 0;
	
	// Инициализация сохранения
	virtual void InitClientDB(int ClientID) = 0;
	virtual void UpdateStats(int ClientID, int Type = 0) = 0;
	virtual void Ban(int i, int Seconds, const char* pReason) = 0;

public:
	virtual int GetClan(int Type, int ClanID) = 0;
	virtual const char *LeaderName(int ClanID) = 0;
	virtual const char *GetClanName(int ClanID) = 0;

	virtual void ResetBotInfo(int ClientID, int BotType, int BotSubType) = 0;
	virtual void InitClientBot(int ClientID) = 0;

	virtual int* GetIdMap(int ClientID) = 0;
	virtual void SetCustClt(int ClientID) = 0;
}; 

class IGameServer : public IInterface
{
	MACRO_INTERFACE("gameserver", 0)
protected:
public:
	virtual void OnInit() = 0;
	virtual void OnConsoleInit() = 0;
	virtual void OnShutdown() = 0;

	virtual void OnTick() = 0;
	virtual void OnPreSnap() = 0;
	virtual void OnSnap(int ClientID) = 0;
	virtual void OnPostSnap() = 0;

	virtual void OnMessage(int MsgID, CUnpacker *pUnpacker, int ClientID) = 0;

	virtual void OnClientConnected(int ClientID) = 0;
	virtual void OnClientEnter(int ClientID) = 0;
	virtual void OnClientDrop(int ClientID, const char *pReason) = 0;
	virtual void OnClientDirectInput(int ClientID, void *pInput) = 0;
	virtual void OnClientPredictedInput(int ClientID, void *pInput) = 0;

	virtual bool IsClientReady(int ClientID) = 0;
	virtual bool IsClientPlayer(int ClientID) = 0;

	virtual const char *GameType() = 0;
	virtual const char *Version() = 0;
	virtual const char *NetVersion() = 0;
	
	virtual class CLayers *Layers() = 0;
	
/* INFECTION MODIFICATION START ***************************************/
	virtual void ClearBroadcast(int To, int Priority) = 0;
	virtual void SendBroadcast_Localization(int To, int Priority, int LifeSpan, const char* pText, ...) = 0;
	virtual void SendBroadcast_Localization_P(int To, int Priority, int LifeSpan, int Number, const char* pText, ...) = 0;
	virtual void AddVote_Localization(int To, const char* aCmd, const char* pText, ...) = 0;
	virtual void UseItem(int ClientID, int ItemID, int Count, int Type) = 0;
	virtual void SendChatTarget(int To, const char* pText) = 0;
	virtual void SendChatTarget_Localization(int To, int Category, const char* pText, ...) = 0;
	virtual void SendChatTarget_Localization_P(int To, int Category, int Number, const char* pText, ...) = 0;
	virtual void SendMOTD(int To, const char* pText) = 0;
	virtual void SendMOTD_Localization(int To, const char* pText, ...) = 0;
	
	virtual void OnSetAuthed(int ClientID, int Level) = 0;
/* INFECTION MODIFICATION END *****************************************/
};

extern IGameServer *CreateGameServer();
#endif
