/*
 * testView.cpp
 *
 *  Created on: 3 janv. 2016
 *      Author: Quincy
 */

#include "../platform/GameInfo.hpp"
#include "../platform/Platform.hpp"
#include "../player/Pawn.hpp"
#include "../player/Player.hpp"
#include "../player/PlayerFactory.hpp"
#include "../view/Window.hpp"

int main()
{
	PlayerFactory* pFactory = new PlayerFactory();
	GameInfo* gi = new GameInfo();
	Player* p1 = pFactory->getIAPlayer("AI-1");
	Player* p2 = pFactory->getIAPlayer("AI-2");
	Pawn* pawn1 = new Pawn();
	p1->addPawn(pawn1);
	Pawn* pawn2 = new Pawn();
	p2->addPawn(pawn2);
	gi->addPlayer(p1);
	gi->addPlayer(p2);
	Platform* pf = new Platform(16);
	view::Window* w = new view::Window(gi, pf);
	w->start();
	return 0;
}
