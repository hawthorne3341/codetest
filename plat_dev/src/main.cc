#include "utils.h"

int main(int argc, char **argv)
{
	int anim_index = parse_index(argc, argv);
	get_anim(anim_index)();
	return 0;
}
