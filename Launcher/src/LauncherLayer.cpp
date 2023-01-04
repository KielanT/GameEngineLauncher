#include "LauncherLayer.h"
#include "imgui_internal.h"


LauncherLayer::LauncherLayer()
{
	m_Image = std::make_shared<Walnut::Image>("Resources/BasicTex.png");

	// TODO if recent projects exist then set recent else set new
	selectedBtn = SelectedBtn::RECENT;
}

void LauncherLayer::OnUIRender()
{
	
	ImGuiWindowFlags flags = 0;

	//ImGuiViewport* viewport = ImGui::GetMainViewport();
	//ImGui::SetNextWindowPos(viewport->Pos);
	//ImGui::SetNextWindowSize(viewport->Size);
	//ImGui::SetNextWindowViewport(viewport->ID);
	//
	//ImGui::Begin("MainWindow", (bool*)0, flags);
	//
	//
	//ImGui::End();
	
	TopBar();
	ButtonPanel();
	MainAreaPanels();
	BottomBar();
	
	//ImGui::ShowDemoWindow();
	
}

void LauncherLayer::TopBar()
{
	ImGuiWindowFlags flags = 0;

	ImGui::Begin("TopBar", (bool*)0, flags);

	ImGui::End();
}

void LauncherLayer::ButtonPanel()
{
	ImGuiWindowFlags flags = 0;

	ImGui::Begin("ButtonPanel", (bool*)0, flags);


	auto pos = ImGui::GetCursorPos();
	std::vector<const char*> c;
	c.push_back("Recent");
	c.push_back("New");

	for (int i = 0; i < 2; i++)
	{
		ImGui::PushID(i);
		
		char buf[32];
		sprintf(buf, "##Object %d", i);
		
		ImGui::SetCursorPos(ImVec2(pos.x, pos.y));
		if (ImGui::Selectable(buf, i == bTest, 0, { (float)m_Image->GetWidth(), (float)m_Image->GetHeight() }))
		{
			selectedBtn = static_cast<SelectedBtn>(i);
		}
		ImGui::SetItemAllowOverlap();
		ImGui::SetCursorPos(ImVec2(pos.x, pos.y));
		ImGui::Image(m_Image->GetDescriptorSet(), { (float)m_Image->GetWidth(), (float)m_Image->GetHeight() });
		ImVec2 textPos = pos;
		textPos.x += ((float)m_Image->GetWidth() - ImGui::CalcTextSize(c[i]).x) * 0.5f;
		textPos.y += ((float)m_Image->GetHeight() - ImGui::CalcTextSize(c[i]).y) * 0.5f;
		ImGui::SetCursorPos(textPos);
		ImGui::Text(c[i]);

		pos.y += (float)m_Image->GetHeight() + 20.0f;
		
		
		
		ImGui::PopID();
	}

	ImGui::End();
}

void LauncherLayer::MainAreaPanels()
{
	ImGuiWindowFlags flags = 0;

	ImGui::Begin("MainAreaPanel", (bool*)0, flags);

	if (selectedBtn == SelectedBtn::RECENT)
	{
		ImGui::Text("Recent");

	}
	if (selectedBtn == SelectedBtn::NEW)
	{
		ImGui::Text("New");
	}

	ImGui::End();
}

void LauncherLayer::BottomBar()
{
	ImGuiWindowFlags flags = 0;

	ImGui::Begin("BottomBar", (bool*)0, flags);

	ImGui::End();
}

//void LauncherLayer::SelectableButtonWithCentredLable(const char* label, bool* p_Selected, std::shared_ptr<Walnut::Image> image, std::string fmt)
//{
//	ImVec2 OrginalVec = ImGui::GetCursorStartPos();
//	ImVec2 vec2 = ImGui::GetCursorStartPos();
//	ImGui::Selectable(label, p_Selected, 0, { (float)image->GetWidth(), (float)image->GetHeight() });
//	ImGui::SetCursorPos(vec2);
//	ImGui::Image(image->GetDescriptorSet(), { (float)image->GetWidth(), (float)image->GetHeight() });
//	vec2.x += ((float)image->GetWidth() - ImGui::CalcTextSize(fmt.c_str()).x) * 0.5f;
//	vec2.y += ((float)image->GetHeight() - ImGui::CalcTextSize(fmt.c_str()).y) * 0.5f;
//	ImGui::SetCursorPos(vec2);
//	ImGui::Text(fmt.c_str());
//	OrginalVec.y += image->GetHeight();
//	ImGui::SetCursorPos(OrginalVec);
//	
//}
