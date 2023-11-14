#include <unistd.h>
#include <stdio.h>

int	is_found(char board[10][10], char c, int row, int col, int count)
{
	while (row < 10)
	{
		while (col < 10 && board[row][col] != c)
			col++;
		if (col < 10)
			count++;
		col = 0;
		row++;
	}
	if (count == 10 && c == 'Q')
	{
		row = 0;
		while (row < 10)
		{
			while (board[row][col] != 'Q' && col < 10)
				col++;
			if (col < 10)
			{
				col += '0';
				write(1, &col, 1);
			}
			row++;
			col = 0;
		}
		write(1, "\n", 1);
		return (1);
	}
	if (count > 0 && c == '.')
		return (1);
	return (0);
}

void	queen_attack(char board[10][10], int start_row)
{
	int		row;
	int		col;
	int		i;

	col = 1;
	i = 0;
	while (start_row < 10)
	{
		while (i < 10 && board[start_row][i] != 'Q')
			i++;
		row = start_row++ + 1;
		while (row < 10 && i < 10)
		{
			board[row][i] = '1';
			if (i - col >= 0)
				board[row][i - col] = '1';
			if (i + col < 10)
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

void	fill(char board[10][10], int start_row, int *count_s, int i)
{
	while (start_row >= 0 && start_row < 10)
	{
		while (i < 10 && board[start_row][i] == '1')
			i++;
		if (i < 10)
			board[start_row][i] = 'Q';
		queen_attack(board, 0);
		i = 0;
		start_row++;
		if (start_row == 10 && is_found(board, 'Q', 0, 0, 0) == 1)
			(*count_s)++;
		if (start_row == 10 && is_found(board, '.', 0, 0, 0) == 0)
			return ;
		if (start_row == 10)
			while (--start_row >= 0)
			{
				while (i < 10 && board[start_row][i] != '.')
					i++;
				if (i < 10 && board[start_row][i] == '.')
				{
					while (i >= 0 && board[start_row][i] != 'Q')
						i--;
					board[start_row][i] = '1';
					while (i < 10 && board[start_row][i] != '.')
						i++;
					board[start_row][i] = 'Q';
					clear_rows(board, ++start_row);
					queen_attack(board, 0);
					fill(board, --start_row, count_s, 0);
				}
				i = 0;
			}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10][10];
	int		start_row;
	int		count_s;
	int		i;

	start_row = 0;
	count_s = 0;
	i = 0;
	clear_rows(board, start_row);
	fill(board, start_row, &count_s, i);
	return (count_s);
}

int	main(void)
{
printf("Solutions: %i\n", ft_ten_queens_puzzle());
}
