#include <stdio.h>
#include "skiplist.h"
#include "sst.h"
#include "debug.h"

#define LOOP (1000000)
int main()
{
	int  i;
	char key[SKIP_KSIZE];

	struct sst *sst;

	struct skiplist *list,*list2;

	sst = sst_new();
	list = skiplist_new(LOOP);
	for (i = 0; i < LOOP; i++) {
		snprintf(key, SKIP_KSIZE, "key:%d", i);

		if (skiplist_notfull(list))
			skiplist_insert(list, key, i, ADD);
		else
			__DEBUG("%s","WARNING: You need more skiplists...");
	}
	
	sst_merge(sst, list);
	skiplist_free(list);
	
	list2 = skiplist_new(LOOP);
	for (i = 0; i < LOOP; i++) {
		snprintf(key, SKIP_KSIZE, "key2:%d", i);

		if (skiplist_notfull(list2))
			skiplist_insert(list2, key, i, ADD);
		else
			__DEBUG("%s","WARNING: You need more skiplists...");
	}
	
	sst_merge(sst, list2);
	skiplist_free(list2);
	return 1;
}
