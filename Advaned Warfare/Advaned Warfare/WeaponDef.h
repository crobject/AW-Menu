//Not Made by me http://codresearch.com/index.php/Weapon_Asset_(AW)
union ScriptString
{
	short scr_string_t;
};
union snd_alias_list_name
{
  char * name;
  void * asset;
};
struct WeaponDefStruct9
{
	char unknown1[0xD4];
};	
 
struct WeaponDefStruct8
{
	void *material1;
	void *material2;
	void *material3;
	void *material4;
	char unknown1[0x18];
};	
 
struct WeaponDefStruct7
{
	char unknown1[4];
	snd_alias_list_name snd1;
	snd_alias_list_name snd2;
	snd_alias_list_name snd3;
	snd_alias_list_name snd4;
};	
 
struct WeaponDefStruct6
{
	const char *xstring1;
	void *material1;
	void *fx1;
	char unknown1[0x68];
};	
 
struct WeaponDefStruct5
{
	char unknown1[4];
	ScriptString (*scriptStrings1)[0x24];
	ScriptString (*scriptStrings2)[0x24];
};	
 
struct WeaponDefStruct3
{
	char unknown1[4];
	void *fx1;
	void *fx2;
};	
 
struct WeaponDefStruct2
{
	char unknown1[4];
	snd_alias_list_name snd1;
	snd_alias_list_name snd2;
};	
 
struct WeaponDefStruct1
{
	char unknown1[4];
	void *xanim1;
	void *xanim2;
	char unknown2[8];
};	
 
struct WeaponDef 
{
	const char *szInternalName;	
	const char *szDisplayName;	
	const char *szOverlayName;	
	int (*xmodelArray1)[2];	
	void *handXModel;		
	void *xmodel2;		
	const char *xstring1;		
	void *material1;		
	void *material2;		
	int (*animR)[0xB4];	
	int (*animL)[0xB4];	
	ScriptString (*scriptStrings0)[0x20];	
	void *attachments1;	
	int (*xanimArray3)[0xB4];	
	WeaponDefStruct1 *struct1;	
	WeaponDefStruct2 *struct2;	
	WeaponDefStruct3 *struct3;	
	int *array1;			
	WeaponDefStruct5 *struct5;	
	ScriptString (*scriptStrings1)[0x24];	
	ScriptString (*scriptStrings2)[0x24];	
	ScriptString (*scriptStrings3)[0x10];	
	ScriptString (*scriptStrings4)[0x10];	
	ScriptString (*scriptStrings5)[0x10];	
	ScriptString (*scriptStrings6)[0x10];	
	ScriptString (*scriptStrings7)[0x10];	
	const char *xstring2;		
	void *fx1;		
	void *fx2;		
	void *fx3;		
	void *fx4;		
	void *fx5;		
	void *fx6;		
	void *fx7;		
	void *fx8;		
	void *fx9;		
	void *fx10;		
	void *fx11;		
	void *fx12;		
	snd_alias_list_name pickUpSound;	
	snd_alias_list_name pickUpSoundPlayer;	
	snd_alias_list_name ammoPickupSound;	
	snd_alias_list_name ammoPickupSoundPlayer;	
	snd_alias_list_name snd5;	
	snd_alias_list_name snd6;	
	snd_alias_list_name snd7;	
	snd_alias_list_name snd8;	
	snd_alias_list_name snd9;	
	snd_alias_list_name snd10;	
	snd_alias_list_name snd11;	
	snd_alias_list_name snd12;	
	snd_alias_list_name snd13;	
	snd_alias_list_name snd14;	
	snd_alias_list_name snd15;	
	snd_alias_list_name snd16;	
	snd_alias_list_name snd17;	
	snd_alias_list_name snd18;	
	snd_alias_list_name snd19;	
	snd_alias_list_name snd20;	
	snd_alias_list_name snd21;	
	snd_alias_list_name snd22;	
	snd_alias_list_name snd23;	
	snd_alias_list_name snd24;	
	snd_alias_list_name snd25;	
	snd_alias_list_name snd26;	
	snd_alias_list_name snd27;	
	snd_alias_list_name snd28;	
	snd_alias_list_name snd29;	
	snd_alias_list_name snd30;	
	snd_alias_list_name snd31;	
	snd_alias_list_name snd32;	
	snd_alias_list_name snd33;	
	snd_alias_list_name snd34;	
	snd_alias_list_name snd35;	
	snd_alias_list_name snd36;	
	snd_alias_list_name snd37;	
	snd_alias_list_name snd38;	
	snd_alias_list_name snd39;	
	snd_alias_list_name snd40;	
	snd_alias_list_name snd41;	
	snd_alias_list_name snd42;	
	snd_alias_list_name snd43;	
	snd_alias_list_name snd44;	
	snd_alias_list_name snd45;	
	snd_alias_list_name snd46;	
	snd_alias_list_name snd47;	
	snd_alias_list_name snd48;	
	snd_alias_list_name snd49;	
	snd_alias_list_name snd50;	
	snd_alias_list_name snd51;	
	snd_alias_list_name snd52;	
	snd_alias_list_name snd53;	
	snd_alias_list_name snd54;	
	snd_alias_list_name snd55;	
	snd_alias_list_name snd56;	
	snd_alias_list_name snd57;	
	snd_alias_list_name snd58;	
	snd_alias_list_name snd59;	
	snd_alias_list_name snd60;	
	snd_alias_list_name snd61;	
	snd_alias_list_name snd62;	
	snd_alias_list_name raiseSound;	
	snd_alias_list_name raiseSoundPlayer;	
	snd_alias_list_name firstRaiseSound;	
	snd_alias_list_name firstRaiseSoundPlayer;	
	snd_alias_list_name putawaySound;	
	snd_alias_list_name putawaySoundPlayer;	
	snd_alias_list_name snd69;	
	snd_alias_list_name snd70;	
	snd_alias_list_name snd71;	
	snd_alias_list_name snd72;	
	snd_alias_list_name snd73;	
	snd_alias_list_name snd74;	
	snd_alias_list_name snd75;	
	snd_alias_list_name snd76;	
	snd_alias_list_name snd77;	
	snd_alias_list_name snd78;	
	snd_alias_list_name snd79;	
	snd_alias_list_name snd80;	
	snd_alias_list_name snd81;	
	snd_alias_list_name snd82;	
	snd_alias_list_name snd83;	
	snd_alias_list_name snd84;	
	snd_alias_list_name snd85;	
	snd_alias_list_name (*parallelBounceSound)[0x35];	
	snd_alias_list_name (*perpendicularBounceSound)[0x35];	
	void *viewShellEjectEffect;		
	void *worldShellEjectEffect;		
	void *viewLastShotEjectEffect;		
	void *worldLastShotEjectEffect;		
	void *fx17;		
	void *reticleCenter;		
	void *reticleSide;		
	int (*xmodelArray2)[0x2];	
	void *xmodel3;		
	void *xmodel4;		
	void *xmodel5;		
	void *xmodel6;		
	void *material5;		
	void *material6;		
	void *material7;		
	void *material8;		
	void *material9;		
	void *material10;		
	const char *xstring3;		
	const char *xstring4;		
	const char *xstring5;		
	void *physCollMap;	
	void *physPreset;		
	const char *xstring6;		
	const char *xstring7;		
	float (*locationDamageMultipliers)[22];	
	const char *xstring8;		
	const char *xstring9;		
	const char *xstring10;		
	const char *xstring11;		
	void *tracer1;	
	void *tracer2;	
	void *laser1;		
	snd_alias_list_name snd86;	
	void *fx18;		
	const char *xstring12;		
	snd_alias_list_name snd87;	
	snd_alias_list_name snd88[4];	
	snd_alias_list_name snd89[4];	
	snd_alias_list_name snd90;	
	snd_alias_list_name snd91;	
	void *xmodel7;		
	WeaponDefStruct7 *struct8;	
	char unknown1[0x3BC];		
	WeaponDefStruct8 struct9;	
	char unknown2[0x104];		
	void *material11;		
	void *material12;		
	void *material13;		
	char unknown3[0x60];		
	const char *xstring13;		
	void *xmodel8;		
	void *fx19;		
	void *fx20;		
	snd_alias_list_name snd92;	
	snd_alias_list_name snd93;	
	char unknown4[0x18];		
	WeaponDefStruct9 *struct10;	
	WeaponDefStruct9 *struct11;	
	void *fx21;		
	void *fx22;		
	char unknown5[0x18];
	void *fx23;		
	snd_alias_list_name snd94;	
	char _unknown5[0xB8];		
	const char *accuracyGraphName[2];
	void *accuracyGraphKnots;	
	void *orignalAccuracyGraphKnots;
	short accuracyGraphKnotCount[2];
	char unknown6[0x64];		
	const char *xstring16;		
	char unknown7[0xA4];		
	ScriptString scriptString1;	
	char unknown8[0x3E];		
	ScriptString scriptString2;	
	char unknown9[0x82];		
};