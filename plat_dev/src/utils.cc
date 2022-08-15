#include<iostream>
#include<fstream>
#include<cstdlib>
#include<random>
#include<chrono>
#include<functional>
#include<unistd.h>
#include<stdio.h>
#include<limits.h>
#include "anims.h"

std::function<void(void)> anims[] = {
	&show_sl,
	&show_ducks,
	&show_bears
};

const size_t NUM_ANIMS = sizeof anims / sizeof anims[0], NUM_ASSETS = 6;

// pernicious extra credit function that writes art from a random file in the assets directory to a file in the current working directory
extern void save_art(int asset_index);

extern int get_random(int upper_bound)
{
	return std::bind(std::uniform_int_distribution<int>(0, upper_bound), std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count()))(); 
}

extern int parse_index(int argc, char **argv)
{
	char *anim_index = NULL;
	int c, parsed_anim_index, asset_index;
	
	opterr = 0;

	while((c = getopt(argc, argv, "wn:")) != -1)
		switch(c) {
			case 'w':
				asset_index = get_random(NUM_ASSETS - 1);
				save_art(asset_index);
				break;
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
		parsed_anim_index = anim_index != NULL ? std::stoi(anim_index) : -1;
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

void save_art(int asset_index)
{
	char buffer[PATH_MAX];

	if (getcwd(buffer, sizeof(buffer)) != NULL) {
		printf("Current working directory : %s\n", buffer);
	} 	

	
	std::string working_directory_path = buffer, asset_base_path = "/usr/share/mysl/assets/", asset_num = std::to_string(asset_index), asset_ext = ".txt", asset_path, newfile_path, current_line;

	asset_path = asset_base_path + asset_num + asset_ext;
	newfile_path = working_directory_path + "/" + asset_num + asset_ext;	

	std::ifstream i;
	std::ofstream o;

	i.open(asset_path);
	o.open(newfile_path);

	while(getline(i, current_line))
		o << current_line << '\n';	
}

