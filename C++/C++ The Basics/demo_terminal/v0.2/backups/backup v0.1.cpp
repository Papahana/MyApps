// https://arthursonzogni.github.io/FTXUI/getting-started.html

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

	auto exit_action = [&] { screen.Exit(); };
	auto exit_button = ftxui::Container::Vertical({
		ftxui::Renderer([] { return ftxui::emptyElement(); }),
		ftxui::Button("X", exit_action, ftxui::ButtonOption::Ascii()) | ftxui::bold | ftxui::align_right,
	});

	auto header = ftxui::hbox({ 
		ftxui::text("EnCrypt C++") | ftxui::center | ftxui::border | ftxui::size(ftxui::WIDTH, ftxui::EQUAL, 15)
	}) | ftxui::center;

	auto app_menu = ftxui::Container::Horizontal({
		ftxui::Renderer([] { return ftxui::emptyElement(); }),
		ftxui::Button("Create", [&] { std::cout << "Trigger function ..."; }, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Read", [&] { std::cout << "Trigger function ..."; }, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Edit", [&] { std::cout << "Trigger function ..."; }, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Delete", [&] { std::cout << "Trigger function ..."; }, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("List", [&] { std::cout << "Trigger function ..."; }, ftxui::ButtonOption::Ascii()) | ftxui::center,
		ftxui::Button("Lost keys", [&] { std::cout << "Trigger function ..."; }, ftxui::ButtonOption::Ascii()) | ftxui::center,
	}) | ftxui::border | ftxui::center;

	auto main_container = ftxui::Container::Vertical({
      	exit_button,
		app_menu,
  	});

  	auto main_renderer = ftxui::Renderer(main_container, [&] {
		return ftxui::vbox({
			exit_button->Render(),
			header,
			ftxui::text("") /* splitter */,
			app_menu->Render(),
		});
  	});

    screen.Loop(main_renderer);
}