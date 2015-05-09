#include "GSC.h"
unsigned int VM_R13;
FunctionID_s FunctionID;
HUD_Fields_s HUD_Fields;
Client_Fields_s Client_Fields;
Entity_Fields_s Entity_Fields;
GameOffsets_s GameOffsets;
int * cParam;
int * cReturnArgs;
int * g_script_error_level;
int * g_script_large_local_mark;
VM_Stack ** pVM;
VM_Stack returnVM;
map<short,Gsc_Function> GSCMap;
Scr_Add_t Scr_Add;
SL_GetStringOfSize_t SL_GetStringOfSize;
Scr_ClearOutParams_t Scr_ClearOutParams;
SL_ConvertToString_t SL_ConvertToString;
Scr_SetObjectField_t Scr_SetObjectField;
Scr_GetObjectField_t Scr_GetObjectField;
Scr_AddString_t      Scr_AddString      ;
DB_FindXAssetHeader_t DB_FindXAssetHeader;
G_GetWeaponIndexForName_t G_GetWeaponIndexForName;
Dvar_FindMalleableVar_t Dvar_FindMalleableVar;
Client_VM_Stack_s Client_VM_Stack;
_setjmp_t __setjmp = (_setjmp_t)0x8286B060;
FunctionID_s FunctionID_s::Decrypt()
{
		FunctionID_s tmp(*this);
#ifndef DEV
		XeCryptRc4(Auth->m_handShake.SessionKey,0x10,(PBYTE)&tmp,sizeof(FunctionID_s));
#endif
		return tmp;
}
GameOffsets_s GameOffsets_s::Decrypt()
{
		GameOffsets_s tmp(*this);
#ifndef DEV
		XeCryptRc4(Auth->m_handShake.SessionKey,0x10,(PBYTE)&tmp,sizeof(GameOffsets_s));
#endif
		return tmp;
		
}
void Scr_AddInt(int value)
{
	VM_Stack* Stack = Scr_Add();
	Stack->Type = 6;
	Stack->Data.iValue = value;
}
void Scr_AddFloat(float value)
{
	VM_Stack* Stack = Scr_Add();
	Stack->Type = 5;
	Stack->Data.fValue = value;
}
void Scr_AddVector(float * value)
{
	VM_Stack* Stack = Scr_Add();
	Stack->Type = 4;
	typedef float * (*Scr_AllocVector_t)(float * pFloat);
	Scr_AllocVector_t Scr_AllocVector = (Scr_AllocVector_t)GameOffsets.Decrypt()._Scr_AllocVector;
	float * pVec = Scr_AllocVector(value);

	Stack->Data.fpValue = pVec;
}
void Scr_AddEntityNum(short entNum)
{
	VM_Stack* Stack = Scr_Add();
	typedef int (*Scr_AddEntityNum_t)(int entNum, int classNum);
	Scr_AddEntityNum_t Scr_AddEntityNum = (Scr_AddEntityNum_t)GameOffsets.Decrypt()._Scr_AddEntityNum;
	Stack->Data.iValue = Scr_AddEntityNum(entNum, 0);
	Stack->Type = 1;
}
int Scr_GetInt(int index)
{
	return Client_VM_Stack.ReturnStack[index].Data.iValue;
}
float Scr_GetFloat(int index)
{
	return Client_VM_Stack.ReturnStack[index].Data.fValue;
}
float * Scr_GetVector(int index)
{
	return Client_VM_Stack.ReturnStack[index].Data.fpValue;
}
void Scr_GetVector(int index, float * vec)
{
	vec[0] = Client_VM_Stack.ReturnStack[index].Data.fpValue[0];
	vec[1] = Client_VM_Stack.ReturnStack[index].Data.fpValue[1];
	vec[2] = Client_VM_Stack.ReturnStack[index].Data.fpValue[2];
}
short Scr_GetConstString(int index)
{
	return Client_VM_Stack.ReturnStack[index].Data.iValue;
}
const char* Scr_GetString(int index)
{
	return SL_ConvertToString(Scr_GetConstString(index));
}
short SL_GetString(const char* string)
{
	return SL_GetStringOfSize(string,1,strlen(string)+1,8);
}
int Scr_GetSelf(int scriptID)
{
	return *(int*)(GameOffsets.Decrypt()._getSelfID/*TU1 : 0x83BADF00*/ + (scriptID * 8)) & 0xFFFF;
}
int Scr_GetEntRef(int index)
{
	return Scr_GetSelf(Client_VM_Stack.ReturnStack[index].Data.iValue);
}

vector<Notify_s> Notify_Stack;
int Notify_Count = 0;
void Notify_AddAction(Gsc_Notify_Function Function, const char* name,int clientNum)
{
	Notify_Count++;
	Notify_Stack.push_back(Notify_s(Function,name,clientNum));
}
template <class _FN>
void Notify_AddAction(_FN _Func(int clientNum,void* ps), const char* name,int clientNum)
{
	Notify_Count++;
	Notify_Stack.push_back(Notify_s(_FN,name,clientNum));
}
bool Notify_RemoveAction(Gsc_Notify_Function Function, const char* name,int clientNum)
{
	for(int i = 0;i<Notify_Stack.size(); i++)
	{
		if(Notify_Stack[i].clientNum == clientNum && Notify_Stack[i].function == Function && !strcmp(Notify_Stack[i].notifyName,name))
		{
			Notify_Stack.erase(Notify_Stack.begin() + i );
			Notify_Count--;
			return true;
		}
	}
	return false;
}

Script_Function_t* FindFunction(int StartStruct, short id, unsigned int length)
{
	Script_Function_t *tFunt = (Script_Function_t*)StartStruct;
	while(((int)tFunt - StartStruct)/sizeof(Script_Function_t) <= length)
	{
		if(id == tFunt->id)
			return tFunt;
		tFunt++;
	}

	return NULL;
}

Script_Function_t* FindFunction(short id)
{
	Script_Function_t* tFunction;
	for(int i = 0;i<8;i++)
	{
		tFunction = FindFunction(GameOffsets.Decrypt().FunctionArrays[i],id,GameOffsets.Decrypt().FunctionArrayLengths[i]);
		if(tFunction != NULL)
			return tFunction;
	}
	return NULL;
	//tFunction = FindFunction(0x8205BED0/*TU1 : 0x8205BE10*/,id,0x12F);
	//if(tFunction != NULL)
	//	return tFunction;
	//tFunction = FindFunction(0x828E1DD8/*TU1 : 0x828B10F8*/,id,0xBA);
	//if(tFunction != NULL)
	//	return tFunction;
	//tFunction = FindFunction(0x8205BC98 /*TU1 : 0x8205BBF8*/,id,0x47); 
	//if(tFunction != NULL)
	//	return tFunction;
	//tFunction = FindFunction(0x8205A700/*TU1 : 0x8205A698*/,id,0x145); 
	//if(tFunction != NULL)
	//	return tFunction;
	//tFunction = FindFunction(0x828E2708/*TU1 : 0x828B19D0*/,id,0x15E);
	//if(tFunction != NULL)
	//	return tFunction;
	//tFunction = FindFunction(0x8205BB78/*TU1 : 0x8205BAD8*/,id,0x24); 
	//if(tFunction != NULL)
	//	return tFunction;
	//tFunction = FindFunction(0x828E23A8/*TU1 : 0x828B16C8*/,id,0x61); 
	//if(tFunction != NULL)
	//	return tFunction;
	//tFunction = FindFunction(0x8205A5A0/*TU1 : 0x8205A550*/,id,0x2C); 
	//if(tFunction != NULL)
	//	return tFunction;

	return NULL;
}
//int BaseAddress = 0x824FA4B8, BaseAddress2 = 0x824FA5B0;
//#define ReadJumpAddress(address) (*(int*)(address) & 0x00FFFFFF) *(char*)address ==  0x48 ? (+ address - 1) : (+ address - 1)
//bool ReadFunctionInformation(int FunctionStart,int *Length, Script_Function_t ** FunctionList)
//{
//	*Length = *(short*)(FunctionStart + 2);
//	*FunctionList = (Script_Function_t*)(((*(short*)(FunctionStart + 0x06) - 1) << 16 ) | *(int*)(FunctionStart + 0x0C) & 0xFFFF);
//	if(*Length && *FunctionList)
//		return true;
//	else 
//		return false;
//}
//Script_Function_t* FindFunction(Script_Function_t* StartStruct, short id, int length)
//{
//	for(int i = 0;i<length;i++,StartStruct++)
//	{
//			if(StartStruct->id == id)
//			return StartStruct;
//	}
//	return NULL;
//}
//Script_Function_t* FindFunction(short id)
//{
//	int tLength;
//	Script_Function_t *FunctionArray;
//	Script_Function_t *tFunt;
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress + 0x1C),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress + 0x28),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress + 0x34),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress + 0x40),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress + 0x4C),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress + 0x78),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress + 0xDC),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//	if(ReadFunctionInformation(ReadJumpAddress(BaseAddress2 + 0x7C),&tLength,&FunctionArray))
//	{
//		if( (tFunt = FindFunction(FunctionArray,id,tLength)))
//			return tFunt;
//	}
//}

template <class T>
T CallFunction<T>(int clientNum,short id,int numArgs, int classnum)
{
	CallFunctionMain(clientNum,id,numArgs,classnum);
	return reinterpret_cast<T>(Client_VM_Stack.ReturnStack[index].Data);
}
template <>
void CallFunction<void>(int clientNum,short id,int numArgs, int classnum)
{
	CallFunctionMain(clientNum,id,numArgs,classnum);
}
template <>
int CallFunction<int>(int clientNum,short id,int numArgs,int classnum)
{
	CallFunctionMain(clientNum,id,numArgs,classnum);
	return Scr_GetInt(0);
}
template <>
short CallFunction<short>(int clientNum,short id,int numArgs,int classnum)
{
	CallFunctionMain(clientNum,id,numArgs,classnum);
	return Scr_GetInt(0);
}
template <>
float CallFunction<float>(int clientNum,short id,int numArgs,int classnum)
{
	CallFunctionMain(clientNum,id,numArgs, classnum);
	return Scr_GetFloat(0);
}
template <>
const char* CallFunction<const char*>(int clientNum,short id,int numArgs,int classnum)
{
	CallFunctionMain(clientNum,id,numArgs,classnum);
	return Scr_GetString(0);
}
template <>
float* CallFunction<float*>(int clientNum,short id,int numArgs,int classnum)
{
	CallFunctionMain(clientNum,id,numArgs,classnum);
	float ret[3];
	Scr_GetVector(0,ret);
	return ret;
}

template <>
vec3_t CallFunction<vec3_t>(int clientNum,short id,int numArgs,int classnum)
{
	CallFunctionMain(clientNum,id,numArgs,classnum);
	vec3_t Vec;
	Scr_GetVector(0,Vec);
	return Vec;
}
bool CallFunctionMain(int clientNum,short id,int numArgs,int classnum)
{
	bool success = true;
	*cReturnArgs = 0;
	*g_script_error_level++;
	Gsc_Function tFunc;
	int tParams = *cParam;
	*cParam = numArgs;
	scr_entref_t ref;
	if(GSCMap.find(id) == GSCMap.end())
	{
		Script_Function_t *ScriptFunt = FindFunction(id);
		if(ScriptFunt == NULL)
		{
			success = false;
			goto end;
		}
		tFunc = ScriptFunt->Function;
		//*(int*)0x83F05600 = 0;
		GSCMap[id] = tFunc;
	}
	try
	{
		ref.classnum = classnum;
		ref.entnum = clientNum;
		GSCMap[id](ref);
	}
	catch(exception e)

	{
		printf("Call Function Error! %s\n",e.what());
		success = false;
	}
end:
	StoreReturnValues(*cReturnArgs);
	*cParam = 0;
	*cReturnArgs = 0;	
	*g_script_error_level--;
	Scr_ClearOutParams();
	return success;
}
void StoreReturnValues(int count)
{
	VM_Stack *pStack;
	pStack = *pVM;
	Client_VM_Stack.ReturnStack.clear();
	for(int i =0;i<count;i++)
	{
		Client_VM_Stack.ReturnStack.push_back(*pStack--);
	}
	Client_VM_Stack.returnCount = count;
}

ClientScr_t* FindScrOffset(int StartStruct, short id, int length)
{
	ClientScr_t* tSCR = (ClientScr_t*)StartStruct;
	while(((int)tSCR - StartStruct)/sizeof(ClientScr_t) <= length)
	{
		if(tSCR->id == id)
			return tSCR;
		tSCR++;
	}
	return NULL;
}
HudScr_t* FindHUDOffset(int StartStruct, short _id, int length)
{
	HudScr_t* pHUD = (HudScr_t*)StartStruct;
	while(((int)pHUD - StartStruct)/sizeof(HudScr_t) <= length)
	{
		if(_id == pHUD->id)
			return pHUD;
		pHUD++;
	}
	return NULL;
}
bool SetField(int clientNum,int offset, int classNum)
{
	bool success = false;
	int tParams = *cParam;
	*cParam = 1; 
	*g_script_error_level++;
	Scr_SetObjectField(classNum,clientNum,offset);
	*cParam = tParams;
	*g_script_error_level--;
	Scr_ClearOutParams();
	return success;
}
bool GetFieldMain(int clientNum,int offset, int classNum)
{
	bool success = false;
	*g_script_error_level++;
	Scr_GetObjectField(classNum,clientNum,offset);
	StoreReturnValues(*cReturnArgs);
	*cReturnArgs = 0;	
	*g_script_error_level--;
	Scr_ClearOutParams();
	return success;
}
template <>
const char* GetField<const char*>(int clientNum,int offset, int classNum)
{
	GetFieldMain(clientNum,offset,classNum);
	return Scr_GetString(0);
}
template <>
int GetField<int>(int clientNum,int offset, int classNum)
{
	GetFieldMain(clientNum,offset,classNum);
	return Scr_GetInt(0);
}
template <>
float GetField<float>(int clientNum,int offset, int classNum)
{
	GetFieldMain(clientNum,offset,classNum);
	return Scr_GetFloat(0);
}
template <>
float* GetField<float*>(int clientNum,int offset, int classNum)
{
	GetFieldMain(clientNum,offset,classNum);
	float out[3];
	Scr_GetVector(0,out);
	return out;
}
template <class T>
void Scr_Push(T val)
{
	VM_Stack* stack = Scr_Add();
	switch(typeid(T))
	{
		case typeid(int):
			stack->Type = 6;
			break;
		case typeid(float):
			stack->Type = 5;
			break;
		case typeid(float*):
			stack->Type = 4;
			break;
	}
	memcpy(stack->Data,&T,sizeof(T));
}