#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INITIAL_BUF_SIZE 1024

int main() {
	/* L: Replaced with malloc further down, can't free static array
	char buf[INITIAL_BUF_SIZE];*/
//get the file descripter. (what are the numbers?)
	int fd = open("numbers.dict", O_RDONLY);
//handle the error
	if (fd == -1)
		return 1;
	printf("fd is %d \n", fd);

//read the file and save it into the buf
	int		bufferSize;
	int     bytesRead;
	int		n;
	char *buf;
	char *newBuf;
	int i;
	bytesRead = 0;
	bufferSize = INITIAL_BUF_SIZE;
	n = 1;

	buf = (char *) malloc(bufferSize);
	if (buf == NULL)
	{
		close(fd);
		return (1);
	}
	while (1)
	{
		// Make bufferSize bigger
		//bufferSize += INITIAL_BUF_SIZE;

		bytesRead += read(fd, buf + bytesRead, bufferSize);
		if (bytesRead == bufferSize * n)
		{
			// Malloc new memory
			newBuf = (char *) malloc(bytesRead + bufferSize);
			if (newBuf == NULL)
			{
				free(buf);
				close(fd);
				return (1);
			}
			// Copy content from buffer to readout
			i = 0;
			while (i < bytesRead)
			{
				newBuf[i] = buf[i];
				i++;
			}
			free(buf);
			buf = newBuf;
			n++;
		}
		else
			break ;
	}
	printf("bytesRead is %d \n",bytesRead);

//process the data
//null terminate the buffer and error handle
	if (bytesRead >= 0)
		buf[bytesRead] = '\0';
	else
		return 1;
// now our buffer is a proper string!

	printf("%s", buf);
}