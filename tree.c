/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

/**
 * A helper function that allocates a new tree node.
 *
 * @param value The entry's value. It represents either an attribute or a filename.
 * @return A pointer to the newly allocated node.
 * (for now it returns NULL, so the compiler doesn't complain)
*/
struct TreeNode *allocate_node(const char *value) {
    struct TreeNode *new_node = malloc(sizeof(struct TreeNode));
    new_node->value = malloc((strlen(value) * sizeof(char) + 1));
    strncpy(new_node->value, value, strlen(value) + 1);

    return new_node;
}

/**
 * Insert a new image to a tree
 *
 * @param tree A pointer to the root of the tree.
 * @param values An array, whose first three members are the attribute values for the image and the last one is
 * the filename
*/
void tree_insert(struct TreeNode *root, char **values) {
    struct TreeNode *current = NULL;
    current = root;
    current = current->child;
    int filePlaced = -1;

    if (current == NULL) {
        current = allocate_node(values[3]);
        struct TreeNode *third_attribute = allocate_node(values[2]);
        third_attribute->child = current;
        struct TreeNode *second_attribute = allocate_node(values[1]);
        second_attribute->child = third_attribute;
        struct TreeNode *first_attribute = allocate_node(values[0]);
        first_attribute->child = second_attribute;
        root->child = first_attribute;
        filePlaced = 1;
    }
    else {
        //tier 1
        if (strcmp(current->value, values[0]) == 0) {
            current = current->child;
            //tier 2
            if (strcmp(current->value, values[1]) == 0) {
                current = current->child;
                //tier 3
                if (strcmp(current->value, values[2]) == 0) {
                    current = current->child;
                    //ppm tier
                    while (current->sibling != NULL) {
                        current = current->sibling;
                    }
                    struct TreeNode *insertion_node = allocate_node(values[3]);
                    current->sibling = insertion_node;
                    filePlaced = 1;
                }
                else {
                    while (current->sibling != NULL) {
                        current = current->sibling;
                        if (strcmp(current->value, values[2]) == 0) {
                            current = current->child;

                            while (current->sibling != NULL) {
                                current = current->sibling;
                            }
                            struct TreeNode *insertion_node = allocate_node(values[3]);
                            current->sibling = insertion_node;
                            filePlaced = 1;
                            break;
                        }
                    }
                    if (filePlaced == -1) {
                        struct TreeNode *ppm_file = allocate_node(values[3]);
                        struct TreeNode *third_attribute = allocate_node(values[2]);
                        third_attribute->child = ppm_file;
                        current->sibling = third_attribute;
                        filePlaced = 1;
                    }
                }
            }
            else {
                while (current->sibling != NULL && filePlaced == -1) {
                    current = current->sibling;
                    if (strcmp(current->value, values[1]) == 0) {
                        current = current->child;
                        if (strcmp(current->value, values[2]) == 0) {
                            current = current->child;

                            while (current->sibling != NULL) {
                                current = current->sibling;
                            }
                            struct TreeNode *insertion_node = allocate_node(values[3]);
                            current->sibling = insertion_node;
                            filePlaced = 1;
                        }
                        else {
                            while (current->sibling != NULL) {
                                current = current->sibling;
                                if (strcmp(current->value, values[2]) == 0) {
                                    current = current->child;

                                    while (current->sibling != NULL) {
                                        current = current->sibling;
                                    }
                                    struct TreeNode *insertion_node = allocate_node(values[3]);
                                    current->sibling = insertion_node;
                                    filePlaced = 1;
                                    break;
                                }
                            }
                            if (filePlaced == -1) {
                                struct TreeNode *ppm_file = allocate_node(values[3]);
                                struct TreeNode *third_attribute = allocate_node(values[2]);
                                third_attribute->child = ppm_file;
                                current->sibling = third_attribute;
                                filePlaced = 1;
                            }
                        }
                    }
                }
                if (filePlaced == -1) {
                    struct TreeNode *ppm_file = allocate_node(values[3]);
                    struct TreeNode *third_attribute = allocate_node(values[2]);
                    third_attribute->child = ppm_file;
                    struct TreeNode *second_attribute = allocate_node(values[1]);
                    second_attribute->child = third_attribute;
                    current->sibling = second_attribute;
                    filePlaced = 1;
                }
            }
        }
        else {
            while (current->sibling != NULL && filePlaced == -1) {
                current = current->sibling;
                if (strcmp(current->value, values[0]) == 0) {
                    current = current->child;
                    if (strcmp(current->value, values[1]) == 0) {
                        current = current->child;
                        if (strcmp(current->value, values[2]) == 0) {
                            current = current->child;

                            while (current->sibling != NULL) {
                                current = current->sibling;
                            }
                            struct TreeNode *insertion_node = allocate_node(values[3]);
                            current->sibling = insertion_node;
                            filePlaced = 1;
                        }
                        else {
                            while (current->sibling != NULL) {
                                current = current->sibling;
                                if (strcmp(current->value, values[2]) == 0) {
                                    current = current->child;

                                    while (current->sibling != NULL) {
                                        current = current->sibling;
                                    }
                                    struct TreeNode *insertion_node = allocate_node(values[3]);
                                    current->sibling = insertion_node;
                                    filePlaced = 1;
                                    break;
                                }
                            }
                            if (filePlaced == -1) {
                                struct TreeNode *ppm_file = allocate_node(values[3]);
                                struct TreeNode *third_attribute = allocate_node(values[2]);
                                third_attribute->child = ppm_file;
                                current->sibling = third_attribute;
                                filePlaced = 1;
                            }
                        }
                    }
                    else {
                        while (current->sibling != NULL && filePlaced == -1) {
                            current = current->sibling;
                            if (strcmp(current->value, values[1]) == 0) {
                                current = current->child;
                                if (strcmp(current->value, values[2]) == 0) {
                                    current = current->child;

                                    while (current->sibling != NULL) {
                                        current = current->sibling;
                                    }
                                    struct TreeNode *insertion_node = allocate_node(values[3]);
                                    current->sibling = insertion_node;
                                    filePlaced = 1;
                                }
                                else {
                                    while (current->sibling != NULL) {
                                        current = current->sibling;
                                        if (strcmp(current->value, values[2]) == 0) {
                                            current = current->child;

                                            while (current->sibling != NULL) {
                                                current = current->sibling;
                                            }
                                            struct TreeNode *insertion_node = allocate_node(values[3]);
                                            current->sibling = insertion_node;
                                            filePlaced = 1;
                                            break;
                                        }
                                    }
                                    if (filePlaced == -1) {
                                        struct TreeNode *ppm_file = allocate_node(values[3]);
                                        struct TreeNode *third_attribute = allocate_node(values[2]);
                                        third_attribute->child = ppm_file;
                                        current->sibling = third_attribute;
                                        filePlaced = 1;
                                    }
                                }
                            }
                        }
                        if (filePlaced == -1) {
                            struct TreeNode *ppm_file = allocate_node(values[3]);
                            struct TreeNode *third_attribute = allocate_node(values[2]);
                            third_attribute->child = ppm_file;
                            struct TreeNode *second_attribute = allocate_node(values[1]);
                            second_attribute->child = third_attribute;
                            current->sibling = second_attribute;
                            filePlaced = 1;
                        }
                    }
                }
            }
            if (filePlaced == -1) {
                struct TreeNode *ppm_file = allocate_node(values[3]);
                struct TreeNode *third_attribute = allocate_node(values[2]);
                third_attribute->child = ppm_file;
                struct TreeNode *second_attribute = allocate_node(values[1]);
                second_attribute->child = third_attribute;
                struct TreeNode *first_attribute = allocate_node(values[0]);
                first_attribute->child = second_attribute;
                current->sibling = first_attribute;
                filePlaced = 1;
            }
        }
    }
    current = NULL;
}

/**
 * Searches a tree to print all files with matching attribute values.
 *
 * @param tree A pointer to the root of the tree.
 * @param values An array of attribute values
*/
void tree_search(const struct TreeNode *root, char **values) {
    struct TreeNode *current  = NULL;
    current = root->child;
    int outputProvided = -1;
    if (current == NULL) {
        printf("(NULL)\n");
    }
    else {
        while (current != NULL) {
            if (strcmp(current->value, values[0]) == 0) {
                current = current->child;

                while (current != NULL) {
                    if (strcmp(current->value, values[1]) == 0) {
                        current = current->child;

                        while (current != NULL) {
                            if (strcmp(current->value, values[2]) == 0) {
                                current = current->child;
                                outputProvided = 1;

                                while (current != NULL) {
                                    printf("%s ", current->value);
                                    current = current->sibling;
                                }
                                printf("\n");
                                break;
                            }
                            else {
                                current = current->sibling;
                            }
                        }
                        break;
                    }
                    else {
                        current = current->sibling;
                    }
                }
                break;
            }
            else {
                current = current->sibling;
            }
        }
        if (outputProvided == -1) {
            printf("(NULL)\n");
        }
    }
    current = NULL;
}

/**
 * Prints a complete tree to the standard output.
 *
 * @param tree A pointer to the root of the tree.
*/
void tree_print(const struct TreeNode *tree) {
    struct TreeNode *attribute1 = NULL;
    struct TreeNode *attribute2 = NULL;
    struct TreeNode *attribute3 = NULL;
    struct TreeNode *ppm = NULL;
    attribute1 = tree->child;

    if (attribute1 != NULL) {
        while (attribute1 != NULL) {
            char *first_attribute = malloc(strlen(attribute1->value)* sizeof(char) + 1);
            strncpy(first_attribute, attribute1->value, strlen(attribute1->value) + 1);

            attribute2 = attribute1->child;

            while (attribute2 != NULL) {
                char *second_attribute = malloc(strlen(attribute2 ->value)* sizeof(char) + 1);
                strncpy(second_attribute, attribute2->value, strlen(attribute2->value) + 1);

                attribute3 = attribute2->child;

                while (attribute3 != NULL) {
                    char *third_attribute = malloc(strlen(attribute3->value)* sizeof(char) + 1);
                    strncpy(third_attribute, attribute3->value, strlen(attribute3->value) + 1);

                    ppm = attribute3->child;

                    while (ppm != NULL) {
                        printf("%s %s %s %s\n", first_attribute, second_attribute, third_attribute, ppm->value);
                        ppm = ppm->sibling;
                    }
                    free(third_attribute);
                    attribute3 = attribute3->sibling;
                }
                free(second_attribute);
                attribute2 = attribute2->sibling;
            }
            free(first_attribute);
            attribute1 = attribute1->sibling;
        }
    }
    else {
        printf("(NULL)\n");
    }
    attribute1 = NULL;
    attribute2 = NULL;
    attribute3 = NULL;
    ppm = NULL;
}