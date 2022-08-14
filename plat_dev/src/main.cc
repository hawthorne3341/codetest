#include "utils.h"

__asm__(".symver realpath,realpath@GLIBC_2.2.5");
int main(int argc, char **argv)
{
	int anim_index = parse_index(argc, argv);
	get_anim(anim_index)();
	return 0;
}
