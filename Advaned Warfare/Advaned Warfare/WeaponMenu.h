#include "MenuClass.h"
#include "GSC.h"
#pragma once
class WeaponMenu : public MenuClass
{
public:
	WeaponMenu(void);
	~WeaponMenu(void);

	void Render();
	
	void ScrollDown();
	void ScrollUP();
	void ScrollRight();
	void ScrollLeft();

	float getXPosition();
	float getYPosition();
	
};

