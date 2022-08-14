#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "utils.h"
#include "sl.h"
#include "bears.h"

static char *bear1_lines[BEAR_HEIGHT] = { 
    _1_BEAR_0,    
    _1_BEAR_1,    
    _1_BEAR_2,    
    _1_BEAR_3,    
    _1_BEAR_4,    
    _1_BEAR_5,    
    _1_BEAR_6,    
    _1_BEAR_7,    
    _1_BEAR_8,    
    _1_BEAR_9,    
    _1_BEAR_10,    
    _1_BEAR_11,    
    _1_BEAR_12,    
    _1_BEAR_13,    
    _1_BEAR_14,    
    _1_BEAR_15,    
    _1_BEAR_16,    
    _1_BEAR_17,    
    _1_BEAR_18    
};

static char *bear2_lines[BEAR_HEIGHT + 1] = { 
    _2_BEAR_0,    
    _2_BEAR_1,    
    _2_BEAR_2,    
    _2_BEAR_3,    
    _2_BEAR_4,    
    _2_BEAR_5,    
    _2_BEAR_6,    
    _2_BEAR_7,    
    _2_BEAR_8,    
    _2_BEAR_9,    
    _2_BEAR_10,    
    _2_BEAR_11,    
    _2_BEAR_12,    
    _2_BEAR_13,    
    _2_BEAR_14,    
    _2_BEAR_15,    
    _2_BEAR_16,    
    _2_BEAR_17,    
    _2_BEAR_18    
};

void print_bears(WINDOW* bearwin, int bear_line, int x) {
    for (int bear = 0; bear < BEAR_COUNT; bear++) {
        if (x % 2 == 0)
            my_mvwaddstr(bearwin, bear_line, x, bear1_lines[bear_line]);
        else
            my_mvwaddstr(bearwin, bear_line, x, bear2_lines[bear_line]);

        x += BEAR_LENGTH + BEAR_OFFSET;
    }
}


void launch_bears(WINDOW* bearwin) {
    int i, c, x = COLS;
 
    for (; x > -((BEAR_LENGTH + BEAR_OFFSET) * BEAR_COUNT); x -= 5) {
	if((c=wgetch(bearwin))=='h') break;

	werase(bearwin);
        for (i = 0; i < BEAR_HEIGHT; ++i) {
            print_bears(bearwin, i, x);
            usleep(BEAR_PACE);
        }
	wrefresh(bearwin);
    }
}

extern void show_bears(void) {
    initscr();
    cbreak();
    curs_set(0);
    noecho();

    WINDOW *instructwin = newwin(2, 69, 2, (COLS/2) - 35);
    mvwprintw(instructwin, 0, 5, "A group of circus bears has escaped and is out for revenge.");
    mvwprintw(instructwin, 1, 0, "Maybe if you bribe them with some \'h\'oney they will leave you alone.\n");
    wrefresh(instructwin);
    
    WINDOW *bearwin = newwin(BEAR_HEIGHT, COLS, (LINES/2) - (BEAR_HEIGHT/2), 0);
    nodelay(bearwin, TRUE);
    launch_bears(bearwin);

    endwin();
    exit(0);
}
