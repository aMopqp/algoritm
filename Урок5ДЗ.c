#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	char data;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} Stack;

typedef struct {
	Node *head;
	Node *last;
	int size;
} QStack;

int push(Stack *st, char val) {
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) return 0;

	temp->data = val;
	temp->next = st->head;

	st->head = temp;
	st->size++;
	return 1;
}

char pop(Stack *st) {
	if (st->size == 0) {
		return -1;
	}
	Node *temp = st->head;
	char result = st->head->data;

	st->head = st->head->next;
	st->size--;
	free(temp);
	return result;
}

int DecimalInBinary(Stack *st , int a) 
{
	while (a > 0) {
		Node *temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL) return 0;
		temp->data = a % 2;
		temp->next = st->head;
		a /= 2;
		st->head = temp;
		st->size++;
	}
	return 1;
}

char* CountParenthesis(Stack *sta, char* str)
{
	char c;
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
		{
			if (!(push(sta, str[i]))) return "No give RAM";
		}
		if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}'))
		{
			c = pop(sta);
			if ((c != str[i]-1) && (c != str[i] - 2)) return "not correct bracket sequence";
		}
	}
	if(pop(sta)==-1) return "correct bracket sequence";
	return "not correct bracket sequence";
}

Stack CopyStack(Stack *st)
{	
	int i=0;
	Stack ret;
	ret.size = 1;
	ret.head = NULL;
	Node * last = (Node*)malloc(sizeof(Node));
	Node * a = (Node*)malloc(sizeof(Node));
	a = st->head;


	do
	{
		Node *temp = (Node*)malloc(sizeof(Node));
		if (++i == 1) ret.head = temp;
		else last->next = temp;

		temp->data = a->data;
		last = temp;

		a = a->next;
		ret.size++;

		
	} while (a->next != NULL);

	Node *temp2 = (Node*)malloc(sizeof(Node));
	last->next = temp2;
	temp2->data = a->data;

	return ret;
}

int Qpush(QStack *st, char val) {
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) return 0;

	temp->data = val;
	if (st->size == 0) st->head = temp;
	else st->last->next = temp ;

	st->last = temp;
	st->size++;
	return 1;
}

char Qpop(QStack *st) {
	if (st->size == 0) {
		return -1;
	}
	Node *temp = st->head;
	char result = st->head->data;

	st->head = st->head->next;
	st->size--;
	free(temp);
	return result;
}


int main(int argc, const char** argv) {
	Stack s;
	s.size = 0;
	s.head = NULL;

	if( !(DecimalInBinary(&s, 49))) printf("Not give RAM\n");  

	Stack s3 = CopyStack(&s);

	while (s.size > 0) {
		printf("%d ", pop(&s));
	}


	Stack s2;
	s2.size = 0;
	s2.head = NULL;
	char* string[8] = { "(2-3)", "(2+[3])-(11)", "(-5)+2)-(1{3)","{1}-(2)",
		               "(2-[3+{4*2}/3])", "2)-(8", "3]0)- 1}1)1", "(22[-(3]4)5"};
	for (int i = 0; i < 8; i++)
	{
		printf("\n %s is %s ", string[i] , CountParenthesis(&s2,string[i]) );
	}
	printf("\n");

	while (s3.size > 0) {
		printf("%d ", pop(&s3));
	}
	
	printf("\n");

	QStack qs;
	qs.head = NULL;
	qs.last = NULL;
	qs.size = 0;
	for (int i = 0; i < 10; i++)
	{
		Qpush(&qs, '1'+i);
	}
	while (qs.size > 0) {
		printf("%d ", Qpop(&qs));
	}

	return 0;
}