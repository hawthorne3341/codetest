#include<criterion/criterion.h>

#define BIN_PATH "./bin/codetest"

Test(cli_tests, n_flag_in_range) {
	int argc = 3;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-n";
	argv[2] = (char *)"2";

//	test logic
	cr_assert(1 == 1);
}

Test(cli_tests, n_flag_outside_range) {
	int argc = 3;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-n";
	argv[2] = (char *)"10";

//	test logic
	cr_assert(1 == 1);
}

Test(cli_tests, no_n_flag) {
	int argc = 1;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;

//	test logic
	cr_assert(1 == 1);
}

Test(cli_tests, unknown_flag) {
	int argc = 2;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-q";

//	test logic
	cr_assert(1 == 1);
}

Test(cli_tests, unknown_character) {
	int argc = 3;
	char **argv = new char *[argc];
	
	argv[0] = (char *)BIN_PATH;
	argv[1] = (char *)"-ы";

//	test logic
	cr_assert(1 == 1);
}
