#pragma once
#include "stdafx.h"
class HUDElem
{
	int FindID(const char* Name);
public:
	HUDElem(int clientNum);
	
	~HUDElem(void);

	//functions
	void SetWayPointIconOffScreenOnly();
	void SecondaryArrow();
	void RotatingIcon();
	void SetWaypoint(int,int,int,int);
	void SetValue(float value);
	void SetTargetEnt(int clientNum);
	void ClearTargetEnt();
	void SetPulseFX(int speed, int decayStart, int decayDuration);
	void SetPlayerNameString(int clientNum);
	void Reset();
	void MoveOverTime(float time);
	void ScaleOverTime(float time, int height, int width);
	void FontScaleOverTime(float time);
	void FadeOverTime(float time);
	void SetText(const char* text);
	void SetText(const char* text,const char* font, float fontScale);
	void SetShader(const char* material, int height, int width);
	void FreeElem();
	void SetPoint(const char* xPoint, const char* yPoint, const char* xRelitive,const char* yRelitive, float x, float y);

	//structure interatctions
	float GetX();
	void SetX(float X);
	float GetY();
	void SetY(float Y);
	float GetZ();
	void SetZ(float Z);
	float GetFontScale();
	void SetFontScale(float fontScale);
	const char* GetFont();
	void SetFont(const char* font);
	const char* GetAlignX();
	void SetAlignX(const char * align);	
	const char* GetAlignY();
	void SetAlignY(const char * align);
	vec3_t GetColor();
	void SetColor(vec3_t Color);
	float GetAlpha();
	void SetAlpha(float a);
	void SetSort(float sort);
	float GetSort();
	void SetHorzAlign(const char* align);
	const char* GetHorzAlign();
	void SetVertAlign(const char* align);
	const char* GetVertAlign();
	vec3_t GetGlowColor();
	void SetGlowColor(vec3_t V);
	float GetGlowAlpha();
	void SetGlowAlpha(float a);
	bool GetForeGround();
	void SetForeGround(bool on);
	void SetArchived(bool on);
	//properties
	__declspec(property(get = GetX, put = SetX)) float X;
	__declspec(property(get = GetY, put = SetY)) float Y;
	__declspec(property(get = GetZ, put = SetZ)) float Z;
	__declspec(property(get = GetFontScale, put = SetFontScale)) float FontScale;
	__declspec(property(get = GetFont, put = SetFont)) const char* Font;
	__declspec(property(get = GetAlignX, put = SetAlignX)) const char* AlignX;
	__declspec(property(get = GetAlignY, put = SetAlignY)) const char* AlignY;
	__declspec(property(get = GetColor, put = SetColor)) vec3_t Color;
	__declspec(property(get = GetAlpha, put = SetAlpha)) float Alpha;
	__declspec(property(get = GetHorzAlign, put = SetHorzAlign)) const char* HorzAlign;
	__declspec(property(get = GetVertAlign, put = SetVertAlign)) const char* VertAlign;
	__declspec(property(get = GetSort, put = SetSort)) float Sort;
	__declspec(property(get = GetGlowColor, put = SetGlowColor)) vec3_t GlowColor;
	__declspec(property(get = GetGlowAlpha, put = SetGlowAlpha)) float GlowAlpha;


};
HUDElem NewHudElem();
HUDElem NewClientHudElem(int client);
HUDElem NewTeamHudElem(const char *team);