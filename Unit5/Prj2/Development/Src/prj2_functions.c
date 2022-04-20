/**
 * @file prj2_functions.c
 * @author Omar Elmasri (masri.omarm@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-04-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "main.h"

//[p]: enter student details manually
void read_manual(void) {
  TYPE_IN_FILE line[MAX_LINE_LENGTH] = {0};
  uint8_t      index_line            = 0;
  uint8_t      line_order            = 0;
  TYPE_IN_FILE word[MAX_WORD_LENGTH] = {0};
  uint8_t      index_word            = 0;
  uint8_t      word_order            = 1;

  char flag = 'n';

  do {
    fgets(line, MAX_LINE_LENGTH, stdin);
    while (line[index_line] != '\n') {
      if (line[index_line] != ' ') { // get word
        word[index_word++] = line[index_line];
      }
      if ((line[index_line] == ' ' && index_word > 0) ||
          (line[index_line + 1] == '\n' &&
           index_word > 0)) { // dump word if next char is space or newline.
        if (1 ==
            map_words(word_order, word, &(students[line_order]), line_order)) { // bug: rollnum should only be digit.
          line_order--;
        }
        memset(word, 0, sizeof(word)); // reset word to receive next word
        word_order++, index_word = 0;
      }
      index_line++;
    }
    word_order = 1, index_line = 0, line_order++;
    printf("Student details added successfully!\n");
    printf("\nContinue? y or n\n");
    // bug: extra newline is added automatically, maybe due to fgets.
    fgets(&flag, 1, stdin);
  } while (flag == 'y' || flag == 'Y');

  ;
};

//[p]: search students by roll num, print details
void find_rollnum(void){

};

//[p]: search students by first name, print details
void find_firstname(void){

};

//[p]: search students by course id, print details
void find_coureid(void){

};

//[p]: return total number of students
void totalnum_student(void){

};

//[p]: delete student with the following roll num
void delete_rollnum(void){

};

//[p]: update student with the following roll num
void update_rollnum(void){

};

//[d]: show all students
/**
 * @brief print student details until the first null student.
 *
 */
void show_all(void) {

  uint8_t current = 0;
  do {
    printf("Student [%d]\n%s %s, Roll Number: %s, Courses:\n", current + 1,
           students[current].name_first, students[current].name_last,
           students[current].rollnum);

    printf("%s\t%s\t%s\t%s\t%s\n", students[current].course[0],
           students[current].course[1], students[current].course[2],
           students[current].course[3], students[current].course[4]);
    current++;
  } while (atoi(students[current].rollnum) != 0);
};

//[d]: exit all
void exit_all(void) {
  printf("Exit...");
  exit(0);
};
