#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/color.hpp"

#include <string>
#include <iostream>

void main() {
	auto screen = ftxui::ScreenInteractive::Fullscreen();
	std::cout << "\033[?25l";
	bool show_modal = false;


	auto exit_action  = [&]{ screen.Exit(); };
	auto exit_button  = ftxui::Container::Vertical({
		ftxui::Renderer([] { return ftxui::emptyElement(); }),
		ftxui::Button("X", exit_action, ftxui::ButtonOption::Ascii()) | ftxui::bold | ftxui::align_right,
	});

	auto header = ftxui::hbox({
		ftxui::text("EnCrypt C++") | ftxui::center | ftxui::border | size(ftxui::WIDTH, ftxui::EQUAL, 15),
	}) | ftxui::center;

	auto open_modal = [&]{ show_modal = true; };
	auto app_menu = ftxui::Container::Horizontal({
		ftxui::Renderer([] { return ftxui::emptyElement(); }),
		ftxui::Button("Create", open_modal, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Read", []{}, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Edit", []{}, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Delete", []{}, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("List", []{}, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Lost keys", []{}, ftxui::ButtonOption::Ascii()) | ftxui::center,
	}) | ftxui::border | ftxui::center;

	
	auto close_btn  = ftxui::Container::Vertical({
		ftxui::Renderer([] { return ftxui::emptyElement(); }),
		ftxui::Button("X", [&] { show_modal = false; exit_button->TakeFocus(); }, ftxui::ButtonOption::Ascii()) | ftxui::align_right,
	});

	auto text_data = ftxui::vbox({
		ftxui::text("Create Account"),
	});

	std::string account_name;
	std::string password;

	ftxui::InputOption password_option;
	password_option.password = true;
	ftxui::Component input_password = ftxui::Input(&password, "password", password_option);

	auto account_form = ftxui::Container::Vertical({
		ftxui::Input(&account_name, "account name"),
		input_password,
	});

	
	auto modal_container = ftxui::Container::Vertical({
		close_btn,
		account_form,
	});

	auto modal_renderer = ftxui::Renderer(modal_container, [&] {
		return ftxui::vbox({
			close_btn->Render(),
			ftxui::separator(),
			text_data,
			ftxui::text(""),
			account_form->Render(),
		}) | ftxui::border;
	});


	auto main_container = ftxui::Container::Vertical({
		exit_button,
		app_menu,
	});

	auto main_renderer = ftxui::Renderer(main_container, [&] {
		return ftxui::vbox({
			exit_button->Render(),
			header,
			ftxui::text(""),
			app_menu->Render(),
		});
	});

	
	auto app_with_modal = Modal(
		main_renderer,     
		modal_renderer,    
		&show_modal        
	);

	screen.Loop(app_with_modal);
}