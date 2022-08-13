#include<criterion/criterion.h>
#include "utils.h"

#define BIN_PATH "./bin/codetest"

Test(cli_tests, n_flag_in_range) {
	int argc = 3;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-n";
	argv[2] = (char *)"2";

	cr_expect(parse_index(argc, argv) == 2, "Requested index valid, returns index");
	
	delete[] argv;
}

Test(cli_tests, n_flag_outside_range) {
	int argc = 3;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-n";
	argv[2] = (char *)"10";

	cr_assert(1 == 1);
	cr_expect(parse_index(argc, argv) == -1, "Requested index valid, returns -1");

	delete[] argv;
}

Test(cli_tests, no_n_flag) {
	int argc = 1;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;

	cr_expect(parse_index(argc, argv) == -1, "No index requested, returns -1");

	delete[] argv;
}

Test(cli_tests, n_without_option, .exit_code = 1) {
	int argc = 2;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-n";

	parse_index(argc, argv);

	delete[] argv;
}

Test(cli_tests, unknown_flag, .exit_code = 1) {
	int argc = 2;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-q";

	parse_index(argc, argv);

	delete[] argv;
}

Test(cli_tests, unknown_character, .exit_code = 1) {
	int argc = 3;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-ы";

	parse_index(argc, argv);

	delete[] argv;
}
