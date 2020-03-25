#ifndef READ_CSV_H // Include guard (read more: https://stackoverflow.com/questions/15045370/multiple-inclusions-of-header-files)
#define READ_CSV_H //MUST BE unique within all header files

#include<stdbool.h>
#define MaxStrLen 100 // each line in the CSV can be a maximum of 100 characters wide
#define MaxTokLen 30
void setField(char*,char);
bool read_line_from_csv(FILE*,char);
int read_from_csv(char*,char);

#endif
