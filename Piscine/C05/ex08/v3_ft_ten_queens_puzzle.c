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

void	queen_attack(char board[10][10])
{
	int		start_row;
	int		row;
	int		col;
	int		i;

	start_row = 0;
	col = 1;
	i = 0;
	while (start_row < 10)
	{
		while (board[start_row][i] != 'Q' && i < 10)
			i++;
		row = start_row++ + 1;
		while (row < 10 && i != 10)
		{
			board[row][i] = '1';
			// printf("i:%i | row:%i | diag_l:%i | diag_r:%i\n", i, row, diag_l, diag_r);
			if (i - col >= 0)
				board[row][i - col] = '1';
			if (i + col <= 9)
				board[row][i + col] = '1';
			row++;
			col++;
		}
		col = 1;
		i = 0;
	}
}

void	clear_rows(char board[10][10], int start_row)
{
	int	start_col;

	start_col = 0;
	while (start_row < 10)
	{
		while (start_col < 10)
			board[start_row][start_col++] = '.';
		start_col = 0;
		start_row++;
	}
}

void	fill(char board[10][10], int start_row)
{
	int	row;
	int	i;

	row = 0;
	i = 0;	
	while (start_row < 10)
	{
		while (board[row][i] == '1' && i < 10)
			i++;
		board[row][i] = 'Q';
		queen_attack(board);
		row = ++start_row;
		i = 0;
	}
	print_board(board);
	ft_putchar('\n');
	if (is_valid(board) == 1)
	{
		print_queen_pos(board);
		return ;
	}
	while (--start_row >= 0)
	{
		while (board[start_row][i] != '.' && i < 10)
			i++;
		if (board[start_row][i] == '.')
			{
				clear_rows(board, start_row + 1);
				board[start_row][i--] = 'Q';
				while (i >= 0 && board[start_row][i] != 'Q')
					i++;
				board[start_row][i] = '1';
				queen_attack(board);
				fill(board, start_row);
			}
		i = 0;
	}
}

void	ft_ten_queens_puzzle()
{
	char	board[10][10];
	int		start_row = 0;

	clear_rows(board, start_row);
	fill(board, start_row);
}

int	main(void)
{
	ft_ten_queens_puzzle();
}
