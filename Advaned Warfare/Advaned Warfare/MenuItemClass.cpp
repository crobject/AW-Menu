#include "MenuItemClass.h"


MenuItemClass::MenuItemClass(void)
{
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
