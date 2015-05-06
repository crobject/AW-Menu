#include "MenuClass.h"


MenuClass::MenuClass(void)
{
}


MenuClass::~MenuClass(void)
{
}

void MenuClass::Render()
{
	for_each(m_menuItems.begin(),m_menuItems.end(),[](MenuItemClass* menuItem)
	{
		
	}
	);
}

string MenuClass::getTitle()
{
	return m_title;
}
vector<MenuItemClass> MenuClass::getMenuItems()
{
	return m_menuItems;
}
MenuItemClass* MenuClass::getSelectedItem()
{
	return m_selectedItem;
}
