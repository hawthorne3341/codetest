#include<iostream>
#include<cstdlib>
#include<random>
#include<chrono>
#include<functional>
#include<unistd.h>
#include "anims.h"

using namespace std;

std::function<void(void)> anims[] = {
	&show_sl,
	&show_ducks,
	&show_bears
};

const size_t NUM_ANIMS = sizeof anims / sizeof anims[0];


extern int get_random(int upper_bound)
{
	return std::bind(std::uniform_int_distribution<int>(0, upper_bound), mt19937(chrono::high_resolution_clock::now().time_since_epoch().count()))(); 
}

extern int parse_index(int argc, char **argv)
{
	char *anim_index = NULL;
	int c, parsed_anim_index;
	
	opterr = 0;

	while((c = getopt(argc, argv, "n:")) != -1)
		switch(c) {
			case 'n':
				anim_index = optarg;
				break;
			case '?':
				if (optopt == 'n')
					fprintf(stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf(stderr,
						"Unknown option character `\\x%x'.\n",
					optopt);
				exit(1);
			default:
				abort();
		}

	try {
		parsed_anim_index = anim_index != NULL ? stoi(anim_index) : -1;
	}
	catch(std::invalid_argument& e){
		fprintf(stderr, "Could not parse argument to -n: %s\n", anim_index);
		return 1;	
	}

	if (parsed_anim_index < 0 || (size_t)parsed_anim_index > (NUM_ANIMS - 1))
		parsed_anim_index = -1;

	return parsed_anim_index;
}

extern std::function<void(void)> get_anim(int anim_index)
{
	if (anim_index == -1) anim_index = get_random(NUM_ANIMS - 1);

	return anims[anim_index];
}

