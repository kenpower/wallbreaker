#include "MainMenu.hpp"
#include "Core/Game.hpp"
#include "Core/Resources.hpp"
#include "Core/Config.hpp"
#include "Gui/Theme.hpp"
// Screens
#include "Wallbreaker.hpp"
#include "Editor.hpp"
#include "OptionsMenu.hpp"

#define ABOUT_TEXT (APP_TITLE " v" APP_VERSION " - " APP_URL)

MainMenu::MainMenu():
	m_about_text(gui::Theme::getFont()),
	m_menu(Game::getInstance().getWindow())
{
	const sf::Texture& t = Resources::getTexture("title.png");
	m_title.setTexture(t);
	m_title.setPosition(0, 16);

	m_about_text.setString(ABOUT_TEXT);
	m_about_text.setPosition(0, APP_HEIGHT - m_about_text.getSize().y);

	m_menu.setPosition(80, 100);
	m_menu.addButton("New game", 1);
	m_menu.addButton("Editor",   2);
	m_menu.addButton("Options",  3);
	m_menu.addButton("Quit",     4);
}


void MainMenu::onEvent(const sf::Event& event)
{
	switch (m_menu.onEvent(event))
	{
		case 1:
			Game::getInstance().nextScreen(new Wallbreaker);
			break;
		case 2:
			Game::getInstance().nextScreen(new Editor);
			break;
		case 3:
			Game::getInstance().nextScreen(new OptionsMenu);
			break;
		case 4:
			Game::getInstance().quit();
			break;
	}
}


void MainMenu::onFocus()
{
	Game::getInstance().getWindow().setMouseCursorVisible(true);
}


void MainMenu::update(float frametime)
{
	m_about_text.move(-50 * frametime, 0);
	float width = m_about_text.getSize().x;
	if (m_about_text.getPosition().x + width < 0)
	{
		m_about_text.setPosition(APP_WIDTH, m_about_text.getPosition().y);
	}
}


void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.clear({0x16, 0x1e, 0x26});
	target.draw(m_title);
	target.draw(m_about_text);
	m_menu.draw();
}




