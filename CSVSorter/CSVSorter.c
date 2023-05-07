#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN "C:\\Users\\Eric\\Desktop\\CS\\Personal Projects\\GradeDistribution\\CSVSorter\\GradeDistribution.csv"
#define OUT "C:\\Users\\Eric\\Desktop\\CS\\Personal Projects\\GradeDistribution\\CSVSorter\\input.txt"
#define MAX_LINE_LENGTH 4096
#define NUM_COLUMNS 23

typedef struct {
    char ***list;
    size_t size;
} CSVSorter;

int compare_courses(const void *a, const void *b);
char **split_string(char *input, const char *delimiter, size_t *count);
void free_split_string(char **array, size_t count);
void remove_commas_from_course_titles(CSVSorter *csv_sorter, char **course);
void sort_courses(CSVSorter *csv_sorter);
void write_output_file(CSVSorter *csv_sorter);

int main() {
    CSVSorter csv_sorter = {NULL, 0};
    char line[MAX_LINE_LENGTH];

    FILE *input_file = fopen(IN, "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), input_file)) {
        char **course = split_string(line, ",", NULL);
        remove_commas_from_course_titles(&csv_sorter, course);
    }

    fclose(input_file);

    sort_courses(&csv_sorter);
    write_output_file(&csv_sorter);

    // Free memory allocated for csv_sorter.list
    for (size_t i = 0; i < csv_sorter.size; i++) {
        free_split_string(csv_sorter.list[i], NUM_COLUMNS);
    }
    free(csv_sorter.list);

    return 0;
}

int compare_courses(const void *a, const void *b) {
    char **x = *(char ***)a;
    char **y = *(char ***)b;

    int xx = atoi(x[3]);
    int yy = atoi(y[3]);

    int cmp = strcmp(x[2], y[2]);
    if (cmp < 0) {
        return -1;
    } else if (cmp > 0) {
        return 1;
    } else if (xx < yy) {
        return -1;
    } else if (xx > yy) {
        return 1;
    } else {
        cmp = strcmp(x[5], y[5]);
        if (cmp < 0) {
            return -1;
        } else if (cmp > 0) {
            return 1;
        }
    }

    return 0;
}

char **split_string(char *input, const char *delimiter, size_t *count) {
    char *token;
    char **result = NULL;
    size_t num_tokens = 0;

    char *input_copy = strdup(input);
    char *input_copy_ptr = input_copy;

    while ((token = strsep(&input_copy, delimiter))) {
        result = realloc(result, sizeof(char *) * (num_tokens + 1));
        result[num_tokens++] = strdup(token);
    }

    free(input_copy_ptr);

    if (count) {
        *count = num_tokens;
    }

    return result;
}

void free_split_string(char **array, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}

void remove_commas_from_course_titles(CSVSorter *csv_sorter, char **course) {
    int comma_count = 0;
    size_t course_length = 0;

    for (size_t i = 0; i < NUM_COLUMNS; i++) {
        if (course[i]) {
            course_length += strlen(course[i]);
        }
    }

    char *line = malloc(course_length + NUM_COLUMNS + 1);
    char *line_ptr = line;
    for (size_t i = 0; i < NUM_COLUMNS; i++) {
        if (course[i]) {
            size_t len = strlen(course[i]);
            memcpy(line_ptr, course[i], len);
            line_ptr += len;
        }
        if (i < NUM_COLUMNS - 1) {
            *line_ptr++ = ',';
            if (comma_count == 5) {
                *line_ptr++ = ',';
            }
        }
        comma_count++;
    }
    *line_ptr = '\0';

    char **new_course = split_string(line, ",", NULL);
    free_split_string(course, NUM_COLUMNS);
    free(line);

    csv_sorter->list = realloc(csv_sorter->list, sizeof(char **) * (csv_sorter->size + 1));
    csv_sorter->list[csv_sorter->size++] = new_course;
}