#include <stdio.h>
#include <stdlib.h>

char matrix[5][5];
																		
void init_matrix(int);																//initializing the matrix
void player_move();																	//player's move
void computer_move_3X3();
void computer_move_4X4();
void computer_move_5X5();															//computer's move															
void disp_matrix_3X3();
void disp_matrix_4X4();	
void disp_matrix_5X5();																//displaying the current matrix															
char check_3X3();
char check_4X4();
char check_5X5();																	//checking if there is a winner																

//main function

int main()
{
	int input, first_move;
	char done=' ';

	printf("\n \n");

	printf("\t This is a game of Tic Tac Toe\n\n");

	printf("\t For 3X3 type 3, for 4X4 type 4 and for 5X5 type 5 : ");

	scanf("%d",&input);

	printf("\n \n");

	printf("\t if you want to make the 1st move, type 1 ...for computer type 2 : ");

	scanf("%d", &first_move);

	printf("\n \n");

	init_matrix(input);																	//initializing the matrix
	
	if(input==3){

		if (first_move == 2) {

			computer_move_3X3();
			disp_matrix_3X3 ();
		}

		do{
			player_move();																//player's move
			disp_matrix_3X3();															//displaying the current matrix
			done=check_3X3();															//checking the matrix

			if(done!=' ')
				break;																	//if the return is other than ' ',we break here
		
			printf("\t Computer's move\n\n\n");
			computer_move_3X3();
			disp_matrix_3X3();															//displaying the matrix
			done=check_3X3();															//checking the matrix

		}while(done==' ');
	}
	else if(input==4){
		do{
			player_move();																//player's move
			disp_matrix_4X4();															//displaying the current matrix
			done=check_4X4();															//checking the matrix

			if(done!=' ')
				break;																	//if the return is other than ' ',we break here
		
			printf("\t Computer's move\n\n\n");
			computer_move_4X4();
			disp_matrix_4X4();															//displaying the matrix
			done=check_4X4();															//checking the matrix

		}while(done==' ');
	}
	else if(input==5){
		do{
			player_move();																//player's move
			disp_matrix_5X5();															//displaying the current matrix
			done=check_5X5();															//checking the matrix

			if(done!=' ')
				break;																	//if the return is other than ' ',we break here
		
			printf("\t Computer's move\n\n\n");
			computer_move_5X5();
			disp_matrix_5X5();															//displaying the matrix
			done=check_5X5();															//checking the matrix

		}while(done==' ');
	}

	if(done=='X')																	//if the return is 'X',user won
		printf("You won\n");														
	else if(done=='O')																//if the return is 'O',computer won
		printf("Computer won\n");													
	else if(done=='D')																//if the return is 'D',match drawn
		printf("Match Drawn\n");

	return 0;
}

//initializing the matrix

void init_matrix(int n)																	
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			matrix[i][j]=' ';														//initially all indices are made empty

}

//player's move

void player_move()
{
	int x,y;

	printf("\t Enter x and y co-ordinates of your move: ");
	scanf("%d %d",&x,&y);															//user to input the x & y co-ordinate of his move

	if(matrix[--x][--y]!=' '){														//if his input index is not empty,invalid move is shown
		printf("Invalid move,try again\n\n");
		player_move();
	}
	else
		matrix[x][y]='X';															//otherwise,we put a 'X' in that index
	printf("\n\n\n");
}

//computer's move

void computer_move_3X3()
{
	int i,j;

    //row checking

	//if 1st & 2nd elements are 'O' or 'X',we make 3rd 'O'

	for(i=0;i<3;i++){

		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][0]=='X'&& matrix[i][1]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	//if 1st & 3rd elements are 'O' or 'X',we make 2nd 'O'

	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][2]=='O')||(matrix[i][0]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'O'or'X',we make 1st 'O'

	for(i=0;i<3;i++){
		if((matrix[i][1]=='O'&& matrix[i][2]=='O')||(matrix[i][1]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

	//column checking

	//if 1st & 2nd elements are 'O'or'X',we make 3rd 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[0][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	//if 1st & 3rd elements are 'O'or'X',we make 2nd 'O'

	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[2][i]=='O')||(matrix[0][i]=='X'&& matrix[2][i]=='X')){								
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'O'or'X',we make 1st 'O'

	for(i=0;i<3;i++){
		if((matrix[2][i]=='O'&& matrix[1][i]=='O')||(matrix[2][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	//diagonal checking

	//if (1,1) & (2,2) is 'O'or'X',we make (3,3)th index 'O'

	if((matrix[0][0]=='O'&&matrix[1][1]=='O')||(matrix[0][0]=='X'&&matrix[1][1]=='X')){										
		if(matrix[2][2]==' '){
				matrix[2][2]='O';
				return;
			}
	}
	//if (1,1) & (3,3) is 'O'or'X',we make (2,2)th index 'O'

	if((matrix[0][0]=='O'&&matrix[2][2]=='O')||(matrix[0][0]=='X'&&matrix[2][2]=='X')){
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}
	//if (3,3) & (2,2) is 'O'or 'X',we make (1,1)th index 'O'

	if((matrix[1][1]=='O'&&matrix[2][2]=='O')||(matrix[1][1]=='X'&&matrix[2][2]=='X')){										
		if(matrix[0][0]==' '){
				matrix[0][0]='O';
				return;
			}
	}
	//if (1,3) & (2,2) is 'O'or'X',we make (3,1)th index 'O'

	if((matrix[0][2]=='O'&&matrix[1][1]=='O')||(matrix[0][2]=='X'&&matrix[1][1]=='X')){					
		if(matrix[2][0]==' '){
				matrix[2][0]='O';
				return;
			}
	}
	//if (1,3) & (3,1) is 'O'or'X',we make (2,2)th index 'O'

	if((matrix[0][2]=='O'&&matrix[2][0]=='O')||(matrix[0][2]=='X'&&matrix[2][0]=='X')){										
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}
	//if (3,1) & (2,2) is 'O'or'X',we make (1,3)th index 'O'

	if((matrix[1][1]=='O'&&matrix[2][0]=='O')||(matrix[1][1]=='X'&&matrix[2][0]=='X')){										
		if(matrix[0][2]==' '){
				matrix[0][2]='O';
				return;
			}
	}

	//blocking tactis(1st move)

	if(matrix[1][1]==' '){
		matrix[1][1]='O';															
		return;
	}

	if (matrix [1][1] == 'O') {

		if (matrix [0][0] == 'X') {

			if (matrix [2][2] == ' ') {
				matrix [2][2] = 'O';
				return;
			}
		}

		if (matrix [0][2] == 'X') {

			if (matrix [2][0] == ' ') {
				matrix [2][0] = 'O';
				return;
			}
		}

		if (matrix [2][0] == 'X') {

			if (matrix [0][2] == ' ') {
				matrix [0][2] = 'O';
				return;
			}	
		}

		if (matrix [2][2] == 'X') {

			if (matrix [0][0] == ' '){
				matrix [0][0] = 'O';
				return;
			}	
		}
	}

	if(matrix[1][1]=='X'){
		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}

	//blocking tactis(2nd move)

	if((matrix[0][0]=='X'&&matrix[2][2]=='X') || (matrix[0][2]=='X'&&matrix[2][0]=='X')){
		if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}

	if(matrix[1][1]=='X'&&matrix[2][2]=='X'){
		if(matrix[0][2]==' '){
			matrix[0][2]='O';
			return;
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)

			if (matrix [i][j] == ' ') {

				matrix [i][j] = 'O';
				return;
			}
		
}

//displaying the current matrix

void disp_matrix_3X3()
{ 
	int i;

	for(i=0;i<3;i++){
		printf("             |     |      \n");
		printf("          %c  |  %c  |  %c  \n",matrix[i][0],matrix[i][1],matrix[i][2]);
		if(i!=2)
			printf("        ----- ----- -----\n");
	}
	printf("\n\n");
}

//checking if there is a winner

char check_3X3()
{
	int i,j;

	//row checking

	for(i=0;i<3;i++)
		if(matrix[i][0]==matrix[i][1]&&matrix[i][0]==matrix[i][2])							//checking if the elements of rows are identical
			return matrix[i][0];

	//column checking

	for(i=0;i<3;i++)
		if(matrix[0][i]==matrix[1][i]&&matrix[0][i]==matrix[2][i])							//checking if the elements of columns are identical
			return matrix[0][i];

	//diagonal checking

	if(matrix[0][0]==matrix[1][1]&&matrix[0][0]==matrix[2][2])								//checking if (1,1),(2,2) & (3,3) are identical
		return matrix[0][0];

	if(matrix[0][2]==matrix[1][1]&&matrix[0][2]==matrix[2][0])								//checking if (1,3),(2,2) & (3,1) are identical
			return matrix[0][2];

	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j]==' ')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}

	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'

	return 'D';
}

//computer's move

void computer_move_4X4()
{
	int i,j;

	//row checking

	//if 1st,2nd & 4th elements are 'O' or 'X',we make 3rd 'O'


	for(i=0;i<4;i++){

		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][1]=='O'&& matrix[i][3]=='O')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[i][0]=='X'&& matrix[i][1]=='X')||(matrix[i][1]=='X'&& matrix[i][3]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	//if 1st,3rd & 4th elements are 'O' or 'X',we make 2nd 'O'


	for(i=0;i<4;i++){

		if((matrix[i][0]=='O'&& matrix[i][2]=='O')||(matrix[i][2]=='O'&& matrix[i][3]=='O')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[i][0]=='X'&& matrix[i][2]=='X')||(matrix[i][2]=='X'&& matrix[i][3]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}

	//if 2nd,3rd & 4th elements are 'O' or 'X',we make 1st 'O'


	for(i=0;i<4;i++){

		if((matrix[i][1]=='O'&& matrix[i][2]=='O')||(matrix[i][2]=='O'&& matrix[i][3]=='O')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[i][1]=='X'&& matrix[i][2]=='X')||(matrix[i][2]=='X'&& matrix[i][3]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}

	//if 1st,2nd & 3rd elements are 'O' or 'X',we make 4th 'O'


	for(i=0;i<4;i++){

		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][1]=='O'&& matrix[i][2]=='O')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[i][0]=='X'&& matrix[i][1]=='X')||(matrix[i][1]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}

    //row checking

	//if 1st & 2nd elements are 'X',we make 3rd 'O'

	for(i=0;i<4;i++){

		if(matrix[i][0]=='X'&& matrix[i][1]=='X'){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	//if 3rd & 4th elements are 'X',we make 2nd 'O'

	for(i=0;i<4;i++){

		if(matrix[i][2]=='X'&& matrix[i][3]=='X'){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'X',we make either 1st or 4th 'O'

	for(i=0;i<4;i++){

		if(matrix[i][1]=='X'&& matrix[i][2]=='X'){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}

	//column checking

	//if 1st, 2nd & 4th elements are 'O'or'X',we make 3rd 'O'

	for(i=0;i<4;i++){

		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[1][i]=='O'&& matrix[3][i]=='O')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[0][i]=='X'&& matrix[1][i]=='X')||(matrix[1][i]=='X'&& matrix[3][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}

	//if 1st, 2nd & 3rd elements are 'O'or'X',we make 4th 'O'

	for(i=0;i<4;i++){

		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[1][i]=='O'&& matrix[2][i]=='O')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[0][i]=='X'&& matrix[1][i]=='X')||(matrix[1][i]=='X'&& matrix[2][i]=='X')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	//if 1st, 3rd & 4th elements are 'O'or'X',we make 2nd 'O'

	for(i=0;i<4;i++){

		if((matrix[0][i]=='O'&& matrix[2][i]=='O')||(matrix[2][i]=='O'&& matrix[3][i]=='O')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[0][i]=='X'&& matrix[2][i]=='X')||(matrix[2][i]=='X'&& matrix[3][i]=='X')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

	//if 2nd, 3rd & 4th elements are 'O'or'X',we make 1st 'O'

	for(i=0;i<4;i++){

		if((matrix[1][i]=='O'&& matrix[2][i]=='O')||(matrix[2][i]=='O'&& matrix[3][i]=='O')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	for(i=0;i<4;i++){

		if((matrix[1][i]=='X'&& matrix[2][i]=='X')||(matrix[2][i]=='X'&& matrix[3][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	//column checking

	//if 1st & 2nd elements are 'X',we make 3rd 'O'
	for(i=0;i<4;i++){
		if(matrix[0][i]=='X'&& matrix[1][i]=='X'){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	//if 3rd & 4th elements are 'X',we make 2nd 'O'

	for(i=0;i<4;i++){
		if(matrix[2][i]=='X'&& matrix[3][i]=='X'){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'X',we make either 1st or 4th 'O'

	for(i=0;i<4;i++){

		if(matrix[1][i]=='X'&& matrix[2][i]=='X'){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	//diagonal checking

	//if (1,1) & (2,2) is 'X',we make (3,3)th index 'O'

	if(matrix[0][0]=='X'&& matrix[1][1]=='X'){

		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}

	//if (3,3) & (4,4) is 'X',we make (2,2)th index 'O'

	if(matrix[2][2]=='X'&& matrix[3][3]=='X'){

		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
	}

	//if (2,2) & (3,3) is 'X',we make either (1,1) or (4,4)th index 'O'

	if(matrix[1][1]=='X'&& matrix[2][2]=='X'){

		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}

	}

	//if (1,4) & (2,3) is 'X',we make (3,2)th index 'O'

	if(matrix[0][3]=='X'&& matrix[1][2]=='X'){

		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
	}

	//if (3,2) & (4,1) is 'X',we make (2,3)th index 'O'

	if(matrix[2][1]=='X'&& matrix[3][0]=='X'){

		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
	}

	//if (2,3) & (3,2) is 'X',we make either (1,4) or (4,1)th index 'O'

	if(matrix[1][2]=='X'&& matrix[2][1]=='X'){

		if(matrix[0][3]==' '){
			matrix[0][3]='O';
			return;
		}
		else if(matrix[3][0]==' '){
			matrix[3][0]='O';
			return;
		}

	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(matrix[i][j]=='X'){

				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}

			}
		}
	}

}

//displaying the current matrix

void disp_matrix_4X4()
{ 
	int i;

	for(i=0;i<4;i++){
		printf("             |     |     |      \n");
		printf("          %c  |  %c  |  %c  |  %c   \n",matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3]);
		if(i!=3)
			printf("        ----- ----- ----- ----- \n");
	}
	printf("\n\n");
}


//checking if there is a winner

char check_4X4()
{
	int i,j;

	//row checking
	
	//checking if the elements of rows are identical

	for(i=0;i<4;i++)
		if((matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2])&&(matrix[i][2]==matrix[i][3]))							
			return matrix[i][0];

	//column checking

	//checking if the elements of columns are identical

	for(i=0;i<4;i++)
		if((matrix[0][i]==matrix[1][i]&&matrix[1][i]==matrix[2][i])&&(matrix[2][i]==matrix[3][i]))							
			return matrix[0][i];

	//diagonal checking

	//checking if (1,1),(2,2),(3,3) & (4,4) are identical

	if((matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2])&&(matrix[2][2]==matrix[3][3]))								
		return matrix[0][0];

	//checking if (1,3),(2,2) & (3,2) & (4,1) are identical

	if((matrix[0][3]==matrix[1][2]&&matrix[1][2]==matrix[2][1])&&(matrix[2][1]==matrix[3][0]))								
			return matrix[0][3];

	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(matrix[i][j]==' ')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}

	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'

	return 'D';
}

//computer's move

void computer_move_5X5()
{
	int i,j;
	//row checking

	//if 1st,2nd & 4th elements are 'O' or 'X',we make 3rd or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[i][0]=='X'&& matrix[i][1]=='X')||(matrix[i][1]=='X'&& matrix[i][3]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][1]=='O'&& matrix[i][3]=='O')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	//if 1st,2nd & 5th elements are 'O' or 'X',we make 3rd or 4th 'O'

	for(i=0;i<5;i++){

		if((matrix[i][0]=='X'&& matrix[i][1]=='X')||(matrix[i][1]=='X'&& matrix[i][4]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][1]=='O'&& matrix[i][4]=='O')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	//if 1st,2nd & 3rd elements are 'O' or 'X',we make 4th or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[i][0]=='X'&& matrix[i][1]=='X')||(matrix[i][1]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][1]=='O'&& matrix[i][2]=='O')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	//if 1st,3rd & 4th elements are 'O' or 'X',we make 2nd or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[i][0]=='X'&& matrix[i][2]=='X')||(matrix[i][2]=='X'&& matrix[i][3]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][0]=='O'&& matrix[i][2]=='O')||(matrix[i][2]=='O'&& matrix[i][3]=='O')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	//if 1st,3rd & 5th elements are 'O' or 'X',we make 2nd or 4th 'O'

	for(i=0;i<5;i++){

		if((matrix[i][0]=='X'&& matrix[i][2]=='X')||(matrix[i][2]=='X'&& matrix[i][4]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][0]=='O'&& matrix[i][2]=='O')||(matrix[i][2]=='O'&& matrix[i][4]=='O')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}

	//if 1st,4th & 5th elements are 'O' or 'X',we make 2nd or 3rd 'O'

	for(i=0;i<5;i++){

		if((matrix[i][0]=='X'&& matrix[i][3]=='X')||(matrix[i][3]=='X'&& matrix[i][4]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][0]=='O'&& matrix[i][3]=='O')||(matrix[i][3]=='O'&& matrix[i][4]=='O')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
	//if 2nd,3rd & 4th elements are 'O' or 'X',we make 1st or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[i][1]=='X'&& matrix[i][2]=='X')||(matrix[i][2]=='X'&& matrix[i][3]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][1]=='O'&& matrix[i][2]=='O')||(matrix[i][2]=='O'&& matrix[i][3]=='O')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}


	//if 2nd,3rd & 5th elements are 'O' or 'X',we make 1st or 4th 'O'

	for(i=0;i<5;i++){

		if((matrix[i][1]=='X'&& matrix[i][2]=='X')||(matrix[i][2]=='X'&& matrix[i][4]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][1]=='O'&& matrix[i][2]=='O')||(matrix[i][2]=='O'&& matrix[i][4]=='O')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}


	//if 2nd,4th & 5th elements are 'O' or 'X',we make 1st or 3rd 'O'

	for(i=0;i<5;i++){

		if((matrix[i][1]=='X'&& matrix[i][3]=='X')||(matrix[i][3]=='X'&& matrix[i][4]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][1]=='O'&& matrix[i][3]=='O')||(matrix[i][3]=='O'&& matrix[i][4]=='O')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	

	//if 3rd,4th & 5th elements are 'O' or 'X',we make 1st or 2nd 'O'

	for(i=0;i<5;i++){

		if((matrix[i][2]=='X'&& matrix[i][3]=='X')||(matrix[i][3]=='X'&& matrix[i][4]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[i][2]=='O'&& matrix[i][3]=='O')||(matrix[i][3]=='O'&& matrix[i][4]=='O')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}

	//row checking

	//if 1st & 2nd elements are 'X',we make 3rd 'O'

	for(i=0;i<5;i++){

		if(matrix[i][0]=='X'&& matrix[i][1]=='X'){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	//if 3rd & 4th elements are 'X',we make either 2nd or 5th 'O'

	for(i=0;i<5;i++){

		if(matrix[i][2]=='X'&& matrix[i][3]=='X'){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'X',we make either 1st or 4th 'O'

	for(i=0;i<5;i++){

		if(matrix[i][1]=='X'&& matrix[i][2]=='X'){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	//if 4th & 5th elements are 'X',we make 3rd 'O'

	for(i=0;i<5;i++){

		if(matrix[i][3]=='X'&& matrix[i][4]=='X'){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	//if 1st & 3rd elements are 'X',we make 2nd 'O'

	for(i=0;i<5;i++){

		if(matrix[i][0]=='X'&& matrix[i][2]=='X'){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	//if 4th & 2nd elements are 'X',we make 3rd 'O'

	for(i=0;i<5;i++){

		if(matrix[i][3]=='X'&& matrix[i][1]=='X'){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	//if 5th & 3rd elements are 'X',we make 4th 'O'

	for(i=0;i<5;i++){

		if(matrix[i][4]=='X'&& matrix[i][2]=='X'){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}

	//column checking

	//if 1st,2nd & 4th elements are 'O' or 'X',we make 3rd or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[0][i]=='X'&& matrix[1][i]=='X')||(matrix[1][i]=='X'&& matrix[3][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[1][i]=='O'&& matrix[3][i]=='O')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	//if 1st,2nd & 5th elements are 'O' or 'X',we make 3rd or 4th 'O'

	for(i=0;i<5;i++){

		if((matrix[0][i]=='X'&& matrix[1][i]=='X')||(matrix[1][i]=='X'&& matrix[4][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[1][i]=='O'&& matrix[4][i]=='O')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	//if 1st,2nd & 3rd elements are 'O' or 'X',we make 4th or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[0][i]=='X'&& matrix[1][i]=='X')||(matrix[1][i]=='X'&& matrix[2][i]=='X')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[1][i]=='O'&& matrix[2][i]=='O')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	//if 1st,3rd & 4th elements are 'O' or 'X',we make 2nd or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[0][i]=='X'&& matrix[2][i]=='X')||(matrix[2][i]=='X'&& matrix[3][i]=='X')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[0][i]=='O'&& matrix[2][i]=='O')||(matrix[2][i]=='O'&& matrix[3][i]=='O')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	//if 1st,3rd & 5th elements are 'O' or 'X',we make 2nd or 4th 'O'

	for(i=0;i<5;i++){

		if((matrix[0][i]=='X'&& matrix[2][i]=='X')||(matrix[2][i]=='X'&& matrix[4][i]=='X')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[0][i]=='O'&& matrix[2][i]=='O')||(matrix[2][i]=='O'&& matrix[4][i]=='O')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	//if 1st,4th & 5th elements are 'O' or 'X',we make 2nd or 3rd 'O'

	for(i=0;i<5;i++){

		if((matrix[0][i]=='X'&& matrix[3][i]=='X')||(matrix[3][i]=='X'&& matrix[4][i]=='X')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[0][i]=='O'&& matrix[3][i]=='O')||(matrix[3][i]=='O'&& matrix[4][i]=='O')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}

	//if 2nd,3rd & 4th elements are 'O' or 'X',we make 1st or 5th 'O'

	for(i=0;i<5;i++){

		if((matrix[1][i]=='X'&& matrix[2][i]=='X')||(matrix[2][i]=='X'&& matrix[3][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[1][i]=='O'&& matrix[2][i]=='O')||(matrix[2][i]=='O'&& matrix[3][i]=='O')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}

	//if 2nd,3rd & 5th elements are 'O' or 'X',we make 1st or 4th 'O'

	for(i=0;i<5;i++){

		if((matrix[1][i]=='X'&& matrix[2][i]=='X')||(matrix[2][i]=='X'&& matrix[4][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[1][i]=='O'&& matrix[2][i]=='O')||(matrix[2][i]=='O'&& matrix[4][i]=='O')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	//if 2nd,4th & 5th elements are 'O' or 'X',we make 1st or 3rd 'O'

	for(i=0;i<5;i++){

		if((matrix[1][i]=='X'&& matrix[3][i]=='X')||(matrix[3][i]=='X'&& matrix[4][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[1][i]=='O'&& matrix[3][i]=='O')||(matrix[3][i]=='O'&& matrix[4][i]=='O')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}

	//if 3rd,4th & 5th elements are 'O' or 'X',we make 1st or 2nd 'O'

	for(i=0;i<5;i++){

		if((matrix[2][i]=='X'&& matrix[3][i]=='X')||(matrix[3][i]=='X'&& matrix[4][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

	for(i=0;i<5;i++){

		if((matrix[2][i]=='O'&& matrix[3][i]=='O')||(matrix[3][i]=='O'&& matrix[4][i]=='O')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

	//column checking

	//if 1st & 2nd elements are 'X',we make 3rd 'O'

	for(i=0;i<5;i++){
		if(matrix[0][i]=='X'&& matrix[1][i]=='X'){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	//if 3rd & 4th elements are 'X',we make 2nd or 5th 'O'

	for(i=0;i<5;i++){
		if(matrix[2][i]=='X'&& matrix[3][i]=='X'){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'X',we make either 1st or 4th 'O'

	for(i=0;i<5;i++){

		if(matrix[1][i]=='X'&& matrix[2][i]=='X'){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	//if 4th & 5th elements are 'X',we make 3rd 'O'
	
	for(i=0;i<5;i++){
		if(matrix[3][i]=='X'&& matrix[4][i]=='X'){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	//if 1st & 3rd elements are 'X',we make 2nd 'O'

	for(i=0;i<5;i++){
		if(matrix[0][i]=='X'&& matrix[2][i]=='X'){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

	//if 4th & 2nd elements are 'X',we make 3rd 'O'
	
	for(i=0;i<5;i++){
		if(matrix[3][i]=='X'&& matrix[1][i]=='X'){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}

	//if 3rd & 5th elements are 'X',we make 4th 'O'
	
	for(i=0;i<5;i++){
		if(matrix[2][i]=='X'&& matrix[4][i]=='X'){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	//diagonal checking

	//if (1,1) & (2,2) is 'X',we make (3,3)th index 'O'

	if(matrix[0][0]=='X'&& matrix[1][1]=='X'){

		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}
	//if (1,1) & (3,3) is 'X',we make (2,2)th index 'O'

	if(matrix[0][0]=='X'&& matrix[2][2]=='X'){

		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
	}
	//if (4,4) & (2,2) is 'X',we make (3,3)th index 'O'

	if(matrix[3][3]=='X'&& matrix[1][1]=='X'){

		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}
	//if (3,3) & (5,5) is 'X',we make (4,4)th index 'O'

	if(matrix[2][2]=='X'&& matrix[4][4]=='X'){

		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}

	//if (2,2) & (3,3) is 'X',we make either (1,1)th or (4,4)th index 'O'

	if(matrix[1][1]=='X'&& matrix[2][2]=='X'){

		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}

	//if (3,3) & (4,4) is 'X',we make either (2,2)th or (5,5)th index 'O'

	if(matrix[2][2]=='X'&& matrix[3][3]=='X'){

		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}

	}

	//if (1,5) & (2,4) is 'X',we make (3,3)th index 'O'

	if(matrix[0][4]=='X'&& matrix[1][3]=='X'){

		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}
	//if (1,5) & (3,3) is 'X',we make (2,4)th index 'O'

	if(matrix[0][4]=='X'&& matrix[2][2]=='X'){

		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	//if (4,2) & (2,4) is 'X',we make (3,3)th index 'O'

	if(matrix[3][1]=='X'&& matrix[1][3]=='X'){

		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}
	
	//if (3,3) & (5,1) is 'X',we make (4,2)th index 'O'

	if(matrix[2][2]=='X'&& matrix[4][0]=='X'){

		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
	}

	//if (3,3) & (4,2) is 'X',we make either (2,4)th or (5,1)th index 'O'

	if(matrix[2][2]=='X'&& matrix[3][1]=='X'){

		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
		else if(matrix[4][0]==' '){
			matrix[4][0]=='O';
			return;
		}
	}

	//if (2,4) & (3,3) is 'X',we make either (1,5) or (4,2)th index 'O'

	if(matrix[1][3]=='X'&& matrix[2][2]=='X'){

		if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
		else if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}

	}

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j]=='X'){

				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}

			}
		}
	}

}

//displaying the current matrix

void disp_matrix_5X5()
{
	int i;

	for(i=0;i<5;i++){
		printf("             |     |     |     |\n");
		printf("          %c  |  %c  |  %c  |  %c  |  %c  \n",matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3],matrix[i][4]);
		if(i!=4)
			printf("        ----- ----- ----- ----- ----- \n");
	}
	printf("\n\n");
}

//checking if there is a winner

char check_5X5()
{
	int i,j;

	//row checking
	
	//checking if the elements of rows are identical

	for(i=0;i<4;i++)
		if((matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2])&&(matrix[i][2]==matrix[i][3]&&matrix[i][3]==matrix[i][4]))							
			return matrix[i][0];

	//column checking

	//checking if the elements of columns are identical

	for(i=0;i<4;i++)
		if((matrix[0][i]==matrix[1][i]&&matrix[1][i]==matrix[2][i])&&(matrix[2][i]==matrix[3][i]&&matrix[3][i]==matrix[4][i]))							
			return matrix[0][i];

	//diagonal checking

	//checking if (1,1),(2,2),(3,3),(4,4) & (5,5) are identical

	if((matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2])&&(matrix[2][2]==matrix[3][3]&&matrix[3][3]==matrix[4][4]))								
		return matrix[0][0];

	//checking if (1,5),(2,4),(3,3),(4,2) & (5,1) are identical

	if((matrix[0][4]==matrix[1][3]&&matrix[1][3]==matrix[2][2])&&(matrix[2][2]==matrix[3][1]&&matrix[3][1]==matrix[4][0]))								
			return matrix[0][4];

	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j]==' ')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}

	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'

	return 'D';
}
