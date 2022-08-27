/*
08/27/2022 15:52	Wrong Answer	N/A	N/A	c
08/26/2022 18:53	Compile Error	N/A	N/A	c
08/26/2022 18:41	Wrong Answer	N/A	N/A	c
08/26/2022 17:05	Wrong Answer	N/A	N/A	c
08/26/2022 17:03	Wrong Answer	N/A	N/A	c
08/26/2022 16:54	Wrong Answer	N/A	N/A	c
08/26/2022 16:25	Wrong Answer	N/A	N/A	c
08/26/2022 16:09	Wrong Answer	N/A	N/A	c

점들 개수 300개밖에 안되니까 만들수 있는 직선을 기울기와 y절편으로 저장하고
가장 많이 많들어진 직선위에 있는 점들 갯수 세는식으로 구현
부동 소수점 연산 때문인지 계속 오답 나와서 이것저것 해보다가 포기

*/


typedef struct Key{
	long double k;
	long double c;
}Key;

typedef struct Node {
	Key key;
	int value;
	struct Node *left, *right;
}Node;

Node *newNode(Key k, int v) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->key.k = k.k;
	temp->key.c = k.c;
	temp->value = v;
	temp->left = temp->right = NULL;
	return temp;
}

Node *current;

Node *putRec(Node *node, Key key, int value) {
	if (node == NULL)
		return newNode(key, value);

	if (key.k < node->key.k){		
		node->left = putRec(node->left, key, value);
	}
	else if (key.k > node->key.k){
		node->right = putRec(node->right, key, value);
	}
	else{
		if (key.c < node->key.c){		
			node->left = putRec(node->left, key, value);
		}
		else if (key.c > node->key.c){
			node->right = putRec(node->right, key, value);		
		}
		else {
			node->value = value;
		}
	}

	return node;
}

void put(Key key, int value) {
	current = putRec(current, key, value);
}

int findRec(Node *node, Key key) {
	if (node != NULL) {
		if (key.k == node->key.k && key.c == node->key.c){
			return node->value;
		}

		int ret = -1;
		ret = findRec(node->left, key);
		if (ret != -1)
			return ret;

		ret = findRec(node->right, key);
		if (ret != -1)
			return ret;
	}

	return -1;
}

bool contains(Key key) {
	int ret = findRec(current, key);
	if (ret != -1)
		return true;
	return false;
}

int get(Key key) {
	return findRec(current, key);
}

Node *minValueNode(Node *node) {
	Node *current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

Node *removeRec(Node *node, Key key) {
	if (node == NULL)
		return node;

	if (key.k < node->key.k)
		node->left = removeRec(node->left, key);
	else if (key.k > node->key.k)
		node->right = removeRec(node->right, key);
	else if (key.k == node->key.k) {
		if (key.c < node->key.c)
		node->left = removeRec(node->left, key);
	else if (key.c > node->key.c)
		node->right = removeRec(node->right, key);
	}
	else {
		if (node->left == NULL) {
			Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			Node *temp = node->left;
			free(node);
			return temp;
		}

		Node* temp = minValueNode(node->right);
		node->key.k = temp->key.k;
		node->key.c = temp->key.c;
		node->value = temp->value;
		node->right = removeRec(node->right, temp->key);
	}

	return node;
}

// void remove(Key key) {
// 	current = removeRec(current, key);
// }

int maxPoints(int** points, int pointsSize, int* pointsColSize){

	current=NULL;
	if(pointsSize==1) return 1;
    int max = 0;
    Key key;
	Key maxKey;
    int keyValue;
    for (int i = 0; i < pointsSize; i++)
    {
        for (int j = i+1; j < pointsSize; j++)
        {
			//key 값으로 기울기와 y절편, 기울기가 무한대이면 x절편을 키 값으로 하는 걸 계산한다.
			//기울기 k: ((long double)points[j][1]- (long double)points[i][1]) / ((long double) points[j][0] - (long double) points[i][0])
			//y 절편 c: y1-kx1 = c 
            if((long double) points[j][0] - (long double) points[i][0] != 0){
                key.k = ((long double)points[j][1]- (long double)points[i][1]) / ((long double) points[j][0] - (long double) points[i][0]);
				key.c = (long double)points[i][1] - key.k*points[i][0];
            } else{
                key.k = (long double)INT_MAX;
				key.c = (long double)points[i][0];
            }
            if(contains(key)){
                keyValue = get(key);
                if(keyValue+1 > max){
					max = keyValue+1;
					maxKey.k = key.k;
					maxKey.c = key.c;
				}
                put( key, keyValue+1 );
            } else {
				if( 1 > max){
					max = 1;
					maxKey.k = key.k;
					maxKey.c = key.c;
				}
                put( key, 1);
            }
        }        
    }
	
	int ret =0;
	if(maxKey.k == (long double)INT_MAX){
		for (int i = 0; i < pointsSize; i++)
		{
			if(points[i][0] == maxKey.c  ) ret++;
		}

	} else {
		for (int i = 0; i < pointsSize; i++)
		{
			if( ( points[i][1] - (maxKey.k*points[i][0] + maxKey.c) )<0.00000001 ){
				ret++;
			}
			else{
			}
		}
	}
	
    return ret;
}
