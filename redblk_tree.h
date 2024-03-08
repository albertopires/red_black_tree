// Copyright (C) 2024 Alberto pires de Oliveira Neto
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/albertopires/red_black_tree/blob/master/LICENSE

#ifndef REDBLK_TREE_H_
#define REDBLK_TREE_H_

struct t_node {
	char *key;
	char *data;
	struct t_node *left;
	struct t_node *right;
	bool color;
};

struct t_node *put(struct t_node **root, char *key, char *data);
struct t_node *get(struct t_node *node, char *key);

#endif
