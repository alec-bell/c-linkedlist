#include <stdio.h>
#include <stdlib.h>

struct float_link {
    float float_val;
    struct float_link *next;
};

int get_dataset() {
    int dataset;
    printf("Enter the number of the data set on which you wish to do calculations: ");
    scanf("%d", &dataset);
    return dataset;
}

int get_option() {
    int option;
    printf("\nWhat would you like to do with this data set? Choose from the following options:\n");
    printf("1) Find the minimum value.\n");
    printf("2) Find the maximum value.\n");
    printf("3) Calculate the sum of all the values.\n");
    printf("4) Calculate the average of all the values.\n");
    printf("5) Print the values in the data set.\n");
    printf("6) Exit the program.\n");
    printf("Enter the number of the option you choose: ");
    scanf("%d", &option);
    return option;
}

float find_min(struct float_link *data) {
    float min;
    /* Pointers for handling the linked list */
    struct float_link *head_ptr;
    struct float_link *traverse_ptr;

    head_ptr = data;
    traverse_ptr = head_ptr->next;
    min = traverse_ptr->float_val;
    while (traverse_ptr != NULL) {
        if(traverse_ptr->float_val < min) {
            min = traverse_ptr->float_val;
        }
        traverse_ptr = traverse_ptr->next;
    }

    return min;
}

float find_max(struct float_link *data) {
    float max;
    /* Pointers for handling the linked list */
    struct float_link *head_ptr;
    struct float_link *traverse_ptr;

    head_ptr = data;
    traverse_ptr = head_ptr->next;
    max = traverse_ptr->float_val;
    while (traverse_ptr != NULL) {
        if(traverse_ptr->float_val > max) {
            max = traverse_ptr->float_val;
        }
        traverse_ptr = traverse_ptr->next;
    }

    return max;
}

float calculate_sum(struct float_link *data) {
    float sum = 0;
    /* Pointers for handling the linked list */
    struct float_link *head_ptr;
    struct float_link *traverse_ptr;

    head_ptr = data;
    traverse_ptr = head_ptr->next;
    while (traverse_ptr != NULL) {
        sum += traverse_ptr->float_val;
        traverse_ptr = traverse_ptr->next;
    }

    return sum;
}

float calculate_avg(struct float_link *data) {
    float sum = 0;
    int count = 0;
    /* Pointers for handling the linked list */
    struct float_link *head_ptr;
    struct float_link *traverse_ptr;

    head_ptr = data;
    traverse_ptr = head_ptr->next;
    count++;
    while (traverse_ptr != NULL) {
        sum += traverse_ptr->float_val;
        traverse_ptr = traverse_ptr->next;
        count++;
    }

    return sum / count;
}

void print_values(struct float_link *data) {
    /* Pointers for handling the linked list */
    struct float_link *head_ptr;
    struct float_link *traverse_ptr;

    head_ptr = data;
    traverse_ptr = head_ptr->next;
    while (traverse_ptr != NULL) {
        printf("%.2f\t", traverse_ptr->float_val);
        traverse_ptr = traverse_ptr->next;
    }
    printf("\n");
}

struct float_link *get_data() {
    /* Number of data sets */
    int n;
    /* Size of current data set */
    int current_size;
    /* Iterators */
    int i;
    int j;
    /* Linked List */
    struct float_link *data;
    /* Pointers for handling the linked list */
    struct float_link *head_ptr;
    struct float_link *traverse_ptr;

    /* Get desired number of data sets */
    scanf("%d", &n);

    /* Allocate space for each of the data sets */
    data = malloc(n * sizeof(struct float_link));
    /* Assign values to each data set */
    for (i = 0 ; i < n ; i++) {
        scanf("%d", &current_size);
        /* Begins traversing after constructing the head (head isn't really necessary but I put it in for the sake of principle lol) */
        head_ptr = (data + i);
        head_ptr->next = malloc(sizeof(struct float_link));
        traverse_ptr = head_ptr->next;
        for (j = 0 ; j < current_size ; j++) {
            scanf("%f", &(traverse_ptr->float_val));
            /* Assigns an address in memory to next */
            if (current_size > j + 1) {
                traverse_ptr->next = malloc(sizeof(struct float_link));
                traverse_ptr = traverse_ptr->next;
            }
        }
    }

    return data;
}

int main() {
    /* Linked List for each data set */
    struct float_link *data;
    /* Operations */
    int dataset;
    int option;

    data = get_data();

    /* Allow users to perform operations on the data */
    do {
        option = get_option();

        switch (option) {
            case 1:
                dataset = get_dataset();
                printf("The minimum value in data set %d is: %.2f\n", dataset, find_min(data + dataset - 1));
                break;
            case 2:
                dataset = get_dataset();
                printf("The maximum value in data set %d is: %.2f\n", dataset, find_max(data + dataset - 1));
                break;
            case 3:
                dataset = get_dataset();
                printf("The sum of values in data set %d is: %.2f\n", dataset, calculate_sum(data + dataset - 1));
                break;
            case 4:
                dataset = get_dataset();
                printf("The average value in data set %d is: %.2f\n", dataset, calculate_avg(data + dataset - 1));
                break;
            case 5:
                dataset = get_dataset();
                printf("These are the values in data set %d:\n", dataset);
                print_values(data + dataset - 1);
                break;
            case 6:
                printf("Have a great day!\n");
                break;
            default:
                printf("Please enter a valid option.\n");
        }

    } while (option != 6);

    return 0;
}
