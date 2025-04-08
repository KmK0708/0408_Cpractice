#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// chapter12 ��� ������ ���õ�

void pointerFunc_12_1()
{
	// �����͸� ����Ͽ� ���� �հ踦 ���ϴ� ��

	int aa[3]; //������ �迭 ����
	int* p;	// ������ ������ ���� ����
	int i, hap = 0;

	for (i = 0;i < 3;i++) // �迭�� ���� 3�� �Է�
	{
		printf(" %d��° ���� : ", i + 1);
		scanf("%d", &aa[i]);
	}
	p = aa;	// ������ ������ �迭 aa�� �ּ� ����

	for (i = 0;i < 3;i++)		//�հ踦 ����. aa[0]~[2]�� �հ踦 ���Ѵ�.
	{
		hap = hap + *(p + i);
	}

	printf("�Է� ������ �� => %d\n", hap);
}

// ������ ũ���� �迭�� ���� �޸� ������ ��
void without_mallocfunc_12_2()
{
	int aa[10000];		//������ �迭 ����
	int* p;		// ������ ������ ���� ����
	int i, hap = 0;
	int count;

	printf(" �Է��� ������? : ");
	scanf("%d", &count);		// �Է��� ������ ���� �Է�

	for (i = 0;i < count;i++)	// �Է��� ������ŭ �迭�� ���� �Է�
	{
		printf(" %d��° ���� : ", i + 1);
		scanf("%d", &aa[i]);
	}

	p = aa;		//������ ������ �ּ� ����

	for (i = 0;i < count;i++)	//�հ� ����
		hap = hap + *(p + i);

	printf("�Է� ������ �� ==> %d\n", hap); //�հ����
}

// malloc �Լ� ��� ��
void with_mallocfunc_12_3()
{
	int* p;		// ������ ������ ���� ����
	int i, hap = 0;
	int count;

	printf(" �Է��� ������? : ");
	scanf("%d", &count);		// �Է��� ������ ���� �Է�

	p = (int*)malloc(sizeof(int) * count);		// �Է��� ������ŭ �޸� Ȯ��



	for (i = 0;i < count;i++)	// �Է��� ������ŭ �ݺ�
	{
		printf(" %d��° ���� : ", i + 1);
		scanf("%d", p+i);
	}

	for (i = 0;i < count;i++)	
		hap = hap + *(p + i);		//�޸��� ���� ���� �հ迡 �����Ѵ�. �迭ó�� p[i]��� �Է��ص� ��.

	printf("�Է� ������ �� ==> %d\n", hap); //�հ����

	free(p);		// �޸� ����
}

// malloc / calloc �Լ� ��
void calloc_mallocfunc_12_4()
{
	int* p, * s;  // ������ ������ ���� ����
	int i, j;

	printf("malloc()�Լ� ���\n");
	p = (int*)malloc(sizeof(int) * 3);	// malloc �Լ��� ������ �޸� 3�� �Ҵ� 12����Ʈ

	for (i = 0;i < 3;i++)
		printf("�Ҵ�� ���� �ʱ갪 p[%d] ==> %d\n", i, p[i]);  // ������ ���� p �� ����Ű�� ���� �� ���

	free(p);  // �޸� ����

	printf("\ncalloc()�Լ� ���\n");
	s = (int*)calloc(sizeof(int), 3); // calloc(ũ��,����) �Լ��� ������ �޸� 3�� �Ҵ�

	for (j = 0;j < 3;j++)
		printf("�Ҵ�� ���� �ʱ갪 s[%d] ==> %d\n", j, s[j]);  // ������ ���� s �� ����Ű�� ���� �� ���

	free(s);
}

// realloc �Լ� ��� ��
void reallocfunc()
{
	int* p;
	int i, hap = 0;
	int count = 0;
	int data;

	p = (int*)malloc(sizeof(int) * 1);	//malloc �Լ��� �޸� 1�� �Ҵ�
	printf(" 1 ��° ���� : ");
	scanf("%d", &p[0]);			//ù��° ���� �Է¹ް� ������ ���� 1����.
	count++;

	for (i = 2; ;i++)		// �ι�° ������ ��� �Է� �޴´�. ������ ��� ���� ����
	{
		printf(" %d ��° ���� : ", i);
		scanf("%d", &data);		// �ٷ� ������ �Էµ� ���� �ӽ� ��ҿ� ����

		if (data != 0)			// �Էµ� ���� 0�� �ƴϸ�
		{
			p = (int*)realloc(p, sizeof(int) * i);	// �޸𸮸� ��ĭ �߰�
		}
		else		// 0�̸�
		{
			break;		// for�� Ż��
		}

		p[i - 1] = data;		// �߰��� �޸� ������ �ӽ� ����� ���� ����
		count++;		// �Է°� ���� 1����

	}

	for (i=0;i<count;i++)		// ����ڰ� �Է��� ���� ��ŭ �ݺ��ؼ� �հ� ���ϱ�
	{
		hap = hap + p[i];
	}

	printf("�Է� ���� �� ==> %d\n", hap);		//�հ� ���

	free(p);		//�޸� ����
}

// 2���� �迭 ��� ��
void dimension2_array()
{
	char data[3][100];	// 3�� 100���� 2���� �迭 ����
	int i;

	for (i = 0;i < 3;i++)	//3�� �ݺ�
	{
		printf(" %d ��° ���ڿ� : ",i + 1);
		gets(data[i]);	// �� �࿡ �ִ� 99�� ���ڿ� �Է�

	}

	printf("\n -- �Է°� �ݴ�� ���(2���� �迭) -- \n");
	for (i = 2;i >= 0;i--)		// 2�� ,1��, 0���� ������ ������ ����� ���
	{
		printf(" %d :%s\n", i + 1, data[i]);
	}
}

// ������ �迭 ��� ��
void pointerArr()
{
	char* p[3];       // ������ �迭 ���� (���ڿ� 3���� ������ �� �ִ� ������ �迭)
	char imsi[100];   // �Է� ���� �ӽ� �迭
	int i, size;

	// ���ڿ� �Է� �� ����
	for (i = 0; i < 3; i++)
	{
		printf("%d ��° ���ڿ� : ", i + 1);
		gets(imsi);  // �ӽ� ������ ���ڿ� �Է� (����: ���Ȼ� unsafe)

		size = strlen(imsi);  // �Է� ���ڿ� ���� ���
		p[i] = (char*)malloc((sizeof(char) * size) + 1); // �Է��� ���� + 1 ũ�� ���� �޸� �Ҵ�

		strcpy(p[i], imsi);  // �Է� ���ڿ��� �Ҵ��� �޸𸮿� ����
	}

	// �������� ���
	printf("\n-- �Է°� �ݴ�� ���(������) --\n");
	for (i = 2; i >= 0; i--)
	{
		printf("%d : %s\n", i + 1, p[i]);		//������ �迭�� ����� ���ڿ� ���
	}

	// �Ҵ�� �޸� ����
	for (i = 0; i < 3; i++)
	{
		free(p[i]);
	}
}

// �Է��� �� �� ¦���� ���ؼ� ����ϱ�
void evenAllplus()
{
	int* p;
	int i, hap = 0;
	int count;

	printf("�Է��� ������? : ");
	scanf("%d", &count);

	//�Է��� ������ ���� �޸� �Ҵ����ֱ�
	p = (int*)malloc(sizeof(int) * count);

	for (i = 0; i< count; i++)
	{
		printf(" %d��° ���� : ", i + 1);
		scanf("%d", p + i);
	}

	for (i = 0; i < count; i++)
	{
		//¦���϶��� �����ֱ�
		if (p[i] % 2 == 0)
		{
			hap = hap + p[i];
		}
	}

	printf("¦���� ���� %d�Դϴ�.", hap);

	free(p);
}

//�Է��� ���ڿ��� �ݴ� ������ ����ϱ�
void reverseinputStr()
{
	char* p[3]; // �迭3������
	char tempArr[100]; // �ӽ� ���� �迭

	int i, k,size;

	// ���ڿ� �Է� �� ����
	for (i = 0; i < 3; i++)
	{
		printf("%d ��° ���ڿ� : ", i + 1);
		gets(tempArr);  // �ӽ� ������ ���ڿ� �Է� (����: ���Ȼ� unsafe)

		size = strlen(tempArr);  // �Է� ���ڿ� ���� ���
		p[i] = (char*)malloc((sizeof(char) * size) + 1); // �Է��� ���� + 1 ũ�� ���� �޸� �Ҵ�

		strcpy(p[i], tempArr);  // �Է� ���ڿ��� �Ҵ��� �޸𸮿� ����
	}

	printf("--�Է��� ���ڿ��� �ݴ�� ����ϱ�--\n");
	for (i = 2; i >= 0;i--)
	{
		//���̸� ���
		size = strlen(p[i]);
		tempArr[size] = '\0'; // ���ڿ��� �� ���� �Է�
		for (k = size - 1; k >= 0;k--)
			tempArr[size - 1 - k] = p[i][k];
		printf("%d : %s\n", i + 1, tempArr);		//������ �迭�� ����� ���ڿ� ���
	}

	// �Ҵ�� �޸� ����
	for (i = 0; i < 3; i++)
	{
		free(p[i]);
	}

}


// �Ʒ��� chapter 13 ����ü ������


//����ü ��� ��
void structTest()
{
	struct bibim
	{
		// ����ü bibim ����
		int a;
		float b;
		char c;
		char d[5];
	};

	struct bibim b1;  // ����ü ���� b1 ���� (���� �������)

	// ����ü ������ ��� ������ �� ����
	b1.a = 10;
	b1.b = 1.1f;
	b1.c = 'A';
	strcpy(b1.d, "ABCD");

	printf("b1.a ==> %d\n", b1.a);
	printf("b1.b ==> %f\n", b1.b);
	printf("b1.c ==> %c\n", b1.c);
	printf("b1.d ==> %s\n", b1.d);
}

//����ü ��� ��������
void notuseStruct()
{
	char name[10]; //�̸�,��������,��������,��� ���� ����
	int kor;
	int eng;
	float avg;

	printf("�̸� : ");
	scanf("%s", name, 9); // �̸� �Է� 9�� �̳�

	printf("���� ���� : ");
	scanf("%d", &kor); // �������� �Է�

	printf("���� ���� : ");
	scanf("%d", &eng); // ���� ���� �Է�

	avg = (kor + eng) / 2.0f; // ��� ���

	printf("\n");
	printf("�̸� ==> %s\n", name );
	printf("���� ���� ==> %d\n", kor);
	printf("���� ���� ==> %d\n", eng);
	printf("��� ���� ==> %5.1f\n",avg);
}

// ����ü�� ��� ���� ��
void useStruct()
{
	struct student // student ����ü ����
	{
		char name[10]; //�̸�,��������,��������,��� ��� ���� ����
		int kor;
		int eng;
		float avg;

	};
	struct student s; // ����ü ���� s ����

	printf("�̸� : ");
	scanf("%s", s.name, 9); // �̸� �Է� 9�� �̳�

	printf("���� ���� : ");
	scanf("%d", &s.kor); // �������� �Է�

	printf("���� ���� : ");
	scanf("%d", &s.eng); // ���� ���� �Է�

	s.avg = (s.kor + s.eng) / 2.0f; // ��� ���

	printf("\n-----����ü Ȱ��-----\n");
	printf("�̸� ==> %s\n", s.name);
	printf("���� ���� ==> %d\n", s.kor);
	printf("���� ���� ==> %d\n", s.eng);
	printf("��� ���� ==> %5.1f\n", s.avg);
}

// ����ü �迭�� ��� ���� ���� ��
void notuse_struct_arr()
{
	char name[3][10]; //�̸�,��������,��������,��� �迭 ����
	int kor[3];
	int eng[3];
	float avg[3];

	int i;

	strcpy(name[0], "kim"); // ù��° �л��� ������ �����Ѵ�.
	kor[0] = 70;				// �̸�,��������,��������,���
	eng[0] = 80;
	avg[0] = (kor[0] + eng[0]) / 2.0f;

	strcpy(name[1], "woo");  // �ι�° �л��� ������ �����Ѵ�
	kor[1] = 60;				   //�̸�, ��������, ��������, ���
	eng[1] = 85;
	avg[1] = (kor[1] + eng[1]) / 2.0f;

	strcpy(name[2], "lee");  // ����° �л��� ������ �����Ѵ�
	kor[2]= 100;				   //�̸�, ��������, ��������, ���
	eng[2] = 70;
	avg[2] = (kor[2] + eng[2]) / 2.0f;

	for (i = 0;i < 3;i++)		// 3�� �ݺ�, �迭 ���� ���
	{
		printf("�̸� ==> %s\n", name[i]);
		printf("���� ���� ==> %d\n", kor[i]);
		printf("���� ���� ==> %d\n", eng[i]);
		printf("��� ���� ==> %5.1f\n", avg[i]);
		printf("\n");
	}
}

// ����ü �迭�� ��� �� ��
void use_struct_arr()
{
	struct student // student ����ü ����
	{
		char name[10]; //�̸�,��������,��������,��� ��� ���� ����
		int kor;
		int eng;
		float avg;

	};

	struct student s[3]; // ����ü �迭 s[3] ����

	int i;

	strcpy(s[0].name, "kim"); // ù��° �л��� ������ �����Ѵ�.
	s[0].kor = 70;				// �̸�,��������,��������,���
	s[0].eng = 80;
	s[0].avg = (s[0].kor + s[0].eng) / 2.0f;

	strcpy(s[1].name, "woo");  // �ι�° �л��� ������ �����Ѵ�
	s[1].kor = 60;				   //�̸�, ��������, ��������, ���
	s[1].eng = 85;
	s[1].avg = (s[1].kor + s[1].eng) / 2.0f;

	strcpy(s[2].name, "lee");  // ����° �л��� ������ �����Ѵ�
	s[2].kor	= 100;				   //�̸�, ��������, ��������, ���
	s[2].eng = 70;
	s[2].avg = (s[2].kor + s[2].eng) / 2.0f;

	printf("----����ü �迭 ----\n");
	for (i = 0;i < 3;i++)
	{
		printf("�л� �̸� => %s\n", s[i].name);
		printf("���� ���� => %d\n", s[i].kor);
		printf("���� ���� => %d\n", s[i].eng);
		printf("��� ���� => %5.1f\n", s[i].avg);
		printf("\n");
	}
}

// ����ü ������ ��� ��
void structpointer()
{
	struct student // student ����ü ����
	{
		char name[10]; //�̸�,��������,��������,��� ��� ���� ����
		int kor;
		int eng;
		float avg;

	};
	struct student s; // ����ü ���� s ����
	struct student* p; // ����ü ������ ���� p ����

	p = &s;	// ������ ������ s�� �ּҸ� ����.

	printf("�̸� : ");
	scanf("%s", p->name, 9); // �̸� �Է� 9�� �̳�

	printf("���� ���� : ");
	scanf("%d", &p->kor); // �������� �Է�

	printf("���� ���� : ");
	scanf("%d", &p->eng); // ���� ���� �Է�

	p->avg = (p->kor + p->eng) / 2.0f; // ��� ���

	printf("\n");
	printf("\n---------����ü ������ Ȱ��--------\n");
	printf("�̸� ==> %s\n", p->name);
	printf("���� ���� ==> %d\n", p->kor);
	printf("���� ���� ==> %d\n", p->eng);
	printf("��� ���� ==> %5.1f\n", p->avg);
}

// ����ü ��� ��
void useunion()
{
	union student{  // ����ü ���� student ����
		int tot;
		char grade;
	};

	union student u;  // ����ü ���� u ����

	u.tot = 300;  // ����ü ������ ��� ������ �� ����
	u.grade = 'A';

	printf("\n------����ü Ȱ��------\n");
	printf("���� ==> %d\n", u.tot);  // ����ü ������ ��� ������ ���
	printf("��� ==> %c\n", u.grade);
}

// ������ ��� ��
void useEnum()
{
	enum week {sun,mon,tue,wed,thu,fri,sat}; // 0���� 6���� ������

	enum week ww; // ������ ���� ww�� ����

	ww = sat; //���� ww�� ���� �����Ѵ�.

	if (ww == sun) //ww �� sun(0) ���� �ƴ����� ���ο� ���� ������ ���
		printf("������ �Ͽ��� �Դϴ�.\n");
	else
		printf("������ �Ͽ����� �ƴմϴ�.\n");
}