#include <iostream>
#include "TEditor.h"

std::string commands[] = {
	"Add digit",
	"Flip sign",
	"Add floating point delimiter",
	"Delete last digit",
	"Clear complex number",
	"Output complex number",
	"Input complex number",
	"Select editing part"
};

int main()
{
    TEditor editor;
	while (1)
	{
		system("CLS");
		int command;
		std::cout << "List of commands:" << std::endl;
		int index = 1;
		for (std::string cmd : commands) {
			std::cout << "\t" << index++ << ") " << cmd << std::endl;
		}
		std::cout << "\t0) Exit" << std::endl;
		std::cout << "\nEnter command: ";
		std::cin >> command;
		if (command == 0) {
			break;
		}
		editor.processCommand(command);
	}
}
