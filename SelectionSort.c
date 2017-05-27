#include <stdio.h>

#define NUMBER 100 //�v�f��NUMBER��100

//�֐��錾
void exchange(int d[],int i, int j);
void exchange2(int *x, int *y);
void Selection(int data[]);
void Selection2(int data[]);
void Display(int number[]);

//main
int main(){

	FILE *fp;
	int number[NUMBER];
	char filename[200];
	char file[200];
	char extension[200];
	//�t�@�C���̓ǂݍ���
	fp=fopen("sample.txt","r");
	if (fp==NULL){
		printf("can't open a file\n");
		exit(1);
	}
	for(int i=0;i<NUMBER;i++)fscanf(fp,"%d",&number[i]);
	fclose(fp);
	
	//�ǂݍ��ݏI���
	
	Selection(number);
	printf("��������\n");
	Display(number);
	Selection2(number);
	printf("\n�傫����\n");	
	Display(number);
	return 0;
}
//����(�z��)
void exchange(int d[],int i, int j){
	int tmp;
	tmp	=d[i];
	d[i]=d[j];
	d[j]=tmp;

}
//�����i�|�C���^)
void exchange2(int *x, int *y){
	int tmp;
	tmp =*x;
	*x	=*y;
	*y	=tmp;
}
//��������
void Selection(int data[]){
	int min;
	for(int i=NUMBER;0<i;i--){
		min=0;
		for(int j=0;j<i;j++){
			if(data[min]<data[j]){
			//�傫�����ɂ���Ƃ���if���́������ɂ���
				min=j;
			}
		}
		//exchange(data,min,i-1);	//�z��
		exchange2(&data[min],&data[i-1]);	//�|�C���^
	}
}
//�傫����
void Selection2(int data[]){
	int min;
	for(int i=NUMBER;0<i;i--){
		min=0;
		for(int j=0;j<i;j++){
			if(data[min]>data[j]){
			//�傫�����ɂ���Ƃ���if���́������ɂ���
				min=j;
			}
		}
		//exchange(data,min,i-1);	//�z��
		exchange2(&data[min],&data[i-1]);	//�|�C���^
	}
}
//�\��
void Display(int number[]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%3d",number[10*i+j]);
		}
		printf("\n");
	}
}

