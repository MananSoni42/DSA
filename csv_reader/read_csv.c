#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "read_csv.h"

int numFields = 0;
char sep = ',';

void setNumFields(char* line, char sep) {
    int count=0;
    for(int i=0; line[i]!='\0'; i++) {
        if (sep == line[i]) {
            count++;
        }
    }
    numFields = count+1;
}

char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos){
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

bool read_line_from_csv(FILE* f, char sep) {
    char line[MaxStrLen], printline[MaxStrLen], *tok, sep_str[2], *ptrline;
    ptrline = &printline[0];
    sep_str[0] = sep; sep_str[1] = '\0';
    int i,padlen1,padlen2,numchars=0;
    bool err=false;

    fgets(line, MaxStrLen, f); // get a single line from the file

    if (numFields == 0) { // get the correct number of fields if not set yet
        setNumFields(line, sep);
    }
    tok = strtok(line, sep_str); // read first token from the line
    for (i=0;i<numFields;i++) {
        if (tok == NULL) { // catch any unknown errors
            err = true;
            break;
        }
        tok = replace_char(tok, '\n', '\0');
        tok = replace_char(tok, '\r', '\0');
    
        padlen1 = (MaxTokLen - strlen(tok))/2;
        padlen2 = MaxTokLen - strlen(tok) - padlen1;
        
        if (i == 0) {
            numchars = sprintf(ptrline, "|%*s%s%*s|", padlen1, "", tok, padlen2, "");
        }
        else {
            numchars = sprintf(ptrline, "%*s%s%*s|", padlen1, "", tok, padlen2, "");
        }
        ptrline += numchars;
        tok = strtok(NULL, sep_str); // read next token
    } printf("\n");

    if(!err) {
        printf("%s",printline);
    }
    return err;
}

int read_from_csv(char* f, char sep) {
    FILE* fstream = fopen(f,"r");
    bool err=false;
    int i=0;

    if (!fstream) {
        printf("ERROR! Could not open file: %s\n",f);
        return 2;
    }
    printf("Reading %s with a seperator %c\n\n",f,sep);
    while(1) {
        if (err) {
            break;
        }

        if (feof(fstream)) {
            break;
        }

        err = read_line_from_csv(fstream, sep);
    }
    fclose(fstream);
    if (err) {
        return 1;
    }
    else {
        return 0;
    }
}

