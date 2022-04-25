#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
	std::time_t start = time(nullptr);
	std::tm timer = *std::localtime(&start);
	std::cout << "Enter time for timer on format MM:SS: ";
	std::cin >> std::get_time(&timer, "%M:%S");

	int countdown = timer.tm_min * 60 + timer.tm_sec;
	std::time_t current = time(nullptr);
	start = current;
	int totalSec = countdown;

	while (current != start + totalSec)
	{
		current = time(nullptr);
		if (current == start + totalSec - countdown)
		{
			system("cls");
			int min = countdown / 60;
			int sec = countdown % 60;
			if (min < 10)
			{
				std::cout << "0";
			}
			std::cout << min << ":";
			if (sec < 10)
			{
				std::cout << "0";
			}
			std::cout << sec << std::endl;
			--countdown;
		}
	}
	std::cout << "DING! DING! DING!" << std::endl;
}