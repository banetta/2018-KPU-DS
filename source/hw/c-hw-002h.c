
person *dllsorted_insert(person *list, person *bef, person *new) {
	

}

// list���� node ���� �Լ�
// ��ȯ������ person * �� ������ ������ head�� ������ �ٲ� �� �ֱ� ������ ������ ���ֱ� ����
person *dlist_delete (person **head, person *i) { 

	if (*head == i)	// ���� head(tail)�� �ڱ� �ڽ��� ����ų ��, head�� �Ű��ش�. list�� ����ų head�� node������ �߸��Ǿ� error�� ���� ����
	{
		*head = i->prev;	// head�� �� ����� ������ �־���
	}
	// head üũ �� ��, �� ��带 ������ �� ����
	i->prev->next = i->next;

	free(i);
	
	return *head;	// if���� ���ǿ� ������ head ������ �ٲ� �ÿ� ����
}

// list display �Լ�
// ǥ���� node�� �޾Ƽ� ���
void dlist_display (person *i) {	

	// ��� �� ǥ���� node�� NULL���� üũ�Ͽ� error ����
	if (i == NULL)
	{
		printf("�� node�� ����ֽ��ϴ�.\n");
		return;	// error �޽��� ��� �� �Լ� ����
	}

	int repeat; // repeat ������ �߰��� �޾Ƽ� ��ü ��带 ������� ���� ��常 ������� üũ�Ͽ� ���

	printf("�ݺ� ����Ͻðڽ��ϱ�?");
	scanf_s("%d", repeat);

	if (repeat = 1)	// �ݺ� ����� ���
	{
		// �ݺ� ��½� ����� ���κ��� üũ�ϱ� ���� pointer�� �߰��� �����Ͽ� üũ
		person *p; 
		p = i;
		
		do
		{
			//	���� p = i; �̱� ������ while���� �ٷ� ������ ���������ʰ� �ٷ� �����ϱ⿡ 
			//	do-while���� �̿�, ���� ����� �� check pointer�� ���� pointer�� �ѱ�� while���� ����
			printf("name : %s, street : %s, city : %s, province : %s, zip : %s\n", p->name);

			p = p->next;

		} while (p != i);
	}
	else	//	���� node ���
	{
		printf("name : %s, street : %s, city : %s, province : %s, zip : %s\n", i->name);
	}
	
}
