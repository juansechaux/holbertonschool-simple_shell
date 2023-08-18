#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct list_s
{
	char *tok;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode;
	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);
	newNode->tok = strdup(str);
	newNode->next = NULL;
	if (*head == NULL)
		*head = newNode;
	else
	{
		list_t *lastNode;
		lastNode = *head;
		while (lastNode->next != NULL)
		{
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
	return (*head);
}

int main(int argc, char *argv[]) 
{
	list_t *head;
	head = NULL;
	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (0);
	}
	char *path = getenv(argv[1]);
	char *token = strtok(path, ":");

	while (token != NULL) 
	{
		printf("%s\n", token);
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (0);
}

