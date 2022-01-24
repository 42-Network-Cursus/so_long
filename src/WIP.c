


#include "../head/so_long.h"

// TO DO
// *Map input checker
//			TO TEST
//		** check .ber file type #OK
//		** 5 symbols (0 1 C E P) #OK
//		** Must have 1 Exit 1 Player 1 Collectible #OK
//		** Walls all around #OK
//		** Rectangle #OK
//		

// *Window // map generator
//		** Handle minimize (clears img atm)
//		** Create window // map W H
//		** push img from map
//		(** next window for bigger maps)
// *HOW TO MOVE PLAYER (Keyhook?)
//		** Player cannot move into wall
//		** Use wasd + arrows for movement
// *Display nbr of moves in terminal

int main(int ac, char **av)
{
	map_check(av[1]);

	return (0);
}