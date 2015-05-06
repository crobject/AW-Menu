#pragma once
#include "stdafx.h"
#include "MenuItemClass.h"
class MenuClass
{
public:
	
	MenuClass(void);
	~MenuClass(void);

	virtual void Render();
	virtual void Scroll();

	string getTitle();
	vector<MenuItemClass> getMenuItems();
	MenuItemClass* getSelectedItem();
protected:
	string m_title;
	vector<MenuItemClass> m_menuItems;
	MenuItemClass* m_selectedItem;
};