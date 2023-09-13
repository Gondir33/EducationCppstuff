#include <iostream>

int main( ) {
	int t_room, t_cond;
	std::string mode;
	std::cin >> t_room >> t_cond;
	std::cin >> mode;
	if (mode == "heat") {
		if (t_cond > t_room)
			std::cout << t_cond;
		else
			std::cout << t_room;
	} else if (mode == "freeze") {
		if (t_room < t_cond)
			std::cout << t_room;
		else
			std::cout << t_cond;
	} else if (mode == "auto") {
		std::cout << t_cond;
	} else {
		std::cout << t_room;
	}
}