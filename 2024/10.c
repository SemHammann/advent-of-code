#include "../libraries/adventofcode.c"

long long search_starts();
long long search_trailheads();

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	fix_file(argv, "M");
	run_parts(begin);
}

void part1()
{
	long long answer = 0;

	answer = search_starts(1);

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;

	answer = search_starts(2);

	printf("Part 2: %lld", answer);
}

long long search_starts(int part)
{
	long long answer = 0;
	for(long long y = 0; y < file.amountlines; y++)
		for(long long x = 0; x < file.lengthlines[y]; x++)
			if(file.file[y][x] == '0')
			{
				answer += search_trailheads(y, x, part);
				if(part == 1)
					for(long long y1 = 0; y1 < file.amountlines; y1++)
						for(long long x1 = 0; x1 < file.lengthlines[y1]; x1++)
							if(file.file[y1][x1] == 'X')
								file.file[y1][x1] = '9';
			}
	return answer;
}

long long search_trailheads(long long y, long long x, int part)
{
	long long answer = 0;
	if(file.file[y][x] == '9')
	{
		if(part == 1)
			file.file[y][x] = 'X';
		return 1;
	}
	else
	{
		if(y + 1 < file.amountlines)
			if(file.file[y + 1][x] == file.file[y][x] + 1)
				answer += search_trailheads(y + 1, x, part);
		if(x + 1 < file.lengthlines[0])
			if(file.file[y][x + 1] == file.file[y][x] + 1)
				answer += search_trailheads(y, x + 1, part);
		if(y - 1 >= 0)
			if(file.file[y - 1][x] == file.file[y][x] + 1)
				answer += search_trailheads(y - 1, x,  part);
		if(x - 1 >= 0)
			if(file.file[y][x - 1] == file.file[y][x] + 1)
				answer += search_trailheads(y, x - 1, part);
		
	}
	return answer;
}