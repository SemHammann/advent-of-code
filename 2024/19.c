#include "../libraries/adventofcode.c" //V1.0

struct Data
{
	char **towels;
	size_t *towels_length;
	size_t amount_towels;
	char **designs;
	size_t *designs_length;
	size_t amount_designs;
	size_t max_design_length;
	char *cache;
};
struct Data data;



void fill_data();
long long designs_possible();

int main(int argc, char **argv)
{
	clock_t begin = clock();
	fix_file(argv, "M");


	run_parts(begin);
}

void part1()
{
	long long answer = 0;

	fill_data();
	data.cache = calloc(data.max_design_length + 2, sizeof(size_t));

	for(size_t i = 0; i < data.amount_designs; i++)
	{
		memset(data.cache, 2, data.max_design_length + 1);
		if(designs_possible(data.designs[i]))
		{
			answer++;
			// printf("%s\n", data.designs[i]);
		}
		
			
	}

	printf("Part 1: %lld", answer);
}

void part2()
{
	long long answer = 0;

	printf("Part 2: %lld", answer);
}

void fill_data()
{
	data.designs = file.file + 2;
	data.designs_length = file.lengthlines + 2;
	data.amount_designs = file.amountlines -2;

	char game[4096];
	char *game2;
	size_t i = 0;
	size_t tmp;

	strcpy(game, file.file[0]);
	game2 = searchAndReplace(game, " ", "");
	data.towels = str_split(game2, ',', false);
	while(*(data.towels + i) != NULL)
		i++;
	data.amount_towels = i;
	data.towels_length = calloc(data.amount_towels + 1, sizeof(size_t));
	for(i = 0; i < data.amount_towels; i++)
	{
		tmp = strlen(data.towels[i]);
		*(data.towels_length + i) = tmp;
	}
	for(size_t i = 0; i < data.amount_designs; i++)
		data.max_design_length = __max(data.designs_length[i], data.max_design_length);
}

long long designs_possible(char *remaining_towel)
{
	size_t len = strlen(remaining_towel);
	if(len == 0)
		return 1;
	if(data.cache[len] != 2)
		return data.cache[len];
	for(size_t i = 0; i < data.amount_towels; i++)
	{
		if(memcmp(remaining_towel, data.towels[i], data.towels_length[i]) == 0)
			if(designs_possible(remaining_towel + data.towels_length[i]))
			{
				data.cache[len] = 1;
				return 1;
			}
		
	}
	data.cache[len] = 0;
	return 0;
}