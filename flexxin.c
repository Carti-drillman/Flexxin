#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> // New module added

#define MAX_VARS 100
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[20];
    int value;
} Variable;

Variable variables[MAX_VARS];
int var_count = 0;

int find_var(char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void set_var(char *name, int value) {
    int index = find_var(name);
    if (index == -1) {
        strcpy(variables[var_count].name, name);
        variables[var_count].value = value;
        var_count++;
    } else {
        variables[index].value = value;
    }
}

int get_var(char *name) {
    int index = find_var(name);
    if (index == -1) {
        printf("Error: Variable '%s' not found.\n", name);
        exit(1);
    }
    return variables[index].value;
}

void execute_line(char *line) {
    char cmd[MAX_LINE_LENGTH];
    char arg1[MAX_LINE_LENGTH];
    char arg2[MAX_LINE_LENGTH];
    char arg3[MAX_LINE_LENGTH]; // New argument for strings
    int value, end;

    if (sscanf(line, "var %s = %d", arg1, &value) == 2) {
        set_var(arg1, value);
    } else if (sscanf(line, "var %s = \"%[^\"]\"", arg1, arg3) == 2) { // New syntax to define strings
        strcpy(variables[var_count].name, arg1);
        variables[var_count].value = atoi(arg3);
        var_count++;
    } else if (sscanf(line, "print \"%[^\"]\"", arg1) == 1) {
        printf("%s\n", arg1);
    } else if (sscanf(line, "print %s", arg1) == 1) {
        printf("%d\n", get_var(arg1));
    } else if (sscanf(line, "%s = %s + %d", arg1, arg2, &value) == 3) {
        set_var(arg1, get_var(arg2) + value);
    } else if (sscanf(line, "%s = %s - %d", arg1, arg2, &value) == 3) {
        set_var(arg1, get_var(arg2) - value);
    } else if (sscanf(line, "%s = %s * %d", arg1, arg2, &value) == 3) {
        set_var(arg1, get_var(arg2) * value);
    } else if (sscanf(line, "%s = %s / %d", arg1, arg2, &value) == 3) {
        set_var(arg1, get_var(arg2) / value);
    } else if (sscanf(line, "if %s == %d", arg1, &value) == 2) {
        if (get_var(arg1) != value) {
            while (fgets(line, sizeof(line), stdin)) {
                if (strncmp(line, "endif", 5) == 0) {
                    break;
                }
            }
        }
    } else if (strncmp(line, "else", 4) == 0) {
        while (fgets(line, sizeof(line), stdin)) {
            if (strncmp(line, "endif", 5) == 0) {
                break;
            }
        }
    } else if (strncmp(line, "endif", 5) == 0) {
        // End of if-else block
    } else if (sscanf(line, "for %s = %d to %d", arg1, &value, &end) == 3) { // Fixed format specifier issue
        for (int i = value; i <= end; i++) {
            set_var(arg1, i);
            fgets(line, sizeof(line), stdin);
            execute_line(line);
        }
    } else if (sscanf(line, "while %s != %d", arg1, &value) == 2) {
        while (get_var(arg1) != value) {
            fgets(line, sizeof(line), stdin);
            execute_line(line);
        }
    } else if (line[0] == '#' || line[0] == '\0') {
        // Comment or empty line, do nothing
    } else {
        printf("Error: Unknown command '%s'\n", line);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file.flex>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline
        execute_line(line);
    }

    fclose(file);
    return 0;
}
