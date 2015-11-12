//j1317 �p�����N �t�x�݉ۑ�"�e�g���X�Q�[��"
//
//4�����A6���E�A2�����A8����]�A�Ƃ�������Ńu���b�N��ς�ł����B
//����񂻂낦��ƃu���b�N��������B
//�����ɑ����̗�������ƃX�R�A���L�т�B
//

#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#include <conio.h>

#define SIZEX 12
#define SIZEY 20
#define EMPTY 0
#define BLOCK 1
#define FRAME 9

int field[SIZEY+1][SIZEX]={0};//�`�ʗp�̔z��
int p_field[SIZEY+1][SIZEX]={0};//�Œ�u���b�N�p�̔z��
int piece[4][4]={0},n_piece[4][4]={0};//���ݓ����Ă���u���b�N�Ǝ��̃u���b�N
int px=4,py=0;//�u���b�N�z��̍���̍��W
int oneline=0,twoline=0,threeline=0,fourline=0;//��������̃J�E���g
int judge=1;//�Q�[�����s���f

void Display()//��ʕ\��
{
	int x,y,i;
	system("cls");// ��ʏ���

	//�Q�[���t�B�[���h�̕\��
	for(y=0;y<SIZEY+1;y++)
	{
		for(x=0;x<SIZEX;x++)
		{
			switch(field[y][x])
			{
				printf("�@");
				break;
			case FRAME:
				printf("��");
				break;
			case BLOCK:
				printf("��");
				break;
			default:
				printf("�@");
				break;
			}
		}
		//�Q�[���[�̕\��
		if(y==1)
			printf("�@NEXT PIECE");
		if(y==2||y==7||y==9||y==12)
				printf("�@������������");
		if(y==3||y==4||y==5||y==6)
		{
			printf("�@��");
			for(i=0;i<4;i++)
			{
				if(n_piece[y-3][i]==BLOCK)
					printf("��");
				else if(n_piece[y-3][i]==EMPTY)
					printf("�@");
			}
			printf("��");
		}
		if(y==10)
			printf("�@��SCORE");
		if(y==11)
			printf("�@��%d",oneline*100+twoline*300+threeline*700+fourline*1500);
		if(y==14||y==19)
			printf("�@��������������");
		if(y==15||y==16||y==17||y==18)
		{
			printf("�@��%d�����:",y-14);
			switch(y-14)
			{
				case 1:
					if(oneline<10)
						printf(" %d��",oneline);
					else
						printf("%d��",oneline);
					break;
				case 2:
					if(twoline<10)
						printf(" %d��",twoline);
					else
						printf("%d��",twoline);
					break;
				case 3:
					if(threeline<10)
						printf(" %d��",threeline);
					else
						printf("%d��",threeline);
					break;
				case 4:
					if(fourline<10)
						printf(" %d��",fourline);
					else
						printf("%d��",fourline);
					break;
			}
		}
		printf("\n");
	}
}

//�u���b�N�̍쐬
void MakePiece()
{
	int x,y;

	px=4;
	py=0;//�ʒu��߂�

	//�u���b�N�̓���ւ�
	for(y=0;y<4;y++)
	{
		for(x=0;x<4;x++)
		{
			piece[y][x]=0;
			piece[y][x]=n_piece[y][x];
			n_piece[y][x]=0;
		}
	}

	 switch(rand()%7){
        case 0:
            n_piece[1][1]=1;//
			n_piece[2][1]=1;//�@����
			n_piece[1][2]=1;//�@����
			n_piece[2][2]=1;//
            break;
        case 1:
            n_piece[1][0]=1;//
			n_piece[1][1]=1;//��������
			n_piece[1][2]=1;//
			n_piece[1][3]=1;//
            break;
        case 2:
            n_piece[1][1]=1;//�@�@�@
			n_piece[1][2]=1;//�@������
			n_piece[2][2]=1;//�@�@��
			n_piece[1][3]=1;//
            break;
        case 3:
            n_piece[1][1]=1;//
			n_piece[2][1]=1;//�@������
			n_piece[1][2]=1;//�@��
			n_piece[1][3]=1;//
            break;
        case 4:
            n_piece[1][1]=1;//
			n_piece[2][1]=1;//�@��
			n_piece[2][2]=1;//�@������
			n_piece[2][3]=1;//
            break;
        case 5:
            n_piece[2][1]=1;//
			n_piece[1][2]=1;//�@�@����
			n_piece[2][2]=1;//�@����
			n_piece[1][3]=1;//
            break;
        case 6:
            n_piece[1][1]=1;//
			n_piece[1][2]=1;//�@���� 
			n_piece[2][2]=1;//�@�@����
			n_piece[2][3]=1;//
            break;
    }

	 for(y=0;y<4;y++)
	{
		for(x=0;x<4;x++)
		{
			//�m�肵�����̂ɐV�����u���b�N���d�˂�
			field[y][x+4]=p_field[y][x+4]+piece[y][x];

			if(field[y][x+4]>BLOCK)
			{
				//�u���b�N�������\���ʒu�ɂ���Ƃ�
				judge=1;
				return 1;
			}
		}
	 }
}

//�ŏ��̎��̃u���b�N����
void StartNextPiece()
{
	int i,j;
	//���̃u���b�N�ۑ��z��̏�����
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			n_piece[i][j]=0;
	}
    switch(rand()%7){
        case 0:
            n_piece[1][1]=1;
			n_piece[2][1]=1;
			n_piece[1][2]=1;
			n_piece[2][2]=1;
            break;
        case 1:
            n_piece[1][0]=1;
			n_piece[1][1]=1;
			n_piece[1][2]=1;
			n_piece[1][3]=1;
            break;
        case 2:
            n_piece[1][1]=1;
			n_piece[1][2]=1;
			n_piece[2][2]=1; 
			n_piece[1][3]=1;
            break;
        case 3:
            n_piece[1][1]=1; 
			n_piece[2][1]=1; 
			n_piece[1][2]=1; 
			n_piece[1][3]=1;
            break;
        case 4:
            n_piece[1][1]=1; 
			n_piece[2][1]=1; 
			n_piece[2][2]=1; 
			n_piece[2][3]=1;
            break;
        case 5:
            n_piece[2][1]=1; 
			n_piece[1][2]=1; 
			n_piece[2][2]=1; 
			n_piece[1][3]=1;
            break;
        case 6:
            n_piece[1][1]=1; 
			n_piece[1][2]=1; 
			n_piece[2][2]=1; 
			n_piece[2][3]=1;
            break;
    }
}

//�����ݒ���܂Ƃ߂Ă���
void Start()
{
	int x,y;
	//�Q�[���t�B�[���h�̏�����
	for(y=0;y<SIZEY+1;y++)
	{
		for(x=0;x<SIZEX;x++)
		{
			if(y==SIZEY||x==0||x==SIZEX-1)
				field[y][x]=p_field[y][x]=FRAME;
			else
				field[y][x]=p_field[y][x]=EMPTY;
		}
	}
	StartNextPiece();
	MakePiece();
	Display();
}

//�u���b�N�̈ʒu�̏�������
void MovePiece(int px2,int py2)
{
	int x,y;
	for(y=0;y<4;y++)//�u���b�N������
	{
		for(x=0;x<4;x++)
		{
			field[py+y][px+x]-=piece[y][x];
		}
	}
	//�V�K���W�̏㏑��
	px=px2;
	py=py2;

	for(y=0;y<4;y++)//���������\��
	{
		for(x=0;x<4;x++)
		{
			field[py+y][px+x]+=piece[y][x];
		}
	}
	Display();
}

//�u���b�N�̉�]
void TurnPiece()
{
	int x,y;
	int a[4][4]={0};//��u�����ۑ�����z��

	for(y=0;y<4;y++)//��]�O�̕ۑ�
	{
		for(x=0;x<4;x++)
			a[y][x]=piece[y][x];
	}

	for(y=0;y<4;y++)//�����v����90�x�̉�]
	{
		for(x=0;x<4;x++)
			piece[y][x]=a[3-x][y];
	}

	if(Check(px,px))//�u���b�N�̏d�Ȃ肪��������ۑ����ɖ߂�
	{
		for(y=0;y<4;y++)
		{
			for(x=0;x<4;x++)
				piece[y][x]=a[y][x];
		}
		return 1;
	}

	for(y=0;y<4;y++)//��]�O�������ĉ�]���\��
	{
		for(x=0;x<4;x++)
		{
			field[py+y][px+x]-=a[y][x];
			field[py+y][px+x]+=piece[y][x];
		}
	}

	Display();
	return 0;
}

//�ړ��悪�󂢂Ă��邩�̊m�F
int Check(int px2,int py2)
{
	int x,y;
	for(y=0;y<4;y++)
	{
		for(x=0;x<4;x++)
		{
			if(piece[y][x]==BLOCK)
			{
				if(p_field[py2+y][px2+x]!=EMPTY)//�ړ��悪��łȂ��Ȃ�1��Ԃ��B
					return 1;
			}
		}
	}
	return 0;//��Ȃ�0��Ԃ�
}

//��𔻒�
void CheckLine()
{
	int x, y, i;
	int j;//����񂪂�����Ă����1�A��ł����Ԃ������0�ɂȂ�
	int lines=0;//���������̗�̐�

	while(1)
	{
		for(y=0;y<SIZEY;y++)
		{
			j=1;
			for(x=1;x<SIZEX-1;x++)
			{
				if(p_field[y][x] == EMPTY)
					j=0;
			}
			if(j == 1)
				break;
		}
		if(j == 0)
			break;
		lines++;

		// �������
		for(x=1;x<SIZEX-1;x++)
			p_field[y][x]=0;

		//�����������ɂ������u���b�N�����낷
		for(i=y;i>0;i--)
		{
			for(x=1;x<SIZEX-1;x++)
				p_field[i][x] = p_field[i-1][x];
		}
	}

	//���������̗�̐��̃J�E���g
	switch(lines)
	{
		case 1:
			oneline++;
			break;
		case 2:
			twoline++;
			break;
		case 3:
			threeline++;
			break;
		case 4:
			fourline++;
			break;
		default:
			break;
	}
}

//�Ō��ɉ���������������
void Control()
{
	char key;
	if(kbhit()) // �L�[�����͂���Ă���ΐ^
	{
		key = getch();//�ꕶ�����́A�G�R�[�o�b�N�Ȃ�
		switch( key )
		{
			case '4':
				if(Check(px-1,py)==0)//��
					MovePiece(px-1,py);
				break;
			case '6':
				if(Check(px+1,py)==0)//�E
					MovePiece(px+1,py);
				break;
			case '2':
				if(Check(px,py+1)==0)//��
					MovePiece(px,py+1);
				break;
			case '8'://��]
				TurnPiece();
				break;
		}
	}
}

//�����Ȃ��Ȃ������̏���
void LockPiece()
{
	int x,y;
	//�\���t�B�[���h���Œ�t�B�[���h�ɏ㏑��
	for(y=0;y<SIZEY+1;y++)
	{
		for(x=0;x<SIZEX;x++)
			p_field[y][x]=field[y][x];
	}

	CheckLine();

	//�񔻒��̂��̂�\���t�B�[���h�ɏ㏑��
	for(y=0;y<SIZEY+1;y++)
	{
		for(x=0;x<SIZEX;x++)
			field[y][x]=p_field[y][x];
	}
}

//���R�����̏���
void FallPiece()//�u���b�N�𗎂Ƃ�
{
	if(!Check(px,py+1))
		MovePiece(px,py+1);//���ɓ���
	else
	{
		//�����󂢂ĂȂ���
		LockPiece();
		MakePiece();
		Display();
	}
}

int main()
{
	int time=0,a=0,i;

	//�X�^�[�g��ʕ\��
	printf("\n\n�`�e�g���X�Q�[���`\n\n");
	printf("������@\n4�����A6���E�A2�����A8����]\n\n");
	printf("�Q�[�����n�߂遨0\n�v���O�����̏I����1\n");
	scanf("%d",&a);
	while(a!=1&&a!=0)//�G���[�\��
	{
		printf("1��0����͂��Ă��������I\n");
		scanf("%d",&a);
	}
	if(a==0)
	{
		judge=0;
		system("cls");
	}
	else if(a==1)
		return 0;
	
	while(a==0)//�S�̂̌J��Ԃ�
	{
		Start();
		i=20000;
		while(judge==0)//�Q�[���̌J��Ԃ�
		{
			Control();

			if(time < i)//���R�����B�ǂ�ǂ񑬂��Ȃ�
				time++;
			else
			{
				FallPiece();
				time=0;
				i-=5;
			}
		}

	//�Q�[���I�[�o�[�\��
	system("cls");
	printf("\n\n\n");
	printf( "�� ������������������������ ��������  �������������� ��\n");
	printf( "�� ��  ������������������   ��  ����  ������  ������ ��\n");
	printf( "�� ��������  ����  �������� ������������������������ ��\n\n");
	printf("YOUR SCORE : %d\n\n",oneline*100+twoline*300+threeline*700+fourline*1500);
	printf("�R���e�B�j���[���܂����H\nYES��0\nNO ��1\n");
	scanf("%d",&a);
	while(a!=1&&a!=0)//�G���[�\��
	{
		printf("1��0����͂��Ă��������I\n");
		scanf("%d",&a);
	}
	if(a==0)
	{
		judge=0;
		oneline=0;
		twoline=0;
		threeline=0;
		fourline=0;
	}
	}
	return 0;
}
