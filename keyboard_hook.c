#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>
#include <string.h>

const char* get_key_text(int code) {
    static const char* keymap[] = {
            [KEY_1] = "1", [KEY_2] = "2", [KEY_3] = "3",
            [KEY_4] = "4", [KEY_5] = "5", [KEY_6] = "6",
            [KEY_7] = "7", [KEY_8] = "8", [KEY_9] = "9",
            [KEY_0] = "0",
            [KEY_A] = "A", [KEY_B] = "B", [KEY_C] = "C",
            [KEY_D] = "D", [KEY_E] = "E", [KEY_F] = "F",
            [KEY_G] = "G", [KEY_H] = "H", [KEY_I] = "I",
            [KEY_J] = "J", [KEY_K] = "K", [KEY_L] = "L",
            [KEY_M] = "M", [KEY_N] = "N", [KEY_O] = "O",
            [KEY_P] = "P", [KEY_Q] = "Q", [KEY_R] = "R",
            [KEY_S] = "S", [KEY_T] = "T", [KEY_U] = "U",
            [KEY_V] = "V", [KEY_W] = "W", [KEY_X] = "X",
            [KEY_Y] = "Y", [KEY_Z] = "Z",
    };

    if (code < sizeof(keymap)/sizeof(keymap[0]) && keymap[code]) {
        return keymap[code];
    } else {
        return "Невідома клавіша";
    }
}

const char* get_key_state_text(int value) {
    switch (value) {
        case 0: return "відпущена";
        case 1: return "натиснута";
        case 2: return "зажата";
        default: return "невідомо";
    }
}

int main() {
    int fd;
    struct input_event ev;

    fd = open("/dev/input/event2", O_RDONLY);
    if (fd < 0) {
        perror("Не можу відкрити пристрій");
        return 1;
    }

    printf("Слухаємо клавіатурні події. Натисніть клавіші...\n");

    while (read(fd, &ev, sizeof(struct input_event)) > 0) {
        if (ev.type == EV_KEY) {
            printf("Клавіша '%s' %s\n", get_key_text(ev.code), get_key_state_text(ev.value));
        }
    }

    close(fd);
    return 0;
}