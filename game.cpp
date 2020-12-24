#include "game.h"

void Menu(){

	printf("###########################\n");
	printf("####1.Play       2.Exit####\n");
	printf("###########################\n");
	printf("###���������ѡ��:");
}

void DrawBoard(char board[][COL], int row, int col)
{
	printf("    1 | 2 | 3 |\n");
	printf("-----------------\n");
	for (int i = 0; i <row; i++){
		printf("%d |", i + 1);//��ʾ�ǵڼ���
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
		printf("���������λ��#");
		scanf("%d %d", &x, &y);//�������������д�룬ֱ��arr,����&����Ϊ��ʱarr������Ԫ�ص�ַ��
		if (x<1 || x>3 || y<1 || y>3){
			printf("����λ����������������\n");//��Ϊ���̴�С��3*3
			continue;//�ص�while
		}
		if (board[x - 1][y - 1] != ' ')//ѡ���λ���Ѿ���������
		{
			printf("��λ���Ѿ��������ӣ�\n");
			continue;//�ص�while
		}
		board[x - 1][y - 1] = P_COLOR;
		return;//����
	}
}
char Judge(char board[][COL], int row, int col)//�û�Ӯ���ء�X��������Ӯ�˷��ء�O������N����ʾ���������ߣ���P��ƽ�֡�
{
	for (int i = 0; i < row; i++)//ɨ����
	{
		if (board[i][0] == board[i][1] &&\
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')//������ͬ�Ҳ�Ϊ0
		{
			return board[i][0];//���غ�����Ԫ��Ҳ����
		}
	}
	for (int j = 0; j < col; j++)//ɨ����
	{
		if (board[0][j] == board[1][j] && \
			board[1][j] == board[2][j] && \
			board[0][j] != ' ')//������ͬ�Ҳ�Ϊ0
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] && \
		board[0][0] != ' ')//���Խ���
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[1][1] != ' ')//���Խ���
	{
		return board[1][1];
	}
	//�����ߵ�����˵��û��Ӯ��ƽ�ֻ�Next.
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
	//���������0 1 2
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
	srand((unsigned long)time(NULL));//���������
	char board[ROW][COL];
	//�ַ��������¹���λ�ã�X��O��û�¹��ĳ�ʼΪ*
	//void .* memset(void *ptr,int value,size_t num)
	//��һ���ڴ�����ض����ݵ���ƣ�����1ָ�����ڴ�����ʼ��ַ�����һ��������Ҫ��Ƶ��ڴ���ֽڵĸ���
	//�м�Ĳ�����ʾ�������ڴ���Ƴ�ʲô
	memset(board, ' ', sizeof(board));
	char win = '\0';
	do{
		DrawBoard(board,ROW,COL);//����Ҫ��������
		PlayMove(board, ROW, COL); //�û���
		win=Judge(board, ROW, COL); //�ж�
		if (win != 'N'){
			break;
		}
		ComputerMove(board, ROW, COL); //������
		win=Judge(board, ROW, COL); //���ж�
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
		printf("ƽ��\n");
		break;
	default:
		break;
	}
	DrawBoard(board, ROW, COL);
}