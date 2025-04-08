#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// chapter12 고급 포인터 예시들

void pointerFunc_12_1()
{
	// 포인터를 사용하여 정수 합계를 구하는 예

	int aa[3]; //정수형 배열 선언
	int* p;	// 정수형 포인터 변수 선언
	int i, hap = 0;

	for (i = 0;i < 3;i++) // 배열에 숫자 3개 입력
	{
		printf(" %d번째 숫자 : ", i + 1);
		scanf("%d", &aa[i]);
	}
	p = aa;	// 포인터 변수에 배열 aa의 주소 대입

	for (i = 0;i < 3;i++)		//합계를 누적. aa[0]~[2]의 합계를 구한다.
	{
		hap = hap + *(p + i);
	}

	printf("입력 숫자의 합 => %d\n", hap);
}

// 고정된 크기의 배열로 인한 메모리 낭비의 예
void without_mallocfunc_12_2()
{
	int aa[10000];		//정수형 배열 선언
	int* p;		// 정수형 포인터 변수 선언
	int i, hap = 0;
	int count;

	printf(" 입력할 개수는? : ");
	scanf("%d", &count);		// 입력할 숫자의 개수 입력

	for (i = 0;i < count;i++)	// 입력한 개수만큼 배열에 숫자 입력
	{
		printf(" %d번째 숫자 : ", i + 1);
		scanf("%d", &aa[i]);
	}

	p = aa;		//포인터 변수에 주소 대입

	for (i = 0;i < count;i++)	//합계 누적
		hap = hap + *(p + i);

	printf("입력 숫자의 합 ==> %d\n", hap); //합계출력
}

// malloc 함수 사용 예
void with_mallocfunc_12_3()
{
	int* p;		// 정수형 포인터 변수 선언
	int i, hap = 0;
	int count;

	printf(" 입력할 개수는? : ");
	scanf("%d", &count);		// 입력할 숫자의 개수 입력

	p = (int*)malloc(sizeof(int) * count);		// 입력한 개수만큼 메모리 확보



	for (i = 0;i < count;i++)	// 입력한 개수만큼 반복
	{
		printf(" %d번째 숫자 : ", i + 1);
		scanf("%d", p+i);
	}

	for (i = 0;i < count;i++)	
		hap = hap + *(p + i);		//메모리의 실제 값을 합계에 누적한다. 배열처럼 p[i]라고 입력해도 됨.

	printf("입력 숫자의 합 ==> %d\n", hap); //합계출력

	free(p);		// 메모리 해제
}

// malloc / calloc 함수 비교
void calloc_mallocfunc_12_4()
{
	int* p, * s;  // 정수형 포인터 변수 선언
	int i, j;

	printf("malloc()함수 사용\n");
	p = (int*)malloc(sizeof(int) * 3);	// malloc 함수로 정수형 메모리 3개 할당 12바이트

	for (i = 0;i < 3;i++)
		printf("할당된 곳의 초깃값 p[%d] ==> %d\n", i, p[i]);  // 포인터 변수 p 가 가르키는 실제 값 출력

	free(p);  // 메모리 해제

	printf("\ncalloc()함수 사용\n");
	s = (int*)calloc(sizeof(int), 3); // calloc(크기,개수) 함수로 정수형 메모리 3개 할당

	for (j = 0;j < 3;j++)
		printf("할당된 곳의 초깃값 s[%d] ==> %d\n", j, s[j]);  // 포인터 변수 s 가 가르키는 실제 값 출력

	free(s);
}

// realloc 함수 사용 예
void reallocfunc()
{
	int* p;
	int i, hap = 0;
	int count = 0;
	int data;

	p = (int*)malloc(sizeof(int) * 1);	//malloc 함수로 메모리 1개 할당
	printf(" 1 번째 숫자 : ");
	scanf("%d", &p[0]);			//첫번째 값을 입력받고 데이터 개수 1증가.
	count++;

	for (i = 2; ;i++)		// 두번째 값부터 계속 입력 받는다. 조건이 없어서 무한 루프
	{
		printf(" %d 번째 숫자 : ", i);
		scanf("%d", &data);		// 바로 위에서 입력된 값을 임시 장소에 저장

		if (data != 0)			// 입력된 값이 0이 아니면
		{
			p = (int*)realloc(p, sizeof(int) * i);	// 메모리를 한칸 추가
		}
		else		// 0이면
		{
			break;		// for문 탈출
		}

		p[i - 1] = data;		// 추가한 메모리 공간에 임시 장소의 값을 대입
		count++;		// 입력값 개수 1증가

	}

	for (i=0;i<count;i++)		// 사용자가 입력한 개수 만큼 반복해서 합계 구하기
	{
		hap = hap + p[i];
	}

	printf("입력 숫자 합 ==> %d\n", hap);		//합계 출력

	free(p);		//메모리 해제
}

// 2차원 배열 사용 예
void dimension2_array()
{
	char data[3][100];	// 3행 100열의 2차원 배열 선언
	int i;

	for (i = 0;i < 3;i++)	//3번 반복
	{
		printf(" %d 번째 문자열 : ",i + 1);
		gets(data[i]);	// 각 행에 최대 99자 문자열 입력

	}

	printf("\n -- 입력과 반대로 출력(2차원 배열) -- \n");
	for (i = 2;i >= 0;i--)		// 2행 ,1행, 0행의 순서로 마지막 행부터 출력
	{
		printf(" %d :%s\n", i + 1, data[i]);
	}
}

// 포인터 배열 사용 예
void pointerArr()
{
	char* p[3];       // 포인터 배열 선언 (문자열 3개를 저장할 수 있는 포인터 배열)
	char imsi[100];   // 입력 받을 임시 배열
	int i, size;

	// 문자열 입력 및 복사
	for (i = 0; i < 3; i++)
	{
		printf("%d 번째 문자열 : ", i + 1);
		gets(imsi);  // 임시 공간에 문자열 입력 (주의: 보안상 unsafe)

		size = strlen(imsi);  // 입력 문자열 길이 계산
		p[i] = (char*)malloc((sizeof(char) * size) + 1); // 입력한 길이 + 1 크기 동적 메모리 할당

		strcpy(p[i], imsi);  // 입력 문자열을 할당한 메모리에 복사
	}

	// 역순으로 출력
	printf("\n-- 입력과 반대로 출력(포인터) --\n");
	for (i = 2; i >= 0; i--)
	{
		printf("%d : %s\n", i + 1, p[i]);		//포인터 배열에 저장된 문자열 출력
	}

	// 할당된 메모리 해제
	for (i = 0; i < 3; i++)
	{
		free(p[i]);
	}
}

// 입력한 수 중 짝수만 합해서 출력하기
void evenAllplus()
{
	int* p;
	int i, hap = 0;
	int count;

	printf("입력할 갯수는? : ");
	scanf("%d", &count);

	//입력한 갯수에 따라 메모리 할당해주기
	p = (int*)malloc(sizeof(int) * count);

	for (i = 0; i< count; i++)
	{
		printf(" %d번째 숫자 : ", i + 1);
		scanf("%d", p + i);
	}

	for (i = 0; i < count; i++)
	{
		//짝수일때만 합해주기
		if (p[i] % 2 == 0)
		{
			hap = hap + p[i];
		}
	}

	printf("짝수의 합은 %d입니다.", hap);

	free(p);
}

//입력한 문자열을 반대 순서로 출력하기
void reverseinputStr()
{
	char* p[3]; // 배열3개선언
	char tempArr[100]; // 임시 저장 배열

	int i, k,size;

	// 문자열 입력 및 복사
	for (i = 0; i < 3; i++)
	{
		printf("%d 번째 문자열 : ", i + 1);
		gets(tempArr);  // 임시 공간에 문자열 입력 (주의: 보안상 unsafe)

		size = strlen(tempArr);  // 입력 문자열 길이 계산
		p[i] = (char*)malloc((sizeof(char) * size) + 1); // 입력한 길이 + 1 크기 동적 메모리 할당

		strcpy(p[i], tempArr);  // 입력 문자열을 할당한 메모리에 복사
	}

	printf("--입력한 문자열을 반대로 출력하기--\n");
	for (i = 2; i >= 0;i--)
	{
		//길이를 재기
		size = strlen(p[i]);
		tempArr[size] = '\0'; // 문자열에 널 문자 입력
		for (k = size - 1; k >= 0;k--)
			tempArr[size - 1 - k] = p[i][k];
		printf("%d : %s\n", i + 1, tempArr);		//포인터 배열에 저장된 문자열 출력
	}

	// 할당된 메모리 해제
	for (i = 0; i < 3; i++)
	{
		free(p[i]);
	}

}


// 아래는 chapter 13 구조체 예제들


//구조체 사용 예
void structTest()
{
	struct bibim
	{
		// 구조체 bibim 선언
		int a;
		float b;
		char c;
		char d[5];
	};

	struct bibim b1;  // 구조체 변수 b1 선언 (실제 저장공간)

	// 구조체 변수와 멤버 변수에 값 대입
	b1.a = 10;
	b1.b = 1.1f;
	b1.c = 'A';
	strcpy(b1.d, "ABCD");

	printf("b1.a ==> %d\n", b1.a);
	printf("b1.b ==> %f\n", b1.b);
	printf("b1.c ==> %c\n", b1.c);
	printf("b1.d ==> %s\n", b1.d);
}

//구조체 사용 안했을때
void notuseStruct()
{
	char name[10]; //이름,국어점수,영어점수,평균 변수 선언
	int kor;
	int eng;
	float avg;

	printf("이름 : ");
	scanf("%s", name, 9); // 이름 입력 9자 이내

	printf("국어 점수 : ");
	scanf("%d", &kor); // 국어점수 입력

	printf("영어 점수 : ");
	scanf("%d", &eng); // 영어 점수 입력

	avg = (kor + eng) / 2.0f; // 평균 계산

	printf("\n");
	printf("이름 ==> %s\n", name );
	printf("국어 점수 ==> %d\n", kor);
	printf("영어 점수 ==> %d\n", eng);
	printf("평균 점수 ==> %5.1f\n",avg);
}

// 구조체를 사용 했을 때
void useStruct()
{
	struct student // student 구조체 선언
	{
		char name[10]; //이름,국어점수,영어점수,평균 멤버 변수 선언
		int kor;
		int eng;
		float avg;

	};
	struct student s; // 구조체 변수 s 선언

	printf("이름 : ");
	scanf("%s", s.name, 9); // 이름 입력 9자 이내

	printf("국어 점수 : ");
	scanf("%d", &s.kor); // 국어점수 입력

	printf("영어 점수 : ");
	scanf("%d", &s.eng); // 영어 점수 입력

	s.avg = (s.kor + s.eng) / 2.0f; // 평균 계산

	printf("\n-----구조체 활용-----\n");
	printf("이름 ==> %s\n", s.name);
	printf("국어 점수 ==> %d\n", s.kor);
	printf("영어 점수 ==> %d\n", s.eng);
	printf("평균 점수 ==> %5.1f\n", s.avg);
}

// 구조체 배열을 사용 하지 않은 예
void notuse_struct_arr()
{
	char name[3][10]; //이름,국어점수,영어점수,평균 배열 선언
	int kor[3];
	int eng[3];
	float avg[3];

	int i;

	strcpy(name[0], "kim"); // 첫번째 학생의 정보를 대입한다.
	kor[0] = 70;				// 이름,국어점수,영어점수,평균
	eng[0] = 80;
	avg[0] = (kor[0] + eng[0]) / 2.0f;

	strcpy(name[1], "woo");  // 두번째 학생의 정보를 대입한다
	kor[1] = 60;				   //이름, 국어점수, 영어점수, 평균
	eng[1] = 85;
	avg[1] = (kor[1] + eng[1]) / 2.0f;

	strcpy(name[2], "lee");  // 세번째 학생의 정보를 대입한다
	kor[2]= 100;				   //이름, 국어점수, 영어점수, 평균
	eng[2] = 70;
	avg[2] = (kor[2] + eng[2]) / 2.0f;

	for (i = 0;i < 3;i++)		// 3번 반복, 배열 내용 출력
	{
		printf("이름 ==> %s\n", name[i]);
		printf("국어 점수 ==> %d\n", kor[i]);
		printf("영어 점수 ==> %d\n", eng[i]);
		printf("평균 점수 ==> %5.1f\n", avg[i]);
		printf("\n");
	}
}

// 구조체 배열을 사용 한 예
void use_struct_arr()
{
	struct student // student 구조체 선언
	{
		char name[10]; //이름,국어점수,영어점수,평균 멤버 변수 선언
		int kor;
		int eng;
		float avg;

	};

	struct student s[3]; // 구조체 배열 s[3] 선언

	int i;

	strcpy(s[0].name, "kim"); // 첫번째 학생의 정보를 대입한다.
	s[0].kor = 70;				// 이름,국어점수,영어점수,평균
	s[0].eng = 80;
	s[0].avg = (s[0].kor + s[0].eng) / 2.0f;

	strcpy(s[1].name, "woo");  // 두번째 학생의 정보를 대입한다
	s[1].kor = 60;				   //이름, 국어점수, 영어점수, 평균
	s[1].eng = 85;
	s[1].avg = (s[1].kor + s[1].eng) / 2.0f;

	strcpy(s[2].name, "lee");  // 세번째 학생의 정보를 대입한다
	s[2].kor	= 100;				   //이름, 국어점수, 영어점수, 평균
	s[2].eng = 70;
	s[2].avg = (s[2].kor + s[2].eng) / 2.0f;

	printf("----구조체 배열 ----\n");
	for (i = 0;i < 3;i++)
	{
		printf("학생 이름 => %s\n", s[i].name);
		printf("국어 점수 => %d\n", s[i].kor);
		printf("영어 점수 => %d\n", s[i].eng);
		printf("평균 점수 => %5.1f\n", s[i].avg);
		printf("\n");
	}
}

// 구조체 포인터 사용 예
void structpointer()
{
	struct student // student 구조체 선언
	{
		char name[10]; //이름,국어점수,영어점수,평균 멤버 변수 선언
		int kor;
		int eng;
		float avg;

	};
	struct student s; // 구조체 변수 s 선언
	struct student* p; // 구조체 포인터 변수 p 선언

	p = &s;	// 포인터 변수에 s의 주소를 대입.

	printf("이름 : ");
	scanf("%s", p->name, 9); // 이름 입력 9자 이내

	printf("국어 점수 : ");
	scanf("%d", &p->kor); // 국어점수 입력

	printf("영어 점수 : ");
	scanf("%d", &p->eng); // 영어 점수 입력

	p->avg = (p->kor + p->eng) / 2.0f; // 평균 계산

	printf("\n");
	printf("\n---------구조체 포인터 활용--------\n");
	printf("이름 ==> %s\n", p->name);
	printf("국어 점수 ==> %d\n", p->kor);
	printf("영어 점수 ==> %d\n", p->eng);
	printf("평균 점수 ==> %5.1f\n", p->avg);
}

// 공용체 사용 예
void useunion()
{
	union student{  // 공용체 변수 student 선언
		int tot;
		char grade;
	};

	union student u;  // 공용체 변수 u 선언

	u.tot = 300;  // 공용체 변수의 멤버 변수에 값 대입
	u.grade = 'A';

	printf("\n------공용체 활용------\n");
	printf("총점 ==> %d\n", u.tot);  // 공용체 변수의 멤버 변숫값 출력
	printf("등급 ==> %c\n", u.grade);
}

// 열거형 사용 예
void useEnum()
{
	enum week {sun,mon,tue,wed,thu,fri,sat}; // 0부터 6까지 열거형

	enum week ww; // 열거형 변수 ww를 선언

	ww = sat; //변수 ww에 값을 대입한다.

	if (ww == sun) //ww 가 sun(0) 인지 아닌지의 여부에 따라 문장을 출력
		printf("오늘은 일요일 입니다.\n");
	else
		printf("오늘은 일요일이 아닙니다.\n");
}