#include "game.h"

void Menu(){

	printf("###########################\n");
	printf("####1.Play       2.Exit####\n");
	printf("###########################\n");
	printf("###请输入你的选择:");
}

void DrawBoard(char board[][COL], int row, int col)
{
	printf("    1 | 2 | 3 |\n");
	printf("-----------------\n");
	for (int i = 0; i <row; i++){
		printf("%d |", i + 1);//显示是第几行
		for (int j = 0; j < col; j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n-----------------\n");
	}
}
void PlayMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1){
		printf("请输入你的位置#");
		scanf("%d %d", &x, &y);//如果是往数组里写入，直接arr,不带&，因为此时arr代表首元素地址。
		if (x<1 || x>3 || y<1 || y>3){
			printf("输入位置有误，请重新输入\n");//因为棋盘大小是3*3
			continue;//回到while
		}
		if (board[x - 1][y - 1] != ' ')//选择的位置已经有棋子了
		{
			printf("该位置已经存在棋子！\n");
			continue;//回到while
		}
		board[x - 1][y - 1] = P_COLOR;
		return;//结束
	}
}
char Judge(char board[][COL], int row, int col)//用户赢返回‘X’，电脑赢了返回‘O’，‘N’表示继续往下走，‘P’平局。
{
	for (int i = 0; i < row; i++)//扫描行
	{
		if (board[i][0] == board[i][1] &&\
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')//整行相同且不为0
		{
			return board[i][0];//返回后两个元素也可以
		}
	}
	for (int j = 0; j < col; j++)//扫描列
	{
		if (board[0][j] == board[1][j] && \
			board[1][j] == board[2][j] && \
			board[0][j] != ' ')//整行相同且不为0
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] && \
		board[0][0] != ' ')//正对角线
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[1][1] != ' ')//反对角线
	{
		return board[1][1];
	}
	//代码走到这里说明没有赢，平局或Next.
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 'N';
			}
		}
	}
	return 'P';
}

void ComputerMove(char board[][COL], int row, int col)
{
	//生成随机数0 1 2
	while (1){
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' '){
			board[x][y] = C_COLOR;
			break;
		}
	}
}

void Game(){
	srand((unsigned long)time(NULL));//随机数种子
	char board[ROW][COL];
	//字符数组存放下过的位置，X或O，没下过的初始为*
	//void .* memset(void *ptr,int value,size_t num)
	//对一块内存进行特定内容的设计，参数1指的是内存块的起始地址，最后一个参数是要设计的内存的字节的个数
	//中间的参数表示想把这块内存设计成什么
	memset(board, ' ', sizeof(board));
	char win = '\0';
	do{
		DrawBoard(board,ROW,COL);//首先要绘制棋盘
		PlayMove(board, ROW, COL); //用户走
		win=Judge(board, ROW, COL); //判断
		if (win != 'N'){
			break;
		}
		ComputerMove(board, ROW, COL); //电脑走
		win=Judge(board, ROW, COL); //再判断
		if (win != 'N'){
			break;
		}
	}while (1); 
	switch (win)
	{
	case P_COLOR:
		printf("you win!\n");
		break;
	case C_COLOR:
		printf("you lose!\n");
		break;
	case 'P':
		printf("平局\n");
		break;
	default:
		break;
	}
	DrawBoard(board, ROW, COL);
}