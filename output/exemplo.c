#include <stdio.h>
char box[10] = { 'o','1','2','3','4','5','6','7','8','9' };// This is to Initialise the board
int checkWin();// This will be used to check for the win
void board();

int main() {
	
	int player = 1, i, choice;
	char xOrO; // X,O
	
	if (!save(box, player))
	{
		fprintf(stderr, "Save function failed!\n");
		//TODO: handle failure
	}

	if (!load(box, &player))
	{
		fprintf(stderr, "Load function failed!\n");
		//TODO: handle failure
	}
	
	do {
		board();
		player = (player % 2) ? 1 : 2;
		printf("Player %d, enter the choice : ", player);
		scanf("%d", &choice);
		xOrO = (player == 1) ? 'X' : 'O';
		if (choice == 1 && box[1] == '1')
			box[1] = xOrO;
		else if (choice == 2 && box[2] == '2')
			box[2] = xOrO;
		else if (choice == 3 && box[3] == '3')
			box[3] = xOrO;
		else if (choice == 4 && box[4] == '4')
			box[4] = xOrO;
		else if (choice == 5 && box[5] == '5')
			box[5] = xOrO;
		else if (choice == 6 && box[6] == '6')
			box[6] = xOrO;
		else if (choice == 7 && box[7] == '7')
			box[7] = xOrO;
		else if (choice == 8 && box[8] == '8')
			box[8] = xOrO;
		else if (choice == 9 && box[9] == '9')
			box[9] = xOrO;

		else {
			printf("Invalid option !");
			player--;
			getchar();
		}
		i = checkWin();
		player++;

	} while (i == -1);

	board();
	if (i == 1) {
		printf("==>Player %d won", --player);
	}
	else {
		printf("==>Game draw");
	}
	getchar();
	return 0;

}
int checkWin() {
	if (box[1] == box[2] && box[2] == box[3])/**/
		return 1;
	else if (box[4] == box[5] && box[5] == box[6])
		return 1;
	else if (box[7] == box[8] && box[8] == box[9])
		return 1;
	else if (box[1] == box[4] && box[4] == box[7])
		return 1;
	else if (box[2] == box[5] && box[5] == box[8])
		return 1;
	else if (box[3] == box[6] && box[6] == box[9])
		return 1;
	else if (box[1] == box[5] && box[5] == box[9])
		return 1;
	else if (box[3] == box[5] && box[5] == box[7])
		return 1;
	else if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
		return 0;
	else
		return -1;
}

void board() {
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", box[1], box[2], box[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", box[4], box[5], box[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", box[7], box[8], box[9]);
	printf("     |     |     \n");
}

//this function returns whether the save operation was successful
bool save(char board_array[10], int player)
{
	FILE* fp;

	//open file
	fp = fopen("savefile.txt", "wt");
	if (fp == NULL)
	{
		fprintf(stderr, "Error opening file\n");
		return false;
	}

	//save player's turn to file
	if (fputc(player == 1 ? '1' : '2', fp) == EOF)
	{
		fprintf(stderr, "Error writing to file\n");
		fclose(fp);
		return false;
	}

	//save board to file
	if (fwrite(board_array, 10, 1, fp) != 1)
	{
		fprintf(stderr, "Error writing to file\n");
		fclose(fp);
		return false;
	}

	//cleanup
	fclose(fp);

	return true;
}

//this function returns whether the load operation was successful
bool load(char board_array[10], int* player)
{
	FILE* fp;

	//open file
	fp = fopen("savefile.txt", "rt");
	if (fp == NULL)
	{
		fprintf(stderr, "Error opening file\n");
		return false;
	}

	//read player's turn from file
	switch (fgetc(fp))
	{
	case EOF:
		fprintf(stderr, "Error reading from file\n");
		fclose(fp);
		return false;
		break;
	case '1':
		*player = 1;
		break;
	case '2':
		*player = 2;
		break;
	default:
		fprintf(stderr, "Unexpected character found in file!\n");
		fclose(fp);
		return false;
	}

	//read board from file
	if (fread(board_array, 10, 1, fp) != 1)
	{
		fprintf(stderr, "Error reading from file\n");
		fclose(fp);
		return false;
	}

	//cleanup
	fclose(fp);

	return true;
}