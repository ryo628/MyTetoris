//j1317 角涼太朗 春休み課題"テトリスゲーム"
//
//4→左、6→右、2→下、8→回転、という操作でブロックを積んでいく。
//横一列そろえるとブロックが消える。
//同時に多くの列を消すとスコアが伸びる。
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

int field[SIZEY+1][SIZEX]={0};//描写用の配列
int p_field[SIZEY+1][SIZEX]={0};//固定ブロック用の配列
int piece[4][4]={0},n_piece[4][4]={0};//現在動いているブロックと次のブロック
int px=4,py=0;//ブロック配列の左上の座標
int oneline=0,twoline=0,threeline=0,fourline=0;//消した列のカウント
int judge=1;//ゲーム続行判断

void Display()//画面表示
{
	int x,y,i;
	system("cls");// 画面消去

	//ゲームフィールドの表示
	for(y=0;y<SIZEY+1;y++)
	{
		for(x=0;x<SIZEX;x++)
		{
			switch(field[y][x])
			{
				printf("　");
				break;
			case FRAME:
				printf("□");
				break;
			case BLOCK:
				printf("■");
				break;
			default:
				printf("　");
				break;
			}
		}
		//ゲーム端の表示
		if(y==1)
			printf("　NEXT PIECE");
		if(y==2||y==7||y==9||y==12)
				printf("　□□□□□□");
		if(y==3||y==4||y==5||y==6)
		{
			printf("　□");
			for(i=0;i<4;i++)
			{
				if(n_piece[y-3][i]==BLOCK)
					printf("■");
				else if(n_piece[y-3][i]==EMPTY)
					printf("　");
			}
			printf("□");
		}
		if(y==10)
			printf("　□SCORE");
		if(y==11)
			printf("　□%d",oneline*100+twoline*300+threeline*700+fourline*1500);
		if(y==14||y==19)
			printf("　□□□□□□□");
		if(y==15||y==16||y==17||y==18)
		{
			printf("　□%d列消し:",y-14);
			switch(y-14)
			{
				case 1:
					if(oneline<10)
						printf(" %d□",oneline);
					else
						printf("%d□",oneline);
					break;
				case 2:
					if(twoline<10)
						printf(" %d□",twoline);
					else
						printf("%d□",twoline);
					break;
				case 3:
					if(threeline<10)
						printf(" %d□",threeline);
					else
						printf("%d□",threeline);
					break;
				case 4:
					if(fourline<10)
						printf(" %d□",fourline);
					else
						printf("%d□",fourline);
					break;
			}
		}
		printf("\n");
	}
}

//ブロックの作成
void MakePiece()
{
	int x,y;

	px=4;
	py=0;//位置を戻す

	//ブロックの入れ替え
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
			n_piece[2][1]=1;//　■■
			n_piece[1][2]=1;//　■■
			n_piece[2][2]=1;//
            break;
        case 1:
            n_piece[1][0]=1;//
			n_piece[1][1]=1;//■■■■
			n_piece[1][2]=1;//
			n_piece[1][3]=1;//
            break;
        case 2:
            n_piece[1][1]=1;//　　　
			n_piece[1][2]=1;//　■■■
			n_piece[2][2]=1;//　　■
			n_piece[1][3]=1;//
            break;
        case 3:
            n_piece[1][1]=1;//
			n_piece[2][1]=1;//　■■■
			n_piece[1][2]=1;//　■
			n_piece[1][3]=1;//
            break;
        case 4:
            n_piece[1][1]=1;//
			n_piece[2][1]=1;//　■
			n_piece[2][2]=1;//　■■■
			n_piece[2][3]=1;//
            break;
        case 5:
            n_piece[2][1]=1;//
			n_piece[1][2]=1;//　　■■
			n_piece[2][2]=1;//　■■
			n_piece[1][3]=1;//
            break;
        case 6:
            n_piece[1][1]=1;//
			n_piece[1][2]=1;//　■■ 
			n_piece[2][2]=1;//　　■■
			n_piece[2][3]=1;//
            break;
    }

	 for(y=0;y<4;y++)
	{
		for(x=0;x<4;x++)
		{
			//確定したものに新しいブロックを重ねる
			field[y][x+4]=p_field[y][x+4]+piece[y][x];

			if(field[y][x+4]>BLOCK)
			{
				//ブロックが初期表示位置にあるとき
				judge=1;
				return 1;
			}
		}
	 }
}

//最初の次のブロック製作
void StartNextPiece()
{
	int i,j;
	//次のブロック保存配列の初期化
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

//初期設定をまとめている
void Start()
{
	int x,y;
	//ゲームフィールドの初期化
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

//ブロックの位置の書き換え
void MovePiece(int px2,int py2)
{
	int x,y;
	for(y=0;y<4;y++)//ブロックを消す
	{
		for(x=0;x<4;x++)
		{
			field[py+y][px+x]-=piece[y][x];
		}
	}
	//新規座標の上書き
	px=px2;
	py=py2;

	for(y=0;y<4;y++)//動いた先を表示
	{
		for(x=0;x<4;x++)
		{
			field[py+y][px+x]+=piece[y][x];
		}
	}
	Display();
}

//ブロックの回転
void TurnPiece()
{
	int x,y;
	int a[4][4]={0};//一瞬だけ保存する配列

	for(y=0;y<4;y++)//回転前の保存
	{
		for(x=0;x<4;x++)
			a[y][x]=piece[y][x];
	}

	for(y=0;y<4;y++)//反時計回りに90度の回転
	{
		for(x=0;x<4;x++)
			piece[y][x]=a[3-x][y];
	}

	if(Check(px,px))//ブロックの重なりがあったら保存時に戻す
	{
		for(y=0;y<4;y++)
		{
			for(x=0;x<4;x++)
				piece[y][x]=a[y][x];
		}
		return 1;
	}

	for(y=0;y<4;y++)//回転前を消して回転後を表示
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

//移動先が空いているかの確認
int Check(int px2,int py2)
{
	int x,y;
	for(y=0;y<4;y++)
	{
		for(x=0;x<4;x++)
		{
			if(piece[y][x]==BLOCK)
			{
				if(p_field[py2+y][px2+x]!=EMPTY)//移動先が空でないなら1を返す。
					return 1;
			}
		}
	}
	return 0;//空なら0を返す
}

//列を判定
void CheckLine()
{
	int x, y, i;
	int j;//横一列がそろっていれば1、一つでも隙間があると0になる
	int lines=0;//同時消しの列の数

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

		// 列を消去
		for(x=1;x<SIZEX-1;x++)
			p_field[y][x]=0;

		//消えた列より上にあったブロックを下ろす
		for(i=y;i>0;i--)
		{
			for(x=1;x<SIZEX-1;x++)
				p_field[i][x] = p_field[i-1][x];
		}
	}

	//同時消しの列の数のカウント
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

//打鍵に応じた動きを処理
void Control()
{
	char key;
	if(kbhit()) // キーが入力されていれば真
	{
		key = getch();//一文字入力、エコーバックなし
		switch( key )
		{
			case '4':
				if(Check(px-1,py)==0)//左
					MovePiece(px-1,py);
				break;
			case '6':
				if(Check(px+1,py)==0)//右
					MovePiece(px+1,py);
				break;
			case '2':
				if(Check(px,py+1)==0)//下
					MovePiece(px,py+1);
				break;
			case '8'://回転
				TurnPiece();
				break;
		}
	}
}

//動けなくなった時の処理
void LockPiece()
{
	int x,y;
	//表示フィールドを固定フィールドに上書き
	for(y=0;y<SIZEY+1;y++)
	{
		for(x=0;x<SIZEX;x++)
			p_field[y][x]=field[y][x];
	}

	CheckLine();

	//列判定後のものを表示フィールドに上書き
	for(y=0;y<SIZEY+1;y++)
	{
		for(x=0;x<SIZEX;x++)
			field[y][x]=p_field[y][x];
	}
}

//自然落下の処理
void FallPiece()//ブロックを落とす
{
	if(!Check(px,py+1))
		MovePiece(px,py+1);//下に動く
	else
	{
		//下が空いてない時
		LockPiece();
		MakePiece();
		Display();
	}
}

int main()
{
	int time=0,a=0,i;

	//スタート画面表示
	printf("\n\n～テトリスゲーム～\n\n");
	printf("操作方法\n4→左、6→右、2→下、8→回転\n\n");
	printf("ゲームを始める→0\nプログラムの終了→1\n");
	scanf("%d",&a);
	while(a!=1&&a!=0)//エラー表示
	{
		printf("1か0を入力してください！\n");
		scanf("%d",&a);
	}
	if(a==0)
	{
		judge=0;
		system("cls");
	}
	else if(a==1)
		return 0;
	
	while(a==0)//全体の繰り返し
	{
		Start();
		i=20000;
		while(judge==0)//ゲームの繰り返し
		{
			Control();

			if(time < i)//自然落下。どんどん速くなる
				time++;
			else
			{
				FallPiece();
				time=0;
				i-=5;
			}
		}

	//ゲームオーバー表示
	system("cls");
	printf("\n\n\n");
	printf( "┏ ┏━┓┏━┓┏┳┓┳━┓ ┏━┓┳  ┳┳━┓┳━┓ ┓\n");
	printf( "┃ ┃  ┓┣━┫┃┃┃┣┫   ┃  ┃┃  ┃┣┫  ┣┳┛ ┃\n");
	printf( "┗ ┗━┛┻  ┻┻  ┻┻━┛ ┗━┛┗━┛┻━┛┻┗┛ ┛\n\n");
	printf("YOUR SCORE : %d\n\n",oneline*100+twoline*300+threeline*700+fourline*1500);
	printf("コンティニューしますか？\nYES→0\nNO →1\n");
	scanf("%d",&a);
	while(a!=1&&a!=0)//エラー表示
	{
		printf("1か0を入力してください！\n");
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
