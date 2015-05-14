#include "MenuClass.h"


MenuClass::MenuClass(void)
{
}


MenuClass::~MenuClass(void)
{
	for_each(m_menuItems.begin(),m_menuItems.end(),[](MenuItemClass menuItem)
		{
			menuItem.getElem().FreeElem();
		}
	);
}

void MenuClass::Render()
{
	int count = 0;
	for_each(m_menuItems.begin(),m_menuItems.end(),[&](MenuItemClass menuItem)
		{
			menuItem.setElem(NewClientHudElem(0));
			menuItem.getElem().SetPoint(getXAlign(),getYAlign(),getHorizAlign(),getVertAlign(),getXPosition(),getYPosition() + (getItemDifference() * static_cast<float>(count)));
			menuItem.getElem().SetText(menuItem.getName().c_str(),getFont(),getFontScale());
			count++;
		}
	);
}
void MenuClass::ScrollDown()
{
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getUnselectedColor());
	if(m_selectedItem != m_menuItems.end())
	{
		m_selectedItem++;
	}
	else
	{
		m_selectedItem = m_menuItems.begin();
	}
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getSelectedColor());
	m_scrollBar.SetY((*m_selectedItem).getElem().GetX());
	m_scrollBar.MoveOverTime(0.25);
}
void MenuClass::ScrollUP()
{
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getUnselectedColor());
	if(m_selectedItem != m_menuItems.begin())
	{
		m_selectedItem--;
	}
	else
	{
		m_selectedItem = m_menuItems.end();
	}
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getSelectedColor());
	m_scrollBar.SetY((*m_selectedItem).getElem().GetX());
	m_scrollBar.MoveOverTime(0.25);
}

void MenuClass::ScrollRight()
{
	//not used in base class
}
void MenuClass::ScrollLeft()
{
	//not used in base class
}
void MenuClass::AddItem(MenuItemClass Item)
{
	m_menuItems.push_back(Item);
}
string& MenuClass::getTitle()
{
	return m_title;
}
vector<MenuItemClass>& MenuClass::getMenuItems()
{
	return m_menuItems;
}
MenuItemClass* MenuClass::getSelectedItem()
{
	return &(*m_selectedItem);
}
float MenuClass::getItemDifference()
{
	return 20;
}
const char* MenuClass::getFont()
{
	return "default";
}
float MenuClass::getFontScale()
{
	return 1.5;
}
float MenuClass::getXPosition()
{
	return 0;
}
float MenuClass::getYPosition()
{
	return 25;
}
const char* MenuClass::getXAlign()
{
	return "center";
}
const char* MenuClass::getYAlign()
{
	return "top";
}
const char* MenuClass::getVertAlign()
{
	return "center";
}
const char* MenuClass::getHorizAlign()
{
	return "top";
}