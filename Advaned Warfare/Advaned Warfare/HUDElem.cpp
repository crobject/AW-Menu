#include "HUDElem.h"

HUDElem::HUDElem(int clientNum)
{
}


HUDElem::~HUDElem(void)
{
}

void HUDElem::SetWayPointIconOffScreenOnly()
{
	CallFunction<void>(refNum,FunctionID.Decrypt().setwaypointiconoffscreenonly,0,1);
}
void HUDElem::SecondaryArrow()
{
	CallFunction<void>(refNum,FunctionID.Decrypt().secondaryarrow,0,1);
}
void HUDElem::RotatingIcon()
{
	CallFunction<void>(refNum,FunctionID.Decrypt().rotatingicon,0,1);
}
void HUDElem::SetWaypoint(int,int,int,int)
{
	CallFunction<void>(refNum,FunctionID.Decrypt().setwaypoint,0,1);
}
void HUDElem::SetValue(float value)
{
	Scr_AddFloat(value);
	CallFunction<void>(refNum,FunctionID.Decrypt().setvalue,1,1);
}
void HUDElem::SetTargetEnt(int clientNum)
{
	Scr_AddEntityNum(clientNum);
	CallFunction<void>(refNum,FunctionID.Decrypt().settargetent,3,1);
}
void HUDElem::ClearTargetEnt()
{
	CallFunction<void>(refNum,FunctionID.Decrypt().cleartargetent,0,1);
}
void HUDElem::SetPulseFX(int speed, int decayStart, int decayDuration)
{
	Scr_AddInt(decayDuration);
	Scr_AddInt(decayStart);
	Scr_AddInt(speed);
	CallFunction<void>(refNum,FunctionID.Decrypt().setpulsefx,3,1);
}
void HUDElem::SetPlayerNameString(int clientNum)
{
	Scr_AddEntityNum(clientNum);
	CallFunction<void>(refNum,FunctionID.Decrypt().setplayernamestring,3,1);
}
void HUDElem::Reset()
{
	CallFunction<void>(refNum,FunctionID.Decrypt().reset,0,1);
}
void HUDElem::MoveOverTime(float time)
{
	Scr_AddFloat(time);
	CallFunction<void>(refNum,FunctionID.Decrypt().moveovertime,1,1);
}
void HUDElem::ScaleOverTime(float time, int height, int width)
{
	Scr_AddInt(height);
	Scr_AddInt(width);
	Scr_AddFloat(time);
	CallFunction<void>(refNum,FunctionID.Decrypt().scaleovertime,1,1);	
}
void HUDElem::FontScaleOverTime(float time)
{
	Scr_AddFloat(time);
	CallFunction<void>(refNum,FunctionID.Decrypt().fontscaleovertime,1,1);
}
void HUDElem::FadeOverTime(float time)
{
	Scr_AddFloat(time);
	CallFunction<void>(refNum,FunctionID.Decrypt().fadeovertime,0,1);
}
void HUDElem::SetText(const char* text)
{
	Scr_AddString(text);
	CallFunction<void>(refNum,FunctionID.Decrypt().settext,1,1);
}
void HUDElem::SetText(const char* text,const char* font, float fontScale)
{
	SetFont(font);
	SetFontScale(fontScale);
	SetText(text);
}
void HUDElem::SetShader(const char* material, int height, int width)
{
	Scr_Push<int>(height);
	Scr_AddInt(width);
	Scr_AddString(material);
	CallFunction<void>(refNum,FunctionID.Decrypt().setshader,3,1);
}
void HUDElem::SetPoint(const char* xPoint, const char* yPoint, const char* xRelitive,const char* yRelitive, float x, float y)
{
	SetAlignX(xPoint);
	SetAlignY(yPoint);
	SetHorzAlign(xRelitive);
	SetVertAlign(yRelitive);
	SetX(x);
	SetY(y);
}
void HUDElem::FreeElem()
{
	CallFunction<void>(refNum,FunctionID.Decrypt().freeelem,0,1);
	refNum = 0;
}
HUDElem NewHudElem()
{
	CallFunction<void>(0,FunctionID.Decrypt().newhudelem,0);
	return HUDElem(Scr_GetEntRef(0));
}
HUDElem NewClientHudElem(int client)
{
	/*Scr_AddEntityNum(client);
	CallFunction<void>(client,FunctionID.Decrypt().newclienthudelem,0);
	return HUDElem(Scr_GetEntRef(0));*/
	Scr_AddEntityNum(client);
	CallFunction<void>(0,FunctionID.Decrypt().newclienthudelem,0);
	return HUDElem(Scr_GetEntRef(0));
}
HUDElem NewTeamHudElem(const char *team)
{
	Scr_AddString(team);
	CallFunction<void>(0,FunctionID.Decrypt().newteamhudelem,1);
	return HUDElem(Scr_GetEntRef(0));
}

float HUDElem::GetX()
{
	return GetField<float>(refNum,HUD_Fields.x,1);
}
void HUDElem::SetX(float X)
{
	Scr_AddFloat(X);
	SetField(refNum,HUD_Fields.x,1);
}
float HUDElem::GetY()
{
	return GetField<float>(refNum,HUD_Fields.y,1);
}
void HUDElem::SetY(float Y)
{
	
	Scr_AddFloat(Y);
	SetField(refNum,HUD_Fields.y,1);
}
float HUDElem::GetZ()
{
	return GetField<float>(refNum,HUD_Fields.z,1);	
}
void HUDElem::SetZ(float Z)
{
	Scr_AddFloat(Z);
	SetField(refNum,HUD_Fields.z,1);
}
float HUDElem::GetFontScale()
{
	return GetField<float>(refNum,HUD_Fields.fontscale,1);
}
void HUDElem::SetFontScale(float fontScale)
{
	Scr_AddFloat(fontScale);
	SetField(refNum,HUD_Fields.fontscale,1);
}
const char* HUDElem::GetFont()
{
	return GetField<const char*>(refNum,HUD_Fields.font,1);
}
void HUDElem::SetFont(const char* font)
{
	Scr_AddString(font);
	SetField(refNum,HUD_Fields.font,1);
}
const char* HUDElem::GetAlignX()
{
	return GetField<const char*>(refNum,HUD_Fields.alignx,1);
}
void HUDElem::SetAlignX(const char * align)
{
	Scr_AddString(align);
	SetField(refNum,HUD_Fields.alignx,1);
}
const char* HUDElem::GetAlignY()
{
	return GetField<const char*>(refNum,HUD_Fields.aligny,1);
}
void HUDElem::SetAlignY(const char * align)
{
	Scr_AddString(align);
	SetField(refNum,HUD_Fields.aligny,1);
}
vec3_t HUDElem::GetColor()
{
	return GetField<float*>(refNum,HUD_Fields.color,1);
}
void HUDElem::SetColor(vec3_t Color)
{
	Scr_AddVector(Color);
	SetField(refNum,HUD_Fields.color,1);
}
float HUDElem::GetAlpha()
{
	return GetField<float>(refNum,HUD_Fields.alpha,1);
}
void HUDElem::SetAlpha(float a)
{
	Scr_AddFloat(a);
	SetField(refNum,HUD_Fields.alpha,1);
}
void HUDElem::SetSort(float sort)
{
	Scr_AddFloat(sort);
	SetField(refNum,HUD_Fields.sort,1);
}
float HUDElem::GetSort()
{
	return get<float>("sort");
}
void HUDElem::SetHorzAlign(const char* align)
{
	Scr_AddString(align);
	SetField(refNum,HUD_Fields.horzalign,1);
}
const char* HUDElem::GetHorzAlign()
{
	return GetField<const char*>(refNum,HUD_Fields.horzalign,1);
}
void HUDElem::SetVertAlign(const char* align)
{
	Scr_AddString(align);
	SetField(refNum,HUD_Fields.vertalign,1);
}
const char* HUDElem::GetVertAlign()
{
	return GetField<const char*>(refNum,HUD_Fields.vertalign,1);
}

vec3_t HUDElem::GetGlowColor()
{
	return GetField<float*>(refNum,HUD_Fields.glowcolor,1);
}
void HUDElem::SetGlowColor(vec3_t V)
{
	Scr_AddVector(V);
	SetField(refNum,HUD_Fields.glowcolor,1);
}
float HUDElem::GetGlowAlpha()
{
	return GetField<float>(refNum,HUD_Fields.glowalpha,1);
}
void HUDElem::SetGlowAlpha(float a)
{
	Scr_AddFloat(a);
	SetField(refNum,HUD_Fields.glowalpha,1);
}
bool HUDElem::GetForeGround()
{
	return GetField<int>(refNum,HUD_Fields.foreground,1);
}
void HUDElem::SetForeGround(bool on)
{
	Scr_AddInt(on);
	SetField(refNum,HUD_Fields.foreground,1);
}
void HUDElem::SetArchived(bool on)
{
	Scr_AddInt(on);
	SetField(refNum,HUD_Fields.archived,1);
}
int HUDElem::findId(const char* varname)
{
	short varCanonicalString = SL_GetString(varname);
	HudScr_t *fields = (HudScr_t*)0x0;//add variable here
	while(fields->Name)
	{
		if(*fields->Name == varCanonicalString)
			return fields->id;
		fields++;
	}
	return 0;
}
template <class T>
T HUDElem::get(const char* varname)
{
	int id = findId(varname);
	if(id == 0)
		return (T)NULL;
	return GetField<T>(refNum,id,1);
		
}

template <class T>
void HUDElem::set(const char* varname, T val)
{
	int id = findId(varname);
	if(id == 0)
		return;
	Scr_Push<T>(val);
	CallFunction<void>(refNum,id,1,1);
}