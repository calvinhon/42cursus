#include <unistd.h>
#include <stdio.h>

int	is_valid(char board[10][10])
{
	int	row = 0;
	int col = 0;

	while (row < 10)
	{
		while (board[row][col] != 'Q' && col < 10)
			col++;
		if (col == 10)
			return (0);
		col = 0;
		row++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_queen_pos(char board[10][10])
{
	int 	row = 0;
	int 	col = 0;
	int 	pos = 0;

	while (row < 10)
	{
		while (board[row][col] != 'Q' && col < 10)
			col++;
		if (col < 10)
		{
			pos = col + '0';
			ft_putchar(pos);
		}
		else
			ft_putchar('.');
		row++;
		col = 0;
	}
	ft_putchar('\n');
}

void	print_board(char board[10][10])
{
	int row = 0;
	int col = 0;

	while (row < 10)
	{
		while (col < 10)
		{
			ft_putchar(board[row][col]);
			col++;
		}
		ft_putchar('\n');
		col = 0;
		row++;
	}
}

void	fill(char board[10][10], int start_row, int start_col)
{
	int 	row = 0;
	int 	col = 1;
	int 	diag_l = 0;
	int 	diag_r = 0;
	int		i = 0;
	
	while (start_row < 10)
	{
		while (board[row][i] == '1' && i < 10)
			i++;
		if (i < 10)
			board[row++][i] = 'Q';
		start_col = i;
		while (row < 10)
		{
			board[row][start_col] = '1';
			diag_l = start_col - col;
			diag_r = start_col + col;
			// printf("i:%i | row:%i | start_col:%i | diag_l:%i | diag_r:%i\n", i, row, start_col, diag_l, diag_r);
			if (diag_l >= 0)
				board[row][diag_l] = '1';
			if (diag_r <= 9)
				board[row][diag_r] = '1';
			row++;
			col++;
		}
		start_row++;
		row = start_row;
		i = 0;
		col = 1;
	}
	print_board(board);
	if (is_valid(board) == 1)
	{
		print_queen_pos(board);
	}
	else
	{
		fill();
	}
}

void	ft_ten_queens_puzzle()
{
	char	board[10][10];
	int		start_row = 0;
	int 	start_col = 0;

	while (start_row < 10)
	{
		while (start_col < 10)
			board[start_row][start_col++] = '.';
		start_col = 0;
		start_row++;
	}
	start_row = 0;
	start_col = 0;
	fill(board, start_row, start_col);
	
}

int	main(void)
{
	ft_ten_queens_puzzle();
}
