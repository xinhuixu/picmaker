#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main(){
  int fd, i, j, xres, yres; 
  xres = 400; yres = 400;
  fd = open("xd.ppm", O_CREAT|O_RDWR,0777);
  
  char h[20]; snprintf(h, sizeof(h), "P3\n%d %d\n255", xres, yres);
  write(fd, h, sizeof(h));

  char c[4];
  for (i=0; i<yres; i++){
    for (j=0; j<xres; j++) {

      sprintf(c, "%d ", j);
      write(fd, c, sizeof(c));
    }
  }
  
  sprintf(c, "\n");
  write(fd, c, sizeof(c));
  close(fd);

}
