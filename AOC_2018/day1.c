#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
}node_t;

node_t *newNode(int val)
{
	node_t *node = (node_t*)malloc(sizeof(node_t));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
void insert(node_t *tree, int val)
{
	if (val < tree->val)
	{
		if (tree->left != NULL)
			insert(tree->left, val);
		else
			tree->left = newNode(val);
	}
	else
	{
		if (tree->right != NULL)
			insert(tree->right, val);
		else
			tree->right = newNode(val);
	}
}

int	search(node_t *tree, int val)
{	
	static int	result = 0;

	if (val == tree->val)
		result = val;
	else if (val < tree->val && tree->left)
		search(tree->left, val);
	else if (val > tree->val && tree->right)
		search(tree->right, val);
	return (result);
}

int	main()
{
	int		flag = 0;
	int		result = 0;
	int		dupe = 0;
	int		number = 0;
	char	str[88];
	node_t	*tree = NULL;
	FILE	*fp = NULL;

	while(dupe == 0)
	{
		fp = fopen("input.txt", "r");
		while (fgets(str, 88, fp))
		{
			number = atoi(str);
			result += number;
			if (tree == NULL)
				tree = newNode(result);
			else if ((search(tree, result)) == result)
				dupe = result;
			else
				insert(tree, result);
		}
		if (!flag)
		{
			printf("sum = %d\n", result);
			flag = 1;
		}
		fclose(fp);
	}
	printf("dupe = %d", dupe);
	return (0);
}
