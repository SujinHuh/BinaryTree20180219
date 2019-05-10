//main.c
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int BinaryTree_CompareKeys(void*one, void*other);

int main(int argc, char *argv[]) {
	BinaryTree binaryTree;
	BinaryNode *index;
	Long key;
	Long ret;

	//1. 이분 검색 트리를 만든다.
	BinaryTree_Create(&binaryTree);

	//2. "50"을 삽입한다.
	key = 50;
	index = BinaryTree_Insert(&binaryTree, &key, sizeof(Long), BinaryTree_CompareKeys);
	BinaryTree_GetKey(&binaryTree, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//3. "40"을 삽입한다.
	key = 40;
	index = BinaryTree_Insert(&binaryTree, &key, sizeof(Long), BinaryTree_CompareKeys);
	BinaryTree_GetKey(&binaryTree, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//4. "30"을 삽입한다.
	key = 30;
	index = BinaryTree_Insert(&binaryTree, &key, sizeof(Long), BinaryTree_CompareKeys);
	BinaryTree_GetKey(&binaryTree, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//5. "20"을 삽입한다.
	key = 20;
	index = BinaryTree_Insert(&binaryTree, &key, sizeof(Long), BinaryTree_CompareKeys);
	BinaryTree_GetKey(&binaryTree, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//6. "10"을 삽입한다.
	key = 10;
	index = BinaryTree_Insert(&binaryTree, &key, sizeof(Long), BinaryTree_CompareKeys);
	BinaryTree_GetKey(&binaryTree, index, &ret, sizeof(Long));
	printf("%d\n", ret);



	//7. 발란스를 맞춘다.
	printf("Balance : %d\n", binaryTree.balance);
	BinaryTree_MakeBalance(&binaryTree, sizeof(Long));
	printf("Balance : %d\n", binaryTree.balance);

	//8. 20을 찾는다.
	key = 20;
	index = BinaryTree_Search(&binaryTree, &key, BinaryTree_CompareKeys);
	BinaryTree_GetKey(&binaryTree, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//9. 20을 지운다.   
	index = BinaryTree_Delete(&binaryTree, &key, sizeof(Long), BinaryTree_CompareKeys);
	if (index == NULL) {
		printf("지워졌습니다.\n");
	}

	//10. 끝낸다.
	BinaryTree_Destroy(&binaryTree);

	return 0;
}

int BinaryTree_CompareKeys(void*one, void*other) {
	int ret;
	Long *one_ = (Long*)one;
	Long *other_ = (Long*)other;

	if (*one_ > *other_) {
		ret = 1;
	}
	else if (*one_ == *other_) {
		ret = 0;
	}
	else if (*one_ < *other_) {
		ret = -1;
	}

	return ret;
}