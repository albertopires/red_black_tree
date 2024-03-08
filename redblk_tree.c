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

#define RED   true
#define BLACK false

bool is_red(struct t_node *node)
{
	if (node == NULL) return false;
	return node->color == RED;
}

struct t_node *rotate_left(struct t_node *h)
{
	struct t_node *x;

	assert(h != NULL && is_red(h->right));
	x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

struct t_node *rotate_right(struct t_node *h)
{
	struct t_node *x;

	assert(is_red(h->left));
	x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

void flip_colors(struct t_node *h)
{
	assert((h != NULL && h->left != NULL) && (h->right != NULL));
	assert((!is_red(h) && is_red(h->left) &&  is_red(h->right))
	|| (is_red(h)  && !is_red(h->left) && !is_red(h->right)));
	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}

struct t_node *create_node(char *key, char *data, bool color)
{
	struct t_node *node;

	node = (struct t_node *) malloc(sizeof(struct t_node));
	if (!node) {
		printf("Malloc error\n");
		abort();
	}
	node->key = key;
	node->data = data;
	node->color = color;

	return node;
}

struct t_node *put_node(struct t_node **h, char *key, char *data)
{
	int cmp;

	if (*h == NULL) {
		*h = create_node(key, data, RED);
		return *h;
	}
	cmp = strcmp(key, (*h)->key);
	if      (cmp < 0) (*h)->left = put_node(&(*h)->left, key, data);
	else if (cmp > 0) (*h)->right = put_node(&(*h)->right, key, data);
	else if (cmp == 0) (*h)->data = data;

	if (is_red((*h)->right) && !is_red((*h)->left)) *h = rotate_left(*h);
	if (is_red((*h)->left) && is_red((*h)->left->left)) *h = rotate_right(*h);
	if (is_red((*h)->left) && is_red((*h)->right)) flip_colors(*h);

	return *h;
}

struct t_node *put(struct t_node **root, char *key, char *data)
{
	*root = put_node(root, key, data);
	(*root)->color = BLACK;

	return *root;
}

struct t_node *get(struct t_node *node, char *key)
{
	int cmp;

	while (node != NULL) {
		cmp = strcmp(key, node->key);
		if (cmp < 0) node = node->left;
		if (cmp > 0) node = node->right;
		if (cmp == 0) return node;
	}

	return NULL;
}
