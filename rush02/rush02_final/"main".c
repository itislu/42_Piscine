/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:51:00 by xili              #+#    #+#             */
/*   Updated: 2023/07/22 17:51:22 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

THIS IS AN ERROR TO NOT BE CONSIDERED AS CHEATING :)

int	line_length(char *buf);

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 1024
struct	dict_entry
{
	long long *key;   // For the number as a string
	char **value; // For the corresponding word
};

void	lookup(long long key, struct dict_entry dict[], long long lineCount, int space_or_not)
{
	int	i;

	i = 0;
	while (i < lineCount)
	{
		//printf("dict[i].key is: %lld\n", *dict[i].key);
		//printf("dict[i].value is: %s\n", *dict[i].value);
		if (*dict[i].key == key)
		{
			write(1, *dict[i].value, line_length(*dict[i].value));
			if (space_or_not)
				write(1, " ", 1);
			printf(" is the dictvalue\n");
			return ;
		}
		i++;
	}
	write(1, "Dict Error\n", 12);
	return ;
}

char *ft_value_trim(char **lines, int i)
{
	int	j= 0;
	int index_i = 0;
	printf("start \n");
	char *value_arr;
	value_arr = (char *)malloc (1000);
	if (value_arr == NULL)
		printf("failed\n");
	printf("%s\n",lines[5]);
// skip the white space to the :
	while (lines[i][j] != ':')
		j++;
	if (lines[i][j] == ':')
		j++;
	while (lines[i][j] == ' ')
	{
		printf("skipping the first parts of spacces\n");
		j++;
	}
	while (lines[i][j] != '\0')
	{
		if ((lines[i][j - 1] != ' ' && lines[i][j + 1] != ' ') || (lines[i][j]== ' ' && lines[i][j + 1] != ' ' && lines[i][j + 1] != '\0'))
		{
	 		printf( "here is a space ,save the space  %c\n",lines[i][j]);
			value_arr[index_i] = lines[i][j];
			index_i++;
		}
		else if (lines[i][j] >= 32 && lines[i][j] < 127 && lines[i][j] != ' ')
		{
			printf( " save the %c\n",lines[i][j]);
			value_arr[index_i] = lines[i][j];
			index_i++;
		}
		else if (lines[i][j] == ' ' )
			printf("skip\n");
		else
			printf("not valid");
		j++;
	}
	printf("control print the value_arr should be %s\n",value_arr);
	value_arr[index_i] = '\0';
	return (value_arr);
}

int	line_length(char *buf)
{
	int	i;
	int	len;


	i = 0;
	len = 0;
	while (buf[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int count_lines(char *buf, int bytesRead)
{
	int	i = 0;
    	int 	lineCount = 0;
    	while (i < bytesRead)
    	{
        	if (buf[i] == '\n')
        	lineCount++;
        i++;
    	}
    	return lineCount;
}
/*
int	check_value_part(char *val_arr)
{
	int	i;

	if (val_arr[i] != ' ' )
		return (0);
	while (val_arr[i] == ' ')
		i++;
	while (printable chars)
	{

	}

}*/

// L: What was the intent of j? It's not doing anything now
// L: atoi returns the value 0 for empty lines. We have to filter that later
// L: Maybe let it return (-1) to differentiate it from a real 0
long long	ft_atoi(char *num_str)
{
	int i;
	i = 0;
	long long result;
	result = 0;

	if (num_str[i] < '0' && num_str[i] > '9' )
		return (-1);
	while (num_str[i] >= '0' && num_str[i] <= '9')
	{
		result = result * 10 + (num_str[i] - '0');
		i++;
	}
	while (num_str[i] == ' ')
		i++;
	if (num_str[i] != ':')
		return (-1);

/*	printf("num_str[i] is: %c\n", num_str[i]);
	if (check_value_part(&num_str[i + 1]) == 0)
		return (-1);*/

	printf("atoi control :%lld", result);
		return (result);
}

int main()
{
 /////////////////////////////////////variable declare/////////////////////////////

	int i;
	int len = 0;
	int j;
	int index;
	char buf[BUF_SIZE];		// L: Check norminette if this is allowed
	int lineCount;

///////////////////////////PART ONE FILE HANDELING ///////////////////////////////
//get the file descripter.
    int fd = open("numbers.dict", O_RDONLY);
    if (fd == -1)
    {
        return 1;
    }
	printf("fd is %d \n", fd);

//read the file and save it into the buf
	int	 bytesRead;
    bytesRead = read(fd, buf, BUF_SIZE - 1);
	printf("bytesRead is %d \n",bytesRead);

//null terminate the buffer and error handle
	if (bytesRead >= 0)
		buf[bytesRead] = '\0';
	else
		return 1;
// now our buffer is a proper string!

//	printf("%s", buf);

/////////////////////////STORE THE LINE INTO AN ARRAY////////////////////////////////

	lineCount = count_lines(buf, bytesRead);
//control:
	printf("Control: Number of lines: %d\n", lineCount);

//Allocate memory for line pointers
   	char **lines = malloc(lineCount * sizeof(char *));
   	//3. malloc the memory for key arr and value arr
	// L: The malloc size was the problem for the weird int behavior
	long long	 *number_part = (long long *)malloc(lineCount * sizeof(long long));
	char	 *value_part = (char *)malloc(bytesRead + 1);
// malloc the struct
// L: Should it be lineCount instead of bytesRead?
struct	 dict_entry *dictionary = malloc((lineCount + 1) * sizeof(struct dict_entry));
// malloc control
	if (number_part == NULL || value_part == NULL)
		printf("false initiaion with malloc! \n");
	else
		printf("control check: success malloc for number_part and value_part\n");


// Store each line in the lines array
    	char *lineStart = buf;
  	 i = 0;
  	int lineIndex = 0;
	while (i < bytesRead)
	{
       	 	if (buf[i] == '\n')
       	 	{
            		buf[i] = '\0'; // Null-terminate the line
          	 	 lines[lineIndex] = lineStart; // Store line pointer
            		lineStart = buf + i + 1; // Move to the start of the next line
            		lineIndex++;
        	}
       		i++;
    }

    // Print lines
    i = 0;
    while (i < lineCount) {
        printf("Line %d: %s\n", i, lines[i]);
        i++;
    }

//////////////////////////////// reading and parsing
// L: Is this bug-free in edge cases?
	 i = 0;
	 j = 0;

	while(i < lineCount)
	{
		if (lines[i][j]!= ':')
			j++;
		else
		{
			printf("lines[i][j] now is %c,",lines[i][j]);
			break ;
		}

	}

//put the number_part to the dic
	i = 0;
	index = 0;
	while (i < lineCount)
	{
		dictionary[i].key = malloc(sizeof(long long)); // Allocate memory for the key
		*(dictionary[i].key) = ft_atoi(lines[i]);  // Store the integer value in the allocated memory
		printf("the dictionary[i].key is %lld, \n", *dictionary[i].key);
		i++;
	}

// L: Trying malloc for .value now
	i = 0;
	char *temp;
	while (i < lineCount)
	{
		temp = ft_value_trim(lines, i);

		dictionary[i].value = malloc(line_length(temp));
		*(dictionary[i].value) = temp;
		printf("the dictionary[i].value is %s\n", *dictionary[i].value);
		i++;
	}

/*	while ()
	{
		if (i < 1)
			lookup(dictionary, translate(), lineCount);
		write(1, " ", 1);
		lookup(dictionary, translate(), lineCount);
		i++;
	}
*/
/*
	lookup(dictionary.key, dictionary.value)

void	lookup(struct dictionary[])
	dictionary[i].key
	dictionary[i].value
	while (input != dictionary[i].key)
	{
		i++;
	}
*/

/*/////////	ALTERNATIVE TO PASSING A STRUCTURE/////////////////////////
	function(dictionary.key, dictionary.value)

void	function(int *key, char **value)
	key[i]
	value[i]
	while (input != dictionary[i].key)
	{
		i++;
	}
	dictionary[i].value
*/
}
/*
//////////////////////might be useful code//////////////////////////////




//3. malloc the memory for key arr and value arr

	char	 *number_part = (char *)malloc(len + 1);
	char	 *value_part = (char *)malloc(len + 1);
// malloc control
	if (number_part == NULL || value_part == NULL)
		printf("false initiaion with malloc! \n");
	else
		printf("control check: success malloc for number_part and value_part\n");


//
//control check : the number part
	printf("the number_part is %s\n", number_part);
//assign the arr to the struct


//trim the value
	i++;
	j = 0;
	while(line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if(line[i] >= 32 || line[i] <= 126)
		{
			value_part[j] = line[i];
			i++;
			j++;
		}
		else
			printf("ERROR\n");
	 }

/



*/
