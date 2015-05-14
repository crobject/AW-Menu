#include "WeaponMenu.h"

const int MAX_ITEM_LINE = 5;
const int MAX_LINES_ON_SCREEN = 2;
WeaponMenu::WeaponMenu(void)
{
	WeaponDef * pWeaponDefs = *(WeaponDef**)GameOffsets.Decrypt()._bg_weaponDefs;
	for(int i = 0;i < 307;i++)
	{
		AddItem(MenuItemClass(pWeaponDefs[i].szDisplayName,NULL));
	}
	m_selectedItem = m_menuItems.begin();
}


WeaponMenu::~WeaponMenu(void)
{
}

void WeaponMenu::Render()
{
	int count = 0;
	auto menuItterator = m_selectedItem;
	for_each(menuItterator, m_selectedItem + MAX_LINES_ON_SCREEN,[&](MenuItemClass menuItem)
	{
		menuItem.setElem(NewClientHudElem(0));
		menuItem.getElem().SetPoint(getXAlign(),getYAlign(),getHorizAlign(),getVertAlign(),getXPosition() + (getItemDifference() * static_cast<float>((m_selectedItem - menuItterator) / sizeof(vector<MenuItemClass>::iterator)
			% MAX_ITEM_LINE)), getYPosition());
		menuItem.getElem().SetText(menuItem.getName().c_str(),getFont(),getFontScale());
		count++;
	});
}
void WeaponMenu::ScrollDown()
{
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getUnselectedColor());
	if(m_selectedItem >= m_menuItems.end() - MAX_ITEM_LINE)
	{
		m_selectedItem += MAX_ITEM_LINE;
	}
	else
	{
		m_selectedItem = m_menuItems.begin();
	}
	//lets re-render the menu
	Render();
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getSelectedColor());
	m_scrollBar.SetY((*m_selectedItem).getElem().GetX());
	m_scrollBar.MoveOverTime(0.25);
}
void WeaponMenu::ScrollUP()
{
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getUnselectedColor());
	if(m_selectedItem >= m_menuItems.begin() + MAX_ITEM_LINE)
	{
		m_selectedItem += MAX_ITEM_LINE;
	}
	else
	{
		m_selectedItem = m_menuItems.end();
	}
	Render();
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getSelectedColor());
	m_scrollBar.SetY((*m_selectedItem).getElem().GetX());
	m_scrollBar.MoveOverTime(0.25);
}
void WeaponMenu::ScrollRight()
{
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getUnselectedColor());
	if((m_menuItems.begin() - m_selectedItem) / sizeof(vector<MenuItemClass>::iterator) % MAX_ITEM_LINE != 0)
	{
		//dont scroll if we are at end of line
		m_selectedItem++;
	}
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getSelectedColor());
	m_scrollBar.SetX((*m_selectedItem).getElem().GetX());
	m_scrollBar.MoveOverTime(0.25);	
}
void WeaponMenu::ScrollLeft()
{
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getUnselectedColor());
	if((m_menuItems.begin() - m_selectedItem) / sizeof(vector<MenuItemClass>::iterator) % MAX_ITEM_LINE != 0)
	{
		//dont scroll if we are at end of line
		m_selectedItem++;
	}
	(*m_selectedItem).getElem().SetColor((*m_selectedItem).getSelectedColor());
	m_scrollBar.SetX((*m_selectedItem).getElem().GetX());
	m_scrollBar.MoveOverTime(0.25);	
}

float WeaponMenu::getXPosition()
{
	return -50;
}
float WeaponMenu::getYPosition()
{
	return 50;
}