#include"file_system.h"

int ls_0(void)
{
	int i, cnt = 0;
	for (i = 0; i < NO_OF_FILES_IN_DIR; i++) {
		int dirEntry = getDirEntry(UA.current_working_directory);

		if ((AllDir[dirEntry].file[i].inode_number) != -1) {
			printf("\t%s \n", AllDir[dirEntry].file[i].file_name);
			cnt++;
		}
	}
	return cnt;
}

int ls_1(char *par)
{
	int i, cnt = 0;
	int dirEntry = getDirEntry(UA.current_working_directory);

	if (*par == 's') {

		for (i = 0; i < NO_OF_FILES_IN_DIR; i++) {
			if ((AllDir[dirEntry].file[i].inode_number) != -1) {
				printf("\t%s \t\t %10d\n",
						AllDir[dirEntry].file[i].file_name,
						DILB[AllDir[dirEntry].file[i].inode_number].file_size);
				cnt++;
			}
		}
	}
	if (*par == 'i') {
		for (i = 0; i < NO_OF_FILES_IN_DIR; i++) {
			if ((AllDir[dirEntry].file[i].inode_number) != -1) {
				printf("\t%3d\t%s \n",
						AllDir[dirEntry].file[i].inode_number,
						AllDir[dirEntry].file[i].file_name);
				cnt++;
			}
		}
	}
	if (*par == 'a') {
		for (i = 0; i < NO_OF_FILES_IN_DIR; i++) {
			if ((AllDir[dirEntry].file[i].inode_number) != -1) {
				printf("\t%3d %10d \t%s\t\t ",
						AllDir[dirEntry].file[i].inode_number,
						DILB[AllDir[dirEntry].file[i].inode_number].file_size,
						AllDir[dirEntry].file[i].file_name);

				if (DILB[AllDir[dirEntry].file[i].inode_number].type == RegularFile)
					printf("RegularFile\t");

				if (DILB[AllDir[dirEntry].file[i].inode_number].type == Directory)
					printf("Directory\t");
				cnt++;
			}
		}
	}
	return cnt;
}
