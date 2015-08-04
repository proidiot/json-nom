/* Copyright 2015 Charles Southerland.
 *
 * This file is part of json-nom.
 *
 * json-nom is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * json-nom is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * json-nom.  If not, see <http://www.gnu.org/licenses/>.
 *
 * More information about json-nom can be found at
 * <https://github.com/proidiot/json-nom/>.
 */

#include <config.h>
#include "nom.h"
#include <string.h>
#include <yajl/yajl_tree.h>

/**
 * Mask properties common to a parent object.
 *
 * This function is called by nom to mask a property in all nested nodes.
 * 
 * @param node The YAJL node whose properties may be masked
 * @param mask The property name to be masked
 */
static void omnom(yajl_val node, const char* mask);

/* Big-O:
 * Best case:  == 1      (if node is neither an array nor an object)
 * Worst case: == n      (if tree is shallow or else both tree is deep and
 *                        property isn't found)
 * Avg case:   == log(n) (if property isn't found)
 *             <= log(n) (if property is found)
 */
static void omnom(yajl_val node, const char* mask)
{
	if (YAJL_IS_ARRAY(node)) {
		size_t i = 0;
		for (i = 0; i < node->u.array.len; i++) {
			omnom(node->u.array.values[i], mask);
		}
	} else if (YAJL_IS_OBJECT(node)) {
		size_t i = 0;
		for (i = 0; i < node->u.object.len; i++) {
			if (node->u.object.values[i] == NULL) {
				continue;
			} else if (strcmp(mask, node->u.object.keys[i])	== 0) {
				/* TODO: yajl_tree_free here? */
				node->u.object.values[i] = NULL;
			} else if (YAJL_IS_OBJECT(node->u.object.values[i])) {
				omnom(node->u.array.values[i], mask);
			}
		}
	}
}

/* Big-O:
 * Best case:  1   (node has no subnodes)
 * Worst case: n^2 (if tree is shallow, each omnom would be 1,
 *                  but omnom would be called n^2 times)
 * Avg case: TODO
 */
void nom(yajl_val node)
{
	if (YAJL_IS_ARRAY(node)) {
		size_t i = 0;
		for (i = 0; i < node->u.array.len; i++) {
			nom(node->u.array.values[i]);
		}
	} else if (YAJL_IS_OBJECT(node)) {
		size_t i = 0;
		for (i = 0; i < node->u.object.len; i++) {
			size_t j = 0;
			for (j = 0; j < node->u.object.len; j++) {
				if (node->u.object.values[j] != NULL) {
					omnom(node->u.object.values[j],
						node->u.object.keys[i]);
				}
			}
		}
		/* if we nom any node before completing the omnoms,
		 * we could end up nomming a node that would have been wiped
		 * out by a top-level omnom, which would be needlessly
		 * expensive
		 */
		for (i = 0; i < node->u.object.len; i++) {
			if (node->u.object.values[i] != NULL) {
				nom(node->u.object.values[i]);
			}
		}
	}
}

