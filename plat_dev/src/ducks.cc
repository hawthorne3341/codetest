#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "ducks.h"
#include "utils.h"

extern void show_ducks(void) {
    initscr();
    cbreak();
    curs_set(0);
    noecho();

    static char *ducks_anim[NUM_SCENES][SCENE_HEIGHT]
        = {{DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS0_1, DUCKS0_2, DUCKS0_3, DUCKS0_4},
           {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS1_1, DUCKS1_2, DUCKS1_3, DUCKS1_4},
           {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS2_1, DUCKS2_2, DUCKS2_3, DUCKS2_4},
           {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS3_1, DUCKS3_2, DUCKS3_3, DUCKS3_4},
           {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS4_1, DUCKS4_2, DUCKS4_3, DUCKS4_4},
           {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS5_1, DUCKS5_2, DUCKS5_3, DUCKS5_4},
	   {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS6_1, DUCKS6_2, DUCKS6_3, DUCKS6_4},
	   {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS7_1, DUCKS7_2, DUCKS7_3, DUCKS7_4},
	   {DUCKSBASE1, DUCKSBASE2, DUCKSBASE3, DUCKSBASE4, DUCKS0_1, DUCKS0_2, DUCKS0_3, DUCKS0_4}};

    WINDOW *duckswin = newwin(SCENE_HEIGHT, SCENE_WIDTH, (LINES/2) - (SCENE_HEIGHT/2), (COLS/2) - (SCENE_WIDTH/2));
    WINDOW *instructwin = newwin(INSTRUCT_HEIGHT, INSTRUCT_WIDTH, 5, (COLS/2) - (SCENE_WIDTH/2));

    mvwprintw(instructwin, 0, 0, "Call the ducks by pressing any key\n\nPress \'%c\' to quit", QUIT_KEY);

    refresh();
    wrefresh(instructwin);
    wrefresh(duckswin);


    int wc;
    do {
        for (int j = 0, i = 0; j < NUM_SCENES; j ++) {
    	    for (; i < SCENE_HEIGHT; i++) {
    		mvwprintw(duckswin, i, 0, ducks_anim[j][i]);
    	        wrefresh(duckswin);	
		usleep(DUCK_PACE);
    	    }	
    	    i = 0;
    	}
    } while((wc=wgetch(duckswin))!=QUIT_KEY); 

    endwin();
    exit(0);
}
