// Copyright (C) 2024 Alberto pires de Oliveira Neto
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/albertopires/red_black_tree/blob/master/LICENSE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>

#include "redblk_tree.h"

void test_get(struct t_node *root, char *key)
{
	struct t_node *n;

	n = get(root, key);
	if (n) {
		printf("%s: %s\n", key, n->data);
	} else {
		printf("%s: Not found\n", key);
	}
}

int main(void)
{
	struct t_node *root;

	root = NULL;

	put(&root, "S", "200");
	put(&root, "E", "300");
	put(&root, "A", "400");
	put(&root, "R", "500");
	put(&root, "C", "600");
	put(&root, "H", "700");
	put(&root, "X", "800");
	put(&root, "M", "900");
	put(&root, "P", "A00");
	put(&root, "L", "B00");

	test_get(root, "S");
	test_get(root, "E");
	test_get(root, "A");
	test_get(root, "R");
	test_get(root, "C");
	test_get(root, "H");
	test_get(root, "X");
	test_get(root, "M");
	test_get(root, "P");
	test_get(root, "L");
	test_get(root, "G"); // NOT FOUND

	exit(EXIT_SUCCESS);
}
