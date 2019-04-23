#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void writeFile (const char* fileName)
{
   int fd = open (fileName, O_WRONLY, S_IWRITE);
   if (fd == -1)
      return;
   const char value [] = "hello \n abc\n";
   printf ("File Opened to write with handle %d\n", fd);
   write (fd, value, sizeof (value));
   write (fd, value, strlen (value));
   close (fd);
}

void readFile (const char* fileName)
{
   int fd = open (fileName, O_RDONLY, 0);
   if (fd == -1)
      return;
   char data = '\0';
   printf ("File Opened with Read Handle %d\n", fd);
   while (read (fd, &data, 1) != 0)
      printf ("%c", data);
   close (fd);
}

void readFileFrom (const char* fileName, int offset)
{
   int fd = open (fileName, O_RDONLY, 0);
   if (fd == -1)
      return;
   char data = '\0';
   lseek (fd, offset, 0/*Beginning*/);
   printf ("File Opened with Read Handle %d to read from %d\n", fd, offset);
   while (read (fd, &data, 1) != 0)
      printf ("%c", data);
   close (fd);
}


int main ()
{
   const char fileName [] = "anc.txt";
   writeFile (fileName);
   readFile (fileName);
   readFileFrom (fileName, 2);
   return 0;
}