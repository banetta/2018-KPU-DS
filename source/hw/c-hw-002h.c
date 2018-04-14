
person *dllsorted_insert(person *list, person *bef, person *new) {
	

}

// list에서 node 삭제 함수
// 반환형으로 person * 를 선언한 이유는 head의 정보가 바뀔 수 있기 때문에 갱신을 해주기 위함
person *dlist_delete (person **head, person *i) { 

	if (*head == i)	// 만약 head(tail)가 자기 자신을 가리킬 때, head를 옮겨준다. list를 가리킬 head에 node정보가 잘못되어 error가 나기 때문
	{
		*head = i->prev;	// head에 앞 노드의 정보를 넣어줌
	}
	// head 체크 후 앞, 뒤 노드를 연결한 뒤 삭제
	i->prev->next = i->next;

	free(i);
	
	return *head;	// if문의 조건에 만족해 head 정보가 바뀔 시에 적용
}

// list display 함수
// 표시할 node를 받아서 출력
void dlist_display (person *i) {	

	// 출력 전 표시할 node가 NULL인지 체크하여 error 방지
	if (i == NULL)
	{
		printf("이 node는 비어있습니다.\n");
		return;	// error 메시지 출력 후 함수 종료
	}

	int repeat; // repeat 변수를 추가로 받아서 전체 노드를 출력할지 현재 노드만 출력할지 체크하여 출력

	printf("반복 출력하시겠습니까?");
	scanf_s("%d", repeat);

	if (repeat = 1)	// 반복 출력일 경우
	{
		// 반복 출력시 출력의 끝부분을 체크하기 위해 pointer를 추가로 생성하여 체크
		person *p; 
		p = i;
		
		do
		{
			//	현재 p = i; 이기 때문에 while문을 바로 돌리면 실행하지않고 바로 종료하기에 
			//	do-while문을 이용, 먼저 선출력 후 check pointer를 다음 pointer로 넘기고 while문을 실행
			printf("name : %s, street : %s, city : %s, province : %s, zip : %s\n", p->name);

			p = p->next;

		} while (p != i);
	}
	else	//	단일 node 출력
	{
		printf("name : %s, street : %s, city : %s, province : %s, zip : %s\n", i->name);
	}
	
}
