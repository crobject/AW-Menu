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
	virtual void ScrollUP();
	virtual void ScrollRight();
	virtual void ScrollLeft();
	virtual float getItemDifference();
	virtual const char* getFont();
	virtual float getFontScale();
	virtual float getXPosition();
	virtual float getYPosition();
	virtual const char* getXAlign();
	virtual const char* getYAlign();
	virtual const char* getVertAlign();
	virtual const char* getHorizAlign();
	string& getTitle();
	vector<MenuItemClass>& getMenuItems();
	MenuItemClass* getSelectedItem();
	void AddItem(MenuItemClass Item);
protected:
	string m_title;
	vector<MenuItemClass> m_menuItems;
	vector<MenuItemClass>::iterator m_selectedItem;
	HUDElem m_scrollBar;
	HUDElem m_background;
};