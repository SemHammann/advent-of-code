#include "../libraries/adventofcode.c" //V1.0

char **map;
long long perimeter;

long long check_cost(char what, size_t y, size_t x);
long long check_area(char what, size_t y, size_t x);

int main(int argc, char **argv)
{
	clock_t begin = clock();
	fix_file(argv, "M");

	map = calloc((file.amountlines + 3), sizeof(char*));
	assert(!(map == NULL));
	for(size_t i = 0; i < file.amountlines + 2; i++)
	{
		*(map + i) = calloc(file.lengthlines[0] + 3, sizeof(char));
		assert(!(*(map + i) == NULL));
	}


	run_parts(begin);
}

void part1()
{
	long long answer = 0;

	for(size_t y = 0; y < file.amountlines; y++)
		for(size_t x = 0; x < file.lengthlines[y]; x++)
			if(file.file[y][x] >= 'A' && file.file[y][x] <= 'Z')
				answer += check_cost(file.file[y][x], y, x);

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;

	printf("Part 2: %lld", answer);
}

long long check_cost(char what, size_t y, size_t x)
{
	perimeter = 0;
	return check_area(what, y, x) * perimeter;
}

long long check_area(char what, size_t y, size_t x)
{
	long long area = 0;
	
	if(file.file[y][x] == what)
	{
		area++;
		file.file[y][x] = what + ('a' - 'A');
		for(size_t i = 0; i < 4; i++)
		{
			if(x + directions[1][i] >= 0 && x + directions[1][i] < file.lengthlines[0] && y + directions[0][i] >= 0 && y + directions[0][i] < file.amountlines)
			{
				area += check_area(what, y + directions[0][i], x + directions[1][i]);
			}
			else
				perimeter++;
		}
	}
	else if(file.file[y][x] != what + ('a' - 'A'))
		perimeter++;

	
	return area;
}
