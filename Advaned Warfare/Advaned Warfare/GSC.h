#pragma once
#include "stdafx.h"
#include <algorithm>
#include<functional>
#include <vector>
#include <map>
#include <setjmp.h>
#include "WeaponDef.h"
#define DEV
#pragma warning( disable : 4309)

struct Achievment_s
{
	int id;
	char name[0x20];
};
struct Entity_Fields_s
{
	char code_classname;
	char classname;
	char origin;
	char model;
	char spawnflags;
	char target;
	char targetname;
	//char count;
	char health;
	char dmg;
	char angles;
	char birthtime;
	char script_linkname;
	char slidevelocity;
	char playercardbackground;
	Entity_Fields_s()
	{
		char* pChar = (char*)this;
		for(int i = 0;i<sizeof(Entity_Fields_s);i++)
		{
			*pChar = i;
			pChar++;
		}
	}
};
extern Entity_Fields_s Entity_Fields;
struct Client_Fields_s
{
	short name;
	short sessionteam;
	short sessionstate;
	short maxhealth;
	short score;
	short kills;
	short assists;
	short deaths;
	short extrascore0;
	short extrascore1;
	short killstreakcount;
	short objective;
	short headicon;
	short headiconteam;
	short hasradar;
	short isradarblocked;
	short radarstrength;
	short radarshowenemydirection;
	short radarmode;
	short enemyradarmode;
	short forcespectatorclient;
	short killcamentity;
	short killcamentitylookat;
	short spectatekillcam;
	short archivetime;
	short psoffsettime;
	short pers;
	short game_extrainfo;
	short playercardpatch;
	short playercardbackground;
#ifdef DEV
	Client_Fields_s()
	{
		name = 0x6000;
		sessionteam = 0x6001;
		sessionstate = 0x6002;
		maxhealth = 0x6003;
		score = 0x6004;
		kills = 0x6005;
		assists = 0x6006;
		deaths = 0x6007;
		extrascore0 = 0x6008;
		extrascore1 = 0x6009;
		killstreakcount = 0x600A;
		objective = 0x600B;
		headicon = 0x600C;
		headiconteam = 0x600D;
		hasradar = 0x600E;
		isradarblocked = 0x600F;
		radarstrength = 0x6010;
		radarshowenemydirection = 0x6011;
		radarmode = 0x6012;
		enemyradarmode = 0x6013;
		forcespectatorclient = 0x6014;
		killcamentity = 0x6015;
		killcamentitylookat = 0x6016;
		spectatekillcam = 0x6017;
		archivetime = 0x6018;
		psoffsettime = 0x6019;
		pers = 0x601A;
		game_extrainfo = 0x601B;
		playercardpatch = 0x601C;
		playercardbackground = 0x601D;
	}
#endif
};
extern Client_Fields_s Client_Fields;
struct HUD_Fields_s
{
#ifdef DEV
	HUD_Fields_s()
	{
		char* pChar = (char*)this;
		for(int i = 0;i<sizeof(HUD_Fields_s);i++)
		{
			*pChar = i;
			pChar++;
		}
	}
#endif
	char x;
	char y;
	char z;
	char fontscale;
	char font;
	char alignx;
	char aligny;
	char horzalign;
	char vertalign;
	char color;
	char alpha;
	char label;
	char sort;
	char foreground;
	char lowresbackground;
	char hidewhendead;
	char hidewheninmenu;
	char glowcolor;
	char glowalpha;
	char archived;
	char showinkillcam;
	char hidein3rdperson;
	char positioninworld;
	char hideindemo;
	char enablehudlighting;
};
extern HUD_Fields_s HUD_Fields;
struct FunctionID_s
{
	short currentweapon;
	short giveweapon;
	short iprintln;
	short iprintlnbold;
	short ishost;
	short beginlocationselection;
	short endlocationselection;
	short radarjamon;
	short laseron;
	short laseroff;
	short recoilscaleoff;
	short recoilscaleon;
	short setorigin;
	short getorigin;
	short setangles;
	short getangles;
	short setclientdvar;
	short setnormalplayerhealth;
	short getnormalplayerhealth;
	short getplayerads;
	short setperk;
	short unsetperk;
	short hasperk;
	short hide;
	short show;
	short setmodel;
	short setvelocity;
	short getvelocity;
	short stunplayer;
	short shellshock;
	short thermalvisionfofoverlayon;
	short thermalvisionfofoverlayoff;
	short visionsetnaked;
	short visionsetthermalforplayer;
	short hasweapon;
	short openmenu;
	short closemenu;
	short setstance;
	short getstance;
	short kick;
	short takeallweapons;
	short takeweapon;
	short attach;
	short secondartoffhandbuttonpressed;
	short fragbuttonpressed;
	short meleebuttonpressed;
	short adsbuttonpressed;
	short attackbuttonpressed;
	short usebuttonpressed;
	short enableweapons;
	short disableweapons;
	short disableoffhandweapons;
	short enableoffhandweapons;
	short enableweaponswitch;
	short disableweaponswitch;
	short disableoffhand;
	short enableoffhand;
	short allowads;
	short enablejump;
	short enablestance;
	short enablemelee;
	short enableweapon;
	short enablesprint;
	short setactionslot;
	short suicide;
	short solid;
	short clonebrushtoscriptmodel;
	short setblur;
	short setwatersheeting;
	short geteye;
	short setslowmotion;
	short forceusehintnon;
	short forceusehintoff;
	short switchtoweapon;
	short givestartammo;
	short givemaxammo;
	short unlockachievment;
	short closeingamemenu;
	short finishplayerdamage;
	short setwaypointiconoffscreenonly;
	short secondaryarrow;
	short rotatingicon;
	short setwaypoint;
	short setvalue;
	short settargetent;
	short cleartargetent;
	short setpulsefx;
	short setplayernamestring;
	short reset;
	short moveovertime;
	short scaleovertime;
	short fontscaleovertime;
	short fadeovertime;
	short settext;
	short setshader;
	short freeelem;
	short newhudelem;
	short newclienthudelem;
	short newteamhudelem;
	short getcurrentoffhandweapon;
	short getxuid;
	short playlocalsound;
	short setplayerdata;
	short getplayerdata;

	
#ifdef DEV
	FunctionID_s()
	{
		currentweapon = 0x80F8;
		giveweapon = 0x80F5;
		iprintln = 0x80C8;
		iprintlnbold = 0x80C9;
		ishost = 0x80D6;
		beginlocationselection = 0x8117;
		endlocationselection = 0x8118;
		radarjamon = 0x809F;
		laseron = 0x802A;
		laseroff = 0x802B;
		recoilscaleoff = 0x815B;
		recoilscaleon = 0x815A;
		setorigin = 0x8107;
		getorigin = 0x82CC;
		setangles = 0x8109;
		getangles = 0x810A;
		setclientdvar = 0x8135;
		setnormalplayerhealth = 0x82E8;
		getnormalplayerhealth = 0x82E7;
		getplayerads = 0x810F;
		setperk = 0x8163;
		unsetperk = 0x8166;
		hasperk = 0x8164;
		hide = 0x850C;
		show = 0x832A;
		setmodel = 0x8029;
		setvelocity = 0x80F1;
		getvelocity = 0x8108;
		stunplayer  = 0x8070;
		shellshock = 0x806F;
		thermalvisionfofoverlayon = 0x8030;
		thermalvisionfofoverlayoff = 0x8031;
		visionsetnaked = 0x814C;
		visionsetthermalforplayer = 0x814E;
		hasweapon = 0x80FB;
		openmenu = 0x8122;
		closemenu = 0x8123;
		setstance = 0x806A;
		getstance = 0x8069;
		kick = 0x138;
		takeallweapons = 0x80F7;
		takeweapon = 0x80F6;
		attach = 0x8000;
		secondartoffhandbuttonpressed = 0x80EF;
		fragbuttonpressed = 0x80EE;
		meleebuttonpressed = 0x810E;
		adsbuttonpressed = 0x810D;
		attackbuttonpressed = 0x810C;
		usebuttonpressed = 0x810B;
		enableweapons = 0x811A;
		disableweapons = 0x8119;
		disableoffhandweapons = 0x811B;
		enableoffhandweapons = 0x811C;
		enableweaponswitch = 0x84BC;
		disableweaponswitch = 0x84BB;
		disableoffhand = 0x811D;
		enableoffhand = 0x811E;
		allowads = 0x8139;
		enablejump = 0x813A;
		enablestance = 0x8275;
		enablemelee = 0x8288;
		enableweapon = 0x8289;
		enablesprint = 0x813B;
		setactionslot = 0x8141;
		suicide = 0x80C6;
		solid = 0x817B;
		clonebrushtoscriptmodel = 0x8182;
		setblur = 0x8151;
		setwatersheeting = 0x80A7;
		geteye = 0x8020;
		setslowmotion = 0x3B;
		forceusehintnon = 0x803E;
		forceusehintoff = 0x803F;
		switchtoweapon = 0x80FC;
		givestartammo = 0x8101;
		givemaxammo =  0x8100;
		unlockachievment = 0x8298;
		closeingamemenu = 0x80C7;
		finishplayerdamage = 0x80C5;
		setwaypointiconoffscreenonly = 0x82BA;
		secondaryarrow = 0x82B9;
		rotatingicon = 0x82B8;
		setwatersheeting = 0x80A7;
		setwaypoint = 0x82B7;
		setvalue = 0x82B6;
		settargetent = 0x82AD;
		cleartargetent = 0x82AD;
		setpulsefx = 0x82C0;
		setplayernamestring = 0x82C1;
		reset = 0x82BE;
		moveovertime = 0x82BD;
		scaleovertime = 0x82BC;
		fontscaleovertime = 0x82C2;
		fadeovertime = 0x82BB;
		settext = 0x82A9;
		setshader = 0x82AB;
		freeelem = 0x82BF;
		newhudelem = 0xF7;
		newclienthudelem = 0xF8;
		newteamhudelem = 0xF9;
		getcurrentoffhandweapon = 0x80FA;
		getxuid = 0x80D1;
		playlocalsound = 0x812D;
		setplayerdata = 0x80B6;
		getplayerdata = 0x80B1;
	}
#endif
	FunctionID_s Decrypt();
};
extern FunctionID_s FunctionID;
struct GameOffsets_s
{
	DWORD _cParam;
	DWORD _cReturnArgs;
	DWORD _g_script_error_level;
	DWORD _pVM;
	DWORD _G_GetWeaponIndexForName;
	DWORD _Scr_Add;
	DWORD _SL_GetStringOfSize;
	DWORD _Dvar_FindMalleableVar;
	DWORD _XeKeysGetConsoleID;
	DWORD _Scr_ClearOutParams;
	DWORD _SL_ConvertToString;
	DWORD _Scr_SetObjectField;
	DWORD _Scr_GetObjectField;
	DWORD _Scr_AddString;
	DWORD _PerkList;
	DWORD _SV_ExecuteClientCommand;
	DWORD _Scr_Notify;
	DWORD _VM_Execute;
	DWORD _ClientConnect;
	DWORD _G_FindLocalizedStringIndex;
	DWORD _ClientDisconnect;
	DWORD _ClientThink_Real;
	DWORD _XeKeysGetKey;
	DWORD FunctionArrays[8];
	DWORD FunctionArrayLengths[8];
	DWORD xbdmBypass;
	DWORD _DB_FindXAssetHeader;
	DWORD _getSelfID;
	DWORD _Jump_Height;
	DWORD _G_Speed;
	DWORD _G_Gravity;
	DWORD _bg_weaponDefs;
	DWORD _Precache;
	DWORD _Achievments;
	DWORD _gentity;
	DWORD _g_localizedtracepassed;
	DWORD _g_localizedtrace;
	DWORD _GScr_UpdateTagInternal;
	DWORD _Level;
	DWORD _client_s;
	DWORD _client_s_size;
	DWORD _client_s_offset;
	DWORD _Scr_AllocVector;
	DWORD _Scr_AddEntityNum;
	DWORD __setjmp;
	DWORD __setjmpVar;
	#ifdef DEV
	GameOffsets_s()
	{
		_cParam = 0x83EEBA78;
		_cReturnArgs = 0x83EEBA74;
		_g_script_error_level = 0x83B7BC74;
		_pVM = 0x83EEBA70;
		_G_GetWeaponIndexForName = 0x824F0478;
		_Scr_Add = 0x82478548;
		_SL_GetStringOfSize = 0x824872A8;
		_Scr_ClearOutParams = 0x82477FB8;
		_SL_ConvertToString = 0x824869F8;
		_Scr_SetObjectField = 0x824F9270;
		_Scr_GetObjectField = 0x824F8DC8;
		_Scr_AddString = 0x824790D0;
		_PerkList = 0x828F5BE0;
		_SV_ExecuteClientCommand = 0x82437248;
		_Scr_Notify = 0x824F9338;
		_VM_Execute = 0x8247AC28;
		_ClientConnect = 0x82564660;
		_G_FindLocalizedStringIndex = 0x82857040;
		_ClientDisconnect = 0x82564918;
		_ClientThink_Real = 0x8256A9A0;
		_XeKeysGetKey = 0x82893424;
		_DB_FindXAssetHeader = 0x825C14A8;
		_Dvar_FindMalleableVar = 0x823A0750;
		_XeKeysGetConsoleID = 0x82893434;
		_getSelfID = 0x83C9FE80;
		_Jump_Height = 0x820639FC;
		_G_Speed = 0x82569EA6;
		_G_Gravity = 0x8256A3F6;
		_bg_weaponDefs = 0x82B41118;
		xbdmBypass = 0x822EB21C;
		_Precache = 0x837F7554;
		_Achievments = 0x828EC35C;
		_gentity = 0x838EB480;
		_g_localizedtrace = 0x82541B38;
		_g_localizedtracepassed = 0x82541778;
		_GScr_UpdateTagInternal = 0x8251DEB0;
		_Level = 0x837F7528;
		_client_s = 0x83F77380;
		_client_s_size = 0x46480;
		_client_s_offset = 0x207E90;
		_Scr_AllocVector = 0x82483AA0;
		_Scr_AddEntityNum = 0x82483450;
		__setjmp = 0x82880660;
		__setjmpVar = 0x83EE0D20;
		FunctionArrays[0] = 0x8205C100;
		FunctionArrays[1] = 0x828F1B18;
		FunctionArrays[2] = 0x8205BEC8;
		FunctionArrays[3] = 0x8205A930;
		FunctionArrays[4] = 0x828F2468;
		FunctionArrays[5] = 0x8205BDA8;
		FunctionArrays[6] = 0x828F20F0;
		FunctionArrays[7] = 0x8205A7C8;
		FunctionArrayLengths[0] = 0x133;
		FunctionArrayLengths[1] = 0xBB;
		FunctionArrayLengths[2] = 0x47;
		FunctionArrayLengths[3] = 0x145;
		FunctionArrayLengths[4] = 0x162;
		FunctionArrayLengths[5] = 0x24;
		FunctionArrayLengths[6] = 0x64;
		FunctionArrayLengths[7] = 0x2D;
	}
	#endif
	GameOffsets_s Decrypt();
};
extern GameOffsets_s GameOffsets;
struct scr_entref_t
{
	short entnum;
	short classnum;
};
typedef void (*Gsc_Function)(scr_entref_t ref);
typedef void (*Gsc_Notify_Function)(void * pClient);
typedef void (*ClientScr_Function)(void *ps);
typedef void (*HudScr_Function)(void *elem, int offset);

union VM_Values
{
	int iValue;
	float fValue;
	short sValue;
	float *fpValue;
	void* pValue;
	char Value[4];
	const char* szValue; 
};

struct VM_Stack
{
	VM_Values Data;
	int Type;
};
struct Client_VM_Stack_s
{
	int returnCount;
	vector<VM_Stack> ReturnStack;
};

struct ClientScr_t
{
	short *Name;
	int id;
	int offset;
	int type;
	ClientScr_Function SetFunction;
	ClientScr_Function GetFunction;
};
struct HudScr_t
{
	short *Name;
	int id;
	int offset;
	int reserved;
	int type;
	int reserved2;
	HudScr_Function SetFunction;
	HudScr_Function GetFunction;
};
struct Script_Function_t
{
	Gsc_Function Function;
	short id;
	short pad;
};
struct Notify_s
{
	Notify_s(Gsc_Notify_Function f,const char* name, int client) : function(f), notifyName(name), clientNum(client){}
	Gsc_Notify_Function function;
	const char* notifyName;
	int clientNum;
};
struct stringTable_s 
{
 char* fileName;
 int columns;
 int rows;
 char** data;
};
typedef VM_Stack* (*Scr_Add_t)();
typedef void (*Scr_ClearOutParams_t)(); 
typedef void (*Scr_AddEntity_t)(void* ent);
typedef const char* (*Scr_GetString_t)(int index);
typedef void (*Scr_AddConstString_t)(unsigned int value);
typedef void (*Scr_AddString_t)(const char* value);
typedef const char* (*SL_ConvertToString_t)(short val);
typedef void (*Scr_GetClientField_t)(void *ps, int offset);
typedef void (*Scr_SetClientField_t)(void *ps, int offset);
typedef bool (*Scr_SetObjectField_t)(int classNum,int entNum,int offset); 
typedef void (*Scr_GetObjectField_t)(int classNum,int entNum,int offset); 
typedef void * (*Dvar_FindMalleableVar_t)(const char *dvarName);
typedef int (*_setjmp_t)(jmp_buf buff);
typedef void* (*DB_FindXAssetHeader_t)(int type, const char* asset, bool createNew);
extern _setjmp_t __setjmp;
typedef unsigned int (*SL_GetStringOfSize_t)(const char* value,unsigned int user, unsigned int len, int type);
extern int * cParam;// = (int*)0x83F056A0/*TU1 : 0x83DF1CF8*/; 
extern int * cReturnArgs;// = (int*)0x83F0569C/*TU1 : 0x83DF1CF4*/;
extern int * g_script_error_level;//  = (int*)0x83EFA8BC/*TU1 : 0x83AC9CF0*/;
extern int * g_script_large_local_mark;// = (int*)0x83B5B5F8;
extern VM_Stack ** pVM;// = (VM_Stack**)0x83F05698/*TU1 : 0x83DF1CF0*/;
extern VM_Stack returnVM;
extern map<short,Gsc_Function> GSCMap;
extern Client_VM_Stack_s Client_VM_Stack;
extern Dvar_FindMalleableVar_t Dvar_FindMalleableVar;
typedef int (*G_GetWeaponIndexForName_t)(const char* weap);
void Notify_AddAction(Gsc_Notify_Function Function, const char* name,int clientNum);

bool Notify_RemoveAction(Gsc_Notify_Function Function, const char* name,int clientNum);

int Scr_GetSelf(int scriptID);
unsigned int FindObject(int id);
unsigned short FindLastSibling(int id);
void Scr_AddInt(int value);
void Scr_AddFloat(float value);
void Scr_AddVector(float * value);
void Scr_AddEntity(void *entity);
void Scr_AddEntityNum(short entNum);

int Scr_GetInt(int index);
float Scr_GetFloat(int index);
void Scr_GetVector(int index,float * vec);
short Scr_GetConstString(int index);
const char* Scr_GetString(int index);
short SL_GetString(const char* string);
int Scr_GetEntRef(int index);

extern Scr_Add_t Scr_Add;// = (Scr_Add_t)0x82474710/*TU1 : 0x8245DAB8*/;
//extern Scr_AddEntity_t Scr_AddEntity = (Scr_AddEntity_t)0x824D7AB0;
extern SL_GetStringOfSize_t SL_GetStringOfSize;// = (SL_GetStringOfSize_t)0x82483290/*TU1 : 0x8246C448*/;
//extern Scr_AddConstString_t Scr_AddConstString = (Scr_AddConstString_t)0x8245DC40;
extern Scr_ClearOutParams_t Scr_ClearOutParams;// = (Scr_ClearOutParams_t)0x82474180/*TU1 : 0x8245D520*/;
extern SL_ConvertToString_t SL_ConvertToString;// = (SL_ConvertToString_t)0x824829E0/*TU1 : 0x8246BB58*/;
extern Scr_SetObjectField_t Scr_SetObjectField;// = (Scr_SetObjectField_t)0x824F35C8/*TU1 : 0x824D87F8*/;
extern Scr_GetObjectField_t Scr_GetObjectField;// = (Scr_GetObjectField_t)0x824F3120/*TU1 : 0x824D8350*/;
extern Scr_AddString_t      Scr_AddString      ;//= (Scr_AddString_t)     0x82475298/*TU1 : 0x8245E650*/;
extern DB_FindXAssetHeader_t DB_FindXAssetHeader;// = (DB_FindXAssetHeader_t)0x825BA508/*TU1 : 0x8259C160*/;
extern G_GetWeaponIndexForName_t G_GetWeaponIndexForName;
void StoreReturnValues(int count);
Script_Function_t *FindFunction(int StartStruct, short id, unsigned int length);
Script_Function_t* FindFunction(short id);
template <class T>
T CallFunction(int clientNum,short id,int numArgs, int classnum = 0);
bool CallFunctionMain(int clientNum,short id,int numArgs,int classnum);
bool SetField(int clientNum,int offset, int classNum);
template <class T>
T GetField(int clientNum,int offset, int classNum);
template <class T>
void Scr_Push(T val)
{
	VM_Stack* stack = Scr_Add();
	if(sizeof(T) > 32)
		throw exception("Scr_Push: Size greated than 32 bits!");
	if(typeid(val) == typeid(int))
		stack->Type = 6;
	else if(typeid(val) == typeid(float))
		stack->Type = 5;
	else if(typeid(val) == typeid(float*) || typeid(val) == typeid(vec3_t))
		stack->Type = 4;

	memcpy(&stack->Data,&val,sizeof(val));
}