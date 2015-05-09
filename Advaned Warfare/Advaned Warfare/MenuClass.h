#pragma once
#include "stdafx.h"
#include "MenuItemClass.h"
class MenuClass
{
public:
	
	MenuClass(void);
	~MenuClass(void);

	virtual void Render();
	virtual void ScrollDown();
	virtual float getItemDifference();
	virtual const char* getFont();
	virtual float getFontScale();
	virtual float getXPosition();
	virtual float getYPosition();

	string& getTitle();
	vector<MenuItemClass>& getMenuItems();
	MenuItemClass* getSelectedItem();
protected:
	string m_title;
	vector<MenuItemClass> m_menuItems;
	vector<MenuItemClass>::iterator m_selectedItem;
	HUDElem m_scrollBar;
	HUDElem m_background;
};