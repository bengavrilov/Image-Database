/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "utils.h"

int main(void) {

        // char array to hold a line of input
	char buf[BUFFER_SIZE] = {'\0'};

        // char* array to hold the pointers to tokens
	char *args[INPUT_ARG_MAX_NUM];
	char *insertArgs[INPUT_ARG_MAX_NUM - 1];
	char *queryArgs[INPUT_ARG_MAX_NUM - 2];

	int numOfArgs = 0;

        // the root of the tree
        struct TreeNode root;
        root.value = "";
        root.child = NULL;
        root.sibling = NULL;

	struct TreeNode *root_ptr = &root;

        while (fgets(buf, BUFFER_SIZE, stdin) != NULL) {
            numOfArgs = tokenize(buf, args);

            if (numOfArgs == 5 && (strcmp(args[0], "i") == 0)) {
                insertArgs[0] = args[1];
                insertArgs[1] = args[2];
                insertArgs[2] = args[3];
                insertArgs[3] = args[4];
                tree_insert(root_ptr, insertArgs);
            }
            else if (numOfArgs == 4 && (strcmp(args[0], "q") == 0)) {
                queryArgs[0] = args[1];
                queryArgs[1] = args[2];
                queryArgs[2] = args[3];
                tree_search(root_ptr, queryArgs);
            }
            else if (numOfArgs == 1 && (strcmp(args[0], "p") == 0)) {
                tree_print(root_ptr);
            }
            else {
                printf("Invalid command.\n");
            }

        }
        return 0;
}
