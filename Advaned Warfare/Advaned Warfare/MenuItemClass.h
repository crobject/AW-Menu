#pragma once
#include "stdafx.h"
#include "HUDElem.h"
class MenuItemClass
{
public:
	MenuItemClass(void);
	MenuItemClass(string name, void (*fn)(void* client), bool * toggle = 0);
	~MenuItemClass(void);

	virtual void call();

	const string& getName();
	const vec3_t& getSelectedColor(); 
	const vec3_t& getUnselectedColor(); 
	HUDElem getElem();
	void setElem(HUDElem elem);

private:
	string m_name;
	bool* m_toggle;
	void (*m_function)(void* client);
	HUDElem m_elem;
	vec3_t m_selectedColor;
	vec3_t m_unselectedColor;
};

