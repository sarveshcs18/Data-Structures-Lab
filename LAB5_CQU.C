#include <stdio.h>
#define size 10

void insert(int ele, int queue[], int *r, int *f) {
	if ((*r == size - 1 && *f == 0) || (*f == *r + 1)) {
		printf(" Queue Overflow \n");
		return;
	}
	if (*f == -1) *f = 0;
	*r = (*r + 1) % size;
	queue[*r] = ele;
}

int delete(int queue[],int *f, int *r) {
	int ele;
	if (*f == -1) {
		printf(" Queue Underflow \n");
		return -999;
	} else {
		ele = queue[*f];
		if (*f == *r) {
			*f = -1;
			*r = -1;
		} else {
			*f = (*f + 1) % size;
			return ele;
		}
	}
}

void display(int queue[], int f, int r) {
	int i;
	if (f == -1) printf(" Queue Underflow\n");
	else {
		for (i = f; i != r; i = (i + 1) % size) printf("%d \n", queue[i]);
		printf("%d", queue[i]);
	}
}

int main() {
	int queue[10];
	int f = -1, r = -1, option, ele, ch;
	clrscr();
	do {    printf("\t\t ****************MENU*******************\n\n");
		printf(" 1.Insert\n \n \n 2.Deletion\n \n \n 3.Display\n \n \n 4. Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &option);

		switch (option) {
			case 1: printf("\n\n\n   Enter Element to be inserted: ");
				scanf("%d", &ele);
				insert(ele, queue, &r, &f);
				break;

			case 2: ele = delete(queue, &f, &r);
				if (ele == -999) break;
				printf("\n\n The Deleted Element is: %d \n \n", ele);
				break;

			case 3: display(queue, f, r);
				break;

			case 4: exit(0);
				break;

			default: printf("\n\nInvalid Input \n");
		}

	printf("\n\n Do you want to continue?\n \n 1. Yes\n \n 2. Exit\n \n");
	scanf("%d", &ch);
	} while (ch == 1);

    return 0;
}