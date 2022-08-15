#include<functional>
#ifndef ANIM_UTILS_H
#define ANIM_UTILS_H

	void save_art(int asset_index);
	int get_random(int upper_bound);
	int parse_index(int argc, char **argv);
	std::function<void(void)> get_anim(int anim_index);

#endif

