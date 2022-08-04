#include <iostream>
#include <thread>
#include <Windows.h>
#include "Memory.h"
#include "sdk.hpp"
#include "vector.h"


int main()
{

	process_id = get_process_id("r5apex.exe");//Getting the Process Id
	base_address = get_module_base_address("r5apex.exe");//Getting The Module Base

	cout << "Process id found at " << process_id << endl;//Printing the Process Id (For Debugging and check if all ok)
	cout << "Process Base Address found at 0x" << hex << base_address << endl;
	
	uintptr_t localplayer = Read<uintptr_t>(base_address + Offsets::local_player);



	while (true)
	{
		for (int i = 0; i < 40; ++i)
		{
			uint64_t player = Read<uint64_t>(base_address + Offsets::cl_entitylist + (i << 5));

			//sorts out alive players form dead ect
			if (player == NULL) continue;
			int health = Read<int>(player + Offsets::OFFSET_HEALTH);
			if (health == 0) continue;

			//cheacks team, you team will not glow
			int team = Read<int>(player + Offsets::OFFSET_TEAM);
			int LocalTeam = Read<int>(localplayer + Offsets::OFFSET_TEAM);
			if (team == LocalTeam)continue;

			Write<int>(player + Offsets::glow_color, RGB(200, 200, 6));//  red
			Write<int>(player + Offsets::glow_enable, 1);//  Enable Glow
			Write<int>(player + Offsets::OFFSET_GLOW_THROUGH_WALLS, 2); // Enable Glow Through Walls
			Write<GlowMode>(player + Offsets::glow_type, { 0, 118, 100, 100 });// Glow Mode

		}
	}
}