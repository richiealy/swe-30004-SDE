#include "GameStateManager.h"
#include "MessageCentre.h"

int main()
{
	MessageCentre* MsgCentre = new MessageCentre();
	GameStateManager* Game = new GameStateManager(MsgCentre);
	Game->Draw();

	return 0;
}