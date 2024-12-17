#include "../libraries/adventofcode.c" //V1.0

#define OUTPUT_LENGTH 500

struct IntCode
{
	long long *reg;
	size_t current;
	size_t length;
	long long A, B, C;
	long long *output;
	size_t place_output;
};
struct IntCode IC;


void part1();
void part2();

void setup();
long long run();

long long operand();
void adv();
void bxl();
void bst();
void jnz();
void bxc();
void out();
void bdv();
void cdv();
void print_output();



int main(int argc, char *argv[])
{
	clock_t begin = clock();
	
	fix_file(argv, "M");

	run_parts(begin);
}

void part1() 
{
	long long answer = 0;

	setup();
	run();

	printf("Part 1: ");
	print_output();
}

void part2()
{
	long long answer = 0;

	printf("Part 2: %lld", answer);
}


void setup()
{
	char *game;
	char **tokens;
	size_t i = 0;
	IC.output = calloc(OUTPUT_LENGTH, sizeof(long long));
	game = calloc(file.lengthlines[4], sizeof(char));
	strcpy(game, file.file[4]);
	IC.current = 0;
	IC.place_output = 0;

	tokens = str_split(game, ' ', false);
	tokens = str_split(*(tokens + 1), ',', false);
	while(*(tokens + i) != NULL)
	{
		i++;
	}
	IC.reg = calloc(i, sizeof(long long));
	IC.length = i;
	for(size_t j = 0; j < i; j++)
	{
		*(IC.reg + j) = str_ll(*(tokens + j));
	}

	strcpy(game, file.file[0]);
	tokens = str_split(game, ':', false);
	IC.A = str_ll(*(tokens + 1) + 1);

	strcpy(game, file.file[1]);
	tokens = str_split(game, ':', false);
	IC.B = str_ll(*(tokens + 1) + 1);

	strcpy(game, file.file[2]);
	tokens = str_split(game, ':', false);
	IC.C = str_ll(*(tokens + 1) + 1);

	return;
}

long long run()
{
	while(IC.current < IC.length)
	{
		switch(*(IC.reg + IC.current))
		{
			case 0:
				adv();
				break;
			case 1:
				bxl();
				break;
			case 2:
				bst();
				break;
			case 3:
				jnz();
				break;
			case 4:
				bxc();
				break;
			case 5:
				out();
				break;
			case 6:
				bdv();
				break;
			case 7:
				cdv();
				break;
			default:
				printf("ERROR");
				exit(-1);
				break;
		}
	}
}

long long operand(long long number)
{
	switch(number)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			return number;
		case 4:
			return IC.A;
		case 5:
			return IC.B;
		case 6:
			return IC.C;
		case 7:
			printf("ERROR CODE 7");
			exit(7);
	}
}

void adv()
{
	IC.A = IC.A >> operand(*(IC.reg + IC.current + 1));
	IC.current += 2;
}

void bxl()
{
	IC.B = *(IC.reg + IC.current + 1) ^ IC.B;
	IC.current += 2;
}

void bst()
{
	IC.B = IC.B = operand(*(IC.reg + IC.current + 1)) % 8;
	IC.current += 2;
}

void jnz()
{
	if(IC.A != 0)
	{
		IC.current = *(IC.reg + IC.current + 1);
	}
	else
		IC.current += 2;
}

void bxc()
{
	IC.B = IC.C ^ IC.B;
	IC.current += 2;
}

void out()
{
	if(IC.place_output > OUTPUT_LENGTH)
	{
		printf("ERROR OUTPUT FULL");
		exit(5);
	}
	else
	{
		IC.output[IC.place_output] = operand(*(IC.reg + IC.current + 1)) % 8;
		IC.place_output++;
		IC.current += 2;
	}
}
void bdv()
{
	IC.B = IC.A >> operand(*(IC.reg + IC.current + 1));
	IC.current += 2;
}

void cdv()
{
	IC.C = IC.A >> operand(*(IC.reg + IC.current + 1));
	IC.current += 2;
}

void print_output()
{
	for(size_t i = 0; i < IC.place_output; i++)
	{
		printf("%lld,", IC.output[i]);
	}
}