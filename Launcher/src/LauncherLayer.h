#pragma once

#include "Walnut/Application.h"
#include "Walnut/Image.h"

enum class SelectedBtn
{
	RECENT = 0,
	NEW
};

class LauncherLayer : public Walnut::Layer
{
public:
	LauncherLayer();

	virtual void OnUIRender() override;

private:
	void TopBar();
	void ButtonPanel();
	void MainAreaPanels();
	void BottomBar();


private:
	bool bTest = false;
	bool bTest2 = false;

	std::shared_ptr<Walnut::Image> m_Image;

	SelectedBtn selectedBtn;
};

// https://github.com/ocornut/imgui/issues/2184 for selectable stuff