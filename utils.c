/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */

#include <stdio.h>
#include <string.h>

#include "utils.h"


/*
 * Tokenize the string stored in cmd based on DELIMITERS as separators.
 * Return the number of tokens, and store pointers to them in cmd_argv.
 */
int tokenize(char *cmd, char **cmd_argv) {

    char *token;
    int numOfTokens = 0;

    token = strtok(cmd, " \n");

    while (token != NULL) {
        cmd_argv[numOfTokens] = token;
        numOfTokens++;
        token = strtok(NULL, " \n");
    }

	return numOfTokens;
}
