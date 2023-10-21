#include <stdio.h>
#include <unistd.h> /* for getopt() */
#include <stdlib.h> /* for EXIT_SUCCESS, EXIT_FAILURE */
#include <string.h>
#include <errno.h>
#include "types.h"
#include "autoFmask.h"



/*
static void free_entries(student_t* entries, int nr_entries)
{
	int i=0;
	student_t* entry;

	for (i=0; i<nr_entries; i++) {
		entry=&entries[i]; /* Point to current entry /
		free(entry->first_name);
		free(entry->last_name);
	}

	free(entries);
}

student_t* parse_records(char* records[], int nr_records) {
    char* recordptr;
    char* token;
    int i;
    student_t* students;
    student_t* cur_student;
    token_id_t token_id;

    students = malloc(sizeof(student_t)*nr_records);
    memset(students,0,sizeof(student_t)*nr_records);

    for (i=0;i<nr_records;i++){
        recordptr=records[i];
        token_id=STUDENT_ID_IDX;
        cur_student=&students[i];

        cur_student->pos=i;

        while((token = strsep(&recordptr, ":"))!=NULL) {           
			switch(token_id) { 
            case STUDENT_ID_IDX:
                if (sscanf(token,"%d",&cur_student->student_id)!=1) {
                    fprintf(stderr, "Couldn't parse student id field in record %d. token is %s\n",i+1, token);
					return NULL;
                }
                break;
            case NIF_IDX:
                strcpy(cur_student->NIF,token);
                break;
            case FIRST_NAME_IDX:
                cur_student->first_name=strdup(token);
                break;
            case LAST_NAME_IDX:
                cur_student->last_name=strdup(token);
                break;
            default:
                break;
            }
            token_id++;
        }
    }
    return students;
}

student_t* search(search_mode_t mode, char* stdn, student_t* students, int nr_entries){
    int i;
    int stdn_id;
    char* ptr;
    student_t* entry;

    for (i=0;i<nr_entries;++i){
        entry=&students[i];
        switch(mode){
        case ID_MODE:
            stdn_id = strtol(stdn,&ptr,10);
            if (entry->student_id==stdn_id)
                return entry;
            break;
        case NIF_MODE:
            if (strcmp(entry->NIF,stdn)==0)
                return entry;
            break;
        }      
    }

    return NULL;
}

char* loadstr(FILE* students) {
    char* c="";
    char* ret="";

//leer bit a bit
    while(fread(c,sizeof(char),1,students)>0){
        strcat(ret,c);
	}

    c = malloc(strlen(ret));
    memset(c,0,strlen(ret));
    c = strdup(ret);

    return c;
}

student_t* read_student_file(FILE* students, int* nr_entries) {
    char* records[MAX_RECORDS_LINE+1];  
    student_t* ret;
    int entries=0;
    char* lineptr;
  	int line_count=0;
	char line[MAX_RECORDS_LINE+1];

    while (fgets(line, MAX_RECORDS_LINE + 1, students) != NULL)
		line_count++;

    /* Rewind position indicator/
	fseek(students,0,SEEK_SET);

    ret=malloc(sizeof(student_t)*line_count);
	/* zero fill the array of structures /
	memset(ret,0,sizeof(student_t)*line_count);

    while (fgets(line, MAX_RECORDS_LINE + 1, students) != NULL) {
		lineptr=line;
        records[entries]=strdup(lineptr);
        entries++;
    }
    *nr_entries = entries;

    ret = parse_records(records,entries);

    return ret;
}

int dump_entries(student_t* entries, int nr_entries, FILE* students) {
    int i;
    student_t* entry;
    char stdnt_id[10];
    int present = 0;
    int nr_students=0;
    student_t* stnd_srch = read_student_file(students,&nr_students);

    for (i=0;i<nr_entries;i++){
        entry=&entries[i];
        sprintf(stdnt_id, "%d", entry->student_id);

        if (search(ID_MODE,stdnt_id,stnd_srch,nr_students) == NULL) {
            fprintf(students, "%d:%s:%s:%s\n", entry->student_id,entry->NIF,entry->first_name,entry->last_name);
        }
        else {
            fprintf(stdout, "Found duplicate student_id %d\n", entry->student_id);     
            present++;
        }
    }

    return present;
}

static int show_records(FILE* students)
{
	int nr_entries;
	int i;
	student_t* entries=read_student_file(students,&nr_entries);

	if (entries == NULL)
		return EXIT_FAILURE;

	for (i=0; i<nr_entries; i++) {
		student_t* e=&entries[i]; /* Point to current entry /
		
		fprintf(stdout,"[Entry #%d]\n",i);
		fprintf(stdout,"\tstudent_id=%d\n\tNIF=%s\n\t"
		        "first_name=%s\n\tlast_name=%s\n",
		        e->student_id, e->NIF,
		        e->first_name, e->last_name);			
	}
	free_entries(entries,nr_entries);
	return EXIT_SUCCESS;
}
*/

int main(int argc, char* argv[]) {

    ObjMeta data_meta;
    ObjTOABT data_toabt;
    char opt;
    emxArray_boolean_T mask;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s -f file [ -h | -l | -c | -a | -q [ -i|-n ID] ] ] [ list of records ]\n",argv[0]);
        exit(0);
    }

    ObservMask(data_toabt.BandBlue, &mask);

    /* Parse command-line options */
    /*
	while((opt = getopt(argc, argv, "f:hlcaqi:n:")) != -1) {
		switch(opt) {
        case 'f':
            /* Open file /
	        if ((file = fopen(optarg, "a+")) == NULL)
		        err(1,"The input file %s could not be opened\n",argv[2]);
            break;
		case 'h':
            fprintf(stderr,"Usage: %s -f file [ -h | -l | -c | -a | -q [ -i|-n ID] ] ] [ list of records ]\n",argv[0]);
            exit(2);
            break;
        case 'l':
            show_records(file);
            break;
        case 'c':
            fclose(fopen(argv[2],"w"));
            entries=0;
            for (i=4;i<argc;i++){
                records[entries]=strdup(argv[i]);
                entries++;
            }
            students = parse_records(records,entries);
            ret = dump_entries(students,entries,file);
            fprintf(stdout,"%d records written succesfully\n",entries-ret);

            break;
        case 'a':           
            entries=0;
            for (i=4;i<argc;i++){
                records[entries]=strdup(argv[i]);
                entries++;
            }
            students = parse_records(records,entries);
            ret = dump_entries(students,entries,file);
            fprintf(stdout,"%d records written succesfully\n",entries-ret);
            break;  
        case 'q':
            isQ=1;
            break;
        case 'i':
            if (!isQ) {
                fprintf(stderr,"Usage: %s -f file -q [ -i|-n ID]\n",argv[0]);
                exit(6);
            }
            students = read_student_file(file,&nr_students);
            e=search(ID_MODE,optarg,students,nr_students);

            if (e==NULL)
                fprintf(stdout,"No entry was found\n");
            else {
                fprintf(stdout,"[Entry #%d]\n",e->pos);
		        fprintf(stdout,"\tstudent_id=%d\n\tNIF=%s\n\t"
		            "first_name=%s\n\tlast_name=%s\n",
		            e->student_id, e->NIF,
		            e->first_name, e->last_name);
            }
            isIN=1;
            break;
        case 'n':           
            if (!isQ) {
                fprintf(stderr,"Usage: %s -f file -q [ -i|-n ID]\n",argv[0]);
                exit(7);
            }
            students = read_student_file(file,&nr_students);
            e=search(NIF_MODE,optarg,students,nr_students);

            if (e==NULL)
                fprintf(stdout,"No entry was found\n");
            else {
                fprintf(stdout,"[Entry #%d]\n",e->pos);
		        fprintf(stdout,"\tstudent_id=%d\n\tNIF=%s\n\t"
		            "first_name=%s\n\tlast_name=%s\n",
		            e->student_id, e->NIF,
		            e->first_name, e->last_name);
            }
            isIN=1;
            break;
        default:
			exit(EXIT_FAILURE);
        }
    }
    if (isQ && !isIN) {
                fprintf(stderr,"Usage: %s -f file -q [ -i|-n ID]\n",argv[0]);
                exit(8);
    }

    fclose(file);
    */
    
    return 0;
}