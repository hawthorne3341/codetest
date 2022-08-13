#include<functional>
#ifndef ANIM_UTILS_H
#define ANIM_UTILS_H

	int get_random_index();
	int parse_index(int argc, char **argv);
	std::function<void(void)> get_anim(int anim_index);

#endif

