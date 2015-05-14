#include "MenuItemClass.h"


MenuItemClass::MenuItemClass(void)
{
}

MenuItemClass::MenuItemClass(string name, void (*fn)(void* client), bool * toggle)
{
	m_name = name;
	m_function = fn;
	m_toggle = toggle;
}
MenuItemClass::~MenuItemClass(void)
{

}
void MenuItemClass::setElem(HUDElem elem)
{
	m_elem = elem;
}
void MenuItemClass::call()
{
	m_function(NULL);
	if(m_toggle)
		*m_toggle ^= 1;
}

const string& MenuItemClass::getName()
{
	return m_name;
}
HUDElem MenuItemClass::getElem()
{
	return m_elem;
}
const vec3_t& MenuItemClass::getSelectedColor()
{
	return m_selectedColor;
}
const vec3_t& MenuItemClass::getUnselectedColor()
{
	return m_unselectedColor;
}
